#include "RNP.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "\033[1;31mError: \033[0m" << argc -1 << " arguments provided, expected 1." << std::endl;
        return 0;
    }

    RPN rpn;
    rpn.applyOperations(argv[1]);

    return 0;
}