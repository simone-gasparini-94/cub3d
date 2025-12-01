#include "data.h"
#include "ft_fprintf.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		perror("Malloc");
		return (1);
	}
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO, "ERROR: Invalid number of arguments.\n");
		return (1);
	}
	if (parse(data, argv[1]) != 1)
	{
		// interpret();
		// clean();
	}
	return (0);
}
