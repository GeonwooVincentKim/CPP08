/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:37:00 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:02:18 by geonwkim         ###   ########.fr       */
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
template <typename T>
typename T::const_iterator easyfind(T& container, int value)
{
    // イテレータ型を取得
	typename T::iterator it;

	// std::findを使用して値を検索
	it = std::find(container.begin(), container.end(), value);

    // 値が見つからない場合は例外をスロー
	if (it == container.end())
		throw NotFoundException();
	// 見つかったイテレータを返す
	return (it);
}

#endif
