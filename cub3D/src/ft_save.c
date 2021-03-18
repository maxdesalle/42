/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@s19.be>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:59:55 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/18 16:34:15 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_bmp_fileheader(v_list *cube, int stride, int fd)
{
	int	i;
	int	filesize;
	unsigned char	fileheader[14];

	i = 0;
	while (i < 14)
		fileheader[i++] = 0;
	filesize = 14 + 40 + stride * cube->screenres.Ry;
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[10] = (unsigned char)(14 + 40);
	write(fd, fileheader, sizeof(fileheader));
}

static void	ft_bmp_infoheader(v_list *cube, int fd)
{
	int	i;
	unsigned char	infoheader[40];

	i = 0;
	while (i < 40)
		infoheader[i++] = 0;
	infoheader[0] = (unsigned char)(40);
	infoheader[4] = (unsigned char)(cube->screenres.Rx);
	infoheader[5] = (unsigned char)(cube->screenres.Rx >> 8);
	infoheader[6] = (unsigned char)(cube->screenres.Rx >> 16);
	infoheader[7] = (unsigned char)(cube->screenres.Rx >> 24);
	infoheader[8] = (unsigned char)(cube->screenres.Ry);
	infoheader[9] = (unsigned char)(cube->screenres.Ry >> 8);
	infoheader[10] = (unsigned char)(cube->screenres.Ry >> 16);
	infoheader[11] = (unsigned char)(cube->screenres.Ry >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(24);
	write(fd, infoheader, sizeof(infoheader));
}

static void	ft_colorflex(int fd, int rgb)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (unsigned char)((rgb & (0xFF << 16)) / 255 / 255);
	g = (unsigned char)((rgb & (0xFF << 8)) / 255);
	b = (unsigned char)(rgb & 0xFF);
	write(fd, &b, sizeof(b));
	write(fd, &g, sizeof(g));
	write(fd, &r, sizeof(r));
}

int			ft_save(v_list *cube)
{
	int	i;
	int	j;
	int	fd;
	int	rgb;

	j = cube->screenres.Ry;
	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777)) == -1)
		return (ft_error(8, cube));
	ft_bmp_fileheader(cube, (cube->screenres.Rx * 3)
			+ ((4 - (cube->screenres.Rx * 3) % 4) % 4), fd);
	ft_bmp_infoheader(cube, fd);
	while (--j >= 0)
	{
		i = cube->screenres.Rx;
		while (--i >= 0)
		{
			ft_pixel_get(cube, cube->screenres.Rx - i, j, &rgb);
			ft_colorflex(fd, rgb);
		}
	}
	close(fd);
	exit(0);
	return (0);
}

/*static void	ft_header(v_list *cube, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
		tmp = 14 + 40 + 4 * cube->screenres.Rx * cube->screenres.Ry;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &cube->screenres.Rx, 4);
	write(fd, &cube->screenres.Ry, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &cube->mlx.bits_per_pixel, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

int	ft_save(v_list *cube)
{
	int	i;
	int	j;
	int	fd;

	j = cube->screenres.Ry;
	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777)) == -1)
		return (ft_error(8, cube));
	ft_header(cube, fd);
	while (j >= 0)
	{
		i = 0;
		while (i < cube->screenres.Rx)
		{
			write(fd, &cube->mlx.addr[j * cube->mlx.size_line / 4 + i], 4);
			i++;
		}
		j--;
	}
	system("chmod 777 save.bmp");
	exit(0);
	return (0);
}*/
