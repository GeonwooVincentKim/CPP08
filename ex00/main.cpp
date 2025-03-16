/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonwkim <geonwkim@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 16:08:11 by geonwkim          #+#    #+#             */
/*   Updated: 2025/03/13 16:08:11 by geonwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
  try {
      std::vector<int> vec = {1, 2, 3, 4, 5};
      std::cout << "Found in vector: " << *easyfind(vec, 3) << std::endl;

      std::list<int> lst = {10, 20, 30, 40, 50};
      std::cout << "Found in list: " << *easyfind(lst, 30) << std::endl;

      std::cout << "Trying to find a missing value..." << std::endl;
      easyfind(vec, 100); // 存在しない値を検索（例外発生）

  } catch (const std::exception& e) {
      std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}