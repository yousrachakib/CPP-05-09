/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:00:22 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/05 00:01:41 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);
	myvector.push_back(40);
	myvector.push_back(50);
	myvector.push_back(60);
	myvector.push_back(70);

	try
	{
		int value_tofind = 100;
		std::vector<int>::iterator it1 = easyfind(myvector, value_tofind);
		std::cout << "value to find : " << value_tofind <<" was found at position : " << \
		std::distance(myvector.begin(), it1) << " inside myvector of int" << std::endl; 
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << "exception caught ===>" << e.what() << '\n';
	}
	
}