/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MuntantStack.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:31:41 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/08 19:33:17 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename Container>
bool	MuntantStack<T, Container>::empty(void) const
{
	return (this->stack_.empty());
}

template <typename T, typename Container>
size_t	MuntantStack<T, Container>::size(void) const
{
	return (this->stack_.size());
}


template <typename T, typename Container>
T&	MuntantStack<T, Container>::top(void)
{
	return (this->stack_.top());
}

template <typename T, typename Container>
const T&	MuntantStack<T, Container>::top(void) const
{
	return (this->stack_.top());
}

template <typename T, typename Container>
void	MuntantStack<T, Container>::push(const T& value)
{
	return (this->stack_.push());
}

template <typename T, typename Container>
void	MuntantStack<T, Container>::pop(void)
{
	return (this->stack_.pop());
}

template<typename T, typename Container>
typename MuntantStack<T, Container>::iterator MuntantStack<T, Container>::begin()
{
    return (stack_.c.begin());
}

template<typename T, typename Container>
typename MuntantStack<T, Container>::iterator MuntantStack<T, Container>::end()
{
    return (stack_.c.end());
}


template<typename T, typename Container>
typename MuntantStack<T, Container>::const_iterator MuntantStack<T, Container>::begin() const
{
    return (stack_.c.begin());
}

template<typename T, typename Container>
typename MuntantStack<T, Container>::const_iterator MuntantStack<T, Container>::begin() const
{
    return (stack_.c.end());
}
