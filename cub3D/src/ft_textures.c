/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:02 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/18 11:46:43 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_path_converter(char *line, char **texture_path)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0' && line[i] != '.')
		i++;
	if (line[i] == '.')
	{
		j = ft_strlen(line) - i;
		*texture_path = ft_substr(line, i, j);
		return (0);
	}
	else
		return (ft_error(2));
}

void	ft_textures(char *line, v_list *cube)
{
	if (line[0] == 'N' && line[1] == 'O')
		ft_path_converter(line, &cube->texture_path.NO);
	if (line[0] == 'S' && line[1] == 'O')
                ft_path_converter(line, &cube->texture_path.SO);
	if (line[0] == 'W' && line[1] == 'E')
                ft_path_converter(line, &cube->texture_path.WE);
	if (line[0] == 'E' && line[1] == 'A')
                ft_path_converter(line, &cube->texture_path.EA);
	if (line[0] == 'S' && line[1] == ' ')
		ft_path_converter(line, &cube->texture_path.SP);
}
