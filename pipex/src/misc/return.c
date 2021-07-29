/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:17:08 by maxdesall         #+#    #+#             */
/*   Updated: 2021/07/29 11:18:58 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	normal(int return_code)
{
	exit(EXIT_SUCCESS);
	return (return_code);
}

int	error(void)
{
	exit(EXIT_FAILURE);
	return (0);
}
