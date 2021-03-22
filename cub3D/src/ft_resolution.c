/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:11:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/28 11:58:44 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

static int	ft_resolution_converter(char *line, v_list *cube)
{
	long	result;

	result = 0;
	while (line[cube->utilities.i] && ((line[cube->utilities.i] >= 9 &&
		line[cube->utilities.i] <= 13)
		|| line[cube->utilities.i] == ' '))
		cube->utilities.i++;
	if (line[cube->utilities.i] == '+' || line[cube->utilities.i] == '-')
		return (ft_error(1, cube));
	while (line[cube->utilities.i] && (line[cube->utilities.i] >= '0'
		&& line[cube->utilities.i] <= '9'))
		result = result * 10 + (line[cube->utilities.i++] - '0');
	cube->utilities.i += 1;
	return (result);
}

static int	ft_fc_check(char *line, int result, v_list *cube)
{
	int	i;
	int	counter;

	i = 1;
	counter = 0;
	while (line[i] && (((line[i] >= '0' && line[i] <= '9') ||
		line[i] == ',' || line[i] == ' ' ||
		(line[i] >= 9 && line[i] <= 13))))
		if (line[i++] == ',')
			counter++;
	if (result > 255255255 || result < 0 || counter != 2)
		return (ft_error(4, cube));
	return (0);
}

static int	ft_floor_ceiling(char *line, v_list *cube, int option)
{
	int	i;
	int	result;

	i = 1;
	result = 0;
	while (line[i] != '\0' && (line[i] == ',' || (line[i] == ' ')
			|| (line[i] >= 9 && line[i] <= 13)))
	{
		while (!(line[i] >= '0' && line[i] <= '9'))
			i++;
		while (line[i] >= '0' && line[i] <= '9') 
			result = result * 10 + (line[i++] - '0');
	}
	if (option == CEILING)
		cube->texture_path.C = result;
	else if (option == FLOOR)
		cube->texture_path.F = result;
	ft_fc_check(line, result, cube);
	return (0);
}

void	ft_resolution(char *line, v_list *cube)
{
	cube->utilities.i = 1;
	if (line[0] == 'R')
	{
		cube->screenres.Rx = ft_resolution_converter(line, cube);
		cube->screenres.Ry = ft_resolution_converter(line, cube);
	}
	else if (line[0] == 'C')
		ft_floor_ceiling(line, cube, 1);
	else if (line[0] == 'F')
		ft_floor_ceiling(line, cube, -1);
}
