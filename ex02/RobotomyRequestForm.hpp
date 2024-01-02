/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:36:29 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/02 18:14:21 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include "AForm.hpp"
#include <iostream>
#include <exception>

class RobotomyRequestForm : public AForm
{
	private :
		std::string	target;
	public :
		RobotomyRequestForm();
		RobotomyRequestForm(std::string inputfile);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);
		void execute(Bureaucrat const & executor) const;
};


#endif