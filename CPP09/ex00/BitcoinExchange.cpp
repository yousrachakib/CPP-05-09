/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:32:18 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/10 16:31:17 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool    check_date(const std::string& date) // Date format: Year-Month-Day
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
    for (int i = 0 ; i < 10 ; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!isdigit(date[i]))
            return (false);
    }
    return (true);
}

bool    check_value(const std::string& value)
{
    float val = atof(value.c_str());
    if (val <= 0 || val >= 1000)
        return (false);
    return (true);
}