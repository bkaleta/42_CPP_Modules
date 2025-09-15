/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:55:42 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/15 22:21:23 by bkaleta          ###   ########.fr       */
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

void RPN::startProgram(int ac, const char* expression) {
	if (RPN::isArgumentCount(ac)) {
		try {
			RPN myRPN;
			myRPN.startRPN(std::string(expression));
		} catch (const char *error) {
			std::cerr << error << std::endl;
		}
	}
	else
		std::cout << "Error: example argument ./RPN  \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
}

bool RPN::isArgumentCount(int ac) {
	if (ac != 2) 
		return false;
	return true;
}

void RPN::startRPN(std::string expression) {
	if (expression.empty()) 
		throw "Error: empty string";
	if (hasTwoDigits(expression)) 
		throw "Error: has Two Digits";
	std::string noSpacesExpression = removeSpaces(expression);
	if (!isValidToken(noSpacesExpression))
		throw "Error: Invalid RPN expression";
	performRPN(noSpacesExpression);
	std::cout << this->myStack.top() << std::endl;
}

void RPN::performRPN(const std::string noSpacesExpression) {
	int result = 0;
	
	for (std::size_t i = 0; i < noSpacesExpression.size(); i++) {
		unsigned char c = static_cast<unsigned char>(noSpacesExpression[i]);
		if (std::isdigit(c)) {
			int num = noSpacesExpression[i] - '0';
			this->myStack.push(num);
		}
		else if (c == '+' || c == '-' || c == '/' || c == '*') {
			if (this->myStack.size() < 2)
				throw "Error: Not enough nums";
			int temp1 = this->myStack.top();
			this->myStack.pop();
			int temp2 = this->myStack.top();
			this->myStack.pop();
			result = calculate(temp1, temp2, c);
			this->myStack.push(result);
		}
		else 
			throw "Error";
	}
	if (myStack.size() != 1)
		throw "Error: wrong final stack value";
}

std::string RPN::removeSpaces(std::string expression) {
	std::string noSpacesExpression;
	for (std::size_t i = 0; i < expression.size(); i++) {
		if (!std::isspace(expression[i]))
			noSpacesExpression += expression[i];
	}
	return noSpacesExpression;
}	


bool RPN::isValidToken(std::string noSpacesExpression) {
	for (unsigned int i = 0; i < noSpacesExpression.size(); i++) {
		unsigned char sign = static_cast<unsigned char>(noSpacesExpression[i]);
		if (!std::isdigit(noSpacesExpression[i]) && sign != '+' 
			&& sign != '-' && sign != '/' && sign != '*')
					throw "Error: invalid operator";
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
				throw "Error: Not enough nums";
			stackCount--;
		}
		else
			return false;
	}
	if (!operatorDetected)
		throw "Error: No Operator Detected";
	if (stackCount != 1)
		throw "Error: wrong final stack value";
	return true;
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
			if (temp1 == 0) 
				throw "Error: division by zero";
			return (temp2 / temp1);
		default:
			throw "Error: bad operator";
	}
}