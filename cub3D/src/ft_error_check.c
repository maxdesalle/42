/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:16:37 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/14 14:20:34 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** checks if the argument save is correctly given. returns 1 if yes, 0 if not.
*/

int	ft_argsavecheck(char *argv)
{
	int		i;
	char	*save;

	i = 0;
	save = "--save";
	while (argv[i] == save[i])
	{
		if (argv[i] == '\0' && save[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

/*
** checks if the map argument is correctly given with the right file format
** (.cub). returns 1 if yes, 0 if not.
*/

int	ft_argnamecheck(char *argv)
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

int	ft_error(int option, v_list *cube)
{
	cube->utilities.error = 1;
	if (option == 0)
		return (write(1, "Error\nInvalid argument", 22));
	if (option == 1)
		return (write(1, "Error\nInvalid resolution", 24));
	if (option == 2)
		return (write(1, "Error\nInvalid map file path", 27));
	if (option == 3)
		return (write(1, "Error\nInvalid map file", 22));
	if (option == 4)
		return (write(1, "Error\nInvalid map", 17));
	if (option == 5)
		return (write(1, "Error\nFailed memory allocation", 30));
	if (option == 6)
		return (write(1, "Error\nInvalid minilibX", 22));
	if (option == 7)
		return (write(1, "Error\nPlayer not found", 22));
	return (0);
}
