/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:12:49 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/10 16:32:13 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    //Check if the number of argument is correct 
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
        return (1);
    }
    //Open the input file
    std::ifstream inputFile(av[1]);

    //Check if file is openned successfully
    if (!inputFile)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return (1);
    }
    
    std::string line;
    //Read file line by line
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string date, value;
        
        //split the line into date & value
        if (std::getline(iss, date, '|') && std::getline(iss, value))
        {
            if (check_date(date))
            {
                std::cerr << "Error: Invalid date format: " << date << std::endl;
                continue;
            }
            if (!check_value(value))
            {
                std::cerr << "Error: Invalid value format or out of range: " << value << std::endl;
                continue;
            }
        }
    }

    //Close the File
    inputFile.close();
    return (0);
}