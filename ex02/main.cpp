/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:45:09 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/22 00:17:32 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    // MutantStackのテスト
    std::cout << "====================\n";
    std::cout << "Test MutantStack\n";
    std::cout << "====================\n";

    MutantStack<int> mstack;

    // 要素を追加
    mstack.push(5);
    mstack.push(17);

    // スタックのトップ要素を表示
    std::cout << "Top: " << mstack.top() << std::endl;

    // トップ要素を削除
    mstack.pop();

    // スタックのサイズを表示
    std::cout << "Size: " << mstack.size() << std::endl;

    // 要素を追加
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // イテレータを使用して要素を走査
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << std::endl;

    // std::stackとの互換性を確認
    std::stack<int> s(mstack);

    // 逆方向イテレータを使用して要素を走査
    std::cout << "====================\n";
    std::cout << "Test MutantStack with std::stack\n";
    std::cout << "====================\n";

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    
    std::cout << "stack: ";
    while (rit != rite)
    {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    return (0);
}
