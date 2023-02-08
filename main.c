#include <stdio.h>
#include "inc/_vs_std.h"

int main(int ac, char **av)
{
	(void)ac;
	printf("%ld\n", __vs_strlen_sse42(av[1]));
	return (0);
}
