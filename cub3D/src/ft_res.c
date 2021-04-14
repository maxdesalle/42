/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 08:07:18 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/14 10:30:47 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* saves the resolution in the c struct using an atoi-like function */

static int	ft_resvert(char *line, t_list *c)
{
	int		i;
	long	result;

	i = c->uti.i - 1;
	result = 0;
	while (line[i] && !(line[i] >= '0' && line[i] <= '9'))
		i++;
	if (line[i] == '\0')
		return (ft_error(1, c));
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

/* checks if there are three commas with numbers in between */

static int	ft_comma(char *line, t_list *c)
{
	int	i;
	int	counter;

	i = c->uti.i;
	counter = 0;
	while (line[++i])
		if (line[i] != ' ' && line[i] != ',' && !(line[i] >= '0'
				&& line[i] <= '9')
			&& !(line[i] >= 9 && line[i] <= 13))
			return (ft_error(9, c));
	i = -1;
	while (line[++i] && !(line[i] >= '0' && line[i] <= '9'))
		if (line[i] == ',')
			return (ft_error(9, c));
	i = -1;
	while (line[++i])
		if (line[i] == ',')
			counter += 1;
	if (counter != 2)
		return (ft_error(9, c));
	return (0);
}

/* converts the color values in the .cub file in three separate values to
 * maintain the rgb values */

static int	ft_ceiling(char *line, t_list *c)
{
	int	i;
	int	result;
	int	counter;

	i = c->uti.i;
	counter = 0;
	ft_comma(line, c);
	while (counter < 3 && line[++i])
	{
		result = 0;
		while (!(line[i] >= '0' && line[i] <= '9'))
			i++;
		while ((line[i] >= '0' && line[i] <= '9') && line[i] != ',')
			result = result * 10 + (line[i++] - '0');
		if (result > 255)
			return (ft_error(9, c));
		if (counter == 0)
			c->fc.cre = result;
		else if (counter == 1)
			c->fc.cgr = result;
		else if (counter == 2)
			c->fc.cbl = result;
		counter++;
	}
	return (1);
}

/* converts the color values in the .cub file in three sperate values to
 * maintain the rgb values */

static int	ft_floor(char *line, t_list *c)
{
	int	i;
	int	result;
	int	counter;

	i = c->uti.i;
	counter = 0;
	ft_comma(line, c);
	while (counter < 3 && line[++i])
	{
		result = 0;
		while (!(line[i] >= '0' && line[i] <= '9'))
			i++;
		while ((line[i] >= '0' && line[i] <= '9') && line[i] != ',')
			result = result * 10 + (line[i++] - '0');
		if (result > 255)
			return (ft_error(9, c));
		if (counter == 0)
			c->fc.fre = result;
		else if (counter == 1)
			c->fc.fgr = result;
		else if (counter == 2)
			c->fc.fbl = result;
		counter++;
	}
	return (1);
}

/* checks if the indicating letter .cub line and redirects to the right
 * functions */

void	ft_res(char *line, t_list *c)
{
	int	i;

	i = 0;
	c->uti.i = 0;
	while (line[c->uti.i] && (line[c->uti.i] == ' '
			|| (line[c->uti.i] >= 9 && line[c->uti.i] <= 13)))
		c->uti.i++;
	if (line[c->uti.i] == 'R')
	{
		c->uti.r += 1;
		c->uti.i += 1;
		i = c->uti.i - 1;
		while (line[++i])
			if (!(line[i] >= 9 && line[i] <= 13) && line[i] != ' '
				&& !(line[i] >= '0' && line[i] <= '9'))
				ft_error(1, c);
		c->res.rx = ft_resvert(line, c);
		c->res.ry = ft_resvert(line, c);
	}
	else if (line[c->uti.i] == 'C')
		c->uti.c += ft_ceiling(line, c);
	else if (line[c->uti.i] == 'F')
		c->uti.f += ft_floor(line, c);
	else
		ft_param(line, c->uti.i, c);
}
