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

/*********************************************************************
*
* @brief    __vs_memmove_slow		Copy bytes to memory area
*									slow because this functions 
*									copy byte per byte and no use
*									any extension to copy
*
* @param    void *dst				Destination of memory area
* @param	const void *src			Source copied to destination
* @param	vs_size_t				Size of source to be copied to destination
*
* @return   return dst				Which is destination of memory area
*
*********************************************************************/

extern void					*__vs_mmemove_slow(void *dst, const void *src, vs_size_t size);

/*********************************************************************
*
* @brief    __vs_memmove_erms		Copy bytes to memory area
*									ERMS is for Enhanced rep movsb and stosb
*									operation is optimization provide by intel
*									you can refer to the intel optimization
*									manual - section 3.7.6 to understand it
*
*									is very fast with lengths between 1 and 128 bytes
*
* @param    void *dst				Destination of memory area
* @param	const void *src			Source to be copied to Destination memory area
* @param	vs_size_t				Size of source to be copied
*
* @return   return dst				Which is destination of memory area
*
* @NOTE								if src < dst:
* 										copy backforward
* 									else
* 										copy forward
*
*********************************************************************/
extern void					*__vs_memmove_erms(void *dst, const void *src, vs_size_t size);

/*********************************************************************
*
* @brief    __vs_memmove_erms_aligned		Copy bytes to memory area
*											ERMS is for Enhanced rep movsb and stosb
*											operation is optimization provide by intel
*											you can refer to the intel optimization
*											manual - section 3.7.6 to understand it
*
*											is very fast with lengths between 1 and 128 bytes
*
*											aligned version allow you copy per block size
*											for example if size is multiple of 8 than
*											rep movsq is used and size is divided by 8
*
*											is the same if size is multiple of 4 and 2
*
*											if size is non multiple of 8,4,2 
*											than copy byte per byte
*											is used
*
* @param    void *dst						Destination of memory area
* @param	const void *src					Source to be copied to Destination memory area
* @param	vs_size_t						Size of source to be copied
*
* @return   return dst						Which is destination of memory area
*
* @NOTE										if src < dst:
* 												copy backforward
* 											else
* 												copy forward
*
*********************************************************************/
extern void					*__vs_memmove_erms_aligned(void *dst, const void *src, vs_size_t size);

extern void					*__vs_memmove_avx_unaligned(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx_unaligned_erms(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx512_no_vzeroupper(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx512_unaligned(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_avx512_unaligned_erms(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_sse2_unaligned(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_sse2_unaligned_erms(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_ssse3(void *dst, const void *src, vs_size_t size);
extern void					*__vs_memmove_ssse3_back(void *dst, const void *src, vs_size_t size);

#endif
