/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:02 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/31 18:54:24 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_path_converter(int option, char *line, v_list *cube)
{
	int	i;
	int	j;
	char	*str;

	i = 0;
	while (line[i] != '.')
		i++;
	if (line[i] == '.')
	{
		j = ft_strlen(line) - i;
		str = ft_substr(line, i, j);
		/* unfinished */
	}
}

void	ft_textures(char *line, v_list *cube)
{
	int	i;

	if (line[i] == 'N' && line[i + 1] == 'O')
		ft_path_converter(1, line, cube);
	if (line[i] == 'S' && line[i + 1] == 'O')
                ft_path_converter(2, line, cube);
	if (line[i] == 'W' && line[i + 1] == 'E')
                ft_path_converter(3, line, cube);
	if (line[i] == 'E' && line[i + 1] == 'A')
                ft_path_converter(4, line, cube);
	if (line[i] == 'S' && line[i + 1] == ' ')
		ft_path_converter(5, line, cube);
}
