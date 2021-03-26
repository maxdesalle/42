/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 08:07:18 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/26 10:33:37 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

static int	ft_resvert(char *line, v_list *c)
{
	long	result;

	result = 0;
	while (line[c->uti.i] && ((line[c->uti.i] >= 9 && line[c->uti.i] <= 13)
				|| line[c->uti.i] == ' '))
		c->uti.i++;
	if (line[c->uti.i] == '+' || line[c->uti.i] == '-')
		return (ft_error(1, c));
	while (line[c->uti.i] && (line[c->uti.i] >= '0'
				&& line[c->uti.i] <= '9'))
		result = result * 10 + (line[c->uti.i++] - '0');
	c->uti.i++;
	return (result);
}

static void     ft_ceiling(char *line, v_list *c)
{
	int     i;
	int	result;
	int     counter;

	i = 1;
	counter = 0;
	while (counter < 3)
	{
		result = 0;
		while (!(line[i] >= '0' && line[i] <= '9'))
			i++;
		while ((line[i] >= '0' && line[i] <= '9') && line[i] != ',')
			result = result * 10 + (line[i++] - '0');
		if (counter == 0)
			c->fc.cre = result;
		else if (counter == 1)
			c->fc.cgr = result;
		else if (counter == 2)
			c->fc.cbl = result;
		i++;
		counter++;
	}
}

static void     ft_floor(char *line, v_list *c)
{
	int     i;
	int	result;
	int     counter;

	i = 1;
	counter = 0;
	while (counter < 3)
	{
		result = 0;
		while (!(line[i] >= '0' && line[i] <= '9'))
			i++;
		while ((line[i] >= '0' && line[i] <= '9') && line[i] != ',')
			result = result * 10 + (line[i++] - '0');
		if (counter == 0)
			c->fc.fre = result;
		else if (counter == 1)
			c->fc.fgr = result;
		else if (counter == 2)
			c->fc.fbl = result;
		i++;
		counter++;
	}
}

void	ft_res(char *line, v_list *c)
{
	c->uti.i = 1;
	if (line[0] == 'R')
	{
		c->res.rx = ft_resvert(line, c);
		c->res.ry = ft_resvert(line, c);
	}
	else if (line[0] == 'C')
		ft_ceiling(line, c);
	else if (line[0] == 'F')
		ft_floor(line, c);
}
