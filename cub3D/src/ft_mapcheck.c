/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/02 09:25:51 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_mapvalid(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '0' || line[i] == '1'
				|| line[i] == '2' || line[i] == '\n')
			i++;
		else
			return (-1);
	}
	return (1);
}


int	ft_mapsize(char *line, v_list *cube)
{
	if (ft_mapvalid(line) == 1)
	{
		cube->nboflines += 1;
		cube->linelength = ft_strlen(line);
	}
	else
		return (ft_error(4));
	return (0);
}
