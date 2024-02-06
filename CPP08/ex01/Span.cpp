/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 01:15:29 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/06 15:34:12 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() :  my_vector(0) , N(0) {}

Span::Span(unsigned int max_size) :  my_vector(std::vector<int>()) , N(max_size) {}

Span::Span(const Span& other)
{
	*this = other;
}
Span&	Span::operator=(const Span& other)
{
	if (this == &other)
		return(*this);
	this->N = other.N;
	this->my_vector = other.my_vector;
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int value)
{
	if (this->my_vector.size() >= this->N)
		throw std::runtime_error("size out of range permited");
	this->my_vector.push_back(value);
}

int  Span::shortestSpan() const
{
	if (this->my_vector.size() < 2)
		throw std::runtime_error("No span can be found. Insufficient data.");
	int shortestSpan = std::numeric_limits<int>::max();
	for (size_t i = 0; i < this->my_vector.size() - 1; ++i)
	{
		for (size_t j = i + 1 ; j < this->my_vector.size() ; ++j)
		{
			int span = std::abs(this->my_vector[j] - this->my_vector[i]);
			if (span < shortestSpan)
				shortestSpan = span;
		}
	}
	return (shortestSpan);
}

int  Span::longestSpan() const
{
	if (this->my_vector.size() < 2)
		throw std::runtime_error("No span can be found. Insufficient data.");
	int longestSpan = std::numeric_limits<int>::min();
	for (size_t i = 0; i < this->my_vector.size() - 1; ++i)
	{
		for (size_t j = i + 1 ; j < this->my_vector.size(); ++j)
		{
			int span = std::abs(this->my_vector[j] - this->my_vector[i]);
			if (span > longestSpan)
				longestSpan = span;
		}	
	}
	return (longestSpan);
}
