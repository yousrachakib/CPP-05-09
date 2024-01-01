/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:07:18 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/01 20:05:45 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


int main()
{
	try
	{
    	Bureaucrat A("hello", 13);
		// Bureaucrat X(A);
		Form B("hiiiii", 12, 34);
		Form C(B);
		// std::cout << X << std::endl;
		// std::cout << C << std::endl;
		// C.beSigned(A);
		A.signForm(C);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}