/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:45:09 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/21 22:55:44 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	std::cout << "====================\n";
	std::cout << "Test MutantStack\n";
	std::cout << "====================\n";

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

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
	std::stack<int> s(mstack); // Copy constructor

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
