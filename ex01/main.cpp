/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:56:25 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:05:20 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib> // std::rand, std::srand
#include <ctime>   // std::time

// 小さなコンテナのテスト
void testVectorContainer()
{
    std::cout << "====================\n";
    std::cout << "Test vector container\n";
    std::cout << "====================\n";

    Span sp(5); // 最大5つの要素を持つSpanを作成
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    try {
        sp.addNumber(11); // 容量を超えて追加しようとする
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl; // エラーメッセージを出力
    }

    try {
        // 最小スパンと最大スパンを計算
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl; // エラーメッセージを出力
    }
}

// 範囲で数値を追加するテスト
void testVectorRange()
{
    std::cout << "====================\n";
    std::cout << "Test vector range\n";
    std::cout << "====================\n";

    Span sp(100); // 最大100個の要素を持つSpanを作成
    std::vector<int> v;

    // ランダムな数値を生成してベクターに追加
    for (int i = 0; i < 100; ++i) {
        v.push_back(rand() % 1000000); // [0, 999999]の範囲
    }

    try {
        sp.addNumber(v.begin(), v.end()); // 範囲で追加
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl; // エラーメッセージを出力
    }
}

// 大規模なコンテナのテスト
void testLargeVectorRange()
{
    std::cout << "====================\n";
    std::cout << "Test vector large range\n";
    std::cout << "====================\n";

    Span sp(100000); // 最大100,000個の要素を持つSpanを作成
    std::vector<int> v;

    // ランダムな数値を生成してベクターに追加
    for (int i = 0; i < 100000; ++i) {
        v.push_back(rand() % 1000000000); // [0, 999999999]の範囲
    }

    try {
        sp.addNumber(v.begin(), v.end()); // 範囲で追加
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl; // エラーメッセージを出力
    }
}

int main()
{
    // ランダムシードを初期化
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    testVectorContainer(); // 小さなコンテナのテスト
    std::cout << std::endl;
    testVectorRange();     // 範囲で追加するテスト
    std::cout << std::endl;
    testLargeVectorRange();// 大規模なコンテナのテスト

    return 0;
}
