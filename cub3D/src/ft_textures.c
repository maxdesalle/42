/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:02 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/01 11:01:33 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_path_converter(int option, char *line, char **texture)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0' && line[i] != '.')
		i++;
	if (line[i] == '.')
	{
		j = ft_strlen(line) - i;
		if (option == 1)
			*texture = ft_substr(line, i, j);
		if (option == 2)
			*texture = ft_substr(line, i, j);
		if (option == 3)
			*texture = ft_substr(line, i, j);
		if (option == 4)
			*texture = ft_substr(line, i, j);
		if (option == 5)
			*texture = ft_substr(line, i, j);
		return (0);
	}
	else
		return (ft_error(2));
}

void	ft_textures(char *line, v_list *cube)
{
	int	i;

	i = 0;
	if (line[i] == 'N' && line[i + 1] == 'O')
		ft_path_converter(1, line, &cube->NO);
	if (line[i] == 'S' && line[i + 1] == 'O')
                ft_path_converter(2, line, &cube->SO);
	if (line[i] == 'W' && line[i + 1] == 'E')
                ft_path_converter(3, line, &cube->WE);
	if (line[i] == 'E' && line[i + 1] == 'A')
                ft_path_converter(4, line, &cube->EA);
	if (line[i] == 'S' && line[i + 1] == ' ')
		ft_path_converter(5, line, &cube->S);
}
