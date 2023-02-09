#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "vs_std.h"
#include "vs_syscall.h"

int main(void)
{
	int fd = vs_syscall(VS_SYS_DUP, 1);
	printf("%d\n", fd);
	vs_syscall(VS_SYS_CLOSE, fd);
	return (0);
}
