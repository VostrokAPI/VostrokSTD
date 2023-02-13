#include "vs_std.h"

int	vs_putchar(int c)
{
	return (vs_write(VS_STDOUT, &c, sizeof(int)));
}
