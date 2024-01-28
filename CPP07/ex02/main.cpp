/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:30:20 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/28 11:46:16 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Default constructor:

template <typename T>
Array<T>::Array() : element(NULL) , n(0) {}

// Parameterized constructor:
template <typename T>
Array<T>::Array(int unsigned n) : size_(n)
{
	element = new T[size_];
	for (unsigned int i; i < size_ ; i++)
		element[i] = T();
}

// Copy constructor :
template <typename T> //check with peers if needs deep copy ?
Array<T>::Array(const Array& other) : size_(other.size_)
{
	element = new T[size_];
	for (unsigned int i = 0; i < size_ ; i++)
		element[i] = other.element[i];
}

// Assignement operator :
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return (*this);
	delete[] element;
	size_ = other.size_;
	element = new T[size_];
	for (unsigned int i = 0; i < size_ ; i++)
		element[i] = other.element[i];
	return (*this);
}

// subscript operator :
template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= size_)
		throw std::exception();
	return (element[i]);
}

// Size member function :

template <typename T>
unsigned int Array<T>::size() const
{
	return (size_);
}