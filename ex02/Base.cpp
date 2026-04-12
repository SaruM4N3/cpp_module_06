/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 00:32:00 by zsonie            #+#    #+#             */
/*   Updated: 2026/04/13 01:49:54 by zsonie           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include<cstdlib>
#include "Base.hpp"
#include "colors.hpp"

Base::~Base() {};

Base *generate(void)
{
    int r = std::rand() % 3;

    if (r == 0)
        return new A();
    if (r == 1)
        return new B();
    return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cerr << "A" << std::endl;
        return;
    }
    catch (std::exception&){};
    try
    {
        dynamic_cast<B&>(p);
        std::cerr << "B" << std::endl;
        return;
    }
    catch (std::exception&){};
    try
    {
        dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (std::exception&){};
}
