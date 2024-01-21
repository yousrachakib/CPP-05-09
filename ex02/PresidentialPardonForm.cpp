/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 20:23:22 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/21 20:28:42 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm() , target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string inputfile) : AForm("Presidential Creation", 25 ,5) , target(inputfile) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy)
{
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this->target != other.target)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

int PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->get_issigned() && executor.getGrade() <= this->get_grade_execute())
	{
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
		return (1);
	}
	else if (!this->get_issigned())
	{
		std::cout << target << " couldn't been pardoned by Zaphod Beeblebrox." << std::endl;
		return (0);
	}
	else
		throw PresidentialPardonForm::GradeTooLowException();
	return (0);	
}