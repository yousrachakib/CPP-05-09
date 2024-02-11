/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:12:49 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/11 12:56:19 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
        return (1);
    }
	try
	{
		std::map<std::string, float> exchangeRates;
		std::string csv_file = "data.csv";
		std::string file = av[1];
		read_fill_map(exchangeRates, csv_file);
		read_parse_inputfile(file, exchangeRates);
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << "exception caught : " << e.what() << '\n';
	}
	
    return (0);
}