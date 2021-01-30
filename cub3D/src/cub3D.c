/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:16 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/30 16:39:10 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/*
** uses get_next_line to parse the map.cub file and store it inside a set of
** linked lists.
*/

void	ft_analytics(char *mapfile, v_list *cube)
{
	int		fd;
	int		reader;
	char	*line;

	reader = 1;
	line = NULL;
	fd = open(mapfile, O_RDONLY);
	while (reader == 1)
	{
		reader = get_next_line(fd, &line);
		ft_resolution(&line, cube);
		free(line);
	}
	close(fd);
	return ;
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
			&& ft_argsavecheck(argv[2]))
		ft_analytics(argv[1], &cube);
	else
		return (ft_error(0));
	return (0);
}
