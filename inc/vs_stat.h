#ifndef VS_STAT_H
#define VS_STAT_H

/////////////////////////////
//
//			INCLUDES
//
/////////////////////////////

#include "vs_time.h"
#include <sys/stat.h>
#include <sys/statfs.h>
#include <sys/statvfs.h>

/////////////////////////////
//
//		TYPEDEFS
//
/////////////////////////////

typedef struct stat						vs_stat_t;
typedef struct stat64					vs_stat64_t;
typedef const char						vs_pathname_t;
typedef vs_stat_t						vs_sbuf_t;

/////////////////////////////
//
//		STAT DEFS
//
/////////////////////////////

int		vs_stat(vs_pathname_t *restrict pname, vs_sbuf_t *restrict buf);
int		vs_fstat(int fd, vs_sbuf_t *restrict buf);
int		vs_lstat(vs_pathname_t *restrict pname, vs_sbuf_t *restrict buf);

#endif
