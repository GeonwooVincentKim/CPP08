/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 18:07:25 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/21 23:59:49 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _max_size(n)
{
}

Span::Span(const Span& span)
{
	*this = span;
}

Span::~Span()
{
}

Span& Span::operator=(const Span& span)
{
	_max_size = span._max_size;
	_v = span._v;
	return (*this);
}

void Span::addNumber(int num)
{
	if (_v.size() >= _max_size)
		throw FullContainerException();
	_v.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _max_size)
		throw FullContainerException();
	_v.insert(_v.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (unsigned int i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

const char* Span::FullContainerException::what() const throw()
{
	return ("Container is full");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers");
}
