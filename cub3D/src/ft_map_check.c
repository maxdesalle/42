/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:03:57 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/02 09:43:41 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* checks if the map line is only made of spaces */

static int	ft_map_space(char *line)
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

/* checks the validity of the map, and returns an error if needed */

int	ft_map_valid(char *line, t_list *c)
{
	if (ft_map_space(line) == 0)
		return (0);
	if (ft_strchr(line, '1') || ft_strchr(line, '0'))
	{
		while (*line)
		{
			if (!(*line == ' ' || *line == '0'
					|| *line == '1' || *line == '2'
					|| *line == 'N' || *line == 'S'
					|| *line == 'E' || *line == 'W'
					|| (*line >= 9 && *line <= 13)))
			{
				if (c->uti.mps == 1 && c->uti.chk == 1)
					return (ft_error(4, c));
				return (0);
			}
			line++;
		}
		if (c->uti.mps != 1 && c->uti.chk == 1)
			c->uti.mps = 1;
		return (1);
	}
	return (0);
}
