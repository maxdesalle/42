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

# include "../include/libasm.h"

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
	int	fd;
	int	reader;
	char	*src;
	char	*dst;
	char	*buff;

	src = malloc(sizeof(char) * (4 + 1));
	if (!src)
		return (0);
	dst = malloc(sizeof(char) * (4 + 1));
	if (!dst)
		return (0);
	buff = malloc(sizeof(char) * (32 + 1));
	if (!buff)
		return (0);
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
	write(1, "ft_write:\t", 10);
	ft_write(1, "this is a very very very very very long test\n", 45);
	write(1, "write:\t\t", 8);
	write(1, "this is a very very very very very long test\n", 45);
	printf("\n\n");

	printf("---------------");
	printf("\n    ft_read\n");
	printf("---------------");
	green();
	printf("\n\n\"# ******************************\"");
	reset();
	printf("\n\n");
	fd = open("./Makefile", O_RDONLY);
	if (fd == -1)
		return (0);
	reader = ft_read(fd, buff, 32);
	close(fd);
	printf("ft_read:\n- read:\t\t\"%s\"\n- ret:\t\t%d\n", buff, reader);
	printf("\n");
	fd = open("./Makefile", O_RDONLY);
	if (fd == -1)
		return (0);
	reader = read(fd, buff, 32);
	close(fd);
	printf("read:\n- read:\t\t\"%s\"\n- ret:\t\t%d\n", buff, reader);
	printf("\n\n");

	printf("---------------");
	printf("\n   ft_strcmp \n");
	printf("---------------");
	green();
	printf("\n\n\"test\" and \"test\"");
	reset();
	printf("\n");
	printf("ft_strcmp:\t%d\n", ft_strcmp("test", "test"));
	printf("strcmp:\t\t%d\n", strcmp("test", "test"));
	green();
	printf("\n\"testa\" and \"test\"");
	reset();
	printf("\n");
	printf("ft_strcmp:\t%d\n", ft_strcmp("testa", "test"));
	printf("strcmp:\t\t%d\n", strcmp("testa", "test"));
	green();
	printf("\n\"testz\" and \"test\"");
	reset();
	printf("\n");
	printf("ft_strcmp:\t%d\n", ft_strcmp("testz", "test"));
	printf("strcmp:\t\t%d\n", strcmp("testz", "test"));
	printf("\n\n");

	printf("---------------");
        printf("\n   ft_strcpy \n");
        printf("---------------");
	green();
	printf("\n\n\"this is a very very very very very very long test\"");
	reset();
	printf("\n");
	src = "this is a very very very very very very long test";
	printf("ft_strcpy:\t%s\n", ft_strcpy(dst, src));
	memset(dst, 0, strlen(dst));
	printf("strcpy:\t\t%s\n", strcpy(dst, src));
	printf("\n\n");

	printf("---------------");
        printf("\n   ft_strdup \n");
        printf("---------------");
	green();
	printf("\n\n");
	return (0);
}
