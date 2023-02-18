.intel_syntax noprefix

.global __vs_memmove_erms_aligned

.section .text

__vs_memmove_erms_aligned:
	endbr64
	mov rax, rdi
	test rdi, rdi
	jz .L_ret
	test rsi, rsi
	jz .L_ret
	test rdx, rdx
	jz .L_ret

	mov rcx, rdx
	test rdx, 0x7
	jz .L_mod8
	test rdx, 0x3
	jz .L_mod4
	test rdx, 0x1
	jz .L_mod2

.L_mod1:
	cmp rdi, rsi
	jz .L_ret
	lea rdx, qword ptr [rdi+rcx]
	cmp rdi, rdx
	jb .L_mod1_dst_below_src
	lea rdi, qword ptr [rdi+rcx-1]
	lea rsi, qword ptr [rsi+rcx-1]
	std
	rep movsb
	cld
	ret

.L_mod1_dst_below_src:
	rep movsb
	ret

.L_mod2:
	shr rcx, 0x1
	cmp rdi, rsi
	jz .L_ret
	lea rdx, qword ptr [rdi+rcx]
	cmp rdi, rdx
	jb .L_mod2_dst_below_src
	lea rdi, qword ptr [rdi+rcx-1]
	lea rsi, qword ptr [rsi+rcx-1]
	std
	rep movsw
	cld
	ret

.L_mod2_dst_below_src:
	rep movsw
	ret

.L_mod4:
	shr rcx, 0x2
	cmp rdi, rsi
	jz .L_ret
	lea rdx, qword ptr [rdi+rcx]
	cmp rdi, rdx
	jb .L_mod4_dst_below_src
	lea rdi, qword ptr [rdi+rcx-1]
	lea rsi, qword ptr [rsi+rcx-1]
	std
	rep movsd
	cld
	ret

.L_mod4_dst_below_src:
	rep movsd
	ret

.L_mod8:
	shr rcx, 0x3
	cmp rdi, rsi
	jz .L_ret
	lea rdx, qword ptr [rdi+rcx]
	cmp rdi, rdx
	jb .L_mod8_dst_below_src
	lea rdi, qword ptr [rdi+rcx-1]
	lea rsi, qword ptr [rsi+rcx-1]
	std
	rep movsq
	cld
	ret

.L_mod8_dst_below_src:
	rep movsq

.L_ret:
	ret	
