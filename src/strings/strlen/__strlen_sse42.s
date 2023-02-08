.intel_syntax noprefix
.file "__strlen_sse42"

.section .text, "ax"

.globl __vs_strlen_sse42

__vs_strlen_sse42:
	test rdi, rdi
	jz .L_null
	xor rax, rax
	mov rcx, rdi
	mov eax, -16
	mov rdx, rcx
	pxor xmm0, xmm0

.L_loop:
	add eax, 0x10
	pcmpistri xmm0, xmmword ptr [rdx+rax*1], 0b1000
	add eax, ecx
	ret

.L_null:
	xor rax, rax
	ret
