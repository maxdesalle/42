/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:02:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/04 16:47:14 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int	precision;
	int	width;
	int	fzero;
	int	fplus;
	int	fminus;
	int	fspace;
	int	ftag;
	char	type;
}		node_t;

int	ft_printf(const char *, ...);
int     ft_parser(va_list argptr, const char *str, node_t *box);
void	ft_putchar(char c);
void	ft_analysis(char *str, va_list argptr, node_t *box);

#endif
