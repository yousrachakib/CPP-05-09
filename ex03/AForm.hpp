/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:59:58 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/15 21:03:45 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
    private:
        const std::string name;
        bool    is_signed;
        const int grade_tosign;
        const int grade_execute;
    public :
        AForm();
        AForm(const std::string input, const int sign, const int execute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
		virtual	void execute(Bureaucrat const & executor) const = 0;
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        const std::string get_name() const;
        bool get_issigned() const;
        int   get_gradetosign() const;
        int   get_grade_execute() const;
		void  beSigned(Bureaucrat& obj);
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);
#endif 