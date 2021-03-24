/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 21:03:57 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/24 21:57:05 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_map_space(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (0);
	return (1);
}

int	ft_map_valid(char *line, v_list *c)
{
	int	i;

	i = 0;
	if (ft_map_space(line) == 0)
		return (0);
	if (ft_strchr(line, '1') || ft_strchr(line, '0'))
	{
		while (line[i] != '\0')
		{
			if (!(line[i] == ' ' || line[i] == '0'
					|| line[i] == '1' || line[i] == '2'
					|| line[i] == 'N' || line[i] == 'S'
					|| line[i] == 'E' || line[i] == 'W'
					|| (line[i] >= 9 && line[i] <= 13)))
			{
				if (c->uti.mps == 1)
					return (ft_error(4, c));
				return (0);
			}
			i++;
		}
		return (1);
	}
}
