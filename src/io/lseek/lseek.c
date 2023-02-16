#include "vs_std.h"

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_syscall.h"

vs_off_t	vs_lseek(int fd, vs_off_t offset, int whence)
{
	return (vs_syscall(VS_SYS_LSEEK, fd, offset, whence));
}
