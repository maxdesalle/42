/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:17:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/18 09:12:55 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_spritecounter(v_list *cube)
{
	int	i;
	int	j;

	j = 0;
	cube->sprite.spritecounter = 0;
	while (j < cube->utilities.nboflines)
	{
		i = 0;
		while (i < cube->utilities.linelength)
		{
			if (cube->map[j][i] == 2)
				cube->sprite.spritecounter += 1;
			i++;
		}
		j++;
	}
}

int	ft_sprite_position(v_list *cube)
{
	int	i;
	int	j;
	int	k;

	ft_spritecounter(cube);
	if ((!(cube->sprite.Sx = malloc(sizeof(int) * cube->sprite.spritecounter))) ||
	(!(cube->sprite.Sy = malloc(sizeof(int) * cube->sprite.spritecounter))))
		return (ft_error(5));
	j = 0;
	k = 0;
	while (j < cube->utilities.nboflines)
	{
		i = 0;
		while (i < cube->utilities.linelength)
		{
			if (cube->map[j][i] == 2)
			{
				cube->sprite.Sx[k] = (double)i + 0.5;
				cube->sprite.Sy[k] = (double)j + 0.5;
				k++;
			}
			i++;
		}
		j++;
	}
	return (0);
}
