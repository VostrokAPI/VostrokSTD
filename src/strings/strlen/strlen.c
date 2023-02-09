#include "vs_std.h"

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_types.h"

/*********************************************************************
*
* @brief    vs_strlen	function return length of string
*
* @param    const char *
*
* @return   vs_size_t:	length of string
*
*********************************************************************/

vs_size_t			vs_strlen(const char *str) __attribute__ ((ifunc ("__vs_strlen_ifunc")));

#ifndef NO_HIDE
/////////////////////////////
//
//			SLOW
//
/////////////////////////////

extern vs_size_t	__vs_strlen_slow(const char *str);

/////////////////////////////
//
//			SSE2
//
/////////////////////////////

extern vs_size_t	__vs_strlen_sse2(const char *str);

/////////////////////////////
//
//			AVX2
//
/////////////////////////////

extern vs_size_t	__vs_strlen_avx2(const char *str);

/////////////////////////////
//
//			SSE42
//
/////////////////////////////

extern vs_size_t	__vs_strlen_sse42(const char *str);
#endif

/////////////////////////////
//
//		IFUNC FUNCTION
//
/////////////////////////////

static vs_size_t (*__vs_strlen_ifunc (void))(const char *str)
{
	__builtin_cpu_init();

	if (__builtin_cpu_supports("avx2"))
		return (__vs_strlen_avx2);

	if (__builtin_cpu_supports("sse2"))
		return (__vs_strlen_sse2);

	return (__vs_strlen_slow);
}
