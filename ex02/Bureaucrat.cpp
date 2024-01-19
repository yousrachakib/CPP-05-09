/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:47:18 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/19 16:00:56 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string input, int grade) : name(input)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}
Bureaucrat::~Bureaucrat()
{
    
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name) , grade(copy.grade)
{
    *this = copy;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return (*this);
}
int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}

void    Bureaucrat::decrementGrade()
{
    this->grade += 1;
    if (this->grade > 150)
        throw GradeTooLowException();
}
void    Bureaucrat::incrementGrade()
{
    this->grade -= 1;
    if (this->grade < 1)
        throw GradeTooHighException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too Low!";
}

void	Bureaucrat::signForm(AForm& obj)
{
	try
	{
		obj.beSigned(*this);
		std::cout << *this << " signed " << obj << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " couldn’t sign " << obj << " because " << this->getGrade() << " > " << obj.get_gradetosign() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		std::cout << this->getName() << " executed " << form.get_name() << std::endl;
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
