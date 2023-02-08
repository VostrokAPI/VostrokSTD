.intel_syntax noprefix
.global __vs_strlen_avx2

.section .text

__vs_strlen_avx2:
	endbr64
	xor rax, rax
	ret
