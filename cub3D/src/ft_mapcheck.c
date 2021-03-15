/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/22 11:53:12 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

static int	ft_mapspace(char *line)
{
	int	i;
	
	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

int	ft_mapvalid(char *line, v_list *cube)
{
	int	i;

	i = 0;
	if (ft_mapspace(line) == 0)
		return (0);
	if (ft_strchr(line, '1') || ft_strchr(line, '0'))
	{
		while (line[i] != '\0')
		{
			if (!(line[i] == ' ' || line[i] == '0' || line[i] == '1'
			|| line[i] == '2' || line[i] == '\n' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
			|| line[i] == '\t'))
			{
				if (cube->utilities.mapstart == 1 && cube->utilities.check == 1)
					return (ft_error(4, cube));
				return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_mapsize(char *line, v_list *cube)
{
	if (ft_mapvalid(line, cube) == 1)
	{
		if (cube->utilities.check == 1)
			cube->utilities.mapstart = 1;
		cube->utilities.nboflines += 1;
		cube->utilities.linelength = ft_strlen_alpha(line);
	}
	return (0);
}

static int	ft_player_orientation(v_list *cube, int i, int j)
{
	if (cube->map[j][i] == 3)
		cube->player.orientation = 3;
	if (cube->map[j][i] == 4)
		cube->player.orientation = 4;
	if (cube->map[j][i] == 5)
		cube->player.orientation = 5;
	if (cube->map[j][i] == 6)
		cube->player.orientation = 6;
	return (0);
}

int	ft_player_position(v_list *cube)
{
	int	i;
	int	j;

	j = 0;
	while (j < cube->utilities.nboflines)
	{
		i = 0;
		while (i < cube->utilities.linelength)
		{
			if (cube->map[j][i] > 2)
			{
				cube->player.Px = i;
				cube->player.Py = j;
				cube->ray.posX = (double)i + 0.5;
				cube->ray.posY = (double)j + 0.5;
				ft_player_orientation(cube, i, j);
				cube->map[j][i] = 0;
			}
			i++;
		}
		j++;
	}
	return (0);
}
