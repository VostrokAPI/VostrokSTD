#include <stdio.h>
#include <stdlib.h>
#include "_vs_std.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int res = atoi(av[1]);
	if (res == -1)
		printf("Hack\n");
	printf("%d\n", res);
	return (0);
}
