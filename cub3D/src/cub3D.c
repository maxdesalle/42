/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:16 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/29 09:14:31 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	somefunction(void)
{
	int	something;

	something = 0;
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

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_argnamecheck(argv[1]))
		somefunction();
	else if (argc == 3 && ft_argnamecheck(argv[1])
			&& ft_argsavecheck(argv[2]))
		somefunction();
	else
		return (ft_error(0));
	return (0);
}
