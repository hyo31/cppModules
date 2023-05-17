#include "BitcoinExchange.hpp"

bool validateDate(Date date) {
    const int maxValidYear = 9999;
    const int minValidYear = 1800;

    if (date.year < minValidYear || date.year > maxValidYear)
        return false;

    if (date.month < 1 || date.month > 12)
        return false;

    if (date.day < 1 || date.day > 31)
        return false;

    if (date.month == 2) {
        if (((date.year % 4 == 0) && (date.year % 100 != 0)) || (date.year % 400 == 0)) {
            return (date.day <= 29);
        }
        return (date.day <= 28);
    }

    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
        return (date.day <= 30);

    return true;
}

Btc::Btc(std::string dataName) {
    std::ifstream           data;
    std::pair<std::string, long double> tempData;
    Date                    date;
    long double             value;
    char                    tempLine[256];
    std::string             line;
    
    data.open(dataName.c_str());
    data.getline(tempLine, 256);
    
    while (data.getline(tempLine, 256)) {
        line = tempLine;
        if (line.length() < 12) {
            throw InvalidData();
        }

        // Reading the date and corresponding value from the file into a map
        if (sscanf(line.substr(11, line.length() - 11).c_str(), "%Lf", &value) != 1)
            throw InvalidData();
        if (sscanf(line.substr(0, 4).c_str(), "%d", &date.year) != 1)
            throw InvalidData();
        if (sscanf(line.substr(5, 2).c_str(), "%d", &date.month) != 1)
            throw InvalidData();
        if (sscanf(line.substr(8, 2).c_str(), "%d", &date.day) != 1)
            throw InvalidData();
        
        if (!validateDate(date)) {
            throw InvalidData();
        }

        tempData.first = line.substr(0, 10);
        tempData.second = value;
        this->_data.insert(tempData);
    }  
}

Btc::~Btc() {

}

Btc::Btc(const Btc &copy)
{
    this->_data = copy._data;    
}

Btc &Btc::operator=(const Btc &copy)
{
    this->_data = copy._data;
    return (*this);
}

void Btc::calculateValue(std::string inputName) {
    std::ifstream           input;
    char                    tempLine[256];

    input.open(inputName.c_str());
    input.getline(tempLine, 256);
    
    while (input.getline(tempLine, 256)) {
        parseLine(tempLine);
    }
}

void Btc::parseLine(std::string line) {
    long double value;
    Date        date;
    bool        error;

    error = false;
    if (line.length() < 14) {
        std::cerr << "\033[1;31mError: \033[0m" << "Bad input => " << line << std::endl;
        return;
    }

    // Reading the date and corresponding value from the file into variables.
    if (sscanf(line.substr(13, line.length() - 13).c_str(), "%Lf", &value) != 1)
        error = true;
    if (sscanf(line.substr(0, 4).c_str(), "%d", &date.year) != 1)
        error = true;
    if (sscanf(line.substr(5, 2).c_str(), "%d", &date.month) != 1)
        error = true;
    if (sscanf(line.substr(8, 2).c_str(), "%d", &date.day) != 1)
        error = true;

    if (error || value < 0 || value > 999 || !validateDate(date)) {
        std::cerr << "\033[1;31mError: \033[0m" << "Bad input => " << line << std::endl;
        return;
    }

    findCorrespondingValue(date, value);

    return;
}

bool dateIsNewer(Date currentDate, Date date) {
    
    // Compare years.
    if (currentDate.year > date.year)
        return true;
    if (currentDate.year < date.year)
        return false;
    
    // If the years were equal, compare months.
    if (currentDate.month > date.month)
        return true;
    if (currentDate.month < date.month)
        return false;
    
    // If the monst were equal, compare days.
    if (currentDate.day > date.day)
        return true;
    return false;
}

void Btc::findCorrespondingValue (Date date, long double value) {
    Date                                            currentDate;
    long double                                     storedValue;
    std::string                                     storedDate;    
    std::map<std::string, long double>::iterator    it;

    std::cout << std::setprecision(16);

    for (it = this->_data.begin(); it != this->_data.end(); it++) {
        if (it == this->_data.begin()) {
            storedValue = it->second;
            storedDate = it->first;
        }
        sscanf(it->first.substr(0, 4).c_str(), "%d", &currentDate.year);
        sscanf(it->first.substr(5, 2).c_str(), "%d", &currentDate.month);
        sscanf(it->first.substr(8, 2).c_str(), "%d", &currentDate.day);

        // This date matches so we use the value of this date.
        if ((currentDate.year == date.year && currentDate.month == date.month && currentDate.day == date.day)) {
            std::cout << it->first << " => " << it->second << " = " << it->second * value << std::endl;
            return;
        }

        // If this date is more recent then the one we are looking for, we use the previous dates value.
        if (dateIsNewer(currentDate, date)) {
            std::cout << storedDate << " => " << storedValue << " = " << storedValue * value << std::endl;
            return;
        }

        // Save the previous values.
        storedValue = it->second;
        storedDate = it->first;
    }

    // All the dates in our database were older, so we use the last one.
    if (it == this->_data.end()) {
        std::cout << storedDate << " => " << storedValue << " = " << storedValue * value << std::endl;
    }
}
