#ifndef VS_TYPES_H
#define VS_TYPES_H

/////////////////////////////
//
//		DEFINES
//
/////////////////////////////

#define VS_NULL (void *)0
#define VS_R_OK 4
#define VS_W_OK 2
#define VS_X_OK 1
#define VS_F_OK 0

/////////////////////////////
//
//		TYPEDEFS
//
/////////////////////////////

typedef signed char			vs_int8_t;
typedef signed short		vs_int16_t;
typedef signed int			vs_int32_t;
typedef signed long long	vs_int64_t;

typedef unsigned char		vs_uint8_t;
typedef unsigned short		vs_uint16_t;
typedef unsigned int		vs_uint32_t;
typedef unsigned long long	vs_uint64_t;

typedef signed char*		vs_string_t;
typedef unsigned char*		vs_ustring_t;
typedef unsigned long		vs_size_t;

typedef enum vs_bool_t		vs_bool_t;
typedef enum vs_seek_t		vs_seek_t;

typedef long				vs_int128_t		__attribute__((__vector_size__(16), __aligned__(16)));
typedef long				vs_int256_t		__attribute__((__vector_size__(32), __aligned__(32)));
typedef long				vs_int128_na_t	__attribute__((__vector_size__(16), __aligned__(1)));
typedef long				vs_int256_na_t	__attribute__((__vector_size__(32), __aligned__(1)));
typedef unsigned long		vs_uint128_t 	__attribute__((__vector_size__(16), __aligned__(16)));
typedef unsigned long		vs_uint256_t	__attribute__((__vector_size__(32), __aligned__(32)));

typedef void*				vs_ptr_t;
typedef char				vs_charptr_t;
typedef short				vs_shortptr_t;
typedef int					vs_intptr_t;
typedef long				vs_longptr_t;
typedef unsigned char		vs_ucharptr_t;
typedef unsigned short		vs_ushortptr_t;
typedef unsigned int		vs_uintptr_t;
typedef unsigned long		vs_ulongptr_t;
typedef int					vs_pid_t;
typedef int					vs_fd_t;

typedef unsigned char		vs_byte_t;
typedef unsigned short		vs_word_t;
typedef unsigned int		vs_dword_t;
typedef unsigned long		vs_qword_t;

typedef unsigned int		vs_umode_t;
typedef long int			vs_off_t;
typedef long long			vs_off64_t;


/////////////////////////////
//
//			ENUM
//
/////////////////////////////

enum vs_bool_t
{
	VS_FALSE,
	VS_TRUE
};

enum vs_seek_t
{
	VS_SEEK_SET,
	VS_SEEK_CUR,
	VS_SEEK_END,
	VS_SEEK_DATA,
	VS_SEEK_HOLE
};

#endif
