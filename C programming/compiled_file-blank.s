	.file	"blank.c"
	.text
	.globl	BITS
	.data
	.type	BITS, @object
	.size	BITS, 1
BITS:
	.byte	8
	.section	.rodata
.LC0:
	.string	"Signed 8: %d\n"
.LC1:
	.string	"Unsigned 8: %u\n"
.LC2:
	.string	"Signed 16: %d\n"
.LC3:
	.string	"Unsigned 16: %d\n"
.LC4:
	.string	"Signed 32: %d\n"
.LC5:
	.string	"Unsigned 32: %u\n"
.LC6:
	.string	"Signed 64: %lld\n"
.LC7:
	.string	"Unsigned 64: %llu\n"
	.align 8
.LC8:
	.string	"The sum from my for loop is %u\n"
	.align 8
.LC9:
	.string	"Overflow error: cannot add %d and %d.\n"
.LC10:
	.string	"Result of addition: %d\n"
.LC11:
	.string	"><"
.LC12:
	.string	"\n"
.LC13:
	.string	"Standard types:"
.LC14:
	.string	"\tSize of int: %zu\n"
.LC15:
	.string	"\tSize of long: %zu\n"
.LC16:
	.string	"\tSize of long long: %zu\n"
.LC17:
	.string	"\nFixed-Width Types:"
.LC18:
	.string	"\tSize of int8_t: %zu\n"
.LC19:
	.string	"\tSize of int16_t: %zu\n"
.LC20:
	.string	"\tSize of int32_t: %zu\n"
.LC21:
	.string	"\tSize of int64_t: %zu\n"
.LC22:
	.string	"\nInteger Value Ranges:"
.LC23:
	.string	"\tINT_MAX: %d\n"
.LC24:
	.string	"\tINT_MIN: %d\n"
.LC25:
	.string	"\tUINT_MAX: %u\n"
.LC26:
	.string	"\tLONG_MAX: %ld\n"
.LC27:
	.string	"\tLONG_MIN: %ld\n"
.LC28:
	.string	"\nFixed-Width Value Ranges"
.LC29:
	.string	"\tint8_t: Min = %d, Max = %d\n"
.LC30:
	.string	"\tint16_t: Min = %d, Max = %d\n"
.LC31:
	.string	"\tint32_t: Min = %d, Max = %d\n"
	.align 8
.LC32:
	.string	"\tint64_t: Min = %lld, Max = %lld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movb	$127, -54(%rbp)
	movb	$-1, -53(%rbp)
	movw	$32767, -52(%rbp)
	movw	$-1, -50(%rbp)
	movl	$2147483647, -44(%rbp)
	movl	$-1, -40(%rbp)
	movabsq	$9223372036854775807, %rax
	movq	%rax, -16(%rbp)
	movq	$-1, -8(%rbp)
	movsbl	-54(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movzbl	-53(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movswl	-52(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movzwl	-50(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-44(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-40(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	$0, -24(%rbp)
	movb	$0, -55(%rbp)
	jmp	.L2
.L3:
	movzbl	-55(%rbp), %eax
	addl	$1, %eax
	cltq
	addq	%rax, -24(%rbp)
	movzbl	-55(%rbp), %eax
	addl	$1, %eax
	movb	%al, -55(%rbp)
.L2:
	cmpb	$-1, -55(%rbp)
	jne	.L3
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2147483647, -36(%rbp)
	movl	$1, -32(%rbp)
	movl	$2147483647, %eax
	subl	-32(%rbp), %eax
	cmpl	%eax, -36(%rbp)
	jle	.L4
	movl	-32(%rbp), %edx
	movl	-36(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L5
.L4:
	movl	-36(%rbp), %edx
	movl	-32(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -28(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L5:
	movl	$0, -48(%rbp)
	jmp	.L6
.L7:
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -48(%rbp)
.L6:
	cmpl	$14, -48(%rbp)
	jle	.L7
	leaq	.LC12(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	leaq	.LC13(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$4, %esi
	leaq	.LC14(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$8, %esi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$8, %esi
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$1, %esi
	leaq	.LC18(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2, %esi
	leaq	.LC19(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$4, %esi
	leaq	.LC20(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$8, %esi
	leaq	.LC21(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC22(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$2147483647, %esi
	leaq	.LC23(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$-2147483648, %esi
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$-1, %esi
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movabsq	$9223372036854775807, %rax
	movq	%rax, %rsi
	leaq	.LC26(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movabsq	$-9223372036854775808, %rax
	movq	%rax, %rsi
	leaq	.LC27(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC28(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$127, %edx
	movl	$-128, %esi
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$32767, %edx
	movl	$-32768, %esi
	leaq	.LC30(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2147483647, %edx
	movl	$-2147483648, %esi
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movabsq	$9223372036854775807, %rax
	movq	%rax, %rdx
	movabsq	$-9223372036854775808, %rax
	movq	%rax, %rsi
	leaq	.LC32(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
