/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:56:25 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/20 18:20:59 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

void testVectorContainer()
{
	std::cout << "====================\n";
    std::cout << "Test vector container\n";
	std::cout << "====================\n";
    Span sp(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        sp.addNumber(11); // Exceeding capacity
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void testVectorRange()
{
	std::cout << "====================\n";
    std::cout << "Test vector range\n";
	std::cout << "====================\n";
    Span sp(100);
    std::vector<int> v;

    for (int i = 0; i < 100; ++i) {
        v.push_back(rand() % 1000000); // Random numbers in range [0, 999999]
    }

    try {
        sp.addNumber(v.begin(), v.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void testLargeVectorRange()
{
	std::cout << "====================\n";
    std::cout << "Test vector large range\n";
	std::cout << "====================\n";
    Span sp(100000);
    std::vector<int> v;

    for (int i = 0; i < 100000; ++i) {
        v.push_back(rand() % 1000000000); // Random numbers in range [0, 999999999]
    }

    try {
        sp.addNumber(v.begin(), v.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    // Initialize random seed once
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    testVectorContainer();
	std::cout << std::endl;
    testVectorRange();
	std::cout << std::endl;
    testLargeVectorRange();

    return 0;
}
