/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:31:30 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/13 15:31:30 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <iostream>

// 例外クラス定義
class ValueNotFoundException: public std::exception {
public:
  virtual const char* what() const throw() {
    return "Value not found in container";
  }
};

template <typename T>
typename T::iterator easyfind(T& container, int value) {
  typename T::iterator it = std::find(container.begin(), container.end(), value);
  if (it == container.end())
    throw ValueNotFoundException();
  return it;
}

#endif
