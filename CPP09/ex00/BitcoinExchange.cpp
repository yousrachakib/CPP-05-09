/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:32:18 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/12 13:25:55 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(const std::string& str)
{
    std::string trimmed = str;
    size_t start = 0;
    while (start < trimmed.length() && trimmed[start] == ' ')
        ++start;
    trimmed = trimmed.substr(start);
    size_t end = trimmed.length() - 1;
    while (end > 0 && trimmed[end] == ' ')
        --end;
    trimmed = trimmed.substr(0, end + 1);
    return trimmed;
}

bool check_date(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    for (size_t i = 0; i < yearStr.length(); ++i)
    {
        if (!isdigit(yearStr[i]))
            return false;
    }

    for (size_t i = 0; i < monthStr.length(); ++i)
    {
        if (!isdigit(monthStr[i]))
            return false;
    }

    for (size_t i = 0; i < dayStr.length(); ++i)
    {
        if (!isdigit(dayStr[i]))

            return false;
    }

    int year = atoi(yearStr.c_str());
    int month = atoi(monthStr.c_str());
    int day = atoi(dayStr.c_str());

    if (year < 2008 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30))
		return false;
	if (month == 2)
    {
        int isLeap = (year % 4 == 0);
        int maxDaysInFebruary = 28;
        if (isLeap)
            maxDaysInFebruary = 29;
        if (day > maxDaysInFebruary)
            return false;
    }
    return true;
}

bool    check_value(const std::string& value)
{
	int flag = 0;
	for (size_t i = 0 ; i < value.length() ; i++)
	{
		if (value[i] == '.')
			flag++;
	}
	// if (flag > 1)
	// {
	// 	std::cout << "flag :" << flag << "\n";
	// 	return (false);
	// }
	for (size_t i = 0 ; i < value.length() ; i++)
	{
		if (!isdigit(value[i]) && flag != 1)
			return false;
	}
    float val = atof(value.c_str());
    if (val <= 0 || val >= 1000)
        return (false);
    return (true);
}


void	read_fill_map(std::map<std::string, float>& exchangeRates, const std::string& filename)
{

	// Open CSV file
	std::string line;
	std::ifstream exchangefile(filename);

	if (!exchangefile)
		throw std::runtime_error("failed to open CSV file.");
	
	std::getline(exchangefile, line);
	while (std::getline(exchangefile, line))
	{
		std::istringstream isEx(line);
		std::string date,rate;
		std::getline(isEx, date, ',');
        std::getline(isEx, rate);
		exchangeRates[date] = atof(rate.c_str());
	}
	exchangefile.close();
}

void	closest_bound(std::map<std::string, float>& exchangeRates,const std::string& date,const std::string& value)
{
  	std::map<std::string, float>::iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end())
        --it; // Use the last available date
    else if (it != exchangeRates.begin() && it->first != date) 
	{
    	std::map<std::string, float>::iterator prev = it;
        --prev;
        if (date.compare(prev->first) - date.compare(it->first) > 0)
            it = prev; // Use the closest lower date
    }
    float exchangeRate = it->second;
    float finalvalue = atof(value.c_str());
    float result = finalvalue * exchangeRate;
	std::cout << date << " => " << value << " = " << result << std::endl;
}


void	read_parse_inputfile(const std::string& file, std::map<std::string, float>& exchangeRates)
{
    std::ifstream inputFile(file);
	std::string line;

    if (!inputFile)
		throw std::runtime_error("Error: could not open inputfile.");
	std::getline(inputFile, line);
	if ( trim(line) != "date | value" || line.empty())
		throw std::runtime_error("Error: could not open inputfile.");
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        std::string date, value;
        if (std::getline(iss, date, '|') && std::getline(iss, value) && !line.empty())
        {
			if (line.find_first_not_of('\n') == std::string::npos)
            	continue;
            if (!check_date(trim(date)))
            {
                std::cerr << "Error: Invalid date format: " << trim(date) << std::endl;
                continue;
            }
            if (!check_value(trim(value)))
            {
                std::cerr << "Error: Invalid value format or out of range: " << trim(value) << std::endl;
                continue;
            }
			closest_bound(exchangeRates,trim(date),trim(value));
        }
		if (!line.empty() && value.empty())
		{
			std::cerr << "Error: bad input : => " << trim(date) << std::endl;
			continue;
		}
		if (!line.empty() && date.empty())
		{
			std::cerr << "Error: bad input : => " << trim(value) << std::endl;
			continue;
		}
    }
    inputFile.close();
}