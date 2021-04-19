/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 10:32:57 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/19 10:33:13 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);

void	green(void)
{
	printf("\033[0;92m");
}

void	reset(void)
{
	printf("\033[0m");
}

int	main(void)
{
	printf("\n");
	printf("---------------");
	printf("\n   ft_strlen \n");
	printf("---------------");
	green();
	printf("\n\n\"test\"");
	reset();
	printf("\nft_strlen:\t%d", (int)ft_strlen("test"));
	printf("\nstrlen:\t\t%d", (int)strlen("test"));
	green();
	printf("\n\n\"this is a test\"");
	reset();
	printf("\nft_strlen:\t%d", (int)ft_strlen("this is a test"));
	printf("\nstrlen:\t\t%d", (int)strlen("this is a test"));
	green();
	printf("\n\n\"this is a very very very very very long test\"");
	reset();
	printf("\nft_strlen:\t%d", (int)ft_strlen("this is a very very very very very long test"));
	printf("\nstrlen:\t\t%d", (int)strlen("this is a very very very very very long test"));
	printf("\n\n");
	printf("---------------");
        printf("\n   ft_write \n");
        printf("---------------");
	green();
        printf("\n\n\"test\"");
	reset();
	printf("\n");
	write(1, "ft_write:\t", 10);
	ft_write(1, "test\n", 5);
	write(1, "write:\t\t", 8);
        write(1, "test\n", 5);
	green();
        printf("\n\"this is a test\"");
	reset();
	printf("\n");
	write(1, "ft_write:\t", 10);
        ft_write(1, "this is a test\n", 15);
	write(1, "write:\t\t", 8);
        write(1, "this is a test\n", 15);
	green();
        printf("\n\"this is a very very very very very long test\"");
	reset();
	printf("\n");
	write(1, "ft_write\t", 10);
        ft_write(1, "this is a very very very very very long test\n", 45);
	write(1, "write:\t\t", 8);
        write(1, "this is a very very very very very long test\n", 45);
	return (0);
}
