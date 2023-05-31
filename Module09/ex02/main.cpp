#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "\033[1;31mError: \033[0m" << " no arguments provided." << std::endl;
        return 0;
    }

    sort(argc, argv);

    return 0;
}