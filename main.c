#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "_vs_std.h"
#include <unistd.h>
#include <vs_stat.h>

int main(void)
{
	vs_stat_t	buf;

	vs_stat("main.c", &buf);

	printf("%ld\n", buf.st_dev);
	return (0);
}
