/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:01:11 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:05:51 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <exception>

// Spanクラス
class Span
{
private:
    unsigned int _max_size;       // 最大サイズ（格納可能な要素数）
    std::vector<int> _v;          // 数値を格納するコンテナ

public:
    // コンストラクタ
    Span(unsigned int n);         // 最大サイズを指定して初期化
    Span(const Span& span);       // コピーコンストラクタ
    ~Span();                      // デストラクタ
    Span& operator=(const Span& span); // 代入演算子オーバーロード

    // メソッド
    void addNumber(int num);      // 1つの数値を追加
    int shortestSpan();           // 最小スパンを計算
    int longestSpan();            // 最大スパンを計算
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end); // 範囲で数値を追加

    // 例外クラス
    class FullContainerException : public std::exception
    {
    public:
        // コンテナが満杯の場合のエラーメッセージ
        virtual const char* what() const throw();
    };

    class NotEnoughNumbersException : public std::exception
    {
    public:
        // スパンを計算するのに十分な数値がない場合のエラーメッセージ
        virtual const char* what() const throw();
    };
};

#endif
