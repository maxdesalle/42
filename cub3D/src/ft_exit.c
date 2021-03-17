/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:26:17 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/18 11:26:47 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_exit(v_list *cube)
{
	cube->utilities.exit = 1;
	ft_map_free(cube);
	free(cube->sprite.Sx);
	free(cube->sprite.Sy);
	free(cube->sprite.spritedistance);
	free(cube->sprite.spriteorder);
	free(cube->sprite.zbuffer);
	if (cube->mlx.img_ptr)
		mlx_destroy_image(cube->mlx.mlx_ptr, cube->mlx.img_ptr);
	if (cube->mlx.texture[0].img_ptr)
		mlx_destroy_image(cube->mlx.mlx_ptr, cube->mlx.texture[0].img_ptr);
	if (cube->mlx.texture[1].img_ptr)
		mlx_destroy_image(cube->mlx.mlx_ptr, cube->mlx.texture[1].img_ptr);
	if (cube->mlx.texture[2].img_ptr)
		mlx_destroy_image(cube->mlx.mlx_ptr, cube->mlx.texture[2].img_ptr);
	if (cube->mlx.texture[3].img_ptr)
		mlx_destroy_image(cube->mlx.mlx_ptr, cube->mlx.texture[3].img_ptr);
	if (cube->mlx.texture[4].img_ptr)
		mlx_destroy_image(cube->mlx.mlx_ptr, cube->mlx.texture[4].img_ptr);
	if (cube->mlx.win_ptr)
		mlx_destroy_window(cube->mlx.mlx_ptr, cube->mlx.win_ptr);
	exit(0);
	return (0);
}
