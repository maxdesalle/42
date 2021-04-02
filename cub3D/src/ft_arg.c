/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:17:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/02 11:18:38 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** checks if the argument save is correctly given. returns 1 if yes, 0 if not.
*/

int	ft_args(char *argv, t_list *c)
{
	int		i;
	char	*save;

	i = 0;
	save = "--save";
	c->uti.sve = 0;
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
