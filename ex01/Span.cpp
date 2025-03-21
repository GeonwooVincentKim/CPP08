/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:07:25 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:05:36 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// コンストラクタ: 最大サイズを指定して初期化
Span::Span(unsigned int n) : _max_size(n)
{
}

// コピーコンストラクタ
Span::Span(const Span& span)
{
    *this = span;
}

// デストラクタ
Span::~Span()
{
}

// 代入演算子オーバーロード
Span& Span::operator=(const Span& span)
{
    _max_size = span._max_size; // 最大サイズをコピー
    _v = span._v;               // コンテナをコピー
    return (*this);
}

// 1つの数値を追加
void Span::addNumber(int num)
{
    if (_v.size() >= _max_size) // コンテナが満杯の場合
        throw FullContainerException();
    _v.push_back(num);          // 数値を追加
}

// 範囲で数値を追加
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    // 範囲の要素数が最大サイズを超える場合
    if (_v.size() + std::distance(begin, end) > _max_size)
        throw FullContainerException();
    _v.insert(_v.end(), begin, end); // 範囲を挿入
}

// 最小スパンを計算
int Span::shortestSpan()
{
    if (_v.size() < 2) // 要素が2つ未満の場合
        throw NotEnoughNumbersException();

    // コンテナを一時的にコピーしてソート
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());

    // 最小スパンを計算
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 2; i < tmp.size(); i++)
    {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return (min);
}

// 最大スパンを計算
int Span::longestSpan()
{
    if (_v.size() < 2) // 要素が2つ未満の場合
        throw NotEnoughNumbersException();

    // コンテナを一時的にコピーしてソート
    std::vector<int> tmp = _v;
    std::sort(tmp.begin(), tmp.end());

    // 最大スパンを計算
    return (tmp[tmp.size() - 1] - tmp[0]);
}

// FullContainerExceptionのエラーメッセージ
const char* Span::FullContainerException::what() const throw()
{
    return ("Container is full");
}

// NotEnoughNumbersExceptionのエラーメッセージ
const char* Span::NotEnoughNumbersException::what() const throw()
{
    return ("Not enough numbers");
}
