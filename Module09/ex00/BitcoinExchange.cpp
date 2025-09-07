/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:34:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/07 17:56:28 by bkaleta          ###   ########.fr       */
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
		if (!valiValue)
			throw "Exception: Wrong Value";
		double value std::atof(strValue.cstr());
		_database[date] = value;
	}
}

bool BitcoinExchange::valiDate(const std::string &date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    std::tm timeinfo = {};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon  = month - 1;
    timeinfo.tm_mday = day;

    if (mktime(&timeinfo) == -1)
        return false;

    if (timeinfo.tm_year != year - 1900 ||
        timeinfo.tm_mon  != month - 1   ||
        timeinfo.tm_mday != day)
        return false;

    return true;
}