/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:22:12 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/14 13:30:38 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "bad input :" << av[0] << " <string of numbers>" << std::endl;
		return (1);
	}
	
	std::string str;
	for (int i = 1; i < ac; i++)
	{
		str += av[i];
		if (i < ac - 1)
			str += " ";
	}
	PmergeMe obj;
	std::string input = str;
	try
	{
		obj.Parse_input(input);
		obj.Ford_Johnson_dq();
		obj.Ford_Johnson_vec();
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
}