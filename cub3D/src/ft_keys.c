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
#include <stdio.h>

int	ft_keycode(int keycode, v_list *cube)
{
	if (keycode == A)
		ft_move_horizontal(cube, 0);
	if (keycode == D) 
		ft_move_horizontal(cube, 1);
	else if (keycode == W || keycode == FORWARD)
		ft_move_vertical(cube, 1);
	else if (keycode == S || keycode == BACKWARD)
		ft_move_vertical(cube, 0);
	else if (keycode == ESC)
		ft_exit(cube);
	else if (keycode == RIGHT)
		ft_rotate_right(cube);
	else if (keycode == LEFT)
		ft_rotate_left(cube);
	return (0);
}
