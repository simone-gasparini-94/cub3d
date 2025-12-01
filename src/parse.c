#include <stdio.h>
#include <unistd.h>
#include "ft_fprintf.h"

int main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO, "ERROR: Invalid number of arguments.\n");	
		return (1);
	}
	return (0);
}
