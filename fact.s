	.file	"fact.c"
	.section	.rodata
.LC0:
	.string	"%d"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$20, %esp
	movl	$1, -16(%ebp)
	movl	$10, -20(%ebp)
	movl	$2, -12(%ebp)
	jmp	.L2
.L3:
	movl	-16(%ebp), %eax
	imull	-12(%ebp), %eax
	movl	%eax, -16(%ebp)
	incl	-12(%ebp)
.L2:
	movl	-12(%ebp), %eax
	cmpl	-20(%ebp), %eax
	jle	.L3
	movl	$.LC0, %eax
	subl	$8, %esp
	pushl	-16(%ebp)
	pushl	%eax
	call	printf
	addl	$16, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
