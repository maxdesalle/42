/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:11:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/05 10:30:47 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_resolution_converter(char *line, v_list *cube)
{
	long	result;

	result = 0;
	while (line[cube->i] && ((line[cube->i] >= 9 && line[cube->i] <= 13)
				|| line[cube->i] == ' '))
		cube->i++;
	if (line[cube->i] == '+' || line[cube->i] == '-')
		return (ft_error(1));
	while (line[cube->i] && (line[cube->i] >= '0' && line[cube->i] <= '9'))
		result = result * 10 + (line[cube->i++] - '0');
	cube->i += 1;
	return (result);
}

void	ft_resolution(char *line, v_list *cube)
{
	cube->i = 0;
	if (line[cube->i] == 'R')
	{
		cube->i += 1;
		cube->Rx = ft_resolution_converter(line, cube);
		cube->Ry = ft_resolution_converter(line, cube);
	}
}
