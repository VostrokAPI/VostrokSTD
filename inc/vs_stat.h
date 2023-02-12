#ifndef VS_STAT_H
#define VS_STAT_H

/////////////////////////////
//
//			INCLUDES
//
/////////////////////////////

#include "vs_time.h"

/////////////////////////////
//
//		TYPEDEFS
//
/////////////////////////////

typedef struct vs_stat_t				vs_stat_t;
typedef const char*	restrict			vs_pathname_t;
typedef vs_stat_t* restrict 			vs_sbuf_t;
typedef unsigned long int				vs_dev_t;
typedef unsigned long int				vs_ino_t;
typedef unsigned long int				vs_nlink_t;
typedef unsigned int					vs_mode_t;
typedef unsigned int					vs_uid_t;
typedef unsigned int					vs_gid_t;
typedef unsigned short					vs_off_t;
typedef long int						vs_blksize_t;
typedef long int						vs_blkcnt_t;

/////////////////////////////
//
//		STRUCTS
//
/////////////////////////////

struct vs_stat_t
{
	vs_dev_t		st_dev;
	vs_ino_t		st_ino;
	vs_mode_t		st_mode;
	vs_nlink_t		st_nlink;
	vs_uid_t		st_uid;
	vs_gid_t		st_gid;
	vs_dev_t		st_rdev;
	vs_off_t		st_size;
	vs_blksize_t	st_blksize;
	vs_blkcnt_t		st_blocks;
	vs_time_t		st_atime;
	vs_time_t		st_mtime;
	vs_time_t		st_ctime;
};

/////////////////////////////
//
//		STAT DEFS
//
/////////////////////////////

int		vs_stat(vs_pathname_t pname, vs_sbuf_t buf);
int		vs_fstat(vs_pathname_t pname, vs_sbuf_t buf);
int		vs_lstat(vs_pathname_t pname, vs_sbuf_t buf);

#endif
