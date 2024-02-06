/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 01:03:56 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/06 01:52:49 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class Span
{
	private :
		std::vector<int> my_vector;
		unsigned	int N;
	public :
		Span();
		Span(unsigned int max_size);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int value);
		int  shortestSpan() const;
		int  longestSpan() const;
		
};


#endif