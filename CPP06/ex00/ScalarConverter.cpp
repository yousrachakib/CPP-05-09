/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:18:57 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/24 17:56:39 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// CHECK TYPE FUNCTIONS :

bool	is_pseudo(std::string& input)
{
	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
			return true;
	return false;
}
bool	is_char(std::string& input)
{
	if (input.length() == 1 && !input.empty())
		return true;
	return false;
}
bool	is_int(std::string& input)
{
    std::istringstream iss(input);
    int value;
    return (iss >> value) && (iss.eof());
}

bool is_double(const std::string& input)
{
    std::istringstream iss(input);
    double value;
    return (iss >> value) && (iss.eof());
}

bool is_float(std::string& input)
{
	if (is_double(input) && input.back() != 'f')
		return false;
	return true;
}

// PRINT TYPES :

void	print_char(double	value)
{
	int	res = static_cast<int>(value); 
	if (!std::isprint(res) || res == 0)
		std::cout << "char : input non displayable" << std::endl;
	else
		std::cout << "char   : " << static_cast<char>(value) << std::endl;
}


bool int_out_of_range(int value)
{
	return value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max();
}


void	print_int(double	value)
{
	int	res = static_cast<int>(value); 
	if (int_out_of_range(res))
		std::cout << "int : int out of range !" << std::endl;
	else
		std::cout << "int    : " << static_cast<int>(value) << std::endl;
}

void	print_double(double	value)
{
	int res = static_cast<int>(value);
	if ((value - res) == 0)
		std::cout << "double : " << value << ".0"<< std::endl;
	else
		std::cout << "double : " << value << std::endl;
}


void	print_float(double	value)
{
	int	res = static_cast<int>(value); 
	if ((value - res) == 0)
		std::cout << "float  : " << static_cast<float>(value) << ".0f"<< std::endl;
	else
		std::cout << "float  : " << static_cast<float>(value) << "f"<< std::endl;
}


void	start_converting(double	value)
{
	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}
// Convert static function :

void	ScalarConverter::convert(std::string& input)
{

	std::stringstream param;

	size_t f_pos = input.find('f');
	if (f_pos != std::string::npos)
	{
		std::string numeric_part = input.substr(0, f_pos);
		double res;
		param << numeric_part;
		param >> res;
		start_converting(res);
	}
	else
	{
		param << input;
		double	res;
		param >> res;
		start_converting(res);
	}
}

// handle pseudo :

void	handle_pseudo(std::string& input)
{
	if (input == "+inff" || input == "+inf")
	{
		std::cout << " char   : impossible " << std::endl;
		std::cout << " int    : impossible"  << std::endl;
		std::cout << " double : +inf" << std::endl;
		std::cout << " float  : +inff" << std::endl;
	}
	else if (input == "-inff" || input == "-inf")
	{
		std::cout << " char   : impossible " << std::endl;
		std::cout << " int    : impossible"  << std::endl;
		std::cout << " double : -inf" << std::endl;
		std::cout << " float  : -inff" << std::endl;
	}
	else if (input == "nan" || input == "nanf")
	{
		std::cout << " char   : impossible " << std::endl;
		std::cout << " int    : impossible"  << std::endl;
		std::cout << " double : nan" << std::endl;
		std::cout << " float  : nanf" << std::endl;
	}
}

int main(int ac,char **av)
{
	if (ac == 2)
	{
		std::string input = av[1];
		if (is_pseudo(input))
			handle_pseudo(input);
		else if ((is_char(input) || is_int(input) || is_double(input) || is_float(input)))
			ScalarConverter::convert(input);
	}
	else
		std::cout << " wrong input !" << std::endl;
}