/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:11:29 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/08 19:10:18 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template < typename T, typename Container = std::deque<T> >
class MuntantStack
{
	private :
		std::stack<T, Container>  stack_;
	public :
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		bool	empty(void) const;
		size_t	size(void) const;
		T&		top(void);
		const T&		top(void) const;
		void	push(const T& value);
		void	pop(void);
		iterator	begin(void);
		iterator	end(void);
		const_iterator begin(void) const;
		const_iterator end(void) const;
};
#endif