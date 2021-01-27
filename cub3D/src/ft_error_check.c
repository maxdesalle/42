/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:16:37 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/27 11:44:41 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/*
** if option 0 is given, the function checks if the file format is equal to
** ".cub". If option 1 is given, it checks if the argument is "--save".
*/

int	ft_argcheck(char *argv, int option)
{
	int		i;
	char	*save;

	i = 0;
	save = "--save";
	if (option == 0)
	{
		i = ft_strlen(argv) - 4;
		if (i > 0 && argv[i] == '.' && argv[i + 1] == 'c' &&
				argv[i + 2] == 'u' && argv[i + 3] == 'b')
			return (1);
		return (0);
	}
	else if (option == 1)
	{
		while (argv[i] == save[i])
		{
			if (argv[i] == '\0' && save[i] == '\0')
				return (1);
			i++;
		}
		return (0);
	}
	else
		return (0);
}


/*
** returns an error based on the given option.
*/

void	ft_error(option)
{
	if (option == 0)
		return (write(1, "Error\nInvalid argument", 23));
}
