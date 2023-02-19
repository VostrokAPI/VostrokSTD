#include "greatest.h"
#include "_vs_std.h"
#include "vs_rand.h"
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
	PASS();
}

TEST	memmove_erms_basic_32768(void)
{
	PASS();
}

TEST	memmove_erms_basic_48000(void)
{
	PASS();
}

TEST	memmove_erms_basic_65535(void)
{
	PASS();
}

TEST	memmove_erms_basic_FFFFF(void)
{
	PASS();
}

TEST	memmove_erms_basic_FFFFFF(void)
{
	PASS();
}

TEST	memmove_erms_basic_1000(void)
{
	PASS();
}

TEST	memmove_erms_basic_FFFFFFFF(void)
{
	PASS();
}

TEST	memmove_erms_basic_7FFFFFFF(void)
{
	PASS();
}

TEST	memmove_erms_basic_80000000(void)
{
	PASS();
}

TEST	memmove_erms_basic_random(void)
{
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
	RUN_TEST(memmove_erms_basic_FFFFFFFF);
	RUN_TEST(memmove_erms_basic_7FFFFFFF);
	RUN_TEST(memmove_erms_basic_80000000);
	for (int i = 0; i < 100; i++)
		RUN_TEST(memmove_erms_basic_random);
}


GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();

	RUN_SUITE(memmove_erms_test);

	GREATEST_MAIN_END();
	return (0);
}
