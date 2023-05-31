#include "PmergeMe.hpp"

void    printResult(std::vector<unsigned int> initial, std::vector<unsigned int> sortedVector, std::deque<unsigned int> sortedDeque, float time1, float time2, int amount) {
    std::cout << std::setprecision(8);
    std::cout << "\033[1;31mInitial string: \033[0m";
    for (size_t i = 0; i < initial.size(); i++) {
        std::cout << " " << initial[i];
    }
    std::cout << "." << std::endl;
    std::cout << "\033[1;92mSorted vector:  \033[0m";
    for (size_t i = 0; i < sortedVector.size(); i++) {
        if (i == 15) {
            std::cout << " [...]";
            break;
        }
        std::cout << " " << sortedVector[i];
    }
    std::cout << "." << std::endl;
    std::cout << "\033[1;92mSorted deque:   \033[0m";
    for (size_t i = 0; i < sortedDeque.size(); i++) {
        if (i == 15) {
            std::cout << " [...]";
            break;
        }
        std::cout << " " << sortedDeque[i];
    }
    std::cout << "." << std::endl;
    std::cout << "Time to process a range of \033[1;33m" << amount << "\033[0m elements with std::vector:   " << time1 << " µs." << std::endl;
    std::cout << "Time to process a range of \033[1;33m" << amount << "\033[0m elements with std::deque:    " << time2 << " µs." << std::endl;
}

std::vector<unsigned int>   parseInput(int amount, char **input) {
    std::vector<unsigned int>   response;
    unsigned int                num;

    for (int i = 1; i < amount; i++) {
        if (sscanf(input[i], "%u", &num) != 1 || input[i][0] == '-') {
            std::cerr << "\033[1;31mError:  \033[0m" << input[i] << std::endl;
            return response;
        }
        response.push_back(num);
    }

    return response;
}

std::vector<unsigned int>   mergeVectors(std::vector<unsigned int> sorted1, std::vector<unsigned int> sorted2) {
    std::vector<unsigned int>   merged;

    while (sorted1.size() && sorted2.size()) {
        if (sorted1[0] < sorted2[0]) {
            merged.push_back(sorted1[0]);
            sorted1.erase(sorted1.begin());
        } else {
            merged.push_back(sorted2[0]);
            sorted2.erase(sorted2.begin());
        }
    }
    while (sorted1.size()) {
        merged.push_back(sorted1[0]);
        sorted1.erase(sorted1.begin());
    }
    while (sorted2.size()) {
        merged.push_back(sorted2[0]);
        sorted2.erase(sorted2.begin());
    }

    return merged;
}

std::deque<unsigned int>   mergeDeques(std::deque<unsigned int> sorted1, std::deque<unsigned int> sorted2) {
    std::deque<unsigned int>   merged;

    while (sorted1.size() && sorted2.size()) {
        if (sorted1[0] < sorted2[0]) {
            merged.push_back(sorted1[0]);
            sorted1.erase(sorted1.begin());
        } else {
            merged.push_back(sorted2[0]);
            sorted2.erase(sorted2.begin());
        }
    }
    while (sorted1.size()) {
        merged.push_back(sorted1[0]);
        sorted1.erase(sorted1.begin());
    }
    while (sorted2.size()) {
        merged.push_back(sorted2[0]);
        sorted2.erase(sorted2.begin());
    }

    return merged;
}

std::vector<unsigned int>   sortVector(std::vector<unsigned int> S) {
    if (S.size() == 1)
        return S;
    
    std::size_t const halfSize = S.size() / 2;
    std::vector<unsigned int> sorted1(S.begin(), S.begin() + halfSize);
    std::vector<unsigned int> sorted2(S.begin() + halfSize, S.end());
    
    sorted1 = sortVector(sorted1);
    sorted2 = sortVector(sorted2);
    S = mergeVectors(sorted1, sorted2);

    return S;
}

std::deque<unsigned int>    sortDeque(std::deque<unsigned int> D) {
    if (D.size() == 1)
        return D;
    
    std::size_t const halfSize = D.size() / 2;
    std::deque<unsigned int> sorted1(D.begin(), D.begin() + halfSize);
    std::deque<unsigned int> sorted2(D.begin() + halfSize, D.end());

    sorted1 = sortDeque(sorted1);
    sorted2 = sortDeque(sorted2);
    D = mergeDeques(sorted1, sorted2);

    return D;
}

void    sort(int amount, char **input) {
    std::vector<unsigned int>   S, parsedInput;
    std::deque<unsigned int>    D;
    float                       timeVector = 0.0, timeDeque = 0.0;
    struct timeval              start, stop;

    parsedInput = parseInput(amount, input);
    if (!parsedInput.size()) {
        return;
    }

    for (size_t i = 0; i < parsedInput.size(); i++) {
        S.push_back(parsedInput[i]);
        D.push_back(parsedInput[i]);
    }

    gettimeofday(&start, 0);
    S = sortVector(S);
    gettimeofday(&stop, 0);
    timeVector = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec)*1e-6;

    gettimeofday(&start, 0);
    D = sortDeque(D);
    gettimeofday(&stop, 0);
    timeDeque = (stop.tv_sec - start.tv_sec) + (stop.tv_usec - start.tv_usec)*1e-6;

    printResult(parsedInput, S, D, timeVector, timeDeque, S.size());
}
