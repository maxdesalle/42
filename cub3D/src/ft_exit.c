/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:14:05 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/25 10:21:05 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_exit(v_list *c)
{
	c->uti.ext = 1;
	ft_mfree(cube);
	free(c->spr.sx);
	free(c->spr.sy);
	free(c->spr.spd);
	free(c->spr.spo);
	free(c->spr.zbf);
	if (c->mlx.img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.img);
	if (c->tex[0].img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.tex[0].img);
	if (c->tex[1].img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.tex[1].img);
	if (c->tex[2].img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.tex[2].img);
	if (c->tex[3].img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.tex[3].img);
	if (c->tex[4].img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.tex[4].img);
	if (c->mlx.win)
		mlx_destroy_window(c->mlx.mlx, c->mlx.win);
	exit(0);
	return (0);
}
