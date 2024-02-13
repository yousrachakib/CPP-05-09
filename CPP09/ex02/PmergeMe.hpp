/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:06:45 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/13 17:15:41 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <exception>
#include <string>
#include <utility>

class PmergeMe
{
	private : 
		int struggler_ve;
		int struggler_dq;
		std::vector<int> ve;
		std::deque<int>	 dq;
		std::vector<int> ve_jacobsthalNumbers;
		std::deque<int> dq_jacobsthalNumbers;
		std::vector<std::pair<int, int> > ve_pairs;
		std::deque<std::pair<int, int> > dq_pairs;
		
	public :
		// PmergeMe();
		// PmergeMe(const PmergeMe& copy);
		// PmergeMe& operator=(const PmergeMe& other);
		// PmergeMe(std::string &input);
		~PmergeMe();
		void	Parse_input(std::string &input);
		void	Ford_Johnson_vec();
		void	Ford_Johnson_dq();
		void	generateJacobsthalNumbers(int size);
		
 };

void binary_search(int value, std::vector<int> &ve_chain);


#endif