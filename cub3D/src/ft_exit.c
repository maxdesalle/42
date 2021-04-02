/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:14:05 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/02 09:43:02 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* frees everything and destroys the mlx images and windows */

int	ft_exit(t_list *c)
{
	ft_mfree(c);
	free(c->spr.sx);
	free(c->spr.sy);
	free(c->spr.spd);
	free(c->spr.spo);
	free(c->spr.zbf);
	if (c->mlx.img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.img);
	if (c->mlx.isp)
		mlx_destroy_image(c->mlx.mlx, c->mlx.isp);
	if (c->tex[0].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[0].img);
	if (c->tex[1].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[1].img);
	if (c->tex[2].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[2].img);
	if (c->tex[3].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[3].img);
	if (c->tex[4].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[4].img);
	if (c->mlx.win)
		mlx_destroy_window(c->mlx.mlx, c->mlx.win);
	exit(0);
	return (0);
}
