/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myReplace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:03:53 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/07 12:42:08 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOSER_HPP
# define LOSER_HPP

#include <iostream>
#include <string>
#include <fstream>

class myReplace
{
private:
	std::string	inputFile;
	std::string	s1;
	std::string	s2;
public:
	myReplace();
	myReplace(std::string input, std::string find, std::string replace);
	~myReplace();
	void		setter(char *av1, char *av2, char *av3);
	void		valid_input(int ac);
	void		my_replace();
	std::string get_input_file() const;
	std::string get_s1() const;
	std::string get_s2() const;
};

#endif