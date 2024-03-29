/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:06:32 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/14 15:52:37 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

// DONT FORGET CANNICAL FORM:
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy) 
{
 	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		this->dq = other.dq;
		this->ve = other.ve;
		this->ve_pairs = other.ve_pairs;
		this->dq_pairs = other.dq_pairs;
		this->dq_jacobsthalNumbers = other.dq_jacobsthalNumbers;
		this->ve_jacobsthalNumbers = other.ve_jacobsthalNumbers;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void binary_search(int value, std::vector<int> &ve_chain)
{
	std::vector<int>::iterator ity;
	ity = std::lower_bound(ve_chain.begin(), ve_chain.end(), value);
	ve_chain.insert(ity, value);
}

void binary_search_dq(int value, std::deque<int> &dq_chain)
{
	std::deque<int>::iterator ity;
	ity = std::lower_bound(dq_chain.begin(), dq_chain.end(), value);
	dq_chain.insert(ity, value);
}

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
	duplicate(this->ve);
}

void duplicate(std::vector<int> vec)
{
	if (vec.size() < 2)
		throw std::runtime_error("Error : can't sort 1 number .");
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = (i + 1); j < vec.size() ; j++)
		{
			if (vec[i] == vec[j])
				throw std::runtime_error("Error : Duplicate numbers .");
		}
	}
}
void PmergeMe::generateJacobsthalNumbers(int size)
{

    ve_jacobsthalNumbers.push_back(0);
    ve_jacobsthalNumbers.push_back(1);
    dq_jacobsthalNumbers.push_back(0);
    dq_jacobsthalNumbers.push_back(1);

    for (int i = 2; i <= size; ++i)
    {
        int jac = ve_jacobsthalNumbers[i - 1] + 2 * ve_jacobsthalNumbers[i - 2];
        ve_jacobsthalNumbers.push_back(jac);
		int jaco = dq_jacobsthalNumbers[i - 1] + 2 * dq_jacobsthalNumbers[i - 2];
		dq_jacobsthalNumbers.push_back(jaco);
    }
}
std::vector<int> generate_combination_ve(std::vector<int> jacobsthal_sequence, size_t size)
{
	int lastJacobsthalNumber = 2;
	std::vector<int> _combined;
	if (size <= 3)
	{
		_combined.push_back(2);
	}
	for (size_t i = 3; i < size; i++)
    {
        size_t index = jacobsthal_sequence[i];
        if (index > size)
            break;
		_combined.push_back(jacobsthal_sequence[i]);

        for (int j = jacobsthal_sequence[i] - 1; j > lastJacobsthalNumber; j--)
        {
            _combined.push_back(j);
        }
		if (i == 3)
            _combined.push_back(lastJacobsthalNumber);
        lastJacobsthalNumber = jacobsthal_sequence[i];
    }
	return (_combined);
}

std::deque<int> generate_combination_dq(std::deque<int> jacobsthal_sequence)
{
	int lastJacobsthalNumber = 2;
	std::deque<int> _combined;
	for (size_t i = 3; i < jacobsthal_sequence.size(); i++)
    {
        size_t index = jacobsthal_sequence[i];
        if (index > jacobsthal_sequence.size())
            break;
		_combined.push_back(jacobsthal_sequence[i]);

        for (int j = jacobsthal_sequence[i] - 1; j > lastJacobsthalNumber; j--)
        {
            _combined.push_back(j);
        }
		if (i == 3)
            _combined.push_back(lastJacobsthalNumber);
        lastJacobsthalNumber = jacobsthal_sequence[i];
    }
	return (_combined);
}

void PmergeMe::Ford_Johnson_vec()
{
	this->time = gettime();
	if (ve.size() % 2 == 1)
	{
		for (size_t i = 0; i < ve.size() - 1; i += 2)
			ve_pairs.push_back(std::make_pair(ve[i], ve[i+1]));
		this->struggler_ve = this->ve[ve.size() - 1];
	}
	else
	{
		for (size_t i = 0; i < ve.size(); i += 2)
			ve_pairs.push_back(std::make_pair(ve[i], ve[i+1]));
	}
	for (size_t i = 0; i < ve_pairs.size(); ++i)
	{
    	if (ve_pairs[i].first < ve_pairs[i].second)
        	std::swap(ve_pairs[i].first, ve_pairs[i].second);
	}
	std::sort(ve_pairs.begin(), ve_pairs.end());	
	std::vector<int> ve_chain;
	std::vector<int> ve_pend;
	ve_chain.push_back(ve_pairs[0].second);
	for (size_t i = 0 ; i < ve_pairs.size() ; ++i)
		ve_chain.push_back(ve_pairs[i].first);
	for (std::vector<std::pair<int , int> >::iterator it  = ve_pairs.begin() + 1; it != ve_pairs.end() ; it++)
	{
		ve_pend.push_back(it->second);
	}
	generateJacobsthalNumbers(ve_pend.size());
	std::vector<int> combination_index = generate_combination_ve(this->ve_jacobsthalNumbers, ve_pend.size()); 
	for (std::vector<int>::iterator it = combination_index.begin(); it != combination_index.end() && !ve_pend.empty(); ++it)
	{
		if ((*it -1) < (int)ve_pend.size())
		{
			if (std::find(ve_chain.begin(), ve_chain.end(), ve_pend[*it - 1]) != ve_chain.end())
				continue;
			binary_search(ve_pend[*it - 1], ve_chain);
		}
	}
	if (!ve_pend.empty())
	{
		for (size_t i = 0 ; i < ve_pend.size() ; i++)
		{
			if (!ve_pend.empty() && std::find(ve_chain.begin(), ve_chain.end(), ve_pend[i]) != ve_chain.end())
				continue;
			binary_search(ve_pend[i], ve_chain);
		}
	}
	if (ve.size() % 2 == 1)
	{
		binary_search(this->struggler_ve, ve_chain);
	}
	this->time_to_process_ve = ((gettime() - this->time) / 1000000.0);
	print_res(ve_chain);
}

long long     PmergeMe::gettime()//time in mirco seconds
{
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long microseconds = te.tv_sec*1000000LL + te.tv_usec;
    return microseconds;
}

void PmergeMe::Ford_Johnson_dq()
{
	this->time = gettime();
	if (dq.size() % 2 == 1)
	{
		for (size_t i = 0; i < ve.size() - 1; i += 2)
			dq_pairs.push_back(std::make_pair(dq[i], dq[i+1]));
		this->struggler_dq = *(this->dq.end());
	}
	else
	{
		for (size_t i = 0; i < ve.size(); i += 2)
			dq_pairs.push_back(std::make_pair(dq[i], dq[i+1]));
	}
	
	for (size_t i = 0; i < dq_pairs.size(); ++i)
	{
    	if (dq_pairs[i].first < dq_pairs[i].second)
        	std::swap(dq_pairs[i].first, dq_pairs[i].second);
	}
	std::sort(dq_pairs.begin(), dq_pairs.end());	
	std::deque<int> dq_chain;
	std::deque<int> dq_pend;
	dq_chain.push_back(dq_pairs[0].second);
	for (size_t i = 0 ; i < dq_pairs.size() ; ++i)
		dq_chain.push_back(dq_pairs[i].first);
	for (std::deque<std::pair<int , int> >::iterator it  = dq_pairs.begin() + 1; it != dq_pairs.end() ; it++)
	{
		dq_pend.push_back(it->second);
	}
	std::deque<int> combination_index = generate_combination_dq(this->dq_jacobsthalNumbers); 
	for (std::deque<int>::iterator it = combination_index.begin(); it != combination_index.end() && !dq_pend.empty(); ++it)
	{
		if ((*it -1) < (int)dq_pend.size())
		{
			if (std::find(dq_chain.begin(), dq_chain.end(), dq_pend[*it - 1]) != dq_chain.end())
				continue;
			binary_search_dq(dq_pend[*it - 1], dq_chain);
		}
	}
	if (!dq_pend.empty())
	{
		for (size_t i = 0 ; i < dq_pend.size() ; i++)
		{
			if (!dq_pend.empty() && std::find(dq_chain.begin(), dq_chain.end(), dq_pend[i]) != dq_chain.end())
				continue;
			binary_search_dq(dq_pend[i], dq_chain);
		}
	}
	if (dq.size() % 2 == 1)
		binary_search_dq(this->struggler_dq, dq_chain);
	this->time_to_process_dq = ((gettime() -  this->time) / 1000000.0);
}
void PmergeMe::print_res(std::vector<int> &main_chain)
{
	std::cout << "before :";
	for (std::vector<int>::iterator it = ve.begin() ; it != ve.end(); it++)
	{
		std::cout << " " << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "after  :";
	for (std::vector<int>::iterator it = main_chain.begin() ; it != main_chain.end(); it++)
	{
		std::cout << " " << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->dq.size() << " elements with std::deque<int> :" << this->time_to_process_dq << " us"<< std::endl; 
	std::cout << "Time to process a range of " << this->ve.size() << " elements with std::vector<int> :" << this->time_to_process_ve << " us"<<std::endl;
}
