/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 08:38:21 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/02 08:45:45 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_map_allocator(v_list *cube)
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

int	ft_map(v_list *cube)
{
	ft_map_allocator(cube);
	return (0);
}
