.intel_syntax noprefix
.global __vs_strlen_avx2

.section .text

__vs_strlen_avx2:
	endbr64
	test rdi, rdi
	jz .L_null
	cmp byte ptr [rdi], 0
	jz .L_null

	mov ecx, edi
	mov rdx, rdi
	vpxor xmm0, xmm0, xmm0
	vpxor xmm1, xmm1, xmm1
	vpxor xmm2, xmm2, xmm2
	vpxor xmm3, xmm3, xmm3
	vpxor xmm4, xmm4, xmm4
	vpxor xmm5, xmm5, xmm5
	vpxor xmm6, xmm6, xmm6
	and ecx, 0x3F
	cmp ecx, 0x20
	ja .L1

	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L3
	add rdi, 0x20
	and ecx, 0x1F
	and rdi, 0xFFFFFFFFFFFFFFE0
	jmp .L4

.L1:
	and ecx, 0x1F
	and rdi, 0xFFFFFFFFFFFFFFE0
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi]
	vpmovmskb eax, ymm1
	sar eax, cl
	test eax, eax
	jz .L2
	tzcnt eax, eax
	add rax, rdi
	add rax, rcx
	sub rax, rdx
	vzeroupper
	ret

.L2:
	add rdi, 0x20

.L4:
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L3
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi+0x20]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L5
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi+0x40]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L6
	vpcmpeqb ymm1, ymm0, ymmword ptr [rdi+0x60]
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L_ret

	add rdi, 0x80
	mov rcx, rdi
	and ecx, 0x7F
	and rdi, 0xFFFFFFFFFFFFFF80

.L_9:
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
	jnz .L8
	add rdi, 0x80
	jmp .L_9

.L8:
	vpcmpeqb ymm1, ymm0, ymm1
	vpmovmskb eax, ymm1
	test eax, eax
	jnz .L3
	vpcmpeqb ymm2, ymm0, ymm2
	vpmovmskb eax, ymm2
	test eax, eax
	jnz .L5
	vpcmpeqb ymm3, ymm0, ymm3
	vpmovmskb eax, ymm3
	test eax, eax
	jnz .L6
	vpcmpeqb ymm4, ymm0, ymm4
	vpmovmskb eax, ymm4

.L_ret:
	tzcnt eax, eax
	add rax, 0x60
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.L3:
	tzcnt eax, eax
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.L5:
	tzcnt eax, eax
	add rax, 0x20
	add rax, rdi
	sub rax, rdx
	vzeroupper
	ret

.L6:
	tzcnt eax, eax
	add rax, 0x40
	add rax, rdi
	sub rax, rdi
	vzeroupper
	ret

.L_null:
	xor rax, rax
	ret
