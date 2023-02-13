#include "vs_std.h"
#include "vs_syscall.h"
#include "vs_types.h"

int	vs_write(int fd, const void *buf, vs_size_t size)
{
	return (vs_syscall(VS_SYS_WRITE, fd, buf, size));
}
