#include "vs_std.h"
#include "_vs_std.h"

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_types.h"

void	*vs_memmove(void *dst, const void *src, vs_size_t size) __attribute__ ((ifunc ("__vs_memmove_ifunc")));

void	*__vs_memmove_slow(void *dst, const void *src, vs_size_t size)
{
	if (!dst || !src || !size)
		return (dst);
	vs_uint8_t	*tdst = (vs_uint8_t *)dst;
	vs_uint8_t	*tsrc = (vs_uint8_t *)src;
	for (vs_size_t i = 0; i < size; i++)
		*tdst++ = *tsrc++;
	return (dst);
}

static void *(*__vs_memmove_ifunc (void))(void *dst, const void *src, vs_size_t size)
{
	return (__vs_memmove_erms);
}
