.intel_syntax noprefix
.global __vs_strlen_avx2

.section .text

__vs_strlen_avx2:
	endbr64
	test rdi, rdi
	jz .L_null
	mov ecx, edi
	mov rdx, rdi
	vpxor xmm0, xmm0, xmm0
	and ecx, 0x3F
	cmp ecx, 0x20
	ja .L_addr_first_byte_above_32
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L_end1
	add rdi, 0x20
	and ecx, 0x1F
	and rdi, -0x1F
	jmp .L_next_label

.L_addr_first_byte_above_32:
	and ecx, 0x1F
	and rdi, -0x1F
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi]
	vpmovmskb eax, ymm1
	sar eax, cl
	test eax, eax
	jz .L_add_rdi_32
	tzcnt eax, eax
	add rax, rdi
	add rax, rcx
	sub rax, rdx
	vzeroupper
	ret

.L_add_rdi_32:
	add rdi, 0x20

.L_next_label:
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L_end1
	
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi+0x20]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L_end2
	
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi+0x40]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L_end3

	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi+0x60]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L_end4

	add rdi, 0x80
	mov rcx, rdi
	and ecx, 0x7F
	and rdi, -0x1F

.L_loop:
	vmovdqa ymm1, ymmword ptr [rdi]
	vmovdqa ymm2, ymmword ptr [rdi+0x20]
	vmovdqa ymm3, ymmword ptr [rdi+0x40]
	vmovdqa ymm4, ymmword ptr [rdi+0x60]
	
	vpminub ymm5, ymm2, ymm1
	vpminub ymm6, ymm4, ymm3
	vpminub ymm5, ymm6, ymm5
	
	vpcmpeqb ymm5, ymm0, ymm5
	vpmovmskb eax, ymm5
	test eax, eax
	jnz .L_end_loop
	add rdi, 0x80
	jmp .L_loop

.L_end_loop:
	vpcmpeqb ymm1, ymm0, ymm1
	vpmovmskb eax, ymm1
	test eax, eax
	jnz end1
	
	vpcmpeqb ymm2, ymm0, ymm2
	vpmovmskb eax, ymm2
	test eax, eax
	jnz .L_end2

	vpcmpeqb ymm3, ymm0, ymm3
	vpmovmskb eax, ymm3
	test eax, eax
	jnz .L_end3

	vpcmpeqb ymm4, ymm0, ymm4
	vpmovmskb eax, ymm4

.L_end4:
	tzcnt eax, eax
	add rax, 0x60
	add rax, rdi
	sub rax, rdi
	vzeroupper
	ret

.L_end1:
	tzcnt eax, eax
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.L_end2:
	tzcnt eax, eax
	add rax, 0x20
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.L_end3:
	tzcnt eax, eax
	add rax, 0x40
	add rax, rdi
	sub rax, rdi
	vzeroupper
	ret

.L_null:
	xor rax, rax
	ret
