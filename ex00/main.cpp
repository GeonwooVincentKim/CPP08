/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:38:00 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:03:12 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    // ====================
    // Vector Test
    // ====================
    std::cout << "====================\n";
    std::cout << "Vector Test\n";
    std::cout << "====================\n";

    std::vector<int> v;

    // 0から9までの値をvectorに追加
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    try
    {
        // 値5を検索（存在する）
        std::cout << "Num: " << *easyfind(v, 5) << std::endl;

        // 値10を検索（存在しない）
        std::cout << "Num: " << *easyfind(v, 10) << std::endl;
    }
    catch(const std::exception& e)
    {
        // 例外が発生した場合、エラーメッセージを出力
        std::cerr << e.what() << '\n';
    }
    
    // ====================
    // List Test
    // ====================
    std::cout << "\n====================\n";
    std::cout << "List Test\n";
    std::cout << "====================\n";

    std::list<int> l;

    // 0から19までの値をlistに追加
    for (int i = 0; i < 20; i++)
        l.push_back(i);

    try
    {
        // 値0を検索（存在する）
        std::cout << "Num: " << *easyfind(l, 0) << std::endl;

        // 値1000を検索（存在しない）
        std::cout << "Num: " << *easyfind(l, 1000) << std::endl;
    }
    catch(const std::exception& e)
    {
        // 例外が発生した場合、エラーメッセージを出力
        std::cerr << e.what() << '\n';
    }

    // ====================
    // Deque Test
    // ====================
    std::cout << "\n====================\n";
    std::cout << "Deque Test\n";
    std::cout << "====================\n";

    std::deque<int> d;

    // 0から699までの値をdequeに追加
    for (int i = 0; i < 700; i++)
        d.push_back(i);

    try
    {
        // 値645を検索（存在する）
        std::cout << "Num: " << *easyfind(d, 645) << std::endl;

        // 値750を検索（存在しない）
        std::cout << "Num: " << *easyfind(d, 750) << std::endl;
    }
    catch(const std::exception& e)
    {
        // 例外が発生した場合、エラーメッセージを出力
        std::cerr << e.what() << '\n';
    }

	return (0);
}