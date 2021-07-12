/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:27:09 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 22:45:30 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STDOUT 1
#define STDERR 1

static int	history_check(int *history, int number, int i)
{
	while (i > 0) {
		if (history[i] == number)
			return (0);
		i--;
	}
	return (1);
}

static size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static size_t	ft_intlen(long x)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = x;
	if (x == 0)
		return (++len);
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (x < 0)
		len++;
	return (len);
}

static char	*ft_itoa(int n)
{
	int		len;
	long	x;
	char	*s;

	x = n;
	len = ft_intlen(x);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len--] = '\0';
	if (x == 0)
		s[0] = '0';
	if (x < 0)
	{
		s[0] = '-';
		x *= -1;
	}
	while (x > 0)
	{
		s[len--] = x % 10 + '0';
		x /= 10;
	}
	return (s);
}

static void	ft_random(int n)
{
	int	i;
	int	snapshot;
	int	history[n];
	int	random_number;
	char	dest[50000];

	i = 0;
	snapshot = n;
	random_number = 0;
	srand(time(NULL));
	while (n > 0)
	{
		random_number = rand() % 10000;
		while (history_check(history, random_number, i) == 0)
			random_number = rand() % 10000;
		history[i] = random_number;
		if (snapshot != n && n != 0)
			ft_strcat(dest, " ");
		ft_strcat(dest, ft_itoa(random_number));
		i++;
		n--;
	}
#if 1
	char	*args[] = {"./push_swap", dest, NULL};
	if (execvp("./push_swap", args) == -1)
		perror("error");
#endif
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
