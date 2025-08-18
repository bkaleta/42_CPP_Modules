/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:41:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/18 23:26:29 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
    data.counter = 7;
    data.joke = "example";

	std::cout << "D Value: " << &data << "\n";
    Data* original = &data;
	std::cout << "Original Value: " << original << "\n";
	
    uintptr_t raw = Serializer::serialize(original);
	std::cout << "Raw: " << raw << "\n";
    Data* again = Serializer::deserialize(raw);
	std::cout << "Again value: " << again << "\n";

    if (again == original) {
        std::cout << "OK: round-trip dziala\n";
        std::cout << "id=" << again->counter
                  << ", name=" << again->joke << std::endl;
    } else {
        std::cout << "ERR: wskazniki sie roznia\n";
    }
    return 0;

	// Data data;
	// Data* pData;
	// uintptr_t raw;
	// Data* pReinterpretedData;
	
	
	// data.joke = "Michau... hau hau";
	// data.counter = 7;
	// pData = NULL;
	// pReinterpretedData = NULL;
	// pReinterpretedData = &data;
	// raw = 0;
	
	// std::cout << "Data struct string: " << data.joke << '\n';
	// std::cout << "Data struct int: " << data.counter << "\n\n";

	// std::cout << "Data Pointer address before Serializer: " << &pData << '\n';
	// std::cout << "Data Pointer value: " << pData << "\n\n";

	// std::cout << "Data Pointer address after Serializer: " << &pReinterpretedData << '\n';
	// std::cout << "Data Pointer value: " << pReinterpretedData << "\n\n";
	
	// std::cout << "uintptr_t raw: " << raw << "\n\n";
	
	// raw = Serializer::serialize(pData);
	
	// std::cout << "uintptr_t raw: " << raw << "\n\n";
	// pReinterpretedData = Serializer::deserialize(raw);
	// std::cout << "Data Pointer address after Serializer: " << &pReinterpretedData << '\n';
	
	// return (0);
}