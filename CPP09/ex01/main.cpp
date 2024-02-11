/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:49:42 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/11 20:16:01 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error : bad input! " << std::endl;
		return (1);
	}
	try
	{
		std::string	input = av[1];
		int result = evaluate_RPN(input);
		std::cout << result << std::endl;
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}