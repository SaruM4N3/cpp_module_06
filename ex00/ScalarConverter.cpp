/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 23:59:27 by zsonie            #+#    #+#             */
/*   Updated: 2026/04/12 22:45:59 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cerrno>

enum Type {CHAR, INT, FLOAT, DOUBLE, UNKNOWN};

static Type detectType(std::string const &str)
{
	//char
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
		return CHAR;

	//specific cases
    if (str == "-inff" || str == "+inff" || str == "nanf")
		return FLOAT;
    if (str == "-inf" || str == "+inf" || str == "nan")
		return DOUBLE;

	//float
	errno = 0;
	char *checkf;
	float tmpfloat = std::strtof(str.c_str(), &checkf);
	static_cast<void>(tmpfloat);
	if (checkf[0] == 'f' && !checkf[1] && errno != ERANGE)
		return FLOAT;
	
	//double
	errno = 0;
	char *checkd;
	double tmpdouble = std::strtod(str.c_str(), &checkd);
	static_cast<void>(tmpdouble);
	if (!checkd[0])
		return DOUBLE;

	//int
	errno = 0;
	char *checki;
	long tmplong = std::strtol(str.c_str(), &checki, 10);
	static_cast<void>(tmplong);
	if (!checki[0] && errno != ERANGE)
    	return INT;
	return UNKNOWN;
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

static void printFromInt(int i)
{
	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(i))
		std::cout << "non-displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
	
	std::cout << "int: ";
	std::cout << i << std::endl;

	std::cout << "float: " << std::fixed << std::setprecision(1) \
	<< static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) \
	<< static_cast<double>(i) << std::endl;
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
	if (std::isnan(static_cast<float>(d)))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(static_cast<float>(d)) && d > 0)
		std::cout << "+inff" << std::endl;
	else if (std::isinf(static_cast<float>(d)) && d < 0)
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
			printFromInt(std::atoi(str.c_str()));
			break;
		case FLOAT:
			printFromFloat(std::strtof(str.c_str(), NULL));
			break;
		case DOUBLE:
			printFromDouble(std::strtod(str.c_str(), NULL));
			break;
		case UNKNOWN:
			std::cout << "Unknown type, pls retry!" << std::endl;
			break;
	}
}

