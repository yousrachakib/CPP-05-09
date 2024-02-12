/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:06:45 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/11 23:25:50 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


bool perfom_operators(std::stack<int>& stack, const std::string& operand)
{
    if (stack.size() < 2)
        return false;

    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();

    if (operand == "+")
        stack.push(a + b);
    else if (operand == "*")
        stack.push(a * b);
    else if (operand == "-")
        stack.push(a - b);
    else if (operand == "/")
    {
        if (b == 0)
            return false;
        stack.push(a / b);
    }
    return true;
}

bool is_operator(const std::string& token)
{
   return (token == "+" || token == "-" || token == "*" || token == "/");
}

int evaluate_RPN(const std::string& input)
{
	std::istringstream ss(input);
	std::stack<int> my_stack;
	
	std::string token;
	while (ss >> token)
	{
		if (is_operator(token))
		{
			// std::cout << "token : " << token << std::endl;
			if (!perfom_operators(my_stack, token))
				throw std::runtime_error("Error: Invalid expression or division by zero.");
		}
		else 
		{
			for (size_t i = 0 ; i < token.length() ; i++)
			{
				if (!isdigit(token[i]))
					throw std::runtime_error("Error.");
			}
			int res = std::atoi(token.c_str());
			if (res < 0 || res > 9)
				throw std::runtime_error("Error.");
			my_stack.push(res);
			// std::cout << "res : " << res << std::endl;
		}
	}
	if (my_stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression.");
	return (my_stack.top());
}