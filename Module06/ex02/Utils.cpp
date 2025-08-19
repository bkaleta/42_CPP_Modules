/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 22:59:29 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/19 23:46:11 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base *generate(void) {
	int random = rand() % 3;
	
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try { 
		(void)dynamic_cast<A&>(p); 
		std::cout << "A" << std::endl; 
		return ; 
	} catch (...) {}
    try { 
		(void)dynamic_cast<B&>(p); 
		std::cout << "B" << std::endl; 
		return ; 
	} catch (...) {}
    try { 
		(void)dynamic_cast<C&>(p); 
		std::cout << "C" << std::endl; 
		return ; 
	} 
		catch (...) {}
}

