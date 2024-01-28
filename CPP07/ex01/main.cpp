/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:34:51 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/27 19:59:26 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"


template <typename T>

void	iter(T* array,size_t lenght, void (*func)(T&))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(array[i]);
	}
}

template <typename T>
void	increment(T& array)
{
	array++;
}

int main()
{
	// char array[] = "ABCD";
	int array[] = {1, 2, 3, 4};
	size_t lenght = sizeof(array) / sizeof(array[0]);

	std::cout << "original array:" << std::endl;
	for (size_t i = 0 ; i < lenght; i++)
		std::cout << "[" << array[i] << "]" << std::endl;
	
	std::cout << "after iter function :" << std::endl;
	iter(array, lenght, increment);
	
	for (size_t i = 0 ; i < lenght; i++)
		std::cout << "[" << array[i] << "]" << std::endl;
	return (0);
}