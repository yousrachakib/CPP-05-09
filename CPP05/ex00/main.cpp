/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:04:23 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/15 14:04:31 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A("test", 13);
        std::cout << A << std::endl;
        Bureaucrat B;
        std::cout << B << std::endl;
        A = B;
        std::cout << A << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}