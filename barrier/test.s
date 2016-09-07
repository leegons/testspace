	.file	"test.cc"
	.text
	.p2align 4,,15
	.globl	_Z4testv
	.type	_Z4testv, @function
_Z4testv:
.LFB0:
	.cfi_startproc
	movl	r(%rip), %eax
	movl	$1, y(%rip)
	movl	%eax, x(%rip)
	ret
	.cfi_endproc
.LFE0:
	.size	_Z4testv, .-_Z4testv
	.globl	r
	.bss
	.align 4
	.type	r, @object
	.size	r, 4
r:
	.zero	4
	.globl	y
	.align 4
	.type	y, @object
	.size	y, 4
y:
	.zero	4
	.globl	x
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.zero	4
	.ident	"GCC: (GNU) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
