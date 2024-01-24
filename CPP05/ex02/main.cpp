/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:25 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/21 20:33:35 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat A("mimi", 1);
		ShrubberyCreationForm B("test");
		RobotomyRequestForm C("zaz");
		PresidentialPardonForm D("soso");
		std::cout << "--------------------------------" << std::endl;
		C.beSigned(A);
		A.signForm(C);
		// C.execute(A);
		A.executeForm(C);
		// std::cout << C << std::endl;
		// std::cout << "--------------------------------" << std::endl;
		// B.beSigned(A);
		// B.execute(A);
		// std::cout << B << std::endl;
		// D.beSigned(A);
		// D.execute(A);
		// std::cout << "--------------------------------" << std::endl;
		// std::cout << D << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}