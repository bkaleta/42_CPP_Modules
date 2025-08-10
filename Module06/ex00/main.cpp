/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:51:55 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/10 17:21:55 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **argv)
{
	if (ac == 2)
		ScalarConverter::convert(argv[1]);
	else	
		std::cout << "Gosciu uzyj normalnie ./ScalarConverter <tutaj dawaj stringa>" << std::endl;

	// std::string literka = "'a'";
	// std::string cyferka = "-124";
	// std::string floacik = "4.2f";
	// std::string doubelek = "4.2";
	
	return (0);
}