/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:01:11 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/21 23:59:44 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iostream>
# include <exception>

class Span
{
private:
	unsigned int _max_size;       // 最大サイズ
    std::vector<int> _v;    // 数値を格納するコンテナ

public:
	Span(unsigned int n);
	Span(const Span& span);
	~Span();
	Span& operator=(const Span& span);

	// Methods
	void addNumber(int num); // 1つの数値を追加
	int shortestSpan(); // 最小スパンを計算
	int longestSpan(); // 最大スパンを計算
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end); // 範囲で数値を追加

	// Exceptions
	class FullContainerException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
};

#endif
