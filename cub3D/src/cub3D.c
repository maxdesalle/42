/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:16 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/27 11:42:43 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/*
** main function. If there are two arguments given (./cub3D map.cub), the
** namecheck functions checks that the map file has the right format (.cub). If
** so, the function calls the initialization function to initialize all the
** flags.
*/

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_namecheck(argv[1]))
		somefunction();
	else if (argc == 3 && ft_argcheck(argv[1], 0) && ft_argcheck(argv[1], 1))
		somefunction();
	else
		return(ft_error(0));
	return (0);
}