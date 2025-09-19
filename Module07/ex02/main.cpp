/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:06:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 21:30:07 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
#include <ctime>
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<std::string> michal(5);
    michal[1] = "czesc";

    try {
    for (int i = 0; i < michal.size(); i++)
        std::cout << michal[i] << std::endl;
    } catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Array<unsigned int> michal2(42);

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
        for (int i = 0; i < numbers.size(); i++)
            std::cout << numbers[i] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }

    delete [] mirror;

    // TEEEEEEEEEEEEEEEEEEEEEEEEESSSSSSSSSSSSSSSSSTTTTTTTTTTTTYYYYYYYYYYYYYYYYYY

     try {
        std::cout << "== Test 1: konstruktor domyślny + OOB read ==\n";
        Array<int> a0;
        std::cout << "size(a0) = " << a0.size() << '\n';
        try {
            (void)a0[0]; // powinien rzucić
            std::cout << "ERROR: brak wyjątku dla OOB read na pustej tablicy!\n";
        } catch (const std::exception& e) {
            std::cout << "OK (OOB read): " << e.what() << '\n';
        }

        std::cout << "\n== Test 2: konstruktor z rozmiarem + domyślna inicjalizacja ==\n";
        Array<int> a1(5);
        std::cout << " (size=" << a1.size() << "): ";
        for (int i = 0; i < a1.size(); ++i) {
            if (i) std::cout << ' ';
        std::cout << a1[static_cast<unsigned>(i)];
    }
        std::cout << '\n';             // powinno wypisać 0 0 0 0 0 (dla int)
        a1[0] = 10; a1[4] = 50;
        std::cout << " (size=" << a1.size() << "): ";
        for (int i = 0; i < a1.size(); ++i) {
            if (i) std::cout << ' ';
        std::cout << a1[static_cast<unsigned>(i)];

        std::cout << "\n== Test 3: konstruktor kopiujący (głęboka kopia) ==\n";
        Array<int> a2(a1);                 // kopia a1
        a2[0] = 999;                       // zmień kopię
        std::cout << "a1[0] = " << a1[0] << " (oczekiwane 10), "
                  << "a2[0] = " << a2[0] << " (oczekiwane 999)\n";

        std::cout << "\n== Test 4: operator= (różne rozmiary) + samo-przypisanie ==\n";
        Array<std::string> s1(3);
        s1[0] = "foo"; s1[1] = "bar"; s1[2] = "baz";
        Array<std::string> s2;             // pusty
        s2 = s1;                           // przypisanie
        std::cout << "s1[1] = " << s1[1] << ", s2[1] = " << s2[1] << '\n';
        s2[1] = "qux";
        std::cout << "po zmianie s2[1]: s1[1] = " << s1[1]
                  << " (bez zmian), s2[1] = " << s2[1] << '\n';
        s2 = s2;                           // samo-przypisanie (powinno być no-op)

        std::cout << "\n== Test 5: OOB write ==\n";
        try {
            s1[3] = "oops";                // indeks == size() → wyjątek
            std::cout << "ERROR: brak wyjątku dla OOB write!\n";
        } catch (const std::exception& e) {
            std::cout << "OK (OOB write): " << e.what() << '\n';
        }

        std::cout << "\n== Test 6: kopiowanie/przypisanie pustych tablic ==\n";
        Array<int> e1;                     // pusty
        Array<int> e2(e1);                 // kopia pustego
        Array<int> e3(2); e3 = e1;         // przypisanie pustego do niepustego
        std::cout << "size(e2) = " << e2.size() << " (0), size(e3) = " << e3.size() << " (0)\n";

        std::cout << "\nWszystkie testy zakończone. Jeśli nie widzisz ERROR powyżej – jest OK.\n";
    }
    } catch (...) {
        std::cerr << "NIEZŁAPANY nieznany wyjątek w main.\n";
        return 1;
    }
    return 0;
}