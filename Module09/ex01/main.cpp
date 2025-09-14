/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 19:54:49 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/14 02:26:55 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av) {
	if (!RPN::isArgumentCount(ac))
		return 0;
	
	RPN myRPN;
	myRPN.startRPN(av[1]);
	if (DEBUG == 1) {
		myRPN.startRPN("7 7 * 7 -"); // 42
		myRPN.startRPN("1 2 * 2 / 2 * 2 4 - +"); // 0
		myRPN.startRPN("(1 + 1)"); // error
		myRPN.startRPN("7 7 * 7 -"); // 42
	}
	return 0;
}