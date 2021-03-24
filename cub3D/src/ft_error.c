/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:48:54 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/24 21:51:12 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** checks if the argument save is correctly given. returns 1 if yes, 0 if not.
*/

int	ft_args(char *argv, v_list *c)
{
	int		i;
	char	*save;

	i = 0;
	save = "--save";
	while (argv[i] == save[i])
	{
		if (argv[i] == '\0' && save[i] == '\0')
		{
			c->uti.sve = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** checks if the map argument is correctly given with the right file format
** (.cub). returns 1 if yes, 0 if not.
*/

int	ft_argn(char *argv)
{
	int		i;
	int		j;
	char	*cub;

	i = ft_strlen(argv) - 4;
	j = 0;
	cub = ".cub";
	if (i > 0)
		while (argv[i++] == cub[j++])
			if (argv[i] == '\0' && cub[j] == '\0')
				return (1);
	return (0);
}

/*
** returns an error based on the given option.
*/

int	ft_error(int option, v_list *c)
{
	c->uti.err = 1;
	if (option == 0)
		return (write(1, "Error\nInvalid argument\n", 23));
	if (option == 1)
		return (write(1, "Error\nInvalid resolution\n", 25));
	if (option == 2)
		return (write(1, "Error\nInvalid map file path\n", 28));
	if (option == 3)
		return (write(1, "Error\nInvalid map file\n", 23));
	if (option == 4)
		return (write(1, "Error\nInvalid map\n", 18));
	if (option == 5)
		return (write(1, "Error\nFailed memory allocation\n", 31));
	if (option == 6)
		return (write(1, "Error\nInvalid minilibX\n", 23));
	if (option == 7)
		return (write(1, "Error\nPlayer not found\n", 24));
	if (option == 8)
		return (write(1, "Error\nImage file could not be created\n", 38));
	return (0);
}
