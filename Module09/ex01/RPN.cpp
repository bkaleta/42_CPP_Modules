/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:55:42 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/13 22:06:28 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &other) {
	if (this != &other)
		*this = other;
}

RPN &RPN::operator=(RPN const &other) {
	if (this != &other)
		this->myStack = other.myStack;
	return (*this);
}

RPN::~RPN() {}

bool isArgumentCount(int ac) {
	if (ac != 2) {
		std::cout << "Error: exmaple argument ./RPN  \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return false;
	}
	return true;
}

void startRPN(std::string expression) {
	// "8 9 *| 9 - 9 - 9 - 4 - 1 +"
	RPN myRPN;
	std::string noSpacesExpression = removeSpaces(expression);
	// if (!isValidToken(noSpacesExpression)) {
	// 	std::cout << "Error" << std::endl;
	// 	return ;
	// }
	size_t i = 0;
	while (i < noSpacesExpression.size()) {
			
		std::cout << noSpacesExpression[i];
		i++;
	}
	std::cout << std::endl;
}

std::string removeSpaces(std::string expression) {
	if (expression.empty()) {
		std::cout << "Error" << std::endl;
		return NULL;
	}
	std::string noSpacesExpression;
	size_t i = 0;
	while (i < expression.size()) {
		if (!isspace(expression[i]))
			noSpacesExpression += expression[i];
		i++;
	}
	return noSpacesExpression;
}


bool isValidToken(std::string noSpacesExpression) {
	if (noSpacesExpression.empty())
		return false;
	std::cout << noSpacesExpression << std::endl;
	for (unsigned int i = 0; i < noSpacesExpression.size(); i++) {
		unsigned char sign = static_cast<unsigned char>(noSpacesExpression[i]);
		if (!std::isdigit(noSpacesExpression[i]) && sign != '+' 
			&& sign != '-' && sign != '/' && sign != '*')
					return false;
	}
	return true;
}