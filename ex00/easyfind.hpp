/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:37:00 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 19:27:58 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm> // std::findを使用するために必要
# include <iostream> // 標準入出力用

// カスタム例外クラス
class NotFoundException : public std::exception
{
public:
	// 例外が発生した際に返すエラーメッセージ
	virtual const char* what() const throw()
	{
		return ("Number not found");
	}
};

// テンプレート関数 easyfind
// 任意のSTLコンテナ内で指定された値を検索する
/*
非constのコンテナを引数に取るため、
constのイテレータを返してしまうので。
利用できる幅が狭まる。
そもそも、見つからなかったときにthrowしているので
リファレンスをそのまま返すことが保証できるので。
そうするといい
イテレータはT::end()で無効な値を表現可能なのでイテレータで返すならthrowする必要はない(完全にstd::findと同じになる)

*/
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    return std::find(container.begin(), container.end(), value);
}

template <typename T>
typename T::const_iterator easyfind(T const & container, int value)
{
    return std::find(container.begin(), container.end(), value);
}

template <typename T>
typename T::reference easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return *it;
}

template <typename T>
typename T::const_reference easyfind(T const & container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return *it;
}


#endif
