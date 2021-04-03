/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:14 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/03 12:17:09 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

/* checks the map value and returns an other one if needed */

static char	ft_return(char a, t_list *c, int j, int i)
{
	if (a == '0' || a == '1' || a == '2')
		return (a);
	else if (a == ' ')
		return ('1');
	else if (a == 'N' || a == 'E' || a == 'S' || a == 'W')
	{
		c->ray.px = (double)i + 0.5;
		c->ray.py = (double)j + 0.5;
		c->map.prx = i;
		c->map.pry = j;
		if (a == 'N')
			c->map.ori = 3;
		else if (a == 'E')
			c->map.ori = 4;
		else if (a == 'S')
			c->map.ori = 5;
		else if (a == 'W')
			c->map.ori = 6;
		return ('0');
	}
	return ('1');
}

/* detects spaces before of after the map bordes compared to the line length */

static void	ft_bawall(char *line, t_list *c)
{
	int	i;

	i = 0;
	while (line[i] != '1' && line[i] != '0' && line[i] != '2')
		c->map.map[c->uti.ctr][i++] = '4';
	c->uti.j = i;
	while (line[i] == '0' || line[i] == '1' || line[i] == '2'
		|| line[i] == ' ' || line[i] == 'N'
		|| line[i] == 'E' || line[i] == 'S'
		|| line[i] == 'W')
		i++;
	c->uti.k = i;
	while (i < c->uti.ll)
		c->map.map[c->uti.ctr][i++] = '4';
}

/* inserts the values read in the .cub file in the map array */

static void	ft_insert(char *line, t_list *c)
{
	int	i;
	int	j;

	j = c->uti.ctr;
	ft_bawall(line, c);
	i = c->uti.j - 1;
	while (line[++i] != '\0' && i < c->uti.k)
		c->map.map[j][i] = ft_return(line[i], c, j, i);
}

/* checks if map line is valid, mallocs it and calls the insert function */

int	ft_map(char *line, t_list *c)
{
	int	j;

	j = c->uti.ctr;
	if (ft_map_valid(line, c) == 1)
	{
		if (j < c->uti.nbl)
			c->map.map[j] = malloc((1 + c->uti.ll) * sizeof(char));
		if (!(c->map.map[j]))
			return (ft_error(5, c));
		ft_insert(line, c);
		c->uti.ctr++;
	}
	return (0);
}
