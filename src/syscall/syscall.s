.intel_syntax noprefix

.global vs_syscall

.section .text

vs_syscall:
	endbr64
	mov rax, rdi
	mov rdi, rsi
	mov rsi, rdx
	mov rdx, rcx
	mov r10, r8
	mov r8, r9
	mov r9, qword [rsp+0x8]
	syscall
	cmp rax, 0xfffffffffffff001
	jae .L_ret_errno
	ret

.L_ret_errno:
	neg eax
	mov ebx, eax
	call __errno_location
	mov dword ptr [rax], ebx
	xor ebx, eax
	xor eax, ebx
	xor ebx, eax
	or rax, 0xffffffffffffffff
	ret
