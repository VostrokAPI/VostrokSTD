#include "vs_std.h"
#include "vs_types.h"
#include "vs_syscall.h"

int	vs_read(int fd, void *buf, vs_size_t size)
{
	return (vs_syscall(VS_SYS_READ, fd, buf, size));
}
