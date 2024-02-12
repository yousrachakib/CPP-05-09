/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:06:32 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/12 21:27:27 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

// DONT FORGET CANNICAL FORM:

PmergeMe::~PmergeMe() {}



void	PmergeMe::Parse_input(std::string &input)
{
	std::istringstream ss(input);
	std::string	correct_input;
    int number;

	while (ss >> correct_input)
	{
		if (correct_input.find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error("Error: Invalid input format. Only positive integers are allowed.");
		number = std::atoi(correct_input.c_str());
		if (number >= 0)
		{
			ve.push_back(number);
            dq.push_back(number);
		}
		else
			throw std::runtime_error("Error: Invalid input format. Only positive integers are allowed.");
	}
	
}

std::vector<int> generateJacobsthalNumbers(int size, std::vector<int> &real)
{
    std::vector<int> jacobsthalNumbers;

    // Base cases
    jacobsthalNumbers.push_back(0);
    jacobsthalNumbers.push_back(1);
    real.push_back(0);
    real.push_back(1);

    for (int i = 2; i <= size; ++i)
    {
        int jacobsthalNumber = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];
        jacobsthalNumbers.push_back(jacobsthalNumber);
		real.push_back(i);
    }

    return jacobsthalNumbers;
}

void PmergeMe::Ford_Johnson()
{
	// fill pairs
	for (size_t i = 0; i < ve.size() - 1; i += 2)
	{
		ve_pairs.push_back(std::make_pair(ve[i], ve[i+1]));
	}
	for (size_t i = 0; i < ve_pairs.size(); ++i)
	{
    	if (ve_pairs[i].first < ve_pairs[i].second)
        	std::swap(ve_pairs[i].first, ve_pairs[i].second);
	}
	std::sort(ve_pairs.begin(), ve_pairs.end());
	for (std::vector<std::pair<int , int> >::iterator it = ve_pairs.begin() ; it != ve_pairs.end(); it++)
	{
		std::cout << "first :"<< it->first << std::endl;
		std::cout << "second :"<< it->second << std::endl;
	}
	std::vector<int> ve_chain;
	std::vector<int> ve_pend;
	ve_chain.push_back(ve_pairs[0].second);
	for (size_t i = 0 ; i < ve_pairs.size() ; ++i)
	{
		ve_chain.push_back(ve_pairs[i].first);
	}
	for (size_t i = 1 ; i < ve_pairs.size() ; ++i)
	{
		ve_pend.push_back(ve_pairs[i].second);
	}
	std::vector<int> real_index;
	std::vector<int> jacobsthal_sequence = generateJacobsthalNumbers(ve_pend.size(), real_index);
	// for (std::vector<int>::iterator it = jacobsthal_sequence.begin() ; it != jacobsthal_sequence.end(); it++)
	// {
	// 	std::cout << "jacob :" << *it << std::endl;
	// }
	// for (std::vector<int>::iterator it = real_index.begin() ; it != real_index.end(); it++)
	// {
	// 	std::cout << "real :" << *it << std::endl;
	// }

	
	

	
	
}