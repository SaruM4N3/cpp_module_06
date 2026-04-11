/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 23:59:27 by zsonie            #+#    #+#             */
/*   Updated: 2026/04/12 01:25:18 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{
    if (DEBUG_MODE)
        std::cout << CYAN << "Default constructor called"
                  << RESET << std::endl;
}
ScalarConverter::ScalarConverter(ScalarConverter &src)
{
    if (DEBUG_MODE)
	    std::cout << CYAN << "Copy constructor called"
	              << RESET << std::endl;
}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy)
{
    std::cout << CYAN << "Copy assignment operator called"
              << RESET << std::endl;
    return *this;
}
ScalarConverter::~ScalarConverter()
{
    std::cout << RED << "Destructor called"
              << RESET << std::endl;
}

enum Type {CHAR, INT, FLOAT, DOUBLE};

static Type detectType(std::string const &str)
{
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
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

static void printFromChar()
{
	
} 

void ScalarConverter::convert(std::string const &str)
{
	Type type = detectType(str);

	switch (type)
	{
		case CHAR:
			//printFromChar();
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

