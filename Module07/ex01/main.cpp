/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:06:15 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/24 23:45:02 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void power2(int &num) {
	num *= num;
}

void to_lower(std::string &str) {
	size_t i = 0;

	while (i < str.length()) {
		str[i] = std::tolower(str[i]);
		i++;
	}
}

template <typename T>
void ft_print(T &a) {
	std::cout << a << " ";
}

int main() {
	int int_arr[] = {1, 2, 3, 4, 5};
	int i = 0;

	::iter(int_arr, 5, power2);
	while (i < 5) {
		std::cout << int_arr[i] << std::endl;
		i++;
	}

	std::cout << std::endl;
	i = 0;

	std::string str_arr[] = {"PIZDA", "I", "CHUJ"};
	::iter(str_arr, 3, to_lower);
	while (i < 3) {
		std::cout << str_arr[i] << std::endl;
		i++;
	}

	int  num[] = {1,2,3};
	iter(num, 3, ft_print<int const>);
}