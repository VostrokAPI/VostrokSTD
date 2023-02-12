#include "vs_stat.h"

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_stat.h"
#include "vs_syscall.h"

int	vs_stat(vs_pathname_t *restrict pname, vs_sbuf_t *restrict buf)
{
	return (vs_syscall(VS_SYS_STAT, pname, buf));
}

int	vs_fstat(int fd, vs_sbuf_t *restrict buf)
{
	return (vs_syscall(VS_SYS_FSTAT, fd, buf));
}

int	vs_lstat(vs_pathname_t *restrict pname, vs_sbuf_t *restrict buf)
{
	return (vs_syscall(VS_SYS_LSTAT, pname, buf));
}

