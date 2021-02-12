/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:38:21 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/12 13:05:54 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

/*int	ft_wall_check(v_list *cube)
{
	int	i;

	i = 0;
	while (
	*/

int	ft_map_free(v_list *cube)
{
	int	i;

	i = 0;
	while (cube->utilities.counter > 0)
	{
		free(cube->map[cube->utilities.counter]);
		cube->utilities.counter--;
	}
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
		return (ft_error(5));
	if (!(i < cube->utilities.nboflines))
		return (0);
	while (i < cube->utilities.nboflines)
	{
		if (!(cube->map[i] = malloc(cube->utilities.linelength * sizeof(int))))
			return (ft_error(5));
		i++;
	}
	return (1);
}
