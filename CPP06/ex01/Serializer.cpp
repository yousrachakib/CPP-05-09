/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:16:09 by yochakib          #+#    #+#             */
/*   Updated: 2024/01/25 13:37:54 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data data;
	data.value = 42;

	uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);


	std::cout << " serialized uintptr_t hold this value : " << serialized << std::endl;
	std::cout << " deserialized Data * hold this value : " << deserialized << std::endl;
	std::cout << " &data hold this value : " << &data << std::endl;

	if (deserialized == &data)
		std::cout << "Well Done" << std::endl;
	else
		std::cout << "YOU FAILED " << std::endl;
}

