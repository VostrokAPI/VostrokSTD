#include "_vs_std.h"
#include "vs_std.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	buf[0x100];
	char	tobecopied[0x100];

	memset(buf, 0, sizeof(buf));
	memset(tobecopied, 0, sizeof(tobecopied));
	strncpy(tobecopied, "test lol", strlen("test lol"));
	__vs_memmove_erms_aligned(buf, tobecopied, strlen(tobecopied));
	printf("%s\n", buf);
	return (0);
}
