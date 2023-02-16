#ifndef VS_RAND_H
#define VS_RAND_H

/////////////////////////////
//
//			INCLUDES
//
/////////////////////////////

#include "vs_types.h"

vs_uint8_t	*vs_urandom(vs_uint8_t *buf, vs_size_t size);
vs_uint8_t	*vs_rdrand(vs_uint8_t *buf, vs_size_t size);

vs_int32_t	vs_rand(int min, int max);
vs_uint64_t	vs_rdrandlong(void);
vs_uint32_t	vs_rdrandint(void);
vs_uint16_t	vs_rdrandshort(void);
vs_uint8_t	vs_rdrandbyte(void);

#endif
