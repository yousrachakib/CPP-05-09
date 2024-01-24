/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:18:57 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/24 11:47:46 by yochakib         ###   ########.fr       */
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
	int i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (input[i++])
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}
bool is_float(std::string& input)
{
    if (input.empty() || input.back() != 'f')
        return false;
    try
	{
        std::stof(input);
        return true;
    }
	catch (const std::exception&)
	{
        return false;
    }
}

bool is_double(std::string& input)
{
	if (input.empty() || input.back() == '.' || input.front() == '.')
		return false;
	bool	dot = false;
	bool	digit = false;
	for (size_t i = 0 ; i < input.length() ; i++ )
	{
		if (input[i] == '.')
		{
			if (dot || !digit)
				return false;
			dot = true;
		}
		else if (!isdigit(input[i]))
			return false;
		else
			digit = true;
	}
	return true;
}

// Convert to char :
void	convert_to_char(std::string input)
{
	int result = std::stoi(input);
	
	if (!std::isprint(result) || result == '\0')
		std::cout << " char :" << "input non displayable" << std::endl;
	else
		std::cout << " char :" << static_cast<char>(result) << std::endl;
	std::cout << " int :" << static_cast<int>(result) << std::endl;
	std::cout << " double :" << std::fixed << std::setprecision(1) << static_cast<double>(std::stod(input)) << std::endl;
	std::cout << " float :" << std::fixed << std::setprecision(1) << static_cast<float>(std::stof(input))<< "f"<<std::endl;
}

// Convert to int :

bool int_out_of_range(int value)
{
	return value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max();
}

void		convert_to_int(std::string& input)
{
	int result = std::stoi(input);
	
	if (!std::isprint(result) || result == '\0')
		std::cout << " char :" << "input non displayable" << std::endl;
	else
		std::cout << " char :" << static_cast<char>(result) << std::endl;
	if (int_out_of_range(result))
		std::cout << "int :" << "input out of <int> range !" << std::endl;
	else
		std::cout << " int :" << static_cast<int>(result) << std::endl;
	std::cout << " double :" << std::fixed << std::setprecision(1) << static_cast<double>(std::stod(input)) << std::endl;
	std::cout << " float :" << std::fixed << std::setprecision(1) << static_cast<float>(std::stof(input))<< "f"<<std::endl;
}

// Convert to double :

void	convert_to_double(std::string& input)
{
	double result = std::stod(input);
	
	if (!std::isprint(result) || result == '\0')
		std::cout << " char :" << "input non displayable" << std::endl;
	else
		std::cout << " char :" << static_cast<char>(result) << std::endl;
	if (int_out_of_range(result))
		std::cout << "int :" << "input out of <int> range !" << std::endl;
	else
		std::cout << " int :" << static_cast<int>(result) << std::endl;
	std::cout << " double :" << std::fixed << std::setprecision(1) << static_cast<double>(result) << std::endl;
	std::cout << " float :" << std::fixed << std::setprecision(1) << static_cast<float>(std::stof(input))<< "f"<<std::endl;
}

// Convert to float

void	convert_to_float(std::string& input)
{
	double result = std::stof(input);
	
	if (!std::isprint(result) || result == '\0')
		std::cout << " char :" << "input non displayable" << std::endl;
	else
		std::cout << " char :" << static_cast<char>(result) << std::endl;
	if (int_out_of_range(result))
		std::cout << "int :" << "input out of <int> range !" << std::endl;
	else
		std::cout << " int :" << static_cast<int>(result) << std::endl;
	std::cout << " double :" << std::fixed << std::setprecision(1) << static_cast<double>(std::stod(input)) << std::endl;
	std::cout << " float :" << std::fixed << std::setprecision(1) << static_cast<float>(result)<< "f"<<std::endl;
	
}

// SET TYPE :

t_type	is_type(std::string& input)
{
	if (is_char(input))
		return CHAR;
	else if (is_int(input))
		return INT;
	else if (is_float(input))
		return FLOAT;
	else
		return DOUBLE;
}

// Convert static function :

void	ScalarConverter::convert(std::string& input)
{
	int type = is_type(input);
	switch (type)
	{
		case CHAR:
			convert_to_char(input);
			break;
		case INT:
			convert_to_int(input);
			break;
		case DOUBLE:
			convert_to_double(input);
			break;
		case FLOAT:
			convert_to_float(input);
			break;
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