/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:19:30 by yochakib          #+#    #+#             */
/*   Updated: 2023/12/29 16:49:34 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const std::string name;
        int               grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat(const std::string input, int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        std::string getName()const;
        int getGrade()const;
        void    incrementGrade();
        void    decrementGrade();
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif