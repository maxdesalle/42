/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:38:21 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/12 13:39:38 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

int	ft_wall_checker(v_list *cube)
{
	int	i;

	i = 0;
	while (i < cube->utilities.linelength && cube->map[0][i] == 1)
		i++;
	if (i != cube->utilities.linelength)
		return (ft_error(4, cube));
	i = 0;
	while (i < cube->utilities.linelength
			&& cube->map[cube->utilities.nboflines - 1][i] == 1)
		i++;
	if (i != cube->utilities.linelength)
		return (ft_error(4, cube));
	return (1);
}

int	ft_wall_check(v_list *cube)
{
	int	i;

	i = 0;
	if (!(ft_wall_checker(cube)))
		return (ft_error(4, cube));
	while (i++ < (cube->utilities.nboflines - 1))
		if (!(cube->map[i][0] == 1 &&
			cube->map[i][cube->utilities.linelength - 1] == 1))
			return (ft_error(4, cube));
	return (1);
}

int	ft_map_free(v_list *cube)
{
	cube->utilities.nboflines -= 1;
	while (cube->utilities.nboflines > 0)
	{
		free(cube->map[cube->utilities.nboflines]);
		cube->utilities.nboflines--;
	}
	free(cube->map);
	return (0);
}

int	ft_array_insert(char *line, v_list *cube)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[j] != '\0' && line[j] != '\n')
	{
		if (line[j] == ' ')
			j++;
		cube->map[cube->utilities.counter][i] = ft_atoi_char(line[j]);
		i++;
		j++;
	}
	cube->utilities.counter += 1;
	return (0);
}

int	ft_map_allocator(v_list *cube)
{
	int	i;

	i = 0;
	if (!(cube->map = malloc(cube->utilities.nboflines * sizeof(int*))))
		return (ft_error(5, cube));
	if (!(i < cube->utilities.nboflines))
		return (0);
	while (i < cube->utilities.nboflines)
	{
		if (!(cube->map[i] =
			malloc(cube->utilities.linelength * sizeof(int))))
			return (ft_error(5, cube));
		i++;
	}
	return (1);
}
