/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:03:34 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/26 16:57:11 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){};

Base * generate(void)
{
	int random = std::rand() % 3;

	switch (random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Congratulation its an [A] type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Congratulation its a [B] type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Congratulation its a [C] type" << std::endl;
	else
		std::cout << "NOT UR LUCKY DAY!!" << std::endl;
}

void	identify(Base& p)
{
	A	a;
	B	b;
	C	c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "Congratulation its an [A] type" << std::endl;
	}
	catch(const std::bad_cast& e)
	{
		try
		{
			b = dynamic_cast<B&>(p);
			std::cout << "Congratulation its a [B] type" << std::endl;
		}
		catch(const std::bad_cast& e)
		{
			try
			{
				c = dynamic_cast<C&>(p);
				std::cout << "Congratulation its a [C] type" << std::endl;
			}
			catch(const std::bad_cast& e)
			{
				std::cout << "NOT UR LUCKY DAY!!" << std::endl;
			}
			
		}
		
	}
}

int main()
{
	Base o;
	Base *obj = generate();
	identify(obj);
	identify(*obj);
	identify(o);
	Base& ref = o;
	identify(ref);
	delete obj;	
}