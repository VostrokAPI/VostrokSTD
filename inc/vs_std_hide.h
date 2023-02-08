#ifndef VS_STD_HIDE_H
#define VS_STD_HIDE_H

/////////////////////////////
//
//			INCLUDES
//
/////////////////////////////

#include "vs_types.h"

/////////////////////////////
//
//		SYMBOLS DEFINITIONS
//
/////////////////////////////

extern vs_size_t			__vs_strlen_slow(const char *str);
extern vs_size_t			__vs_strlen_sse2(const char *str);
extern vs_size_t			__vs_strlen_sse42(const char *str);
extern vs_size_t			__vs_strlen_avx2(const char *str);

#endif
