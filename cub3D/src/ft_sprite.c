/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:17:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/02 21:55:13 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_sprite_calc(v_list *cube)
{
         cube->sprite.drawstartY = -cube->sprite.spriteheight / 2 +
                         cube->screenres.Ry / 2;
         cube->sprite.drawendY = cube->sprite.spriteheight / 2 +
                         cube->screenres.Ry / 2;
         if (cube->sprite.drawstartY < 0)
                 cube->sprite.drawstartY = 0;
         if (cube->sprite.drawendY >= cube->screenres.Ry)
                 cube->sprite.drawendY = cube->screenres.Ry - 1;
	 cube->sprite.spritewidth = abs((int)(cube->screenres.Ry /
		cube->sprite.transformY));
	 cube->sprite.drawstartX = -cube->sprite.spritewidth / 2 +
		 cube->sprite.spritescreenX;
	 cube->sprite.drawendX = cube->sprite.spritewidth / 2 +
		 cube->sprite.spritescreenX;
	 if (cube->sprite.drawstartX < 0)
		 cube->sprite.drawstartX = 0;
	 if (cube->sprite.drawstartY >= cube->screenres.Rx)
		 cube->sprite.drawendX = cube->screenres.Rx - 1;
}



static int	ft_sprite_order(v_list *cube)
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

static int	ft_sprite_draw(v_list *cube)
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
	cube->sprite.spriteheight = abs((int)(cube->screenres.Ry /
			cube->sprite.transformY));
	ft_sprite_calc(cube);
	return (cube->sprite.drawstartX);
}

static void	ft_sprite_compute(v_list *cube, int y, int texX, int stripe)
{

}

void	ft_sprite_display(v_list *cube)
{
	int	y;
	int	texX;
	int	stripe;

	cube->utilities.i = 0;
	ft_sprite_order(cube);
	while (cube->utilities.i++ < cube->sprite.spritecounter)
	{
		sprite = ft_sprite_draw(cube);
		while (stripe++ < cube->sprite.drawendX)
		{
			texX = (int)(256 * (stripe - (-cube->sprite.spritewidth
			/ 2 + cube->sprite.spritescreenX)) * cube->
			mlx.texture[4].width / cube->sprite.spritewidth) / 256;
			if (cube->sprite.transformY > 0 && stripe >= 0 &&
			stripe < cube->screenresRx && cube->
			sprite.transformY < cube->sprite.zbuffer[stripe])
			{
				y = cube->sprite.drawstartY;
				while (y++ < cube->sprite.drawendY)
					ft_sprite_compute(cube, y, texX, stripe);
			}
		}
	}
}
