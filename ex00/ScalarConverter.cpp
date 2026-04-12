/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 23:59:27 by zsonie            #+#    #+#             */
/*   Updated: 2026/04/12 03:47:38 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

enum Type {CHAR, INT, FLOAT, DOUBLE};

static Type detectType(std::string const &str)
{
    if (str[0] == '\'' && str[str.length()-1] == '\'')
		return CHAR;
    if (str == "-inff" || str == "+inff" || str == "nanf")
		return FLOAT;
    if (str == "-inf" || str == "+inf" || str == "nan")
		return DOUBLE;
	if (str.length() > 1 && str[str.length()-1] == 'f' && std::isdigit(str[str.length()-2]))
		return FLOAT;
	if (str.find('.') != std::string::npos)
		return DOUBLE;
    return INT;
}

static void printFromChar(char c)
{
	std::cout << "char: ";
	if (!isprint(c))
		std::cout << "non-displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) \
	<< static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) \
	<< static_cast<double>(c) << std::endl;
} 

static void printFromInt(long l)
{
	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(l)))
		std::cout << "non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
	
	std::cout << "int: ";
	if (l < -2147483648 || l > 2147483647)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(l) << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) \
	<< static_cast<float>(l) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) \
	<< static_cast<double>(l) << std::endl;
}

static void printFromFloat(float f)
{
	std::cout << "char: ";
	if (std::isnan(f) ||std::isinf(f) || f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(f)))
		std::cout << "non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	
	std::cout << "int: ";
	if (std::isnan(f) || std::isinf(f) 
		|| f < static_cast<float>(-2147483648) 
		|| f > static_cast<float>(2147483647))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f) && f > 0)
		std::cout << "+inff" << std::endl;
	else if (std::isinf(f) && f < 0)
		std::cout << "-inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) \
		<< static_cast<float>(f) << "f" << std::endl;
	
	std::cout << "double: ";
	if (std::isnan(f))
		std::cout << "nan" << std::endl;
	else if (std::isinf(f) && f > 0)
		std::cout << "+inf" << std::endl;
	else if (std::isinf(f) && f < 0)
		std::cout << "-inf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) \
		<< static_cast<double>(f) << std::endl;
}

static void printFromDouble(double d)
{
	std::cout << "char: ";
	if (std::isnan(d) ||std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(static_cast<int>(d)))
		std::cout << "non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) 
		|| d < static_cast<double>(-2147483648) 
		|| d > static_cast<double>(2147483647))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d) && d > 0)
		std::cout << "+inff" << std::endl;
	else if (std::isinf(d) && d < 0)
		std::cout << "-inff" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) \
		<< static_cast<float>(d) << "f" << std::endl;
	
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d) && d > 0)
		std::cout << "+inf" << std::endl;
	else if (std::isinf(d) && d < 0)
		std::cout << "-inf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) \
		<< static_cast<double>(d) << std::endl;
}


void ScalarConverter::convert(std::string const &str)
{
	Type type = detectType(str);

	switch (type)
	{
		case CHAR:
			printFromChar(str[1]);
			break;
		case INT:
			printFromInt(std::strtol(str.c_str(), NULL, 10));
			break;
		case FLOAT:
			printFromFloat(std::strtof(str.c_str(), NULL));
			break;
		case DOUBLE:
			printFromDouble(std::strtod(str.c_str(), NULL));
			break;
	}
}

