#include "../includes/tetriminos.h"

int	start_size(int *m, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (m[i] == 1 || m[i] == 2)
			return (4);
		if (m[i] == 3)
			return (2);
		i++;
	}
	return (3);
}
