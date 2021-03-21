/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@s19.be>                  +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:59:55 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/18 16:34:15 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** first, write the BM letters to indicate that it's a BMP file on two bytes
** then, write on 4 bytes the total size of the file
** now write two times on 2 bytes the 0 value
** finally write the total size of the headers (54) on 4 bytes
**
** source: https://bit.ly/3s30LKB
*/

static void	ft_bmp_fileheader(v_list *cube, int fd)
{
	int	fileheader;

	write(fd, "BM", 2);
	fileheader = 54 + 4 * cube->screenres.Rx * cube->screenres.Ry;
	write(fd, &fileheader, 4);
	fileheader = 0;
	write(fd, &fileheader, 2);
	write(fd, &fileheader, 2);
	fileheader = 54;
	write(fd, &fileheader, 4);
}

/*
** first write on 4 bytes the size of the infoheader (40)
** then write the width and afterwards the height on 4 bytes
** now write 1 on two bytes
** and write the number of of bits a pixel takes on 2 bytes
** finish by writing 6 times the 0 value on 4 bytes
*/

static void	ft_bmp_infoheader(v_list *cube, int fd)
{
	int	infoheader;

	infoheader = 40;
	write(fd, &infoheader, 4);
	write(fd, &cube->screenres.Rx, 4);
	write(fd, &cube->screenres.Ry, 4);
	infoheader = 1;
	write(fd, &infoheader, 2);
	write(fd, &cube->mlx.bits_per_pixel, 2);
	infoheader = 0;
	write(fd, &infoheader, 4);
	write(fd, &infoheader, 4);
	write(fd, &infoheader, 4);
	write(fd, &infoheader, 4);
	write(fd, &infoheader, 4);
	write(fd, &infoheader, 4);
}

/*
** use the open function to create a new file and have the right permissions
** start the while loop with the height and decrease the value at each cycle
** it can't be done anohter way, because the image will be the other way around
** for each row, we process all the columns by initializing i to -1
** in the column processing, write the value of the address of the mlx loop
*/ 

int			ft_save(v_list *cube)
{
	int	i;
	int	j;
	int	fd;

	j = cube->screenres.Ry;
	if ((fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777)) == -1)
		return (ft_error(8, cube));
	ft_bmp_fileheader(cube, fd);
	ft_bmp_infoheader(cube, fd);
	while (--j >= 0)
	{
		i = -1;
		while (++i < cube->screenres.Rx)
			write(fd, &cube->mlx.addr[j * cube->mlx.size_line
					/ 4 + i], 4);
	}
	close(fd);
	ft_exit(cube);
	return (0);
}
