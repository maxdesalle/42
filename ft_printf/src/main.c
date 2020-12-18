/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:33:39 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/18 14:52:41 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"
#include <stdio.h>

void	ft_c_test(void)
{
	ft_printf("%s", "char\n");
	ft_printf("%s", "------------------------------------------------------------------------------------------\n");
	ft_printf("%-5c\n", 'a');
	ft_printf("%5c\n", 'a');
	ft_printf("La lettre affichée est: %c\nEt en voici une autre: %c\n", 'a', 'b');
	ft_printf("Ceci est un petit test: %%, et en voici un autre: %c\n", 'A');
	ft_printf("\n");
}

void	ft_s_test(void)
{
	ft_printf("%s", "string\n");
	ft_printf("%s", "------------------------------------------------------------------------------------------\n");
	ft_printf("%-5.7s\n", "test");
	ft_printf("%-8.7s\n", "test");
	ft_printf("%-8.2s\n", "test");
	ft_printf("%-5.2s\n", "test");
	ft_printf("%-6.3s\n", "test");
	ft_printf("%.3s\n", "test");
	ft_printf("Ceci est un test: %s\n", "et ceci en est un autre");
	ft_printf("Maintenant, nous allons introduire la largeur du côté gauche:%9s\n", "width");
	ft_printf("Puis nous allons introduire la largeur du côté droit: %-10s\n", "width");
	ft_printf("Et maintenant la %.6s\n", "précision");
	ft_printf("\n");
}

void	ft_di_test(void)
{
	ft_printf("%s", "int\n");
	ft_printf("%s", "------------------------------------------------------------------------------------------\n");
	ft_printf("%d\n", 25);
	ft_printf("%5.1d\n", 25);
	ft_printf("%.5d\n", 25);
	ft_printf("%2.5d\n", 25);
	ft_printf("%7.5d\n", 25);
	ft_printf("%-7.5d\n", 25);
	ft_printf("%7d\n", 25);
	ft_printf("%-7d", 25);
}

int	main(void)
{
	ft_c_test();
	ft_s_test();
	ft_di_test();
	ft_printf("-----\n");
	ft_printf("%u\n", 25);
	ft_printf("%u\n", -25);
	ft_printf("%5u\n", 25);
	ft_printf("%5.1u\n", 25);
	ft_printf("%5.4u\n", 25);
	ft_printf("%5.6u\n", 25);
	ft_printf("%-5u\n", 25);
	ft_printf("%-5.1u\n", 25);
	ft_printf("%-5.4u\n", 25);
	ft_printf("%-5.6u\n", 25);
	ft_printf("%1.1u\n", 25);
	return (0);
}
