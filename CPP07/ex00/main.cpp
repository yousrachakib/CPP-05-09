/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:52:18 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/27 12:30:43 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template <typename myTemplate>
void	swap(myTemplate& arg1, myTemplate& arg2)
{
	myTemplate temp; 
	temp =  arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename myTemplate1>
myTemplate1		min(myTemplate1&	arg1,myTemplate1& arg2)
{
	if (arg1 >= arg2)
		return arg2;
	else
		return arg1;
}

template <typename myTemplate2>
myTemplate2	max(myTemplate2& arg1, myTemplate2& arg2)
{
	if (arg1 > arg2)
		return arg1;
	else
		return arg2;
}


int main( void ) 
{
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}