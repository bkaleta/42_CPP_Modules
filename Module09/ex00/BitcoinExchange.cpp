/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:34:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/07 21:24:46 by bkaleta          ###   ########.fr       */
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
	(void)av;
	if (ac == 2) {
		try {
			BitcoinExchange broker;
			//broker.performExchange(av);
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
		// 	if (value < 1 || value > 1000)
		// 		continue;
		// 	throw "Exception: Wrong Value";
		// }
		// std::cout << date << " | " << value << std::endl;
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
	bool dbFlag = db;
	if (!validNumber(strValue))
		return false;

	char *endptr = 0;
    double val = std::strtod(strValue.c_str(), &endptr);

    if (endptr == strValue.c_str() || *endptr != '\0') {
        return false;
	}

	if (!dbFlag) {
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