#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "\033[1;31mError: \033[0m" << argc -1 << " arguments provided, expected 1." << std::endl;
        return 0;
    }

    try {
        Btc btc("data.csv");
        btc.calculateValue(argv[1]);
    } catch (Btc::InvalidData &e) {
        std::cerr << "\033[1;31mError: \033[0m" << e.what() << std::endl;
    }

    return 0;
}