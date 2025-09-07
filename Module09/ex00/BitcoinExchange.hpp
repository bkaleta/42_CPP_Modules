#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <ctime>
# include <cstdlib>

class BitcoinExchange
{
private:
	std::map<std::string, double> _database;
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &other);
	BitcoinExchange &operator=(BitcoinExchange const &other);
	~BitcoinExchange();

	void readDB();
	void performExchange(const char *fileName);
	bool valiDate(const std::string &date);
	// valuedate
	// printExchange
};

void programStart(int ac, char *av);


#endif