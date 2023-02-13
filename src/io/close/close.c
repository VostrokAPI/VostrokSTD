#include "vs_std.h"

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_syscall.h"

int	vs_close(int fd)
{
	return (vs_syscall(VS_SYS_CLOSE, fd));
}

