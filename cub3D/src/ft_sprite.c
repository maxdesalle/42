/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:17:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/02 19:15:27 by mdesalle         ###   ########.fr       */
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

int	ft_sprite_order(v_list *cube)
{
	int	i;

	i = 0;
	while (i++ < cube->sprite.spritecounter)
	{
		cube->sprite.spriteorder[i] = i;
		cube->sprite.spritedistance[i] = ((cube->ray.posX -
			cube->sprite.Sx[i]) * (cube->ray.posX -
			cube->ray.sprite.Sx[i]) + (cube->ray.posY -
			cube->sprite.Sy[i]) * (cube->ray.posY -
			cube->sprite.Sy[i]));
	}
}

int	ft_sprite_draw(v_list *cube)
{
	cube->sprite.spriteX = cube->sprite.Sx[cube->sprite.spriteorder[i]]
		- cube->ray.posX;
	cube->sprite.spriteY = cube->sprite.Sy[cube->sprite.spriteorder[i]]
		- cube->ray.posY;
	cube->sprite.invDet = 1.0 / (cube->ray.planeX * cube->ray.dirY
		- cube->ray.dirX * cube->ray.planeY);
	cube->sprite.transformX = cube->sprite.invDet * (cube->ray.dirY *
			cube->sprite.spriteX - cube->ray.dirX *
			cube->sprite.spriteY);
	cube->sprite.transformY = cube->sprite.invDet * (-cube->ray.planeY *
			cube->sprite.spriteX + cube->ray.planeX *
			cube->sprite.spriteY);
	cube->sprite.spritescreenX = (int)((cube->screenres.Ry / 2) * (1 +
			cube->sprite.transformX / cube->sprite.transformY));
}

int	ft_sprite_position(v_list *cube)
{
	int	i;
	int	j;
	int	k;

	ft_spritecounter(cube);
	if (!(cube->sprite.Sx = malloc(sizeof(double) * cube->sprite.spritecounter)))
		return (ft_error(5));
	if (!(cube->sprite.Sy = malloc(sizeof(double) * cube->sprite.spritecounter)))
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
