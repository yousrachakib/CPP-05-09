/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 22:12:11 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/15 14:14:12 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	target;
	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& filename);
		ShrubberyCreationForm(const ShrubberyCreationForm& copy);
		~ShrubberyCreationForm();
		int execute(Bureaucrat const & executor) const;
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);
};

#endif