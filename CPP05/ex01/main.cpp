/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:07:18 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/16 15:27:39 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


int main()
{
	try
	{
    	Bureaucrat A("hello", 13);
		Form B("hiiiii", 12, 34);
		A.signForm(B);
		B.beSigned(A);
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}