/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 01:00:10 by zsonie            #+#    #+#             */
/*   Updated: 2026/04/12 01:22:22 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include"colors.hpp"

class ScalarConverter
{
	public:
		static void convert(std::string const &str);
		
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &src);
		ScalarConverter &operator=(ScalarConverter const &copy);
		~ScalarConverter();
};

#endif
