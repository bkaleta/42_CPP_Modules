/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:55:42 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/14 02:20:21 by bkaleta          ###   ########.fr       */
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

bool RPN::isArgumentCount(int ac) {
	if (ac != 2) {
		std::cout << "Error: exmaple argument ./RPN  \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		return false;
	}
	return true;
}

void RPN::startRPN(std::string expression) {
	if (expression.empty()) {
		std::cout << "Error: empty string" << std::endl;
		return ;
	}
	if (hasTwoDigits(expression)) {
		std::cout << "Error: has Two Digits" << std::endl;
		return ;
	}
	std::string noSpacesExpression = removeSpaces(expression);
	if (!isValidToken(noSpacesExpression)) {
		std::cout << "Error" << std::endl;
		return ;
	}
	
	int result = 0;
	
	for (std::size_t i = 0; i < noSpacesExpression.size(); i++) {
		unsigned char c = static_cast<unsigned char>(noSpacesExpression[i]);
		if (std::isdigit(c)) {
			int num = noSpacesExpression[i] - '0';
			this->myStack.push(num);
		}
		else if (c == '+' || c == '-' || c == '/' || c == '*') {
			if (this->myStack.size() < 2) {
				std::cout << "Error" << std::endl;
				exit(EXIT_FAILURE);
			}
			int temp1 = this->myStack.top();
			this->myStack.pop();
			int temp2 = this->myStack.top();
			this->myStack.pop();
			result = calculate(temp1, temp2, c);
			this->myStack.push(result);
		}
		else {
			std::cout << "Error" << std::endl;
            exit(EXIT_FAILURE);
		}
	}
	std::cout << this->myStack.top() << std::endl;
}

std::string RPN::removeSpaces(std::string expression) {
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


bool RPN::isValidToken(std::string noSpacesExpression) {
	if (noSpacesExpression.empty())
		return false;
	for (unsigned int i = 0; i < noSpacesExpression.size(); i++) {
		unsigned char sign = static_cast<unsigned char>(noSpacesExpression[i]);
		if (!std::isdigit(noSpacesExpression[i]) && sign != '+' 
			&& sign != '-' && sign != '/' && sign != '*')
					return false;
	}

	int stackCount = 0;
	bool operatorDetected = false;
	for (std::size_t i = 0; i < noSpacesExpression.size(); i++) {
		unsigned char c = static_cast<unsigned char>(noSpacesExpression[i]);
		if (std::isdigit(c))
			stackCount++;
		else if (c == '+' || c == '-' || c == '/' || c == '*') {
			operatorDetected = true;
			if (stackCount < 2)
				return false;
			stackCount--;
		}
		else
			return false;
	}
	return stackCount == 1 && operatorDetected;
}

bool RPN::hasTwoDigits(std::string expression) {
	if (expression.size() < 2)
		return false;
	for (std::size_t i = 1; i < expression.size(); ++i) {
        unsigned char temp1 = static_cast<unsigned char>(expression[i-1]);
        unsigned char temp2 = static_cast<unsigned char>(expression[i]);
		if (std::isdigit(temp1) && std::isdigit(temp2))
			return true;
    }
    return false;
}
	
int RPN::calculate(int temp1, int temp2, unsigned char sign) {
	switch (sign) {
		case '+': return (temp2 + temp1);
		case '-': return (temp2 - temp1);
		case '*': return (temp2 * temp1);
		case '/':
			if (temp1 == 0) { 
				std::cout << "Error: division by zero" << std::endl; 
				std::exit(EXIT_FAILURE); 
			}
			return (temp2 / temp1);
		default:
			std::cout << "Error: bad operator" << std::endl; 
			std::exit(EXIT_FAILURE);
	}
}