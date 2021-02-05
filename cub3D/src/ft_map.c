/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:38:21 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/05 13:51:40 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_map_free(v_list *cube)
{
	int	i;

	i = 0;
	while (cube->counter > 0)
		free(cube->map[cube->counter]);
	return (0);
}

int	ft_array_insert(char *line, v_list *cube)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] == ' ')
			i++;
		cube->map[cube->counter][i] = ft_atoi_char(line[i]);
		i++;
	}
	cube->counter += 1;
	return (0);
}

int	ft_map_allocator(v_list *cube)
{
	int	i;

	i = 0;
	if (!(cube->map = malloc(cube->nboflines * sizeof(int*))))
		return (ft_error(5));
	if (!(i < cube->nboflines))
		return (0);
	while (i < cube->nboflines)
	{
		if (!(cube->map[i] = malloc(cube->linelength * sizeof(int))))
			return (ft_error(5));
		i++;
	}
	return (1);
}
