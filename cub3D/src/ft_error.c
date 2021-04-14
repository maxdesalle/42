/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:48:54 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/14 10:37:33 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_parinit(t_list *c)
{
	c->uti.s = 0;
	c->uti.r = 0;
	c->uti.f = 0;
	c->uti.c = 0;
	c->uti.so = 0;
	c->uti.no = 0;
	c->uti.we = 0;
	c->uti.ea = 0;
}

int	ft_dparam(t_list *c)
{
	if (c->uti.r != 1 || c->uti.s != 1 || c->uti.f != 1 || c->uti.c != 1
		|| c->uti.so != 1 || c->uti.no != 1 || c->uti.we != 1
		|| c->uti.ea != 1)
		return (ft_error(9, c));
	return (0);
}

int	ft_param(char *line, int i, t_list *c)
{
	if (line[i] != 'S' && line[i] != 'W' && line[i] != 'N'
		&& line[i] != 'E' && line[i] != 'R' && line[i] != 'C'
		&& line[i] != 'F' && line[i] != '1' && line[i] != '\0')
		return (ft_error(3, c));
	return (0);
}

int	ft_terror(t_list *c)
{
	int	i;
	int	j;

	i = -1;
	if (c->res.rx <= 0 || c->res.ry <= 0)
		return (ft_error(9, c));
	while (++i <= 4)
	{
		if (c->uti.pth[i] == 0)
			return (ft_error(9, c));
		j = ft_strlen(c->tex[i].pth) - 4;
		if (c->tex[i].pth[j] != '.' || c->tex[i].pth[j + 1] != 'x'
			|| c->tex[i].pth[j + 2] != 'p'
			|| c->tex[i].pth[j + 3] != 'm')
		{
			c->uti.ult = 1;
			return (ft_error(9, c));
		}
	}
	return (0);
}

/*
** returns an error based on the given option.
*/

int	ft_error(int option, t_list *c)
{
	c->uti.err = 1;
	if (option == 0)
		write(1, "Error\nInvalid argument\n", 23);
	if (option == 1)
		write(1, "Error\nInvalid resolution\n", 25);
	if (option == 2)
		write(1, "Error\nInvalid map file path\n", 28);
	if (option == 3)
		write(1, "Error\nInvalid map file\n", 23);
	if (option == 4)
		write(1, "Error\nInvalid map\n", 18);
	if (option == 5)
		write(1, "Error\nFailed memory allocation\n", 31);
	if (option == 6)
		write(1, "Error\nInvalid minilibX\n", 23);
	if (option == 7)
		write(1, "Error\nPlayer not found\n", 24);
	if (option == 8)
		write(1, "Error\nImage file could not be created\n", 38);
	if (option == 9)
		write(1, "Error\nTexture could not be loaded\n", 34);
	ft_exit(c);
	return (0);
}
