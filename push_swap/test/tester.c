/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:27:09 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/10 20:39:16 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STDOUT 1
#define STDERR 1

static void	ft_putchar(char c)
{
	write(STDOUT, &c, 1);
}

static void	ft_putnbr(int n)
{
	long	x;

	x = n;
	if (x < 0)
	{
		ft_putchar('-');
		x *= -1;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
}

static int	history_check(int *history, int number, int i)
{
	while (i > 0)
	{
		if (history[i] == number)
			return (0);
		i--;
	}
	return (1);
}

static void	ft_random(int n)
{
	int	i;
	int	history[n];
	int	random_number;

	i = 0;
	random_number = 0;
	srand(time(NULL));
	write(STDOUT, "export ARG=", 11);
	write(STDOUT, "\"", 1);
	while (n > 0)
	{
		random_number = rand() % 10000;
		while (history_check(history, random_number, i) == 0)
			random_number = rand() % 10000;
		history[i] = random_number;
		ft_putnbr(random_number);
		if (n != 1)
			write(STDOUT, " ", 1);
		i++;
		n--;
	}
	write(STDOUT, "\"", 1);
	write(STDOUT, "\n", 1);
}

static int	error(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}

static int	ft_return(int result, int sign)
{
	result *= sign;
	if (result > 0 && sign < 0)
		return (error());
	if (result < 0 && sign > 0)
		return (error());
	return (result);
}

static int	is_empty(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

static int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && is_empty(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	i += is_sign(str[i]);
	while (str[i] && is_num(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (ft_return(result, sign));
}

int	main(int argc, char **argv)
{
	int	n;

	n = 0;
	if (argc != 2)
	{
		write(STDERR, "An error occurred\n", 18);
		return (0);
	}
	n = ft_atoi(argv[1]);
	ft_random(n);
	return (0);
}
