/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:06:45 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/12 21:04:38 by yochakib         ###   ########.fr       */
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
		std::vector<int> ve;
		std::deque<int>	 dq;

		std::vector<std::pair<int, int> > ve_pairs;
		std::deque<std::pair<int, int> > dq_pairs;
		
	public :
		// PmergeMe();
		// PmergeMe(const PmergeMe& copy);
		// PmergeMe& operator=(const PmergeMe& other);
		// PmergeMe(std::string &input);
		~PmergeMe();
		void	Parse_input(std::string &input);
		void	Ford_Johnson();
		
 };



#endif