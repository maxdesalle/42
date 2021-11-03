/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:28:47 by mdesalle          #+#    #+#             */
/*   Updated: 2021/10/28 14:57:16 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base	*generate(void)
{
	A	*a = new A;
	B	*b = new B;
	C	*c = new C;

	switch (std::rand() % 4)
	{
		case (1):
			return (static_cast<Base *>(a));
		case(2):
			return (static_cast<Base *>(b));
		default:
			return (static_cast<Base *>(c));
	}

	return (nullptr);
}

void	identify(Base *p)
{
	std::cout << "pointer: ";
	if (dynamic_cast<A *>(p))
		std::cout << "A";
	else if (dynamic_cast<B *>(p))
		std::cout << "B";
	else if (dynamic_cast<C *>(p))
		std::cout << "C";
	else
		std::cerr << "error";
	std::cout << std::endl;
}

void	identify(Base &p)
{
	std::cout << "reference: ";
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A";
	}
	catch(const std::bad_cast &e)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B";
	}
	catch(const std::bad_cast &e)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C";
	}
	catch(const std::bad_cast &e)
	{
	}
	std::cout << std::endl;
}

int	main(void)
{
	std::srand(std::time(nullptr));

	Base *v1 = generate();
	Base *v2 = generate();
	Base *v3 = generate();

	Base &r1 = *v1;
	Base &r2 = *v2;
	Base &r3 = *v3;

	identify(v1);
	identify(v2);
	identify(v3);

	identify(r1);
	identify(r2);
	identify(r3);

	return (0);
}
