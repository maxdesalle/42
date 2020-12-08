/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:02:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/05 15:32:36 by mdesalle         ###   ########.fr       */
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
	int				fminus;
	int				fspace;
	int				width;
	int				fzero;
	int				fplus;
	int				ftag;
	int				len;
	int				di;
	int				c;
	char			type;
	char			*s;
	void			*p;
	unsigned int	xx;
	unsigned int	u;
}				t_list;

int				ft_printf(const char *str, ...);
int				ft_parser(va_list argptr, const char *str, t_list *box);
void			ft_putchar(char c, t_list *box);
void			ft_super_putchar(int len, char c, t_list *box);
void			ft_analysis(char *str, va_list argptr, t_list *box);

#endif