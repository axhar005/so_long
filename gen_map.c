#include "inc/so_long.h"

int	main(void)
{
	int i = 0;
	int j = 0;
	int	fd;
    int size = 516;
	fd = open("map/map.ber", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd == -1)
	{
		printf("fd err\n");
		return (1);
	}
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
            if (i == 2 && j == 2)
				write(fd, "E", 1);
            else if (i == 2 && j == 3)
				write(fd, "C", 1);
            else if (i == 2 && j == 4)
				write(fd, "P", 1);
			else if ((j == 0 || i == 0) || (i == size - 1 || j == size - 1))
				write(fd, "1", 1);
			else
				write(fd, "0", 1);
			j++;
		}
        if (i != size - 1)
		    write(fd, "\n", 1);
		i++;
	}
	
	return (0);
}