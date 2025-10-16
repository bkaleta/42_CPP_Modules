/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 20:30:54 by bkaleta           #+#    #+#             */
/*   Updated: 2025/10/16 22:30:09 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

int main() {
	std::list<int> values;
	
	values.push_back(1);
	values.push_back(2);
	values.push_back(7);
	values.push_back(4);
	// test list incorrect
	try {
		std::cout << "List test: ";
		std::list<int>::const_iterator it = easyfind(values, 3);
		std::cout << "Const iterator: " << *it << std::endl;
	} catch (std::out_of_range &warrning) {
		std::cerr << warrning.what() << std::endl;
	}
	// test list correct
	try {
		std::cout << "List test: ";
		std::list<int>::iterator it = easyfind(values, 4);
		std::cout << "Iterator: " << *it << std::endl;
	} catch (std::out_of_range &warrning) {
		std::cerr << warrning.what() << std::endl;
	}
	// test vector incorrect
	try {
		std::cout << "Vector test: ";
		std::vector<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(4);
		std::vector<int>::const_iterator it = easyfind(nums, 3);
		std::cout << "Const iterator: " << *it << std::endl;
	} catch (std::out_of_range &warrning) {
		std::cerr << warrning.what() << std::endl;
	}
	// test vector correct
	try {
		std::cout << "Vector test: ";
		std::vector<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(4);
		std::vector<int>::const_iterator it = easyfind(nums, 4);
		std::cout << "Const iterator: " << *it << std::endl;
	} catch (std::out_of_range &warrning) {
		std::cerr << warrning.what() << std::endl;
	}
	// test deque incorrect
	try {
		std::cout << "Deque test: ";
		std::deque<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(4);
		std::deque<int>::const_iterator it = easyfind(nums, 3);
		std::cout << "Const iterator: " << *it << std::endl;
	} catch (std::out_of_range &warrning) {
		std::cerr << warrning.what() << std::endl;
	}
	// test deque correct
	try {
		std::cout << "Deque test: ";
		std::deque<int> nums;
		nums.push_back(1);
		nums.push_back(2);
		nums.push_back(4);
		std::deque<int>::const_iterator it = easyfind(nums, 4);
		std::cout << "Const iterator: " << *it << std::endl;
	} catch (std::out_of_range &warrning) {
		std::cerr << warrning.what() << std::endl;
	}
}