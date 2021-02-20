/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/20 14:37:02 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_mapvalid(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (!(line[i] == ' ' || line[i] == '0' || line[i] == '1'
				|| line[i] == '2' || line[i] == '\n'
				|| line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W'))
			return (0);
		else
			i++;
	}
	return (1);
}


int	ft_mapsize(char *line, v_list *cube)
{
	if (ft_mapvalid(line) == 1)
	{
		cube->utilities.nboflines += 1;
		cube->utilities.linelength = ft_strlen_alpha(line);
	}
	else if (ft_mapvalid(line) == 0)
		return (0);
	else
		return (ft_error(4));
	return (0);
}

static int	ft_player_orientation(v_list *cube, int i, int j)
{
	if (cube->map[j][i] == 3)
		cube->player.orientation = 0;
	if (cube->map[j][i] == 4)
		cube->player.orientation = 180;
	if (cube->map[j][i] == 5)
		cube->player.orientation = 90;
	if (cube->map[j][i] == 6)
		cube->player.orientation = 270;
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
				cube->player.posX = (double)i + 0.5;
				cube->player.posY = (double)j + 0.5;
				cube->map[j][i] = 0;
				return (ft_player_orientation(cube, i, j));
			}
			i++;
		}
		j++;
	}
	return (ft_error(7));
}
