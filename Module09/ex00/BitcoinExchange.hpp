#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <ctime>
# include <cstdlib>
# include <cctype>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange &operator=(BitcoinExchange const &other);
	~BitcoinExchange();

	void readDB();
	void performExchange(const char *fileName);
	bool valiDate(const std::string &date);
	bool valiDateForm(const std::string &date);
	bool valiValue(const std::string &strValue, double &value, bool db);
	bool validNumber(const std::string &strValue);
private:
	std::map<std::string, double> _database;
};

void programStart(int ac, char *av);


#endif