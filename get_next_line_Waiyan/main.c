#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt",O_RDONLY);
	char *tmp;
	tmp = get_next_line(fd);
	while (tmp)
	{
		printf("%s",tmp);
		tmp = get_next_line(fd);
	}
}