/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:50:20 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:17:19 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// デフォルトコンストラクタ
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
}

// コピーコンストラクタ
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& stack) : std::stack<T>(stack)
{
}

// 代入演算子オーバーロード
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& stack)
{
    if (this == &stack) // 自己代入チェック
        std::stack<T>::operator=(stack);
    return (*this);
}

// デストラクタ
template <typename T>
MutantStack<T>::~MutantStack()
{
}

// イテレータを返すメソッド
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}
