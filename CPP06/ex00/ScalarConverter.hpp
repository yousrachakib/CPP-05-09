/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:14:00 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/24 11:19:17 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP


#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <exception>
#include <sstream>
#include <iomanip> 

typedef enum s_type
{
	CHAR,
	INT,
	DOUBLE,
	FLOAT,
} t_type;

class ScalarConverter
{
	private :
		ScalarConverter(); // Private constructor to prevent instantiation
	public :
		static void	convert(std::string& input);
};

#endif