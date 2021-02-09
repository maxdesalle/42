/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 18:06:59 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/09 18:13:23 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_initiation(v_list *cube)
{
	if (!(cube->mlx_ptr = mlx_init()))
		return (ft_error(6));
	mlx_get_screen_size(cube->mlx_ptr, &cube->Sx, &cube->Sy);
	return (0);
}
