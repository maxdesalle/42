#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>

size_t	ft_strlen(const char *s);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s);

#endif
