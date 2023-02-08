.intel_syntax noprefix
.file "__strlen_sse42"

.section .text, "ax"

.globl __vs_strlen_sse42

__vs_strlen_sse42:
	endbr64
	xor rax, rax
	test rdi, rdi
	jz .L_null
	mov rdx, rdi
	pxor xmm0, xmm0

.L_loop:
	pcmpistri xmm0, xmmword ptr [rdx+rax*1], 0b1000
	add eax, ecx
	test ecx, ecx
	jnz .L_loop
	ret

.L_null:
	ret
