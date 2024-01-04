/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:10:11 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/04 19:18:19 by yochakib         ###   ########.fr       */
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
    int i = 0;
    std::string Formtype [] = {"Presidential Creation", "Robotomy Creation", "Shrubbery Creation"};
    AForm *(*Internwork[])(std::string&) = { makePresidential , makeRobotomy, makeShrubbery};
    
    for (int i = 0; i < 3 ; i++ )
    {
        if (name == Formtype[i])
            Internwork[i](target);
    }
    return NULL;
}
