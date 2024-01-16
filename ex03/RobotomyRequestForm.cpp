/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:41:51 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/15 18:21:33 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm() , target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string inputfile) : AForm("Robotomy Creation", 72, 45) ,target(inputfile) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this->target != other.target)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	static int checker;
	
	if (this->get_issigned() && executor.getGrade() <= this->get_grade_execute())
	{
		std::cout << "*Drilling noises*" << std::endl;
		checker = checker % 2;
		if (checker == 0)
			std::cout << target << " has been robotomized successfully!" << std::endl;
		else
			std::cout << "Robotomy failed for " << target << "." << std::endl;
		checker++;
	}
	else if (!this->get_issigned())
	{
			std::cout << "Cannot execute the form. It is not signed." << std::endl;
            return;
	}
	else
		throw RobotomyRequestForm::GradeTooLowException();	
}