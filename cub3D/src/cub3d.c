/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:54:41 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/24 21:47:54 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
