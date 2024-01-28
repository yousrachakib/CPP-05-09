/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:44:00 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/27 12:30:10 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename myTemplate>

void	swap(myTemplate& arg1,myTemplate& arg2);

template <typename myTemplate1>
myTemplate1		min(myTemplate1&	arg1,myTemplate1& arg2);

template <typename myTemplate2>
myTemplate2		max(myTemplate2&	arg1,myTemplate2& arg2);


#endif
