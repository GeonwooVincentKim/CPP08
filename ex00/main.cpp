/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:38:00 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/20 17:48:36 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
	std::cout << "====================\n";
    std::cout << "Vector Test\n";
    std::cout << "====================\n";
    std::vector<int> v;

    for (int i = 0; i < 10; i++)
        v.push_back(i);
    try
    {
        std::cout << "Num: " << *easyfind(v, 5) << std::endl;
        std::cout << "Num: " << *easyfind(v, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n====================\n";
    std::cout << "List Test\n";
    std::cout << "====================\n";
    std::list<int> l;

    for (int i = 0; i < 20; i++)
        l.push_back(i);
    try
    {
        std::cout << "Num: " << *easyfind(l, 0) << std::endl;
        std::cout << "Num: " << *easyfind(l, 1000) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n====================\n";
    std::cout << "Deque Test\n";
    std::cout << "====================\n";
    std::deque<int> d;

    for (int i = 0; i < 700; i++)
        d.push_back(i);
    try
    {
        std::cout << "Num: " << *easyfind(d, 645) << std::endl;
        std::cout << "Num: " << *easyfind(d, 750) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	return (0);
}