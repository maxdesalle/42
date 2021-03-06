/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:00:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/09 18:34:36 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

/*
** main function
*/

/*
** initiates the va_list and the linked list used to store the flags in it.
** calls the ft_parser function to start parsing the format string.
*/

int	ft_printf(const char *str, ...)
{
	t_list	box;
	va_list	argptr;

	box.len = 0;
	va_start(argptr, str);
	ft_parser(&argptr, (char *)str, &box);
	va_end(argptr);
	return (box.len);
}
