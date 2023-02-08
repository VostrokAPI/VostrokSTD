#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "vs_std.h"

int main(int ac, char **av)
{
	if (ac != 2) return (1);
	printf("%ld\n", __vs_strlen_slow(av[1]));
	return (0);
}
