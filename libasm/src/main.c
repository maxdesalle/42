# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);

int	main(void)
{
	printf("---------------");
	printf("\n   ft_strlen \n");
	printf("---------------");
	printf("\n\n\"test\"");
	printf("\nft_strlen: %d", (int)ft_strlen("test"));
	printf("\nstrlen: %d", (int)strlen("test"));
	printf("\n\n\"this is a test\"");
	printf("\nft_strlen: %d", (int)ft_strlen("this is a test"));
	printf("\nstrlen: %d", (int)strlen("this is a test"));
	printf("\n\n\"this is a very very very very very long test\"");
	printf("\nft_strlen: %d", (int)ft_strlen("this is a very very very very very long test"));
	printf("\nstrlen: %d", (int)strlen("this is a very very very very very long test"));
	return (0);
}
