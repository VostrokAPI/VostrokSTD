#include "_vs_std.h"
#include "vs_std.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	dst[0x100];
	char	src[0x100];

	strcpy(src, "hello");
	__vs_memmove_erms(dst, src, strlen(src));

	printf("%s\n", dst);
	return (0);
}
