/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:56:57 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/24 10:52:42 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_orientation_initiation(v_list *cube)
{
	if (cube->player.orientation == 3)
	{
		cube->ray.dirX = -1;
		cube->ray.planeY = 0.66;
	}
	if (cube->player.orientation == 4)
	{
		cube->ray.dirX = 1;
		cube->ray.planeY = -0.66;
	}
	if (cube->player.orientation == 5)
	{
		cube->ray.dirY = 1;
		cube->ray.planeX = 0.66;
	}
	if (cube->player.orientation == 6)
	{
		cube->ray.dirY = -1;
		cube->ray.planeX = -0.66;
	}
}

static void	ft_camray_initiation(v_list *cube)
{
	cube->ray.cameraX = (2 * cube->ray.raycounter /
			(double)cube->screenres.Rx) - 1;
	cube->ray.rayDirX = cube->ray.dirX +
		(cube->ray.planeX * cube->ray.cameraX);
	cube->ray.rayDirY = cube->ray.dirY +
		(cube->ray.planeY * cube->ray.cameraX);
	cube->ray.deltaDistX = sqrt(1 + ((cube->ray.rayDirY *
			cube->ray.rayDirY) / (cube->ray.rayDirX *
			cube->ray.rayDirX)));
	cube->ray.deltaDistY = sqrt(1 + ((cube->ray.rayDirX *
			cube->ray.rayDirX) / (cube->ray.rayDirY *
			cube->ray.rayDirY)));
	cube->ray.movespeed = 10;
	cube->ray.rotspeed = 0.05;
}

static void	ft_sidedist_calculator(v_list *cube)
{
	if (cube->ray.rayDirX < 0)
	{
		cube->ray.stepX = -1;
		cube->ray.sideDistX = (cube->ray.posX - cube->ray.mapX) *
			cube->ray.deltaDistX;
	}
	else
	{
		cube->ray.stepX = 1;
		cube->ray.sideDistX = (cube->ray.mapX + 1.0 -
			cube->ray.posX) * cube->ray.deltaDistX;
	}
	if (cube->ray.rayDirY < 0)
	{
		cube->ray.stepY = -1;
		cube->ray.sideDistY = (cube->ray.posY - cube->ray.mapY) *
			cube->ray.deltaDistY;
	}
	else
	{
		cube->ray.stepY = 1;
		cube->ray.sideDistY = (cube->ray.mapY + 1.0 -
			cube->ray.posY) * cube->ray.deltaDistY;
	}
}

static void	ft_hit_check(v_list *cube)
{
	while (cube->ray.hit == 0)
	{
		if (cube->ray.sideDistX < cube->ray.sideDistY)
		{
			cube->ray.sideDistX += cube->ray.deltaDistX;
			cube->ray.mapX += cube->ray.stepX;
			cube->ray.side = 0;
		}
		else
		{
			cube->ray.sideDistY += cube->ray.deltaDistY;
			cube->ray.mapY += cube->ray.stepY;
			cube->ray.side = 1;
		}
		if (cube->map[cube->ray.mapX][cube->ray.mapY] == 1)
			cube->ray.hit = 1;
	}
}

void		ft_visual_initiation(v_list *cube)
{
	ft_orientation_initiation(cube);
	ft_camray_initiation(cube);
	ft_sidedist_calculator(cube);
	ft_hit_check(cube);
}
