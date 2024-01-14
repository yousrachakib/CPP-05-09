/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:06:25 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/14 17:58:12 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat A("hii", 1);
		Intern *someRandomIntern = NULL;
		AForm* rrf;
		std::string name = "Shrubbery Creation";
		std::string target = "Bender";
		rrf = someRandomIntern->makeForm(name, target);
		rrf->beSigned(A);
		rrf->execute(A);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}