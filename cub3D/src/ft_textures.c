/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:50:02 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/01 16:33:33 by mdesalle         ###   ########.fr       */
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

static void	ft_texture_column(v_list *cube)
{
	int	i;

	i = cube->ray.drawstart;
	cube->ray.step = 1.0 * cube->mlx.texture[0].height / cube->ray.lineheight;
	cube->ray.texPos = (cube->ray.drawstart - cube->screenres.Ry / 2 +
			cube->ray.lineheight / 2) * cube->ray.step;
	while (i++ <= cube->ray.drawend)
	{
		cube->ray.texY = (int)cube->ray.texPos &
			(cube->mlx.texture[cube->mlx.texDir].height - 1);
		cube->ray.texPos += cube->ray.step;
		cube->mlx.addr[i * cube->mlx.size_line +
			cube->ray.raycounter] =
			cube->mlx.texture[cube->mlx.texDir].addr[cube->ray.texY
			* cube->mlx.texture[cube->mlx.texDir].size_line
			+ cube->ray.texX];
	}

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

void	ft_texture_place(v_list *cube)
{
	int	i;

	i = 0;
/*	while (i++ < cube->ray.drawstart)
		cube->mlx.addr[cube->mlx.size_line * i + cube->ray.raycounter] =
			(int)cube->texture_path.C;*/
	if (i <= cube->ray.drawend)
		ft_texture_column(cube);
	i = cube->ray.drawend;
/*	while (i++ < cube->screenres.Ry)
		cube->mlx.addr[cube->mlx.size_line * i + cube->ray.raycounter] =
			(int)cube->texture_path.F;*/
}
