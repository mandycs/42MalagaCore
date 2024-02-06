#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	char *line;

	int fd = open("map1.ber", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
	}
	return 1;
}