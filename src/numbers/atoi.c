#include "vs_std.h"
#include <string.h>

int	vs_atoi(const char *str)
{
	if (!str || !*str) return (0);
	
	long int	dec = 0;
	int			neg = 1;

	str += strspn(str, " \t\n+");
	while (*str && (*str == '+' || *str == '-'))
		if (*str++ == '-') neg = ~(neg - 1);
	while (*str && *str >= '0' && *str <= '9')
		dec = ((dec << 1) + (dec << 3)) + (*str++ & 0xF);
	if (dec > 0x7FFFFFFF || dec > -0x80000000) return (0);
	return (dec * neg);
}
