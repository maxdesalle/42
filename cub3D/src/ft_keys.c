/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 11:27:01 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/20 14:38:22 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_keycode(int keycode, v_list *cube)
{
	if (keycode == A)
		ft_horizontal(cube, 1);
	else if (keycode == D)
		ft_horizontal(cube, 0);
	else if (keycode == W)
		ft_vertical(cube, 1);
	else if (keycode == S)
		ft_vertical(cube, 0);
	else if (keycode == ESC)
		ft_exit(cube);
	else if (keycode == RIGHT)
		ft_rotate(cube, 1);
	else if (keycode == LEFT)
		ft_rotate(cube, 0);
	ft_visual(cube);
	return (0);
}
