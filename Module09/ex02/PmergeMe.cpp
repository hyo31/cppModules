#include "PmergeMe.hpp"

std::vector<unsigned int>   parseInput(char **input) {
    std::vector<unsigned int>   response;
    unsigned int                num;

    for (int i = 1; input[i]; i++) {
        if (sscanf(input[i], "%u", &num) != 1) {
            std::cerr << "\033[1;31mError\033[0m" << std::endl;
            return response;
        }
        response.push_back(num);
    }

    return response;
}

void    sortVector(char **input) {
    std::vector<unsigned int>   S, S2, parsedInput;

    parsedInput = parseInput(input);
    if (!parsedInput.size()) {
        return;
    }

    for (int i = 0; parsedInput[i]; i++) {
        std::cout << parsedInput[i] << std::endl;
    }
}
