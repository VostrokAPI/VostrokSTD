.intel_syntax noprefix
.global __vs_strlen_sse2

.section .text

__vs_strlen_sse2:
	endbr64
	pxor xmm0, xmm0
	pxor xmm1, xmm1
	pxor xmm2, xmm2
	pxor xmm3, xmm3
	mov rax, rdi
	mov rcx, rdi
	and rcx, 0xFFF
	cmp rcx, 0xFCF
	ja .L_addr_greater_than_4047
	movdqu xmm4, xmmword ptr [rax]
	pcmpeqb xmm4, xmm0
	pmovmskb edx, xmm4
	test edx, edx
	jz .L_greater_than_15
	bsf eax, edx
	ret

.L_addr_greater_than_4047:
	and rax, 0xFFFFFFFFFFFFFFC0
	
	pcmpeqb xmm0, xmmword ptr [rax]
	pcmpeqb xmm1, xmmword ptr [rax+0x10]
	pcmpeqb xmm2, xmmword ptr [rax+0x20]
	pcmpeqb xmm3, xmmword ptr [rax+0x30]
	
	pmovmskb esi, xmm0
	pmovmskb edx, xmm1
	pmovmskb r8d, xmm2
	pmovmskb ecx, xmm3

	shl rdx, 0x10
	shl rcx, 0x10
	or rdx, rsi
	or rcx, r8
	shl rcx, 0x20
	or rdx, rcx
	mov rcx, rdi
	xor rcx, rax

	and rax, 0xFFFFFFFFFFFFFFC0
	sar rdx, cl
	test rdx, rdx
	jz .L_reset_xmm_registers
	bsf rax, rdx
	ret

.L_greater_than_15:
	and rax, 0xFFFFFFFFFFFFFFF0
	pcmpeqb xmm1, xmmword ptr [rax+0x10]
	pcmpeqb xmm2, xmmword ptr [rax+0x20]
	pcmpeqb xmm3, xmmword ptr [rax+0x30]
	pmovmskb edx, xmm1
	pmovmskb r8d, xmm2
	pmovmskb ecx, xmm3
	shl rdx, 0x10
	shl rcx, 0x10
	or rcx, r8
	shl rcx, 0x20
	or rdx, rcx
	mov rcx, rdi
	xor rcx, rax
	and rax, 0xFFFFFFFFFFFFFFC0
	sar rdx, cl
	test rdx, rdx
	jz .L_greater_than_64
	bsf rax, rdx
	ret

.L_reset_xmm_registers:
	pxor xmm0, xmm0
	pxor xmm1, xmm1
	pxor xmm2, xmm2
	pxor xmm3, xmm3

.L_greater_than_64:
	movdqa xmm0, xmmword ptr [rax+0x40]
	pminub xmm0, xmmword ptr [rax+0x50]
	pminub xmm0, xmmword ptr [rax+0x60]
	pminub xmm0, xmmword ptr [rax+0x70]
	pcmpeqb xmm0, xmm3
	pmovmskb edx, xmm0
	test edx, edx
	jnz .L_add64
	sub rax, 0xFFFFFFFFFFFFFF80
	movdqa xmm0, xmmword ptr [rax]
	pminub xmm0, xmmword ptr [rax+0x10]
	pminub xmm0, xmmword ptr [rax+0x20]
	pminub xmm0, xmmword ptr [rax+0x30]
	pcmpeqb xmm0, xmm3
	pmovmskb edx, xmm0
	test edx, edx
	jnz .L_end
	jmp .L_greater_than_64

.L_add64:
	add rax, 0x40

.L_end:
	pxor xmm0, xmm0
	pcmpeqb xmm0, xmmword ptr [rax]
	pcmpeqb xmm1, xmmword ptr [rax+0x10]
	pcmpeqb xmm2, xmmword ptr [rax+0x20]
	pcmpeqb xmm3, xmmword ptr [rax+0x30]
	pmovmskb esi, xmm0
	pmovmskb edx, xmm1
	pmovmskb r8d, xmm2
	pmovmskb ecx, xmm3
	shl rdx, 0x10
	shl rcx, 0x10
	or rdx, rsi
	or rcx, r8
	shl rcx, 0x20
	or rdx, rcx
	bsf rdx, rdx
	add rax, rdx
	sub rax, rdi
	ret

