/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:15:27 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/15 15:34:48 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* detects key presses and calls the required functions */

void	ft_start(t_list *c)
{
	c->uti.ext = 0;
	c->uti.stt = 1;
	mlx_hook(c->mlx.win, 17, 0, ft_exit, c);
	mlx_hook(c->mlx.win, 2, 0, ft_key, c);
	mlx_loop_hook(c->mlx.mlx, ft_raycast, c);
	mlx_loop(c->mlx.mlx);
}

/* assigns the address and struct image pointer to the right texture */

int	ft_compute(t_list *c)
{
	int	i;

	i = -1;
	ft_dparam(c);
	if (c->fc.cre == -1 || c->fc.cgr == -1 || c->fc.cbl == -1
		|| c->fc.fre == -1 || c->fc.fgr == -1 || c->fc.fbl == -1)
		return (ft_error(9, c));
	while (++i <= 4)
	{
		c->tex[i].img = mlx_xpm_file_to_image(c->mlx.mlx,
				c->tex[i].pth, &c->tex[i].wdh, &c->tex[i].hgt);
		if (!(c->tex[i].img))
			return (ft_error(6, c));
		c->tex[i].adr = (unsigned int *)mlx_get_data_addr(
				c->tex[i].img, &c->tex[i].bpp, &c->tex[i].sl,
				&c->tex[i].end);
		if (!(c->tex[i].adr))
			return (ft_error(6, c));
	}
	return (0);
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
