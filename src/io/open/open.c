#include "vs_std.h"

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_syscall.h"

int	vs_open(const char *pathname, int flags, vs_umode_t mode)
{
	return (vs_syscall(VS_SYS_OPEN, pathname, flags, mode));
}
