	.file	"coins.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
.globl c
	.bss
	.align 8
	.type	c, @object
	.size	c, 8
c:
	.zero	8
.globl x
	.align 32
	.type	x, @object
	.size	x, 79360
x:
	.zero	79360
.globl __divdi3
	.text
.globl _Z5recurxiii
	.type	_Z5recurxiii, @function
_Z5recurxiii:
.LFB963:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	movl	8(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -44(%ebp)
	cmpl	$0, -44(%ebp)
	jg	.L2
	.cfi_offset 3, -12
	cmpl	$0, -44(%ebp)
	js	.L9
	cmpl	$11, -48(%ebp)
	ja	.L2
.L9:
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	jmp	.L4
.L2:
	movl	16(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	20(%ebp), %eax
	sall	$4, %eax
	addl	24(%ebp), %eax
	sall	$3, %eax
	addl	$x, %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	testl	%edx, %edx
	js	.L5
	testl	%edx, %edx
	jg	.L10
	cmpl	$0, %eax
	jbe	.L5
.L10:
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	(%eax), %eax
	jmp	.L4
.L5:
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	shrdl	$1, %edx, %eax
	sarl	%edx
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	16(%ebp), %eax
	leal	1(%eax), %edx
	movl	24(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-24(%ebp), %eax
	movl	-20(%ebp), %edx
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_Z5recurxiii
	movl	%eax, -24(%ebp)
	movl	%edx, -20(%ebp)
	movl	20(%ebp), %eax
	leal	1(%eax), %ebx
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	$3, 8(%esp)
	movl	$0, 12(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	__divdi3
	movl	24(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_Z5recurxiii
	movl	%eax, -32(%ebp)
	movl	%edx, -28(%ebp)
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	shrdl	$2, %edx, %eax
	sarl	$2, %edx
	movl	%eax, c
	movl	%edx, c+4
	movl	24(%ebp), %eax
	leal	1(%eax), %ecx
	movl	c, %eax
	movl	c+4, %edx
	movl	%ecx, 16(%esp)
	movl	20(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_Z5recurxiii
	movl	%eax, c
	movl	%edx, c+4
	movl	-32(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	-24(%ebp), %ecx
	movl	-20(%ebp), %ebx
	addl	%eax, %ecx
	adcl	%edx, %ebx
	movl	c, %eax
	movl	c+4, %edx
	addl	%ecx, %eax
	adcl	%ebx, %edx
	movl	%eax, -40(%ebp)
	movl	%edx, -36(%ebp)
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	cmpl	-44(%ebp), %edx
	jl	.L7
	cmpl	-44(%ebp), %edx
	jg	.L11
	cmpl	-48(%ebp), %eax
	jbe	.L7
.L11:
	movl	-12(%ebp), %ecx
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	movl	-40(%ebp), %eax
	movl	-36(%ebp), %edx
	jmp	.L4
.L7:
	movl	-12(%ebp), %ecx
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	%eax, (%ecx)
	movl	%edx, 4(%ecx)
	movl	-48(%ebp), %eax
	movl	-44(%ebp), %edx
.L4:
	addl	$84, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE963:
	.size	_Z5recurxiii, .-_Z5recurxiii
	.section	.rodata
.LC0:
	.string	"%lld"
	.text
.globl main
	.type	main, @function
main:
.LFB964:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$80, %esp
	jmp	.L13
.L26:
	movl	$0, 72(%esp)
	movl	$0, 76(%esp)
	jmp	.L14
.L25:
	movl	$0, 64(%esp)
	movl	$0, 68(%esp)
	jmp	.L15
.L22:
	movl	$0, 56(%esp)
	movl	$0, 60(%esp)
	jmp	.L16
.L19:
	movl	72(%esp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$2, %eax
	addl	64(%esp), %eax
	sall	$4, %eax
	addl	56(%esp), %eax
	movl	$-1, x(,%eax,8)
	movl	$-1, x+4(,%eax,8)
	addl	$1, 56(%esp)
	adcl	$0, 60(%esp)
.L16:
	movl	$1, %eax
	cmpl	$0, 60(%esp)
	js	.L17
	cmpl	$0, 60(%esp)
	jg	.L18
	cmpl	$15, 56(%esp)
	jbe	.L17
.L18:
	movl	$0, %eax
.L17:
	testb	%al, %al
	jne	.L19
	addl	$1, 64(%esp)
	adcl	$0, 68(%esp)
.L15:
	movl	$1, %eax
	cmpl	$0, 68(%esp)
	js	.L20
	cmpl	$0, 68(%esp)
	jg	.L21
	cmpl	$19, 64(%esp)
	jbe	.L20
.L21:
	movl	$0, %eax
.L20:
	testb	%al, %al
	jne	.L22
	addl	$1, 72(%esp)
	adcl	$0, 76(%esp)
.L14:
	movl	$1, %eax
	cmpl	$0, 76(%esp)
	js	.L23
	cmpl	$0, 76(%esp)
	jg	.L24
	cmpl	$30, 72(%esp)
	jbe	.L23
.L24:
	movl	$0, %eax
.L23:
	testb	%al, %al
	jne	.L25
	movl	$0, c
	movl	$0, c+4
	movl	40(%esp), %eax
	movl	44(%esp), %edx
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	%eax, (%esp)
	movl	%edx, 4(%esp)
	call	_Z5recurxiii
	movl	%eax, 48(%esp)
	movl	%edx, 52(%esp)
	movl	48(%esp), %eax
	movl	52(%esp), %edx
	movl	%eax, 4(%esp)
	movl	%edx, 8(%esp)
	movl	$_ZSt4cout, (%esp)
	call	_ZNSolsEx
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, 4(%esp)
	movl	%eax, (%esp)
	call	_ZNSolsEPFRSoS_E
.L13:
	leal	40(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	scanf
	testl	%eax, %eax
	setg	%al
	testb	%al, %al
	jne	.L26
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE964:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB971:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	.L27
	cmpl	$65535, 12(%ebp)
	jne	.L27
	movl	$_ZStL8__ioinit, (%esp)
	call	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %eax
	movl	$__dso_handle, 8(%esp)
	movl	$_ZStL8__ioinit, 4(%esp)
	movl	%eax, (%esp)
	call	__cxa_atexit
.L27:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE971:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__I_c, @function
_GLOBAL__I_c:
.LFB972:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	_Z41__static_initialization_and_destruction_0ii
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE972:
	.size	_GLOBAL__I_c, .-_GLOBAL__I_c
	.section	.ctors,"aw",@progbits
	.align 4
	.long	_GLOBAL__I_c
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL20__gthrw_pthread_joinmPPv,pthread_join
	.weakref	_ZL21__gthrw_pthread_equalmm,pthread_equal
	.weakref	_ZL20__gthrw_pthread_selfv,pthread_self
	.weakref	_ZL22__gthrw_pthread_detachm,pthread_detach
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL19__gthrw_sched_yieldv,sched_yield
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL31__gthrw_pthread_mutex_timedlockP15pthread_mutex_tPK8timespec,pthread_mutex_timedlock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL29__gthrw_pthread_mutex_destroyP15pthread_mutex_t,pthread_mutex_destroy
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL27__gthrw_pthread_cond_signalP14pthread_cond_t,pthread_cond_signal
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL30__gthrw_pthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec,pthread_cond_timedwait
	.weakref	_ZL28__gthrw_pthread_cond_destroyP14pthread_cond_t,pthread_cond_destroy
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.ident	"GCC: (Ubuntu/Linaro 4.5.2-8ubuntu4) 4.5.2"
	.section	.note.GNU-stack,"",@progbits
