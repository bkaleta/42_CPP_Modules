/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:34:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 22:28:17 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	readDB();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
	if (this != &other)
		*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
	if (this != &other)
		this->_database = other._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void programStart(int ac, char *av) {
	if (ac == 2) {
		try {
			BitcoinExchange broker;
			broker.performExchange(av);
		} catch (const char *error) {
			std::cerr << error << std::endl;
		}
	}
	else
		std::cout << "Try: ./btc arg1" << std::endl;
}

void BitcoinExchange::readDB() {
	std::ifstream database("data.csv");
	if (!database.is_open())
		throw "Exception: Cannot open file";
	
	std::string line;
	std::getline(database, line);
	if (line != "date,exchange_rate")
		throw "Exception: Wrong database format";
	
	while (std::getline(database, line)) {
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			throw "Exception: wrong line format";

		std::string date = line.substr(0, pos);
		std::string strValue = line.substr(pos + 1);

		if (!valiDate(date))
			throw "Exception: Wrong Date";
		double value = 0.0;
		if (!valiValue(strValue, value, 1)) {
			std::cerr << "Error: bad value => " << strValue << std::endl;
			continue;
		}
		_database[date] = value;
	}
}

bool BitcoinExchange::valiDate(const std::string &date) {
	if (!valiDateForm(date))
		return false;
	
	int year 	= std::atoi(date.substr(0, 4).c_str());
	int month 	= std::atoi(date.substr(5, 2).c_str());
	int day 	= std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;
	
	int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if (leap)
		daysInMonth[1] = 29;
	
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::valiDateForm(const std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}
	return true;
}

bool BitcoinExchange::valiValue(const std::string &strValue, double &value, bool db) {
	if (!validNumber(strValue))
		return false;

	char *endptr = 0;
    double val = std::strtod(strValue.c_str(), &endptr);

    if (endptr == strValue.c_str() || *endptr != '\0') {
        return false;
	}
	if (!db) {
		if (val < 0.0 || val > 1000.0)
			return false;
	}
		
    value = val;
    return true;
}

bool BitcoinExchange::validNumber(const std::string &strValue) {
	bool hasDigit = false;
	bool hasDot   = false;

	if (strValue.empty())
		return false;
	
	std::size_t i = 0;
	if (strValue[i] == '+' || strValue[i] == '-')
		++i;
	
	for (; i < strValue.size(); ++i) {
        unsigned char c = static_cast<unsigned char>(strValue[i]);
        if (std::isdigit(c)) {
            hasDigit = true;
            continue;
        }
        if (c == '.') {
            if (hasDot)
                return false;
            hasDot = true;
            continue;
        }
        return false;
    }
    return hasDigit;	
}

void BitcoinExchange::performExchange(const char *fileName) {
	std::ifstream input(fileName);
    if (!input.is_open()) {
        std::cerr << "Error: cannot open input file: " << *fileName << std::endl;
        return;
    }

    std::string line;

    if (!std::getline(input, line)) {
        std::cerr << "Error: empty input file" << std::endl;
        return;
    }
    {
        std::stringstream ss(line);
        std::string headerDate, headerDelimiter, headerValue;
        ss >> headerDate;
        ss >> headerDelimiter;
        ss >> headerValue;
        if (!(headerDate == "date" && headerDelimiter == "|" && headerValue == "value")) {
            std::cerr << "Error: bad header => " << line << std::endl;
        }
    }

    while (std::getline(input, line)) {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string inputDate;
        char delimiter = 0;
        std::string inputValue;

        if (!(ss >> inputDate)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!(ss >> delimiter) && delimiter != '|') {
            std::cerr << "Error: bad separator => " << line << std::endl;
            continue;
        }
        if (!(ss >> inputValue)) {
            std::cerr << "Error: bad value => " << line << std::endl;
            continue;
        }

        if (!valiDate(inputDate)) {
            std::cerr << "Error: bad date => " << inputDate << std::endl;
            continue;
        }

        double value = 0.0;
        if (!valiValue(inputValue, value, 0)) {
            std::cerr << "Error: bad value => " << inputValue << std::endl;
            continue;
        }

        try {
            std::map<std::string, double>::const_iterator it = _database.lower_bound(inputDate);
            double rate = 0.0;
            if (it != _database.end() && it->first == inputDate) {
                rate = it->second;
            } else {
                if (it == _database.begin()) {
                    std::cerr << "Error: no earlier rate for date " << inputDate << std::endl;
                    continue;
                }
                --it;
                rate = it->second;
            }

            const double result = value * rate;
            std::cout << inputDate << " => " << value << " = "
                      << result << std::endl;
        } catch (...) {
            std::cerr << "Error: unexpected lookup failure for " << inputDate << std::endl;
            continue;
        }
    }
}