/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yochakib <yochakib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:13:30 by yochakib          #+#    #+#             */
/*   Updated: 2024/02/11 13:36:30 by yochakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>

std::string trim(const std::string& str);
bool    check_date(const std::string& date);
bool    check_value(const std::string& value);
void	read_fill_map(std::map<std::string, float>& exchangeRates, const std::string& filename);
void	closest_bound(std::map<std::string, float>& exchangeRates,const std::string& date,const std::string& value);
void	read_parse_inputfile(const std::string& file, std::map<std::string, float>& exchangeRates);

#endif