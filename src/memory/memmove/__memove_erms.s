.intel_syntax noprefix
.global __vs_memmove_erms

.section .text

__vs_memmove_erms:
	endbr64
	mov rax, rdi
	test rdi, rdi
	jz .L_ret
	test rsi, rsi
	jz .L_ret
	test rdx, rdx
	jz .L_ret

.L_loop:
	mov rcx, rdx
	cmp rdi, rsi
	jb .L_dst_below_src
	jz .L_ret
	lea rdx, qword ptr [rsi+rcx]
	cmp rdi, rdx
	jb .L_dst_below_src
	lea rdi, qword ptr [rdi+rcx-1]
	lea rsi, qword ptr [rsi+rcx-1]
	std
	rep movsb
	cld
	ret

.L_dst_below_src:
	rep movsb

.L_ret:
	ret

