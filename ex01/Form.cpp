/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:09:41 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/29 19:07:00 by yochakib         ###   ########.fr       */
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

Form::Form(const std::string input, bool is_signed, const int sign, const int execute) : name(name) , grade_tosign(sign), grade_execute(execute)
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

Form::Form(const Form& copy)
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

const char* Form::GradeTooHighException::what() throw()
{
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() throw()
{
    return "Form grade too low!";
}
const std::string Form::get_name()
{
    return (this->name);
}

const bool Form::get_issigned()
{
    return (this->is_signed);
}

const int   Form::get_gradetosign()
{
    return (this->grade_tosign);
}

const int   Form::get_grade_execute()
{
    return (this->grade_execute);
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
    std::cout << "Form name: " << obj.get_name() << "Form grade to sign : " << obj.get_gradetosign() << "Form grade to execute : " << obj.get_grade_execute << "is Form signed  : " << obj.get_issigned()  << std::endl;
}