/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:45:29 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:16:21 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack> // std::stackを使用
# include <iostream> // 標準入出力用

// MutantStackクラス
// std::stackを基にしたクラスで、イテレータを追加
template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // コンストラクタ
    MutantStack();
    MutantStack(const MutantStack& stack);
    MutantStack& operator=(const MutantStack& stack);
    ~MutantStack();

    // イテレータ型の定義
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // イテレータを返すメソッド
    iterator begin(); // 先頭イテレータ
    iterator end();   // 終端イテレータ

    const_iterator begin() const; // const版の先頭イテレータ
    const_iterator end() const;   // const版の終端イテレータ

    reverse_iterator rbegin(); // 逆方向の先頭イテレータ
    reverse_iterator rend();   // 逆方向の終端イテレータ

    const_reverse_iterator rbegin() const; // const版の逆方向先頭イテレータ
    const_reverse_iterator rend() const;   // const版の逆方向終端イテレータ
};

# include "MutantStack.tpp" // テンプレート実装をインクルード

#endif
