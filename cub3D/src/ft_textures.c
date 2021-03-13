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
#include <stdio.h>

static int	ft_path_converter(char *line, char **texture_path, v_list *cube)
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
		return (ft_error(2, cube));
}

static void	ft_texdir(v_list *cube)
{
	if (cube->ray.side == 0 && cube->ray.rayDirX < 0)
		cube->mlx.texDir = 0;
	if (cube->ray.side == 0 && cube->ray.rayDirX >= 0)
		cube->mlx.texDir = 1;
	if (cube->ray.side == 1 && cube->ray.rayDirY < 0)
		cube->mlx.texDir = 2;
	if (cube->ray.side == 1 && cube->ray.rayDirY >= 0)
		cube->mlx.texDir = 3;
	if (cube->ray.side == 0)
		cube->ray.wallX = cube->ray.posY + cube->ray.perpwalldist
			* cube->ray.rayDirY;
	else
		cube->ray.wallX = cube->ray.posX + cube->ray.perpwalldist
			* cube->ray.rayDirX;
	cube->ray.wallX -= floor((cube->ray.wallX));
}

static void	ft_texture_column(v_list *cube)
{
	int	i;

	i = cube->ray.drawstart;
	ft_texdir(cube);
	cube->ray.step = 1.0 * cube->mlx.texture[0].height / cube->ray.lineheight;
	cube->ray.texX = (int)(cube->ray.wallX *
			(double)cube->mlx.texture[cube->mlx.texDir].width);
	if ((cube->ray.side == 0 && cube->ray.rayDirX > 0) ||
			(cube->ray.side == 1 && cube->ray.rayDirY < 0))
		cube->ray.texX = cube->mlx.texture[cube->mlx.texDir].width
			- cube->ray.texX - 1;
	cube->ray.texPos = (cube->ray.drawstart - cube->screenres.Ry / 2 +
			cube->ray.lineheight / 2) * cube->ray.step;
	while (i <= cube->ray.drawend)
	{
		cube->ray.texY = (int)cube->ray.texPos &
			(cube->mlx.texture[cube->mlx.texDir].height - 1);
		cube->ray.texPos += cube->ray.step;
		cube->mlx.addr[i * cube->mlx.size_line / 4 +
				cube->ray.raycounter] =
				cube->mlx.texture[cube->mlx.texDir].addr[cube->ray.texY
				* cube->mlx.texture[cube->mlx.texDir].size_line / 4
				+ cube->ray.texX];
		i++;
	}

}

void	ft_textures(char *line, v_list *cube)
{
	if (line[0] == 'N' && line[1] == 'O')
		ft_path_converter(line, &cube->mlx.texture[0].path, cube);
	if (line[0] == 'S' && line[1] == 'O')
                ft_path_converter(line, &cube->mlx.texture[1].path, cube);
	if (line[0] == 'W' && line[1] == 'E')
                ft_path_converter(line, &cube->mlx.texture[2].path, cube);
	if (line[0] == 'E' && line[1] == 'A')
                ft_path_converter(line, &cube->mlx.texture[3].path, cube);
	if (line[0] == 'S' && line[1] == ' ')
		ft_path_converter(line, &cube->mlx.texture[4].path, cube);
}

void	ft_texture_place(v_list *cube)
{
	int	i;

	i = 0;
	while (i < cube->ray.drawstart)
	{
		cube->mlx.addr[cube->mlx.size_line / 4 * i + cube->ray.raycounter] =
			(int)cube->texture_path.C;
		i++;
	}
	if (i <= cube->ray.drawend)
		ft_texture_column(cube);
	i = cube->ray.drawend;
	while (i < cube->screenres.Ry)
	{
		cube->mlx.addr[cube->mlx.size_line / 4 * i + cube->ray.raycounter] =
			(int)cube->texture_path.F;
		i++;
	}
}
