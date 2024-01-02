/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:30 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/02 20:39:34 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private : 
		std::string	target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(std::string inputfile);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		void execute(Bureaucrat const & executor) const;	
};



#endif