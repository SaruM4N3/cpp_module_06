/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:53:03 by zsonie            #+#    #+#             */
/*   Updated: 2026/04/13 01:56:34 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "colors.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main(int argc, char **argv)
{
	static_cast<void>(argc);
	static_cast<void>(argv);
	std::srand(std::time(NULL));

	Base *base1 = generate();
	std::cout << CYAN "base1" RESET << " identify ptr: " << GREEN;
	identify(*base1);
	std::cout << CYAN "base1" RESET << " identify ref: " << GREEN;
	identify(base1);
	std::cout << RESET << std::endl;

	Base *base2 = generate();
	std::cout << CYAN "base2" RESET << " identify ptr: " << GREEN;
	identify(*base2);
	std::cout << CYAN "base2" RESET << " identify ref: " << GREEN;
	identify(base2);
	std::cout << RESET << std::endl;

	Base *base3 = generate();
	std::cout << CYAN "base3" RESET << " identify ptr: " << GREEN;
	identify(*base3);
	std::cout << CYAN "base3" RESET << " identify ref: " << GREEN;
	identify(base3);
	return 0;
}
