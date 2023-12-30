/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:07:18 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/30 19:20:22 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat A;
	Form B("me", 12, 34);

	A.signForm(B);
	std::cout << B << std::endl;
}