/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 18:02:05 by maxdesall         #+#    #+#             */
/*   Updated: 2021/10/27 19:18:00 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(void): _str("default")
{
}

Scalar::Scalar(std::string str): _str(str)
{
}

Scalar::~Scalar(void)
{
}

Scalar::Scalar(Scalar const &ref): _str(ref.getStr())
{
}

Scalar				&Scalar::operator=(Scalar const &ref)
{
	_str = ref.getStr();
	return (*this);
}

std::string			Scalar::getStr(void)	const
{
	return (_str);
}

Scalar::operator	char(void)
{
	char	character = 0;
	int		value = 0;

	try
	{
		value = stoi(getStr());
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "char: impossible";
		std::cout << std::endl;
		return (0);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "char: impossible";
		std::cout << std::endl;
		return (0);
	}
	if (value > CHAR_MAX || value < CHAR_MIN)
	{
		std::cout << "char: impossible";
		std::cout << std::endl;
		return (0);
	}
	else
	{
		character = static_cast<char>(value);
		if (character > 31 && character < 127)
			std::cout << "char: " << character;
		else
			std::cout << "char: Non displayable";
		std::cout << std::endl;
		return (character);
	}
	return (character);
}

Scalar::operator	int(void)
{
	int	value = 0;

	try
	{
		value = stoi(getStr());
		std::cout << "int: " << value;
		std::cout << std::endl;
		return (value);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "int: impossible";
		std::cout << std::endl;
		return (0);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "int: impossible";
		std::cout << std::endl;
		return (0);
	}
	return (value);
}

Scalar::operator	float(void)
{
	float	value = 0;

	try
	{
		value = stof(getStr());
		std::cout << "float: " << value << "f";
		std::cout << std::endl;
		return (value);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "float: impossible";
		std::cout << std::endl;
		return (value);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "float: impossible";
		std::cout << std::endl;
		return (value);
	}
	return (value);
}

Scalar::operator	double(void)
{
	double	value = 0;

	try
	{
		value = stod(getStr());
		std::cout << "double: " << value;
		std::cout << std::endl;
		return (value);
	}
	catch (const std::invalid_argument &e)
	{
		std::cout << "double: impossible";
		std::cout << std::endl;
		return (value);
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "double: impossible";
		std::cout << std::endl;
		return (value);
	}
	return (value);
}
