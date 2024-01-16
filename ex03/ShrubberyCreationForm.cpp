/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:24:27 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/15 18:22:06 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm() , target("Default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& filename) : AForm("Shrubbery Creation", 145, 137) , target(filename) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{
	*this = copy;
}
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this->target != other.target)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()	{}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	std::string	filename = this->target;
	std::ofstream	outputFile;
	if (this->get_issigned() && executor.getGrade() <= this->get_grade_execute())
	{
		filename.append("_shrubbery");
		outputFile.open(filename);
		if (!outputFile.is_open())
		{
			std::cout << "Failed to create the shrubbery file." << std::endl;
			return ;
		}
		outputFile << "     *\n";
		outputFile << "    / \\\n";
		outputFile << "   /   \\\n";
		outputFile << "  *     *\n";
		outputFile << " / \\   / \\\n";
		outputFile << "*   * *   *\n";
		outputFile.close();
		std::cout << "Shrubbery has been created in " << filename << std::endl;
	}
	else
		throw	ShrubberyCreationForm::GradeTooLowException();
}