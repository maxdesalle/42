/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:27:09 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/13 11:40:16 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/test.h"

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

static void	caller(char *dest)
{
	char	*args[] = {"./push_swap", dest, NULL};

	if (execvp("./push_swap", args) == -1)
		perror("Error");
}

static int	randlen(int snapshot, int *history)
{
	int	len;

	len = 0;
	while (snapshot-- > 0)
	{
		len += ft_intlen(history[snapshot]);
		len += 1;
	}
	return (len);
}

static char	*saver(int len, int snapshot, int *history)
{
	int		n;
	char	*dest;

	n = snapshot;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (len-- > 0)
		dest[len] = '\0';
	while (n-- > 0)
	{
		if (snapshot != (n + 1))
			ft_strcat(dest, " ");
		ft_strcat(dest, ft_itoa(history[n]));
	}
	return (dest);
}

static void	ft_random(int n)
{
	int		i;
	int		snapshot;
	int		history[n];
	int		random_number;
	char	*dest;

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
		i++;
		n--;
	}
	dest = saver(randlen(snapshot, history), snapshot, history);
	caller(dest);
	free(dest);
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
	printf("TEST");
	return (0);
}
