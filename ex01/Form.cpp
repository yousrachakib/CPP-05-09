/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:09:41 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/30 19:18:11 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default") , grade_tosign(150) , grade_execute(150)
{
    if (this->grade_tosign < 1)
        throw GradeTooHighException();
    if (this->grade_tosign > 150)
        throw GradeTooLowException();
    if (this->grade_execute < 1)
        throw GradeTooHighException();
    if (this->grade_execute > 150)
        throw GradeTooLowException();
	this->is_signed = false;
}

Form::Form(const std::string input, const int sign, const int execute) : name(input) , grade_tosign(sign), grade_execute(execute)
{
    if (this->grade_tosign < 1)
        throw GradeTooHighException();
    if (this->grade_tosign > 150)
        throw GradeTooLowException();
    if (this->grade_execute < 1)
        throw GradeTooHighException();
    if (this->grade_execute > 150)
        throw GradeTooLowException();
	this->is_signed = false;
}

Form::Form(const Form& copy) : name(copy.name) , is_signed(copy.is_signed) , grade_tosign(copy.grade_tosign) , grade_execute(copy.grade_execute)
{
    *this = copy;
}

Form::~Form()
{
    
}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}
const std::string Form::get_name() const
{
    return (this->name);
}

bool Form::get_issigned() const
{
    return (this->is_signed);
}

int   Form::get_gradetosign() const
{
    return (this->grade_tosign);
}

int   Form::get_grade_execute() const
{
    return (this->grade_execute);
}

std::ostream& operator<<(std::ostream& os,const Form& obj)
{
    os << "Form name: " << obj.get_name() << "|Form grade to sign : " << obj.get_gradetosign() << "|Form grade to execute : " << obj.get_grade_execute() << "|is Form signed  : " << obj.get_issigned()  << std::endl;
	return os;
}

void  Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() >= this->grade_tosign)
		throw GradeTooLowException();
	this->is_signed = true;
}