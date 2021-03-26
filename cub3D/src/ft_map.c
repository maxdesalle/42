/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:14 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/26 11:54:52 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

static char	ft_return(char a, v_list *c)
{
	if (a == '0' || a == '1' || a == '2')
		return (a);
	else if (a == ' ')
		return ('1');
	else if (a == 'N' || a == 'E' || a == 'S' || a == 'W')
	{
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

static void	ft_insert(char *line, v_list *c)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = c->uti.ctr;
	while (line[++i] != '\0')
	{
		if (line[i] == '\t')
		{
			k = 8;
			while (k-- > 0)
				c->map.map[j][i++] = '1';
		}
		c->map.map[j][i] = ft_return(line[i], c);
	}
	k = c->uti.ll - i;
	while (k-- > 0)
		c->map.map[j][i++] = '1';
}

int	ft_map(char *line, v_list *c)
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
