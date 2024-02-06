/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 02:07:58 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/06 15:21:58 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main()
// {
// 	try
// 	{

//     	std::srand(static_cast<unsigned int>(std::time(nullptr)));
//     	Span span(10);
//     	for (int i = 0; i < 10; i++)
//     	{
//         	int value = std::rand() % 100; // Generate a random number between 0 and 99
//         	span.addNumber(value);
//     	}

// 		// Calculate and print the shortest span
// 		int shortestSpan = span.shortestSpan();
// 		std::cout << "Shortest span: " << shortestSpan << std::endl;

// 		// Calculate and print the longest span
// 		int longestSpan = span.longestSpan();
// 		std::cout << "Longest span: " << longestSpan << std::endl;

// 		// Try adding a new number when the Span is already full
// 		span.addNumber(42); // This should throw an exception
// 	}
// 	catch(const std::runtime_error& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// 	return 0;
// }

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}