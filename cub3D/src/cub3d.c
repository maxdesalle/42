/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:54:41 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/25 10:32:01 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_compute(v_list *c)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		c->tex[i].img = mlx_xpm_file_to_image( c->mlx.mlx,
			c->tex[i].pth, &c->tex[i].wdh, &c->tex[i].hgt);
		if (!(c->tex[i].img))
			return (ft_error(6, c));
		c->tex[i].adr = (unsigned int *)mlx_get_data_addr(c->tex[i]
			.img, &c->tex[i].bpp, &c->tex[i].sl, &c->tex[i].end);
		if (!(c->tex[i].adr))
			return (ft_error(6, c));
		i++;
	}
	return (0);
}

static int	ft_raycast(v_list *c)
{
	if (c->uti.ext == 0)
		return (0) ;
	c->ray.rc = 0;
	while (c->ray.rc < c->res.rx)
	{
		ft_visinit(c);
		ft_texplace(c);
		c->spr.zbf[c->ray.rc] = c->ray.prp;
		c->ray.rc++;
	}
	ft_sprisual(c);
	if (c->uti.sve == 1)
		ft_save(c);
	mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->mlx.img, 0, 0);
	ft_swap(c);
	return (0);
}

static int	ft_mlx(v_list *c)
{
	if (c->uti.err == 1)
		return (0);
	ft_orinit(c);
	ft_compute(c);
	c->mlx.mlx = mlx_init();
	if (!(c->mlx.mlx))
		return (ft_error(6, c));
	mlx_get_screen_size(c->mlx.mlx, &c->res.sx, &c->res.sy);
	if (c->res.rx > c->res.sx)
		c->res.rx = c->res.sx;
	if (c->res.ry > c->res.sy)
		c->res.ry = c->res.sy;
	c->mlx.img = mlx_new_image(c->mlx.mlx, c->res.rx, c->res.ry);
	c->mlx.adr = (unsigned int *)mlx_get_data_addr(c->mlx.img,
			&c->mlx.bpp, &c->mlx.sl, &c->mlx.end);
	if (c->uti.sve == 1)
		ft_raycast(c);
	c->mlx.win = mlx_new_window(c->mlx.mlx, c->res.rx, c->res.ry, "Cub3D");
	c->mlx.isp = mlx_new_image(c->mlx.mlx, c->res.rx, c->res.ry);
	c->mlx.asp = (unsigned int *)mlx_get_data_addr(c->mlx.isp,
			&c->mlx.bpp, &c->mlx.sl, &c->mlx.end);
	ft_start(c);
	return (0);
}

static int	ft_analytics(char *mapfile, v_list *c)
{
	int		fd;
	char	*line;

	ft_init(c);
	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		return (ft_error(3, c));
	while (get_next_line(fd, &line) == 1)
	{
		ft_res(line, c);
		if (ft_map_valid(line, c) == 1)
			ft_map(line, c);
		free(line);
	}
	close(fd);
	ft_mlx(c);
	return (0);
}

int	main(int argc, char **argv)
{
	v_list	c;

	if (argc == 2 && ft_argn(argv[1]))
		ft_analytics(argv[1], &c);
	else if (argc == 3 && ft_argn(argv[1]) && ft_args(argv[2], &c))
		ft_analytics(argv[1], &c);
	else
		return (ft_error(0, &c));
	return (0);
}
