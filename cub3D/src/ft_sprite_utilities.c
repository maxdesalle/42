/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 21:51:28 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/02 21:52:21 by mdesalle         ###   ########.fr       */
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

static int	ft_sprite_malloc(v_list *cube)
{
	if (!(cube->sprite.Sx = malloc(cube->sprite.spritecounter * sizeof(double))))
		return (ft_error(5, cube));
	if (!(cube->sprite.Sy = malloc(cube->sprite.spritecounter * sizeof(double))))
		return (ft_error(5, cube));
	if (!(cube->sprite.spritedistance = malloc(cube->sprite.spritecounter * sizeof(double))))
		return (ft_error(5, cube));
	if (!(cube->sprite.spriteorder = malloc(cube->sprite.spritecounter * sizeof(double))))
		return (ft_error(5, cube));
	if (!(cube->sprite.zbuffer = malloc(cube->screenres.Rx * sizeof(double))))
		return (ft_error(5, cube));
	return (0);
}

int	ft_sprite_position(v_list *cube)
{
	int	i;
	int	j;
	int	k;

	ft_spritecounter(cube);
	ft_sprite_malloc(cube);
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

void	ft_sprite_sort(v_list *cube)
{
	int	i;
	int	j;
	double	k;

	j = -1;
	ft_sprite_order(cube);
	while (++j < cube->sprite.spritecounter)
	{
		i = -1;
		while (++i < cube->sprite.spritecounter - 1)
		{
			if (cube->sprite.spritedistance[i] < cube->sprite.spritedistance[i + 1])
			{
				k = cube->sprite.spritedistance[i];
				cube->sprite.spritedistance[i] = cube->sprite.spritedistance[i + 1];
				cube->sprite.spritedistance[i + 1] = k;
				k = cube->sprite.spriteorder[i];
				cube->sprite.spriteorder[i] = cube->sprite.spriteorder[i + 1];
				cube->sprite.spriteorder[i + 1] = (int)k;
			}
		}
	}
}
