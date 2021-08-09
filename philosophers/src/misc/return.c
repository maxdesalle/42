/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:30:22 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/09 12:13:07 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	errtoi(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}

int	error(void)
{
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
