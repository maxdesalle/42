/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 07:56:57 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/23 11:29:49 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_orientation_initiation(v_list *cube)
{
	if (cube->player.orientation == 3)
	{
		cube->ray.dirX = -1;
		cube->ray.planY = 0.66;
	}
	if (cube->player.orientation == 4)
	{
		cube->ray.dirX = 1;
		cube->ray.planY = -0.66;
	}
	if (cube->player.orientation == 5)
	{
		cube->ray.dirY = 1;
		cube->ray.planX = 0.66;
	}
	if (cube->player.orientation == 6)
	{
		cube->ray.dirY = -1;
		cube->ray.planX = -0.66;
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

int		ft_visual_initiation(v_list *cube)
{
	ft_orientation_initiation(cube);
	ft_camray_initiation(cube);

