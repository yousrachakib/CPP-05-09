/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:30:30 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/28 16:25:29 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP


#include <iostream>

template <typename T>
class Array
{
	private:
		T* element;
		unsigned int size_;
	public:
		Array();
		Array(int unsigned n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T&	   operator[](unsigned int i);
		unsigned int size() const;
		~Array();
};

#endif