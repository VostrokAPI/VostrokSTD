#include "vs_std.h"
#include "_vs_std.h"
#include <cpuid.h>

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_types.h"

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

void	*vs_memmove(void *dst, const void *src, vs_size_t size) __attribute__ ((ifunc ("__vs_memmove_ifunc")));


static void *(*__vs_memmove_ifunc (void))(void *dst, const void *src, vs_size_t size)
{
	unsigned int eax, ebx, ecx, edx;

	__get_cpuid(0x7, &eax, &ebx, &ecx, &edx);

	if ((ebx & 0x100))
		return (__vs_memmove_erms);
	return (__vs_memmove_slow);
}
