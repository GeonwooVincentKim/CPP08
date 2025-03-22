/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:07:25 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 19:48:13 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <limits>

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
    _v.insert(std::lower_bound(_v.begin(), _v.end(), num), num); // 二分探索で挿入
    // _v.push_back(num);          // 数値を追加
}

// 範囲で数値を追加
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    // 範囲の要素数が最大サイズを超える場合
    if (_v.size() + std::distance(begin, end) > _max_size)
        throw FullContainerException();
    for ()
    _v.insert(std::lower_bound(_v.begin(), _v.end(), *it), *it);
}

// 最小スパンを計算
int Span::shortestSpan() const
{
    std::vector<int>::const_iterator it1 = _v.begin(); 
    if (it1 == _v.end())
        throw NotEnoughNumbersException();
    std::vector<int>::const_iterator it2 = it1++;
    if (it2 == _v.end())
        throw NotEnoughNumbersException(); 
    int res = std::numeric_limits<int>::max();
    while (it1 != _v.end()){
        res = std::min(res, *it1 -*it2);
        ++it1,;
    }
    return (res);
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
