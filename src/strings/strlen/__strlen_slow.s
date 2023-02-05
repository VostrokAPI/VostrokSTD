.intel_syntax noprefix

.global __vs_strlen_slow

.section .text

__vs_strlen_slow:
	endbr64
	test rdi, rdi
	jz .L_ret_zero
	cmp byte ptr [rdi], 0x0
	jz .L_ret_zero
	mov rax, rdi

.L_loop:
	inc rdi
	cmp byte ptr [rdi], 0x0
	jnz .L_loop
	sub rdi, rax
	xor rdi, rax
	xor rax, rdi
	xor rdi, rax
	ret

.L_ret_zero:
	xor rax, rax
	ret
