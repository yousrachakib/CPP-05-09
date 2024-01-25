/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:51:05 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/25 14:51:39 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime>
#include <exception>

class Base
{
	public : 
		virtual ~Base(){};
};

class A : public Base 
{};

class B : public Base
{};

class C : public Base
{};

#endif