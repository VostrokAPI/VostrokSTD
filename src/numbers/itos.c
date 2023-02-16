#include "vs_std.h"
#include "vs_types.h"
#include "vs_types.h"

static vs_uint32_t	_nb_len(int nb)
{
	vs_uint32_t	i = 0;

	if (nb < 0) {
		nb = ~(nb - 1);
		i++;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static vs_uint32_t _count_zero(int nb)
{
	vs_uint32_t	i = 0;

	if (!_nb_len(nb))
		return (0);
	if (nb < 0)
		nb = ~(nb - 1);
	while (!(nb % 10)) {
		i++;
		nb /= 10;
	}
	return (i);
}

static int	_rev_int(int nb)
{
	int			rev		= 0;
	int			neg		= 1;

	if (nb < 0) {
		neg = ~(neg - 1);
		nb = ~(nb - 1);
	}
	while (nb > 0) {
		rev *= 10;
		rev += (nb % 10);
		nb /= 10;
	}
	return (rev * neg);
}

char	*vs_itos(int nbr, char *buf, vs_size_t size)
{
	(void)size;
	if (!buf) return (VS_NULL);

	vs_uint32_t	zero = _count_zero(nbr);
	vs_uint32_t	len = _nb_len(nbr);
	int			rev = _rev_int(nbr);
	vs_size_t	index = 0;

	if (rev < 0) {
		rev = ~(rev - 1);
		buf[index++] = '-';
	}

	while (index < (len - zero)) {
		buf[index++] = (rev % 10) | '0';
		rev /= 10;
	}

	while (zero) {
		buf[index++] = '0';
		zero--;
	}

	buf[index] = 0;
	return (buf);
}
