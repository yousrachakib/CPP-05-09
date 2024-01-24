/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:51:51 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/24 19:40:41 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <sstream>
#include <iomanip> 

typedef struct Data
{
	int value;
} Data;


class Serializer
{
	private :
		Serializer();
	public :
		static uintptr_t	serialize(Data * ptr);
		static Data *		deserialize(uintptr_t raw);
};

#endif