#include "vs_rand.h"
#include "vs_std.h"
#include "vs_types.h"
#include <time.h>
#include <immintrin.h>
#include <fcntl.h>

vs_uint8_t	*vs_urandom(vs_uint8_t *buf, vs_size_t size)
{
	if (!buf) return (VS_NULL);

	if (!size) return (buf);

	int fd = vs_open("/dev/urandom", O_RDONLY, S_IRUSR);
	
	if (fd < 0) return (VS_NULL);
	
	if (vs_read(fd, buf, size) != (int)size)
		return (VS_NULL);
	
	vs_close(fd);
	
	return (buf);
}

vs_uint8_t	*vs_rdrand(vs_uint8_t *buf, vs_size_t size)
{
	unsigned int	data = 0;

	if (!buf) return (VS_NULL);
	if (!size) return (buf);

	for (vs_size_t i = 0; i < size; i++) {
		_rdrand32_step(&data);
		buf[i] = (i < size) ? ((data >> 0x18) & 0xFF) 		: 0;
		buf[i+1] = (i+1 < size) ? ((data >> 0x10) & 0xFF)	: 0;
		buf[i+2] = (i+2 < size) ? ((data >> 0x8) & 0xFF)	: 0;
		buf[i+3] = (i+3 < size) ? ((data >> 0x0) & 0xFF)	: 0;
	}
	return (buf);
}

vs_int32_t	vs_rand(int min, int max)
{
	srand(time(VS_NULL));
	return ((min + rand() % (max - min)));
}

vs_uint64_t	vs_rdrandlong(void)
{
	vs_uint64_t	data = 0;

	_rdrand64_step(&data);
	return (data);
}

vs_uint32_t	vs_rdrandint(void)
{
	vs_uint32_t	data = 0;

	_rdrand32_step(&data);
	return (data);
}

vs_uint16_t	vs_rdrandshort(void)
{
	vs_uint16_t	data = 0;

	_rdrand16_step(&data);
	return (data);
}

vs_uint8_t	vs_rdrandbyte(void)
{
	vs_uint16_t	data = 0;

	_rdrand16_step(&data);
	return (data & 0xFF);
}

