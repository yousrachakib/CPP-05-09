/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:30:20 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/28 18:28:02 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Default constructor:

template <typename T>
Array<T>::Array() : element(NULL) , size_(0) {}

// Parameterized constructor:
template <typename T>
Array<T>::Array(int unsigned n) : size_(n)
{
	element = new T[size_];
	for (unsigned int i = 0; i < size_ ; i++)
		element[i] = T();
}

// Copy constructor :
template <typename T>
Array<T>::Array(const Array& other) : size_(other.size_)
{
	puts("hi from copy constructor");
	element = NULL;
	*this = other;
}

// Destructor :
template <typename T>
Array<T>::~Array()
{
	delete[] element;
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


int main() 
{
   try
   {
		Array<int> arr1(5);  // Create an array of 5 integers
		
		for (unsigned int i = 0; i < arr1.size(); i++)
			arr1[i] = i + 1;  // Assign values to the array elements

		Array<int> arr2 = arr1;  // Copy constructor

		arr2[2] = 10;  // Modify arr2, arr1 remains unchanged

		std::cout << "arr1: ";
		
		for (unsigned int i = 0; i < arr1.size(); i++)
			std::cout << arr1[i] << " ";
		std::cout << std::endl;

		std::cout << "arr2: ";
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << " ";
		std::cout << std::endl;

		std::cout << arr2[7] << std::endl; // exception case 

   }
   catch(const std::exception& e)
   {
		std::cerr << "index out of range !"  << std::endl;
   }
    return (0);
}