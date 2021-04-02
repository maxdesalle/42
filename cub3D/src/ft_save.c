/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@s19.be>                  +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 09:59:55 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/02 09:44:34 by mdesalle         ###   ########.fr       */
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

static void	ft_fhead(t_list *c, int fd)
{
	int	fhead;

	write(fd, "BM", 2);
	fhead = 54 + 4 * c->res.rx * c->res.ry;
	write(fd, &fhead, 4);
	fhead = 0;
	write(fd, &fhead, 2);
	write(fd, &fhead, 2);
	fhead = 54;
	write(fd, &fhead, 4);
}

/*
** first write on 4 bytes the size of the infoheader (40)
** then write the width and afterwards the height on 4 bytes
** now write 1 on two bytes
** and write the number of of bits a pixel takes on 2 bytes
** finish by writing 6 times the 0 value on 4 bytes
*/

static void	ft_ihead(t_list *c, int fd)
{
	int	ihead;

	ihead = 40;
	write(fd, &ihead, 4);
	write(fd, &c->res.rx, 4);
	write(fd, &c->res.ry, 4);
	ihead = 1;
	write(fd, &ihead, 2);
	write(fd, &c->mlx.bpp, 2);
	ihead = 0;
	write(fd, &ihead, 4);
	write(fd, &ihead, 4);
	write(fd, &ihead, 4);
	write(fd, &ihead, 4);
	write(fd, &ihead, 4);
	write(fd, &ihead, 4);
}

/*
** use the open function to create a new file and have the right permissions
** start the while loop with the height and decrease the value at each cycle
** it can't be done anohter way, because the image will be the other way around
** for each row, we process all the columns by initializing i to -1
** in the column processing, write the value of the address of the mlx loop
*/

int	ft_save(t_list *c)
{
	int	i;
	int	j;
	int	fd;

	j = c->res.ry;
	fd = open("save.bmp", O_CREAT | O_WRONLY | O_TRUNC, 77777);
	if (fd == -1)
		return (ft_error(8, c));
	ft_fhead(c, fd);
	ft_ihead(c, fd);
	while (--j >= 0)
	{
		i = -1;
		while (++i < c->res.rx)
			write(fd, &c->mlx.adr[j * c->mlx.sl / 4 + i], 4);
	}
	close(fd);
	ft_exit(c);
	return (0);
}
