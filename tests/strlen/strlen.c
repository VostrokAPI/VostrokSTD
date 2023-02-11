#include <stdio.h>
#include <string.h>
#include <signal.h>

#include "_vs_std.h"
#include "greatest.h"

/////////////////////////////
//
//		STRLEN SLOW TEST
//
/////////////////////////////

TEST	vs_strlen_slow_null(void)
{
	ASSERT_EQ(__vs_strlen_slow(NULL), 0);
	PASS();
}

TEST	vs_strlen_slow_basics(void)
{
	ASSERT_EQ(__vs_strlen_slow("hello"), strlen("hello"));
	PASS();
}

TEST	vs_strlen_slow_null_byte(void)
{
	ASSERT_EQ(__vs_strlen_slow(""), 0);
	PASS();
}

TEST	vs_strlen_slow_small_buf(void)
{
	char	buf[0x40];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ(__vs_strlen_slow(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_slow_med_buf(void)
{
	char	buf[0x80];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ(__vs_strlen_slow(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_slow_big_buf(void)
{
	char	buf[0x100];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_slow(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_slow_very_big(void)
{
	char	buf[0x1000];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_slow(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_slow_unaligned_small(void)
{
	char	buf[37];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_slow(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_slow_unaligned_med(void)
{
	char	buf[121];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_slow(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_slow_unaligned_big(void)
{
	char	buf[0xff6];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_slow(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_slow_large_buf(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFF);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	memset(ptr, 0, 0xFFFFFFFF);
	memset(ptr, 'A', 0xFFFFFFFF);
	ASSERT_EQ(__vs_strlen_slow(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

TEST	vs_strlen_slow_large_buf_unaligned(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFA);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	memset(ptr, 0, 0xFFFFFFFA);
	memset(ptr, 'A', 0xFFFFFFFA);
	ASSERT_EQ(__vs_strlen_slow(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

SUITE(strlen_slow_test)
{
	RUN_TEST(vs_strlen_slow_null);
	RUN_TEST(vs_strlen_slow_basics);
	RUN_TEST(vs_strlen_slow_null_byte);
	RUN_TEST(vs_strlen_slow_small_buf);
	RUN_TEST(vs_strlen_slow_med_buf);
	RUN_TEST(vs_strlen_slow_big_buf);
	RUN_TEST(vs_strlen_slow_very_big);
	RUN_TEST(vs_strlen_slow_unaligned_small);
	RUN_TEST(vs_strlen_slow_unaligned_med);
	RUN_TEST(vs_strlen_slow_unaligned_big);
	RUN_TEST(vs_strlen_slow_large_buf);
	RUN_TEST(vs_strlen_slow_large_buf_unaligned);
}

/////////////////////////////
//
//		STRLEN SSE4.2
//
/////////////////////////////

TEST	vs_strlen_sse42_null(void)
{
	ASSERT_EQ(__vs_strlen_sse42(NULL), 0);
	PASS();
}

TEST	vs_strlen_sse42_basics(void)
{
	ASSERT_EQ_FMT(__vs_strlen_sse42("hello"), strlen("hello"), "%ld");
	PASS();
}

TEST	vs_strlen_sse42_null_byte(void)
{
	ASSERT_EQ(__vs_strlen_sse42(""), 0);
	PASS();
}

TEST	vs_strlen_sse42_small_buf(void)
{
	char	buf[0x40];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ_FMT(__vs_strlen_sse42(buf), strlen(buf), "%ld");
	PASS();
}

TEST	vs_strlen_sse42_med_buf(void)
{
	char	buf[0x80];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ(__vs_strlen_sse42(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse42_big_buf(void)
{
	char	buf[0x100];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse42(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse42_very_big(void)
{
	char	buf[0x1000];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse42(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse42_unaligned_small(void)
{
	char	buf[37];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse42(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse42_unaligned_med(void)
{
	char	buf[121];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse42(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse42_unaligned_big(void)
{
	char	buf[0xff6];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse42(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse42_large_buf(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFF);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	memset(ptr, 0, 0xFFFFFFFF);
	memset(ptr, 'A', 0xFFFFFFFF);
	ASSERT_EQ(__vs_strlen_sse42(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

TEST	vs_strlen_sse42_large_buf_unaligned(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFA);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	memset(ptr, 0, 0xFFFFFFFA);
	memset(ptr, 'A', 0xFFFFFFFA);
	ASSERT_EQ(__vs_strlen_sse42(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

SUITE(strlen_sse42_test)
{
	RUN_TEST(vs_strlen_sse42_null);
	RUN_TEST(vs_strlen_sse42_basics);
	RUN_TEST(vs_strlen_sse42_null_byte);
	RUN_TEST(vs_strlen_sse42_small_buf);
	RUN_TEST(vs_strlen_sse42_med_buf);
	RUN_TEST(vs_strlen_sse42_big_buf);
	RUN_TEST(vs_strlen_sse42_very_big);
	RUN_TEST(vs_strlen_sse42_unaligned_small);
	RUN_TEST(vs_strlen_sse42_unaligned_med);
	RUN_TEST(vs_strlen_sse42_unaligned_big);
	RUN_TEST(vs_strlen_sse42_large_buf);
	RUN_TEST(vs_strlen_sse42_large_buf_unaligned);
}

/////////////////////////////
//
//		STRLEN SSE2
//
/////////////////////////////

TEST	vs_strlen_sse2_null(void)
{
	ASSERT_EQ(__vs_strlen_sse2(NULL), 0);
	PASS();
}

TEST	vs_strlen_sse2_basics(void)
{
	ASSERT_EQ_FMT(__vs_strlen_sse2("hello"), strlen("hello"), "%ld");
	PASS();
}

TEST	vs_strlen_sse2_null_byte(void)
{
	ASSERT_EQ(__vs_strlen_sse2(""), 0);
	PASS();
}

TEST	vs_strlen_sse2_small_buf(void)
{
	char	buf[0x40];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ_FMT(__vs_strlen_sse2(buf), strlen(buf), "%ld");
	PASS();
}

TEST	vs_strlen_sse2_med_buf(void)
{
	char	buf[0x80];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ(__vs_strlen_sse2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse2_big_buf(void)
{
	char	buf[0x100];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse2_very_big(void)
{
	char	buf[0x1000];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse2_unaligned_small(void)
{
	char	buf[37];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse2_unaligned_med(void)
{
	char	buf[121];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse2_unaligned_big(void)
{
	char	buf[0xff6];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_sse2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_sse2_large_buf(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFF);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	memset(ptr, 0, 0xFFFFFFFF);
	memset(ptr, 'A', 0xFFFFFFFF);
	ASSERT_EQ(__vs_strlen_sse2(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

TEST	vs_strlen_sse2_large_buf_unaligned(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFA);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	memset(ptr, 0, 0xFFFFFFFA);
	memset(ptr, 'A', 0xFFFFFFFA);
	ASSERT_EQ(__vs_strlen_sse2(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

SUITE(strlen_sse2_test)
{
	RUN_TEST(vs_strlen_sse2_null);
	RUN_TEST(vs_strlen_sse2_basics);
	RUN_TEST(vs_strlen_sse2_null_byte);
	RUN_TEST(vs_strlen_sse2_small_buf);
	RUN_TEST(vs_strlen_sse2_med_buf);
	RUN_TEST(vs_strlen_sse2_big_buf);
	RUN_TEST(vs_strlen_sse2_very_big);
	RUN_TEST(vs_strlen_sse2_unaligned_small);
	RUN_TEST(vs_strlen_sse2_unaligned_med);
	RUN_TEST(vs_strlen_sse2_unaligned_big);
	RUN_TEST(vs_strlen_sse2_large_buf);
	RUN_TEST(vs_strlen_sse2_large_buf_unaligned);
}

/////////////////////////////
//
//		STRLEN AVX2
//
/////////////////////////////

TEST	vs_strlen_avx2_null(void)
{
	ASSERT_EQ(__vs_strlen_avx2(NULL), 0);
	PASS();
}

TEST	vs_strlen_avx2_basics(void)
{
	ASSERT_EQ_FMT(__vs_strlen_avx2("hello"), strlen("hello"), "%ld");
	PASS();
}

TEST	vs_strlen_avx2_null_byte(void)
{
	ASSERT_EQ(__vs_strlen_avx2(""), 0);
	PASS();
}

TEST	vs_strlen_avx2_small_buf(void)
{
	char	buf[0x40];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ_FMT(__vs_strlen_avx2(buf), strlen(buf), "%ld");
	PASS();
}

TEST	vs_strlen_avx2_med_buf(void)
{
	char	buf[0x80];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));

	ASSERT_EQ(__vs_strlen_avx2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_avx2_big_buf(void)
{
	char	buf[0x100];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_avx2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_avx2_very_big(void)
{
	char	buf[0x1000];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_avx2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_avx2_unaligned_small(void)
{
	char	buf[37];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_avx2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_avx2_unaligned_med(void)
{
	char	buf[125];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_avx2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_avx2_unaligned_big(void)
{
	char	buf[0xff6];

	memset(buf, 0, sizeof(buf));
	memset(buf, 'A', sizeof(buf));
	ASSERT_EQ(__vs_strlen_avx2(buf), strlen(buf));
	PASS();
}

TEST	vs_strlen_avx2_large_buf(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFF);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	
	memset(ptr, 0, 0xFFFFFFFF);
	memset(ptr, 'A', 0xFFFFFFFF);
	ASSERT_EQ(__vs_strlen_avx2(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

TEST	vs_strlen_avx2_large_buf_unaligned(void)
{
	char	*ptr = malloc(sizeof(char) * 0xFFFFFFFA);

	if (!ptr)
		FAILm("Error: Failed to allocate memory");
	
	memset(ptr, 0, 0xFFFFFFFA);
	memset(ptr, 'A', 0xFFFFFFFA);
	ASSERT_EQ(__vs_strlen_avx2(ptr), strlen(ptr));
	free(ptr);
	PASS();
}

SUITE(strlen_avx2_test)
{
	RUN_TEST(vs_strlen_avx2_null);
	RUN_TEST(vs_strlen_avx2_basics);
	RUN_TEST(vs_strlen_avx2_null_byte);
	RUN_TEST(vs_strlen_avx2_small_buf);
	RUN_TEST(vs_strlen_avx2_med_buf);
	RUN_TEST(vs_strlen_avx2_big_buf);
	RUN_TEST(vs_strlen_avx2_very_big);
	RUN_TEST(vs_strlen_avx2_unaligned_small);
	RUN_TEST(vs_strlen_avx2_unaligned_med);
	RUN_TEST(vs_strlen_avx2_unaligned_big);
	RUN_TEST(vs_strlen_avx2_large_buf);
	RUN_TEST(vs_strlen_avx2_large_buf_unaligned);
}

void	catch_sig(int sig)
{
	if (sig == SIGSEGV) {
		printf("\033[31m[+] SIGSEGV Detected\n\033[00m");
		exit(1);
	}
}

GREATEST_MAIN_DEFS();

int main(int argc, char **argv)
{
	signal(SIGSEGV, catch_sig);

	__builtin_cpu_init();
	
	GREATEST_MAIN_BEGIN();
	
	RUN_SUITE(strlen_slow_test);
	
	if (__builtin_cpu_supports("sse2"))
		RUN_SUITE(strlen_sse2_test);
	else
		printf("\033[31m[-] Your cpu doest not support SSE2 Extension, test not performed !\033[00m");

	if (__builtin_cpu_supports("sse4.2"))
		RUN_SUITE(strlen_sse42_test);
	else
		printf("\033[31m[-] Your cpu does not support SSE4.2 Extension, test not performed !\033[00m");

	if (__builtin_cpu_supports("avx2"))
		RUN_SUITE(strlen_avx2_test);
	else
		printf("\033[31m[-] Your cpu does not support AVX2 Extension, test not performed !\033[00m");

	GREATEST_MAIN_END();
	return (0);
}
