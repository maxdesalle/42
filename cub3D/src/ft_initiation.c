/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:06:59 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/14 14:22:18 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_computation(v_list *cube, t_texture *texture, char *texture_path)
{
	if (!(texture->img_ptr = mlx_xpm_file_to_image(
					cube->mlx.mlx_ptr,
					texture_path,
					&texture->width,
					&texture->height)))
		return (ft_error(6));
	if (!(texture->addr = (int *)mlx_get_data_addr(
					texture->img_ptr,
					&texture->bits_per_pixel,
					&texture->size_line,
					&texture->endian)))
		return (ft_error(6));
	return (0);
}

static int	ft_compute(v_list *cube)
{
	ft_computation(cube, &cube->mlx.north, cube->texture_path.NO);
	ft_computation(cube, &cube->mlx.south, cube->texture_path.SO);
	ft_computation(cube, &cube->mlx.west, cube->texture_path.WE);
	ft_computation(cube, &cube->mlx.east, cube->texture_path.EA);
	ft_computation(cube, &cube->mlx.sprite, cube->texture_path.S);
	return (0);
}

int	ft_initiation(v_list *cube)
{
	if (!(cube->mlx.mlx_ptr = mlx_init()))
		return (ft_error(6));
	mlx_get_screen_size(cube->mlx.mlx_ptr,
			&cube->screenres.Sx, &cube->screenres.Sy);
	if (cube->screenres.Rx > cube->screenres.Sx)
		cube->screenres.Rx = cube->screenres.Sx;
	if (cube->screenres.Ry > cube->screenres.Sy)
		cube->screenres.Ry = cube->screenres.Sy;
	ft_compute(cube);
	return (0);
}
