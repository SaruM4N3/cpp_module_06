/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 23:59:27 by zsonie            #+#    #+#             */
/*   Updated: 2026/04/12 02:10:45 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

enum Type {CHAR, INT, FLOAT, DOUBLE};

static Type detectType(std::string const &str)
{
    if (str[0] == '\'' && str[str.length()-1] == '\'')
		return CHAR;
    if (str == "-inff" || str == "+inff" || str == "nanf")
		return FLOAT;
    if (str == "-inf" || str == "+inf" || str == "nan")
		return DOUBLE;
	if (str.length() > 1 && str[str.length()-1] == 'f')
		return FLOAT;
	//find does return the index where the '.' has been found
	//or std::string::npos when '.' isnt found
	//so if not found it goes directly to return INT
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
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
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
			//printFromInt();
			break;
		case FLOAT:
			//printFromFloat();
			break;
		case DOUBLE:
			//printFromDouble();
			break;
	}
}

