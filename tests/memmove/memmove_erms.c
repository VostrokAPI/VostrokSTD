#include "greatest.h"
#include "_vs_std.h"
#include "vs_rand.h"
#include "vs_types.h"
#include <stdlib.h>
#include <string.h>

/////////////////////////////
//
//		MEMMOVE ERMS
//
/////////////////////////////

TEST	memmove_erms_basic_1(void)
{
	char		dst = 0;
	const char	src = 'A';

	__vs_memmove_erms(&dst, &src, sizeof(char));
	ASSERT_MEM_EQ(&dst, &src, sizeof(char));
	PASS();
}

TEST	memmove_erms_basic_2(void)
{
	char		dst[0x2] = {0, 0};
	const char	src[0x2] = {'A', 'B'};

	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(dst));
	PASS();
}

TEST	memmove_erms_basic_4(void)
{
	char		dst[0x4] = {0, 0, 0, 0};
	const char	src[0x4] = {'A', 'B', 'C', 'D'};

	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(dst));
	PASS();
}

TEST	memmove_erms_basic_8(void)
{
	char		dst[0x8] = {0, 0, 0, 0, 0, 0, 0, 0};
	const char	src[0x8] = {'A', 'B', 'C', 'D', \
						  'E', 'F', 'G', 'H'};

	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_16(void)
{
	char		dst[0x10];
	const char	src[0x10] = "hello world test";

	memset(dst, 0, sizeof(dst));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_32(void)
{
	char		dst[0x20];
	const char	src[0x20] = "hello world test hello world lol";

	memset(dst, 0, sizeof(dst));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_64(void)
{
	char		dst[0x40];
	const char	src[0x40] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

	memset(dst, 0, sizeof(dst));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_80(void)
{
	char		dst[0x50];
	char		src[0x50];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_100(void)
{
	char	dst[0x64];
	char	src[0x64];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_128(void)
{
	char	dst[0x80];
	char	src[0x80];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_160(void)
{
	char	dst[0xA0];
	char	src[0xA0];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_200(void)
{
	char	dst[0xC8];
	char	src[0xC8];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_256(void)
{
	char	dst[0x100];
	char	src[0x100];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_512(void)
{
	char	dst[0x200];
	char	src[0x200];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_1024(void)
{
	char	dst[0x400];
	char	src[0x400];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_2048(void)
{
	char	dst[0x800];
	char	src[0x800];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_4096(void)
{
	char	dst[0x1000];
	char	src[0x1000];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_8192(void)
{
	char	dst[0x2000];
	char	src[0x2000];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_16384(void)
{
	char	dst[16384];
	char	src[16384];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_32768(void)
{
	char	dst[32768];
	char	src[32768];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_48000(void)
{
	char	dst[48000];
	char	src[48000];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(src));
	ASSERT_MEM_EQ(dst, src, sizeof(src));
	PASS();
}

TEST	memmove_erms_basic_65535(void)
{
	char	*dst = (char *)malloc(sizeof(char) * 0xFFFF);
	char	*src = (char *)malloc(sizeof(char) * 0xFFFF);

	memset(dst, 0, 0xFFFF);
	memset(src, 'A', 0xFFFF);
	__vs_memmove_erms(dst, src, 0xFFFF);
	ASSERT_MEM_EQ(dst, src, 0xFFFF);
	free(dst);
	free(src);
	PASS();
}

TEST	memmove_erms_basic_FFFFF(void)
{
	char	*dst = (char *)malloc(sizeof(char) * 0xFFFFF);
	char	*src = (char *)malloc(sizeof(char) * 0xFFFFF);

	memset(dst, 0, 0xFFFFF);
	memset(src, 'A', 0xFFFFF);
	__vs_memmove_erms(dst, src, 0xFFFFF);
	ASSERT_MEM_EQ(dst, src, 0xFFFFF);
	free(dst);
	free(src);
	PASS();
}

TEST	memmove_erms_basic_FFFFFF(void)
{
	char	*dst = (char *)malloc(sizeof(char) * 0xFFFFFF);
	char	*src = (char *)malloc(sizeof(char) * 0xFFFFFF);

	memset(dst, 0, 0xFFFFFF);
	memset(src, 'A', 0xFFFFFF);
	__vs_memmove_erms(dst, src, 0xFFFFFF);
	ASSERT_MEM_EQ(dst, src, 0xFFFFFF);
	free(dst);
	free(src);
	PASS();
}

TEST	memmove_erms_basic_1000(void)
{
	char	dst[1000];
	char	src[1000];

	memset(dst, 0, sizeof(dst));
	memset(src, 'A', sizeof(src));
	__vs_memmove_erms(dst, src, sizeof(dst));
	ASSERT_MEM_EQ(dst, src, sizeof(dst));
	PASS();
}

TEST	memmove_erms_basic_7FFFFFFF(void)
{
	char	*dst = (char *)malloc(sizeof(char) * 0x7FFFFFFF);
	char	*src = (char *)malloc(sizeof(char) * 0x7FFFFFFF);

	memset(dst, 0, 0x7FFFFFFF);
	memset(src, 'A', 0x7FFFFFFF);
	__vs_memmove_erms(dst, src, 0x7FFFFFFF);
	ASSERT_MEM_EQ(dst, src, 0x7FFFFFFF);
	free(dst);
	free(src);
	PASS();
}

TEST	memmove_erms_basic_80000000(void)
{
	char	*dst = (char *)malloc(sizeof(char) * 0x80000000);
	char	*src = (char *)malloc(sizeof(char) * 0x80000000);

	memset(dst, 0, 0x80000000);
	memset(src, 'A', 0x80000000);
	__vs_memmove_erms(dst, src, 0x80000000);
	ASSERT_MEM_EQ(dst, src, 0x80000000);
	free(dst);
	free(src);
	PASS();
}

TEST	memmove_erms_basic_random(void)
{
	vs_uint8_t	dst[0xFFFFF];
	vs_uint8_t	buf[0xFFFFF];

	memset(dst, 0, sizeof(dst));
	memset(buf, 0, sizeof(buf));
	vs_rdrand(buf, sizeof(buf));
	__vs_memmove_erms(dst, buf, sizeof(buf));
	ASSERT_MEM_EQ(dst, buf, sizeof(buf));
	PASS();
}

TEST	memmove_erms_basic_random_cpy_backward(void)
{
	vs_uint8_t	buf[0xFFFFF];
	vs_uint8_t	dst[0xFFFFF];

	memset(dst, 0, sizeof(dst));
	memset(buf, 0, sizeof(buf));
	vs_rdrand(buf, sizeof(buf));
	__vs_memmove_erms(dst, buf, sizeof(buf));
	ASSERT_MEM_EQ(dst, buf, sizeof(buf));
	PASS();
}

TEST	memmove_erms_basic_segvtest(void)
{
	char	buf[0x100];
	char	*ptr = buf;

	ASSERT_EQ(ptr, __vs_memmove_erms(buf, NULL, 5));
	ASSERT_EQ(ptr, __vs_memmove_erms(buf, "hello", 0));
	ASSERT_EQ(VS_NULL, __vs_memmove_erms(VS_NULL, "hello", 5));
	PASS();
}

SUITE(memmove_erms_test)
{
	RUN_TEST(memmove_erms_basic_1);
	RUN_TEST(memmove_erms_basic_2);
	RUN_TEST(memmove_erms_basic_4);
	RUN_TEST(memmove_erms_basic_8);
	RUN_TEST(memmove_erms_basic_16);
	RUN_TEST(memmove_erms_basic_32);
	RUN_TEST(memmove_erms_basic_64);
	RUN_TEST(memmove_erms_basic_80);
	RUN_TEST(memmove_erms_basic_100);
	RUN_TEST(memmove_erms_basic_128);
	RUN_TEST(memmove_erms_basic_160);
	RUN_TEST(memmove_erms_basic_200);
	RUN_TEST(memmove_erms_basic_256);
	RUN_TEST(memmove_erms_basic_512);
	RUN_TEST(memmove_erms_basic_1000);
	RUN_TEST(memmove_erms_basic_1024);
	RUN_TEST(memmove_erms_basic_2048);
	RUN_TEST(memmove_erms_basic_4096);
	RUN_TEST(memmove_erms_basic_8192);
	RUN_TEST(memmove_erms_basic_16384);
	RUN_TEST(memmove_erms_basic_32768);
	RUN_TEST(memmove_erms_basic_48000);
	RUN_TEST(memmove_erms_basic_65535);
	RUN_TEST(memmove_erms_basic_FFFFF);
	RUN_TEST(memmove_erms_basic_FFFFFF);
	RUN_TEST(memmove_erms_basic_7FFFFFFF);
	RUN_TEST(memmove_erms_basic_80000000);
	for (int i = 0; i < 100; i++)
		RUN_TEST(memmove_erms_basic_random);
	for (int i = 0; i < 100; i++)
		RUN_TEST(memmove_erms_basic_random_cpy_backward);
	RUN_TEST(memmove_erms_basic_segvtest);
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(memmove_erms_test);

	GREATEST_MAIN_END();
	return (0);
}
