/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:03:57 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/04 21:21:26 by mdesalle         ###   ########.fr       */
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
			if (!(*line == ' ' || *line == '0' || *line == '1' || *line == '2'
					|| *line == 'N' || *line == 'S' || *line == 'E'
					|| *line == 'W' || (*line >= 9 && *line <= 13)))
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

/* counts all the lines, computes the map line length and mallocs it */

int	ft_count(char *mapfile, t_list *c)
{
	char	*line;

	c->uti.fd = open(mapfile, O_RDONLY);
	if (c->uti.fd == -1)
		return (ft_error(3, c));
	while (get_next_line(c->uti.fd, &line) == 1)
	{
		if (ft_map_valid(line, c) == 1 && c->uti.mps != 1)
			c->uti.mps = 1;
		if (c->uti.mps == 1)
		{
			c->uti.nbl++;
			if ((int)ft_strlen(line) > c->uti.ll)
				c->uti.ll = (int)ft_strlen(line);
		}
		free(line);
	}
	close(c->uti.fd);
	c->map.map = malloc(c->uti.nbl * sizeof(char *));
	if (!(c->map.map))
		return (ft_error(5, c));
	return (0);
}

/* checks the vertical borders vertically of the inserted map array */

int	ft_vborder(t_list *c)
{
	int	i;
	int	j;

	j = -1;
	while (++j < c->uti.ll)
	{
		i = -1;
		while (++i < c->uti.nbl && c->map.map[i][j] != '1')
			if (c->map.map[i][j] != '4')
				return (ft_error(4, c));
		i = c->uti.nbl;
		while (--i > 0 && c->map.map[i][j] != '1')
			if (c->map.map[i][j] != '4')
				return (ft_error(4, c));
	}
	return (0);
}

/* checks the vertical borders horizontally of the inserted map array */

int	ft_hborder(t_list *c)
{
	int	i;
	int	j;

	j = -1;
	ft_terror(c);
	while (++j < c->uti.nbl)
	{
		i = -1;
		while (++i < c->uti.ll && c->map.map[j][i] != '1')
			if (c->map.map[j][i] != '4')
				return (ft_error(4, c));
		i = c->uti.ll;
		while (--i > 0 && c->map.map[j][i] != '1')
			if (c->map.map[j][i] != '4')
				return (ft_error(4, c));
	}
	return (0);
}
