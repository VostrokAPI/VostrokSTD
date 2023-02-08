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
	inc rax
	cmp byte ptr [rax], 0x0
	jnz .L_loop
	sub rax, rdi
	ret

.L_ret_zero:
	xor rax, rax
	ret
