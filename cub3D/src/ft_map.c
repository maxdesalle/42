/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:56:14 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/25 19:23:40 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_map(char *line, v_list *c)
{
	int	i;
	int	j;

	i = 0;
	j = c->uti.ctr;
	if (ft_map_valid(line, c) == 1)
	{
		if (j < c->uti.nbl)
			c->map.map[j] = malloc((1 + c->uti.ll) * sizeof(char));
		if (!(c->map.map[j]))
			return (ft_error(5, c));
		while (line[i++] != '\0')
			c->map[j][i] = line[i];
		while (c->map[j][i++] != '\0')
			c->map[j][i] = '1';
		c->uti.ctr++;
	}
}
