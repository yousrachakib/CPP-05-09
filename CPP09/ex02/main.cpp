/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:22:12 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/12 17:14:10 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe obj;
	std::string input = av[1];
	if (ac != 2)
	{
		std::cerr << "bad input :" << av[0] << " <string of numbers>" << std::endl;
		return (1);
	}
	obj.Parse_input(input);
	obj.Ford_Johnson();
	
}