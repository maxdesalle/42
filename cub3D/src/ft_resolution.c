/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:11:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/11 10:27:08 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_resolution_converter(char *line, v_list *cube)
{
	long	result;

	result = 0;
	while (line[cube->utilities.i] && ((line[cube->utilities.i] >= 9 && line[cube->utilities.i] <= 13)
				|| line[cube->utilities.i] == ' '))
		cube->utilities.i++;
	if (line[cube->utilities.i] == '+' || line[cube->utilities.i] == '-')
		return (ft_error(1));
	while (line[cube->utilities.i] && (line[cube->utilities.i] >= '0' && line[cube->utilities.i] <= '9'))
		result = result * 10 + (line[cube->utilities.i++] - '0');
	cube->utilities.i += 1;
	return (result);
}

void	ft_resolution(char *line, v_list *cube)
{
	cube->utilities.i = 0;
	if (line[cube->utilities.i] == 'R')
	{
		cube->utilities.i += 1;
		cube->screenres.Rx = ft_resolution_converter(line, cube);
		cube->screenres.Ry = ft_resolution_converter(line, cube);
	}
}
