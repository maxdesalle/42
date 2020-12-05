/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:02:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/05 10:28:48 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_list
{
	int				precision;
	int				width;
	int				fzero;
	int				fplus;
	int				fminus;
	int				fspace;
	int				ftag;
	int				c;
	int				di;
	char			*s;
	char			type;
	void			*p;
	unsigned int	u;
	unsigned int	xx;
}				t_list;

int				ft_printf(const char *str, ...);
int				ft_parser(va_list argptr, const char *str, t_list *box);
void			ft_putchar(char c);
void			ft_analysis(char *str, va_list argptr, t_list *box);

#endif
