/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 09:11:06 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/25 10:18:13 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_height(v_list *cube)
{
	if (cube->ray.side == 0)
		cube->ray.perpwalldist = (cube->ray.mapX - cube->ray.posX +
			(1 - cube->ray.stepX) / 2) / cube->ray.rayDirX;
	else if (cube->ray.side == 1)
		cube->ray.perpwalldist = (cube->ray.mapY - cube->ray.posY +
			(1 - cube->ray.stepY) / 2) / cube->ray.rayDirY;
	cube->ray.lineheight =
		(int)(cube->screenres.Ry / cube->ray.perpwalldist);
	cube->ray.drawstart =
		-cube->ray.lineheight / 2 + cube->screenres.Ry / 2;
	if (cube->ray.drawstart < 0)
		cube->ray.drawstart = 0;
	cube->ray.drawend = cube->ray.lineheight / 2 + cube->screenres.Ry / 2;
	if (cube->ray.drawend >= cube->screenres.Ry)
		cube->ray.drawend = cube->screenres.Ry - 1;
}

void	ft_delta(v_list *cube)
{
	if (cube->ray.rayDirY == 0)
	{
		cube->ray.deltaDistX = 0;
		cube->ray.deltaDistY = 1;
	}
	if (cube->ray.rayDirX == 0)
	{
		cube->ray.deltaDistX = 1;
		cube->ray.deltaDistY = 0;
	}
	else
	{
		cube->ray.deltaDistX = sqrt(1 + (cube->ray.rayDirY *
			cube->ray.rayDirY) / (cube->ray.rayDirX *
			cube->ray.rayDirX));
		cube->ray.deltaDistY = sqrt(1 + (cube->ray.rayDirX *
			cube->ray.rayDirX) / (cube->ray.rayDirY *
			cube->ray.rayDirY));
	}
}
