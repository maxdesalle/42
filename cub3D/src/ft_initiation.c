/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:06:59 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/01 16:26:37 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_compute(v_list *cube)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (!(cube->mlx.texture[i].img_ptr = mlx_xpm_file_to_image(
					cube->mlx.mlx_ptr,
					cube->mlx.texture[i].path,
					&cube->mlx.texture[i].width,
					&cube->mlx.texture[i].height)))
			return (ft_error(6, cube));
		if (!(cube->mlx.texture[i].addr = (int *)mlx_get_data_addr(
					cube->mlx.texture[i].img_ptr,
					&cube->mlx.texture[i].bits_per_pixel,
					&cube->mlx.texture[i].size_line,
					&cube->mlx.texture[i].endian)))
			return (ft_error(6, cube));
		i++;
	}
	return (0);
}

int	ft_visual(v_list *cube)
{
	cube->ray.raycounter = 0;
	while (cube->ray.raycounter < cube->screenres.Rx)
	{
		ft_visual_initiation(cube);
		ft_texture_place(cube);
		ft_sprite_display(cube);
		cube->ray.raycounter++;
	}
	mlx_put_image_to_window(cube->mlx.mlx_ptr, cube->mlx.win_ptr,
			cube->mlx.img_ptr, 0, 0);
	return (0);
}

static int	ft_mlx_start(v_list *cube)
{
	mlx_hook(cube->mlx.win_ptr, 2, 0, ft_keycode, cube);
	mlx_loop_hook(cube->mlx.mlx_ptr, ft_visual, cube);
/*	mlx_hook(cube->mlx.mlx_ptr, 17, 0, ft_exit, cube);*/
	mlx_loop(cube->mlx.mlx_ptr);
	return (0);
}

int	ft_initiation(v_list *cube)
{
	if (cube->utilities.error == 1)
		return (0);
	ft_orientation_initiation(cube);
	if (!(cube->mlx.mlx_ptr = mlx_init()))
		return (ft_error(6, cube));
	mlx_get_screen_size(cube->mlx.mlx_ptr,
			&cube->screenres.Sx, &cube->screenres.Sy);
	if (cube->screenres.Rx > cube->screenres.Sx)
		cube->screenres.Rx = cube->screenres.Sx;
	if (cube->screenres.Ry > cube->screenres.Sy)
		cube->screenres.Ry = cube->screenres.Sy;
	ft_compute(cube);
	if (!(cube->mlx.img_ptr = mlx_new_image(cube->mlx.mlx_ptr, cube->screenres.Rx,
			cube->screenres.Ry)))
		return (ft_error(6, cube));
	if (!(cube->mlx.addr = (int *)mlx_get_data_addr(cube->mlx.img_ptr,
			&cube->mlx.bits_per_pixel, &cube->mlx.size_line,
			&cube->mlx.endian)))
		return (ft_error(6, cube));
	if (!(cube->mlx.win_ptr = mlx_new_window(cube->mlx.mlx_ptr,
			cube->screenres.Rx, cube->screenres.Ry, "Cub3D")))
		return (ft_error(6, cube));
	ft_mlx_start(cube);
	return (0);
}
