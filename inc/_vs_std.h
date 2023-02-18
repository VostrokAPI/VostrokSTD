#ifndef _VS_STD_H
#define _VS_STD_H

/////////////////////////////
//
//			INCLUDES
//
/////////////////////////////

#include "vs_types.h"

/*********************************************************************
*
* @brief    __vs_strlen_slow			get length of string
* 										slow because that function 
* 										count char by char
* 										when pointer is on null byte 
* 										it return length
* 										of string this algorithms maybe slow 
* 										on large buffer
*
* @param    const char	*str			String to calculate
*
* @return   vs_size_t (unsigned long)	Which is length of string 
* 										without null byte
*
*********************************************************************/
extern vs_size_t			__vs_strlen_slow(const char *str);

/*********************************************************************
*
* @brief    __vs_strlen_sse2			get length of string
* 										witrh SSE2 Cpu extension
* 										it use xmm registers,the 
* 										xmm registers are 16 bytes of length 
* 										and the opcodes belonging to SSE2 
* 										allow to make calculations on 16 bytes 
* 										(string packed comparison etc...)
*
* @param    const char	*str			String to calculate
*
* @return   vs_size_t (unsigned long)	Which is length of string 
* 										without null byte
*
*********************************************************************/
extern vs_size_t			__vs_strlen_sse2(const char *str);

/*********************************************************************
*
* @brief    __vs_strlen_sse42			get length of string
* 										witrh SSE42 Cpu extension
* 										it use xmm registers,the 
* 										xmm registers are 16 bytes of length 
* 										and the opcodes belonging to SSE42 
* 										allow to make calculations on 16 bytes 
* 										(string comparison etc...)
*
* @param    const char	*str			String to calculate
*
* @return   vs_size_t (unsigned long)	Which is length of string 
* 										without null byte
*
*********************************************************************/
extern vs_size_t			__vs_strlen_sse42(const char *str);

/*********************************************************************
*
* @brief    __vs_strlen_avx2			get length of string
* 										witrh AVX2 Cpu extension
* 										it use ymm registers,the 
* 										xmm registers are 16 bytes of length 
* 										and the opcodes belonging to AVX2 
* 										allow to make calculations on 32 bytes 
* 										(string comparison etc...)
* 										AVX (Advanced Vector Extension)
* 										Cpu support vectorization
* 										this extension is mainly used
* 										for Image and data processing
*
* @param    const char	*str			String to calculate
*
* @return   vs_size_t (unsigned long)	Which is length of string 
* 										without null byte
*
*********************************************************************/
extern vs_size_t			__vs_strlen_avx2(const char *str);

extern void					*__vs_memmove_erms(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx_unaligned(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx512_no_vzeroupper(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx512_unaligned(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx512_unaligned_erms(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_sse2_unaligned(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_sse2_unaligned_erms(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_ssse3(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_ssse3_back(void *dst, const void *src, vs_size_t size);

#endif
