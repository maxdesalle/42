/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:16 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/18 11:49:19 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_map_analytics(char *mapfile, v_list *cube)
{
	int	i;
	int	j;
	int	fd;
	char	*line;

	i = 0;
	j = 0;
	cube->utilities.check = 0;
	cube->utilities.mapstart = 0;
	cube->utilities.counter = 0;
	if ((fd = open(mapfile, O_RDONLY)) == -1)
		return (ft_error(3, cube));
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_mapvalid(line, cube) == 1)
			ft_array_insert(line, cube);
		free(line);
	}
	close (fd);
/*	ft_wall_check(cube);*/
	ft_player_position(cube);
	ft_sprite_position(cube);
	ft_initiation(cube);
	return (0);
}

/*
** uses get_next_line to parse the map.cub file and store it inside a set of
** linked lists.
*/

static int	ft_analytics(char *mapfile, v_list *cube)
{
	int		fd;
	char	*line;

	cube->utilities.check = 1;
	cube->utilities.mapstart = 0;
	cube->utilities.nboflines = 0;
	cube->utilities.linelength = 0;
	if ((fd = open(mapfile, O_RDONLY)) == -1)
		return (ft_error(3, cube));
	while (get_next_line(fd, &line) == 1)
	{
		ft_resolution(line, cube);
		ft_textures(line, cube);
		ft_mapsize(line, cube);
		free(line);
	}
	close(fd);
	ft_map_allocator(cube);
	ft_map_analytics(mapfile, cube);
	return (0);
}

/*
** main function. If there are two arguments given (./cub3D map.cub), the
** namecheck functions checks that the map file has the right format (.cub). If
** so, the function calls the initialization function to initialize all the
** flags.
**
** if there are 3 arguments, it checks the file extension and the
** save argument. Otherwise, it returns an error through the ft_error function.
*/

int		main(int argc, char **argv)
{
	v_list	cube;

	if (argc == 2 && ft_argnamecheck(argv[1]))
		ft_analytics(argv[1], &cube);
	else if (argc == 3 && ft_argnamecheck(argv[1])
			&& ft_argsavecheck(argv[2], &cube))
		ft_analytics(argv[1], &cube);
	else
		return (ft_error(0, &cube));
	return (0);
}
