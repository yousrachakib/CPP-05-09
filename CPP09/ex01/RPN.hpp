/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:50:01 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/11 20:15:56 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

int		evaluate_RPN(const std::string& input);
bool	is_operator(const std::string& token);
bool	perfom_operators(std::stack<int>& stack,const std::string& operand);

#endif