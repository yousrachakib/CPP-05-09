/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:13:30 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/10 13:32:06 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


bool    check_date(const std::string& date);
bool    check_value(const std::string& value);

#endif