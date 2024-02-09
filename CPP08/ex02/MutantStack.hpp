/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:11:29 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/09 15:08:23 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template < typename T>
class MutantStack : public std::stack<T>
{
	private :
		std::stack<T>  stack_;
	public :
		MutantStack() {};
		~MutantStack() {};
		typedef typename  std::deque<T>::iterator iterator;
		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				this->c = other.c;
			return (*this);
		}
		iterator	begin(void) {return this->c.begin();}
		iterator	end(void){return this->c.end();}
};
#endif