#ifndef VS_STD_H
#define VS_STD_H

#if defined(_WIN32)
	#error "VostrokSTD is not supported on Windows"
#endif

/////////////////////////////
//
//		INCLUDES
//
/////////////////////////////

#include "vs_types.h"

/////////////////////////////
//
//		TYPEDEFS
//
/////////////////////////////

typedef enum	vs_std_fd_t	vs_std_fd_t;

/////////////////////////////
//
//			ENUM
//
/////////////////////////////

enum	vs_std_fd_t
{
	VS_STDIN,
	VS_STDOUT,
	VS_STDERR
};

/////////////////////////////
//
//		STRLEN
//
/////////////////////////////

vs_size_t	vs_strlen(const char *str);

void		*vs_memcpy(void *restrict dst, const void *restrict src, vs_size_t n);
void		*vs_memmove(void *dst, const void *src, vs_size_t n);
void		*vs_memset(void *s, int c, vs_size_t size);
void		*vs_memchr(void *s, int c, vs_size_t n);
void		*vs_memmem(const void *htack, vs_size_t hlen, const void *ndle, vs_size_t nlen);
void		*vs_malloc(vs_size_t size);
void		*vs_calloc(vs_size_t nmemb, vs_size_t size);
char		*vs_strcpy(char *restrict dst, const char *restrict src);
char		*vs_strncpy(char *restrict dst, const char *restrict src, vs_size_t n);
char		*vs_strstr(const char *haystack, const char *needle);
char		*vs_strnstr(const char *haystack, const char *needle, vs_size_t n);
char		*vs_strcasestr(const char *haystack, const char *needle);
char		*vs_strchr(const char *s, int c);
char		*vs_strrchr(const char *s, int c);
char		*vs_strtok(char *restrict str, const char *restrict delim);
char		*vs_strrtok(char *restrict str, const char *restrict delim);
char		*vs_strcat(char *restrict dst, const char *restrict src);
char		*vs_strncat(char *restrict dst, const char *restrict src, vs_size_t n);
vs_size_t	vs_strspn(const char *s, const char *accept);
vs_size_t	vs_strcspn(const char *s, const char *reject);
vs_size_t	vs_gets(const char *s, vs_size_t n);
int			vs_puts(const char *s);
int			vs_printf(const char *restrict fmt, ...);
int			vs_sprintf(char *restrict str, const char *restrict fmt, ...);
int			vs_snprintf(char *restrict str, vs_size_t size, const char *restrict fmt, ...);
int			vs_dprinf(int fd, const char *restrict fmt, ...);
int			vs_write(int fd, const void *buf, vs_size_t s);
int			vs_read(int fd, const void *buf, vs_size_t s);
int			vs_putchar(char c);
void		vs_bzero(void *s, vs_size_t n);
void		vs_free(void **ptr);

#endif
