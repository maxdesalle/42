/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:15:27 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/02 10:26:49 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* detects key presses and calls the required functions */

void	ft_start(t_list *c)
{
	c->uti.ext = 0;
	mlx_hook(c->mlx.win, 17, 0, ft_exit, c);
	mlx_hook(c->mlx.win, 2, 0, ft_key, c);
	mlx_loop_hook(c->mlx.mlx, ft_raycast, c);
	mlx_loop(c->mlx.mlx);
}

/* redirects to the right functions when a key is pressed */

int	ft_key(int key, t_list *c)
{
	if (key == A)
		ft_horizontal(c, 0);
	if (key == D)
		ft_horizontal(c, 1);
	if (key == W || key == FORWARD)
		ft_vertical(c, 1);
	if (key == S || key == BACKWARD)
		ft_vertical(c, 0);
	if (key == ESC)
		ft_exit(c);
	if (key == RIGHT)
		ft_rright(c);
	if (key == LEFT)
		ft_rleft(c);
	return (0);
}
