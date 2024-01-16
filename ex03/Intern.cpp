/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:10:11 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/16 15:31:14 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& copy)
{
    *this = copy;
}
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}

AForm *makePresidential(std::string&  target)
{
    return (new PresidentialPardonForm(target));
}
AForm *makeRobotomy(std::string&  target)
{
    return (new RobotomyRequestForm(target));
}
AForm *makeShrubbery(std::string&  target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string& name, std::string&  target)
{
    std::string Formtype [] = {"Presidential Creation", "Robotomy Creation", "Shrubbery Creation"};
    
    AForm*  (*Internwork[])(std::string&  target) = { makePresidential , makeRobotomy, makeShrubbery};
    
    for (int i = 0; i < 3 ; i++ )
    {
        if (name == Formtype[i])
        {
            std::cout << "Intern creates  " << name << std::endl;
            return Internwork[i](target);
        }
    }
    std::cout << "Intern couldn't create  " << name << std::endl;
    return NULL;
}
