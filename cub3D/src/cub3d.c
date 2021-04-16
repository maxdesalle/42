/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:54:41 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/15 15:42:49 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* processes the visuals for every column of pixels, computes the sprites
 * and swaps the image and address with temporary ones to reduce lag */

int	ft_raycast(t_list *c)
{
	if (c->uti.ext == 0)
	{
		c->ray.rc = -1;
		while (++c->ray.rc < c->res.rx)
		{
			ft_visinit(c);
			ft_texplace(c);
			c->spr.zbf[c->ray.rc] = c->ray.prp;
		}
		ft_sprisual(c);
		if (c->uti.sve == 1)
			ft_save(c);
		mlx_put_image_to_window(c->mlx.mlx, c->mlx.win, c->mlx.img, 0, 0);
		ft_swap(c);
	}
	return (0);
}

/* the follow-up function of ft_mlx() */

static int	ft_mlx_alpha(t_list *c)
{
	c->mlx.img = mlx_new_image(c->mlx.mlx, c->res.rx, c->res.ry);
	if (!(c->mlx.img))
		return (ft_error(6, c));
	c->mlx.adr = (unsigned int *)mlx_get_data_addr(c->mlx.img,
			&c->mlx.bpp, &c->mlx.sl, &c->mlx.end);
	if (!(c->mlx.adr))
		return (ft_error(6, c));
	if (c->uti.sve == 1)
		ft_raycast(c);
	c->mlx.win = mlx_new_window(c->mlx.mlx,
			c->res.rx, c->res.ry, "Cub3D");
	if (!(c->mlx.win))
		return (ft_error(6, c));
	c->mlx.isp = mlx_new_image(c->mlx.mlx, c->res.rx, c->res.ry);
	if (!(c->mlx.isp))
		return (ft_error(6, c));
	c->mlx.asp = (unsigned int *)mlx_get_data_addr(c->mlx.isp,
			&c->mlx.bpp, &c->mlx.sl, &c->mlx.end);
	if (!(c->mlx.asp))
		return (ft_error(6, c));
	ft_start(c);
	return (0);
}

/* initiates the mlx pointer, computes the screen size, floor and ceiling
 * colors, and inities all the needed mlx pointers */

static int	ft_mlx(t_list *c)
{
	if (c->uti.err == 1)
		return (0);
	ft_orinit(c);
	c->mlx.mlx = mlx_init();
	if (!(c->mlx.mlx))
		return (ft_error(6, c));
	ft_compute(c);
	mlx_get_screen_size(c->mlx.mlx, &c->res.sx, &c->res.sy);
	if (c->res.rx > c->res.sx)
		c->res.rx = c->res.sx;
	if (c->res.ry > c->res.sy)
		c->res.ry = c->res.sy;
	c->fc.c = 0 << 24 | c->fc.cre << 16 | c->fc.cgr << 8 | c->fc.cbl;
	c->fc.f = 0 << 24 | c->fc.fre << 16 | c->fc.fgr << 8 | c->fc.fbl;
	ft_mlx_alpha(c);
	return (0);
}

/* opens the .cub file, reads and analyzes the files and stores the
 * information in the c struct */

static int	ft_analytics(char *mapfile, t_list *c)
{
	char	*line;

	ft_init(c);
	ft_count(mapfile, c);
	c->uti.chk = 0;
	c->uti.fd = open(mapfile, O_RDONLY);
	if (c->uti.fd == -1)
		return (ft_error(3, c));
	while (get_next_line(c->uti.fd, &line) == 1)
	{
		ft_res(line, c);
		ft_tex(line, c);
		if (ft_map_valid(line, c) == 1)
			ft_map(line, c);
		free(line);
	}
	free(line);
	c->uti.map = 1;
	close(c->uti.fd);
	ft_hborder(c);
	ft_vborder(c);
	ft_sprosition(c);
	ft_remap(c);
	ft_mlx(c);
	return (0);
}

/* does this really need an explainer? */

int	main(int argc, char **argv)
{
	t_list	c;

	c.uti.arg = 0;
	c.res.rx = -1;
	c.res.ry = -1;
	ft_parinit(&c);
	if (argc == 2 && ft_argn(argv[1]))
	{
		c.uti.arg = 1;
		ft_analytics(argv[1], &c);
	}
	else if (argc == 3 && ft_argn(argv[1]) && ft_args(argv[2], &c))
	{
		c.uti.arg = 1;
		ft_analytics(argv[1], &c);
	}
	else
		return (ft_error(0, &c));
}
