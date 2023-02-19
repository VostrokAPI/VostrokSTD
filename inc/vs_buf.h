#ifndef VS_BUF_H
#define VS_BUF_H

#include "vs_std.h"
#include "vs_types.h"

/////////////////////////////
//
//		DEFINES
//
/////////////////////////////

#define VS_STACK_BUF_SIZE 0xFFFFF

#ifndef VS_BUF_SIZE
#define VS_BUF_SIZE 0x100
#endif

#ifndef VS_BUF_STACK
#define VS_BUF_STACK 0x1
#endif

#ifndef VS_BUF_MEMCOPY
#define VS_BUF_MEMCOPY(dst, src, size) (vs_memmove(dst, src, size))
#endif

/////////////////////////////
//
//		TYPEDEF
//
/////////////////////////////

typedef struct vs_buf_t 		vs_buf_t;
typedef struct vs_stack_buf_t	vs_stack_buf_t;
typedef struct vs_heap_buf_t	vs_heap_buf_t;

/////////////////////////////
//
//		STRUCT
//
/////////////////////////////

struct vs_buf_t
{
#if VS_BUF_STACK != 0 && VS_BUF_SIZE <= VS_STACK_BUF_SIZE
	char	buf[VS_BUF_SIZE];
#else
	char	*buf;
#endif
	union {
		vs_uint64_t	*u64_buf;
		vs_int64_t	*i64_buf;
		vs_uint32_t	*u32_buf;
		vs_int32_t	*i32_buf;
		vs_uint16_t	*u16_buf;
		vs_int16_t	*i16_buf;
		vs_uint8_t	*u8_buf;
		vs_int8_t	*i8_buf;
	};

	union {
		vs_size_t	size;
		vs_size_t	length;
		vs_size_t	len;
	};

	union {
		vs_size_t	capacity;
		vs_size_t	max_size;
	};

	vs_bool_t		in_stack;
	vs_bool_t		in_heap;
};

struct	vs_stack_buf_t
{
	#if VS_BUF_SIZE > VS_STACK_BUF_SIZE
	#error "the buffer size is greater than vostrok buffer can be support"
	#else
	char	buf[VS_BUF_SIZE];
	#endif

	union {
		vs_uint64_t	*u64_buf;
		vs_int64_t	*i64_buf;
		vs_uint32_t	*u32_buf;
		vs_int32_t	*i32_buf;
		vs_uint16_t	*u16_buf;
		vs_int16_t	*i16_buf;
		vs_uint8_t	*u8_buf;
		vs_int8_t	*i8_buf;
	};

	union {
		vs_size_t	size;
		vs_size_t	length;
		vs_size_t	len;
	};

	union {
		vs_size_t	capacity;
		vs_size_t	max_size;
	};
};


struct	vs_heap_buf_t
{
	char	*buf;

	union {
		vs_uint64_t	*u64_buf;
		vs_int64_t	*i64_buf;
		vs_uint32_t	*u32_buf;
		vs_int32_t	*i32_buf;
		vs_uint16_t	*u16_buf;
		vs_int16_t	*i16_buf;
		vs_uint8_t	*u8_buf;
		vs_int8_t	*i8_buf;
	};

	union {
		vs_size_t	size;
		vs_size_t	length;
		vs_size_t	len;
	};

	union {
		vs_size_t	capacity;
		vs_size_t	max_size;
	};
};

/////////////////////////////
//
//			INIT
//
/////////////////////////////

int		vs_buf_init(vs_buf_t *buf);
int		vs_buf_stack_init(vs_stack_buf_t *buf);
int		vs_buf_heap_init(vs_heap_buf_t *buf);

/////////////////////////////
//
//			FREE
//
/////////////////////////////

void	vs_buf_free(vs_buf_t *buf);
void	vs_buf_heap_free(vs_heap_buf_t *buf);

#endif
