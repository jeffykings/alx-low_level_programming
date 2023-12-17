section .data
	strn: db "Hello, Holberton", 10
	strnlen: EQU $ - strn

global main

section .text

main:
	mov rax, 1
	mov rdi, 1
	mov rsi, strn
	mov rdx, strnlen
	syscall

	mov rax, 60
	mov rdi, 0
	syscall
