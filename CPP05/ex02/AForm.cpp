/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:09:41 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/02 16:21:28 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default") , grade_tosign(150) , grade_execute(150)
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

AForm::AForm(const std::string input, const int sign, const int execute) : name(input) , grade_tosign(sign), grade_execute(execute)
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

AForm::AForm(const AForm& copy) : name(copy.name) , is_signed(copy.is_signed) , grade_tosign(copy.grade_tosign) , grade_execute(copy.grade_execute)
{
    *this = copy;
}

AForm::~AForm()
{
    
}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm grade too low!";
}
const std::string AForm::get_name() const
{
    return (this->name);
}

bool AForm::get_issigned() const
{
    return (this->is_signed);
}

int   AForm::get_gradetosign() const
{
    return (this->grade_tosign);
}

int   AForm::get_grade_execute() const
{
    return (this->grade_execute);
}

std::ostream& operator<<(std::ostream& os,const AForm& obj)
{
    os << "AForm name: " << obj.get_name() << "|AForm grade to sign : " << obj.get_gradetosign() << "|AForm grade to execute : " << obj.get_grade_execute() << "|is AForm signed  : " << obj.get_issigned()  << std::endl;
	return os;
}

void  AForm::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > this->grade_tosign)
		throw GradeTooLowException();
	this->is_signed = true;
}