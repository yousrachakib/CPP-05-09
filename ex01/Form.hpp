/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:59:58 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/29 19:02:22 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Form
{
    private:
        const std::string name;
        bool    is_signed;
        const int grade_tosign;
        const int grade_execute;
    public :
        Form();
        Form(const std::string input, bool is_signed, const int sign, const int execute);
        Form(const Form& copy);
        Form& operator=(const Form& other);
        ~Form();
        class GradeTooHighException : public std::exception
        {
            const char* what() throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() throw();
        };
        const std::string get_name();
        const bool get_issigned();
        const int   get_gradetosign();
        const int   get_grade_execute();
};

std::ostream& operator<<(std::ostream& os, const Form& obj);
#endif 