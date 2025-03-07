/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:03:45 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/07 13:00:39 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myReplace.hpp"

// Default Constructor
myReplace::myReplace() {}

// Constructor
myReplace::myReplace(std::string input, std::string find, std::string replace)
	: inputFile(input), s1(find), s2(replace) {}
	
// Destructor
myReplace::~myReplace() {}

// Setters
void	myReplace::setter(char *av1, char *av2, char *av3)
{
	inputFile = av1;
	s1 = av2;
	s2 = av3;
}
// Getters
std::string myReplace::get_input_file() const
{
	return (inputFile);
}

std::string myReplace::get_s1() const
{
	return (s1);
}

std::string myReplace::get_s2() const
{
	return (s2);
}
// Validation
void myReplace::valid_input(int ac)
{
	if (ac != 4)
	{
		std::cout << "Proper input: ./program file string1 string2\n";
		exit(1);
	}
}

void	myReplace::my_replace()
{
	std::string		content;
	std::string		line;
	size_t			i;
	size_t 			lastNewline;
	
	std::ifstream inFile(this->inputFile);
	if (!inFile)
	{
		std::cerr << "Error: Unable to open file " << this->inputFile << std::endl;
		exit(1);
	}
	std::ofstream outFile(this->inputFile + ".replace");
	if (!outFile)
	{
		std::cerr << "Error: Unable to create file " << this->inputFile + ".replace" << std::endl;
		inFile.close();
		exit(1);
	}
	
	while (std::getline(inFile, line))
		content += line + '\n';
	inFile.close();
	std::cout << content << std::endl;
	i = 0;
	while ((i = content.find(this->s1, i)) != std::string::npos)
	{
		content.erase(i, this->s1.length());
		content.insert(i, this->s2);
		i += this->s2.length();
	}
	lastNewline = content.find_last_of('\n');
	if (lastNewline != std::string::npos)
    	content.erase(lastNewline);
	
	outFile << content;
	outFile.close();

	std::cout << "Operation completed: " << this->inputFile + ".replace" << " Created" << std::endl;
}
