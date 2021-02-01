/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/01 14:34:52 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_map(char *line, v_list *cube)
{
	ft_map_converter(char *line);
	if (ft_map_valid(line, cube) == 1)

}

static int	ft_mapvalid(char *line, v_list *cube)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '0' || line[i] == '1'
				line[i] == '2' || line[i] == '\n')
			i++;
		else
			return (ft_error(4));
	}
	return (0);
}


int	ft_mapsize(char *line, v_list *cube)
{
	static int	nboflines;
	static int	linelength;

	if (ft_mapvalid(line, cube))
	{

