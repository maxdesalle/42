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
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*src;
	char	*dst;
	char	*buff;
	char	*ret;
	char	*wrongbuff;

	src = malloc(46);
	if (!src)
		return (0);
	dst = malloc(46);
	if (!dst)
		return (0);
	memcpy(src, "this is a very very very very very long test", 45);
	memcpy(dst, "hello world", 12);
	buff = calloc(32 + 1, sizeof(char));
	if (!buff)
		return (0);
	wrongbuff = calloc(32 + 1, sizeof(char));
	if (!buff)
		return (0);
	printf("---------------");
	printf("\n   ft_strlen \n");
	printf("---------------");
	green();
	printf("\n\n\"\"");
	reset();
	printf("\nft_strlen:\t%d", (int)ft_strlen(""));
	printf("\nstrlen:\t\t%d", (int)strlen(""));
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
	printf("\n\n\"test in test.txt\"");
	reset();
	printf("\n");
	fd = open("./test.txt", O_CREAT | O_RDWR);
	if (fd == -1)
		return (0);
	chmod("./test.txt", 400);
	errno = 0;
	write(1, "ft_write:\t", 10);
	ft_write(fd, "test\n", 5);
	printf("errno:\t%d\n", errno);
	errno = 0;
	write(1, "write:\t\t", 8);
	write(fd, "test\n", 5);
	printf("errno:\t%d\n", errno);
	close(fd);
	green();
	printf("\n\n\"wrong file descriptor\"");
	reset();
	printf("\n");
	errno = 0;
	write(1, "ft_write:\t", 10);
	ft_write(-1, "test\n", 5);
	printf("errno:\t%d\n", errno);
	errno = 0;
	write(1, "write:\t\t", 8);
	write(-1, "test\n", 5);
	printf("errno:\t%d\n", errno);
	green();
	printf("\n\n\"test\"");
	reset();
	printf("\n");
	errno = 0;
	write(1, "ft_write:\t", 10);
	ft_write(1, "test\n", 5);
	printf("errno:\t%d\n", errno);
	errno = 0;
	write(1, "write:\t\t", 8);
	write(1, "test\n", 5);
	printf("errno:\t%d\n", errno);
	green();
	printf("\n\"this is a test\"");
	reset();
	printf("\n");
	errno = 0;
	write(1, "ft_write:\t", 10);
	ft_write(1, "this is a test\n", 15);
	printf("errno:\t%d\n", errno);
	errno = 0;
	write(1, "write:\t\t", 8);
	write(1, "this is a test\n", 15);
	printf("errno:\t%d\n", errno);
	green();
	printf("\n\"this is a very very very very very long test\"");
	reset();
	printf("\n");
	errno = 0;
	write(1, "ft_write:\t", 10);
	ft_write(1, "this is a very very very very very long test\n", 45);
	printf("errno:\t%d\n", errno);
	errno = 0;
	write(1, "write:\t\t", 8);
	write(1, "this is a very very very very very long test\n", 45);
	printf("errno:\t%d\n", errno);
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
	errno = 0;
	reader = ft_read(fd, buff, 32);
	close(fd);
	printf("ft_read:\n- read:\t\t\"%s\"\n- ret:\t\t%d\n- errno:\t%d\n", buff, reader, errno);
	printf("\n");
	fd = open("./Makefile", O_RDONLY);
	if (fd == -1)
		return (0);
	errno = 0;
	reader = read(fd, buff, 32);
	close(fd);
	printf("read:\n- read:\t\t\"%s\"\n- ret:\t\t%d\n- errno:\t%d\n", buff, reader, errno);
	green();
	printf("\n\n\"wrong file descriptor\"");
	reset();
	printf("\n\n");
	errno = 0;
	reader = ft_read(-1, wrongbuff, 32);
	close(fd);
	printf("ft_read:\n- read:\t\t\"%s\"\n- ret:\t\t%d\n- errno:\t%d\n", wrongbuff, reader, errno);
	printf("\n");
	errno = 0;
	reader = read(-1, wrongbuff, 32);
	close(fd);
	printf("read:\n- read:\t\t\"%s\"\n- ret:\t\t%d\n- errno:\t%d\n", wrongbuff, reader, errno);
	green();
	printf("\n\n\"stdin reading\"");
	reset();
	printf("\n");
	ft_read(0, wrongbuff, 32);
	printf("\nft_read:\t%s\n", wrongbuff);
	printf("\n");

	printf("---------------");
	printf("\n   ft_strcmp \n");
	printf("---------------");
	green();
	printf("\n\n\"\" and \"\"");
	reset();
	printf("\n");
	printf("ft_strcmp:\t%d\n", ft_strcmp("", ""));
	printf("strcmp:\t\t%d\n", strcmp("", ""));
	green();
	printf("\n\n\"\" and \"test\"");
	reset();
	printf("\n");
	printf("ft_strcmp:\t%d\n", ft_strcmp("", "test"));
	printf("strcmp:\t\t%d\n", strcmp("", "test"));
	green();
	printf("\n\n\"test\" and \"\"");
	reset();
	printf("\n");
	printf("ft_strcmp:\t%d\n", ft_strcmp("test", ""));
	printf("strcmp:\t\t%d\n", strcmp("test", ""));
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
	printf("\n\"test\" and \"testz\"");
	reset();
	printf("\n");
	printf("ft_strcmp:\t%d\n", ft_strcmp("test", "testz"));
	printf("strcmp:\t\t%d\n", strcmp("test", "testz"));
	printf("\n\n");

	printf("---------------");
	printf("\n   ft_strcpy \n");
	printf("---------------");
	green();
	printf("\n\n\"this is a very very very very very long test\"");
	reset();
	printf("\n");
	ret = ft_strcpy(dst, src);
	printf("ft_strcpy:\n- src:\t%s\n- dst:\t%s\n- ret:\t%s\n", src, dst, ret);
	printf("\n\n");

	printf("---------------");
	printf("\n   ft_strdup \n");
	printf("---------------");
	green();
	printf("\n\n\"\"");
	reset();
	printf("\n");
	s1 = ft_strdup("");
	printf("ft_strdup:\t%s\n", s1);
	s2 = strdup("");
	printf("strdup:\t\t%s\n", s2);
	green();
	printf("\n\n\"this is a test\"");
	reset();
	printf("\n");
	s3 = ft_strdup("this is a test");
	printf("ft_strdup:\t%s\n", s3);
	s4 = strdup("this is a test");
	printf("strdup:\t\t%s\n", s4);
	free(buff);
	free(dst);
	free(s1);
	free(s2);
	return (0);
}
