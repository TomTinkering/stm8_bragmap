;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.4.0 #8981 (Oct  6 2014) (Linux)
; This file was generated Wed Feb 11 23:22:39 2015
;--------------------------------------------------------
	.module uart
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _uart_write
	.globl _strlen
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area INITIALIZED
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area DABS (ABS)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME
__interrupt_vect:
	int s_GSINIT ;reset
	int 0x0000 ;trap
	int 0x0000 ;int0
	int 0x0000 ;int1
	int 0x0000 ;int2
	int 0x0000 ;int3
	int 0x0000 ;int4
	int 0x0000 ;int5
	int 0x0000 ;int6
	int 0x0000 ;int7
	int 0x0000 ;int8
	int 0x0000 ;int9
	int 0x0000 ;int10
	int 0x0000 ;int11
	int 0x0000 ;int12
	int 0x0000 ;int13
	int 0x0000 ;int14
	int 0x0000 ;int15
	int 0x0000 ;int16
	int 0x0000 ;int17
	int 0x0000 ;int18
	int 0x0000 ;int19
	int 0x0000 ;int20
	int 0x0000 ;int21
	int 0x0000 ;int22
	int 0x0000 ;int23
	int 0x0000 ;int24
	int 0x0000 ;int25
	int 0x0000 ;int26
	int 0x0000 ;int27
	int 0x0000 ;int28
	int 0x0000 ;int29
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME
	.area GSINIT
	.area GSFINAL
	.area GSINIT
__sdcc_gs_init_startup:
__sdcc_init_data:
; stm8_genXINIT() start
	ldw x, #l_DATA
	jreq	00002$
00001$:
	clr (s_DATA - 1, x)
	decw x
	jrne	00001$
00002$:
	ldw	x, #l_INITIALIZER
	jreq	00004$
00003$:
	ld	a, (s_INITIALIZER - 1, x)
	ld	(s_INITIALIZED - 1, x), a
	decw	x
	jrne	00003$
00004$:
; stm8_genXINIT() end
	.area GSFINAL
	jp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME
	.area HOME
__sdcc_program_startup:
	jp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CODE
;	uart.c: 4: int uart_write(const char *str) {
;	-----------------------------------------
;	 function uart_write
;	-----------------------------------------
_uart_write:
	sub	sp, #3
;	uart.c: 6: for(i = 0; i < strlen(str); i++) {
	clr	(0x01, sp)
00106$:
	ldw	x, (0x06, sp)
	pushw	x
	call	_strlen
	addw	sp, #2
	ldw	(0x02, sp), x
	ld	a, (0x01, sp)
	ld	xl, a
	rlc	a
	clr	a
	sbc	a, #0x00
	ld	xh, a
	cpw	x, (0x02, sp)
	jrnc	00104$
;	uart.c: 7: while(!(USART1_SR & USART_SR_TXE));
00101$:
	ldw	x, #0x5230
	ld	a, (x)
	sll	a
	jrnc	00101$
;	uart.c: 8: USART1_DR = str[i];
	clrw	x
	ld	a, (0x01, sp)
	ld	xl, a
	addw	x, (0x06, sp)
	ld	a, (x)
	ldw	x, #0x5231
	ld	(x), a
;	uart.c: 6: for(i = 0; i < strlen(str); i++) {
	inc	(0x01, sp)
	jra	00106$
00104$:
;	uart.c: 10: return(i); // Bytes sent
	ld	a, (0x01, sp)
	ld	xl, a
	rlc	a
	clr	a
	sbc	a, #0x00
	ld	xh, a
	addw	sp, #3
	ret
;	uart.c: 13: int main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	uart.c: 16: CLK_DIVR = 0x00; // Set the frequency to 16 MHz
	ldw	x, #0x50c0
	clr	(x)
;	uart.c: 17: CLK_PCKENR1 = 0xFF; // Enable peripherals
	ldw	x, #0x50c3
	ld	a, #0xff
	ld	(x), a
;	uart.c: 19: PC_DDR = 0x08; // Put TX line on
	ldw	x, #0x500c
	ld	a, #0x08
	ld	(x), a
;	uart.c: 20: PC_CR1 = 0x08;
	ldw	x, #0x500d
	ld	a, #0x08
	ld	(x), a
;	uart.c: 22: USART1_CR2 = USART_CR2_TEN; // Allow TX & RX
	ldw	x, #0x5235
	ld	a, #0x08
	ld	(x), a
;	uart.c: 23: USART1_CR3 &= ~(USART_CR3_STOP1 | USART_CR3_STOP2); // 1 stop bit
	ldw	x, #0x5236
	ld	a, (x)
	and	a, #0xcf
	ld	(x), a
;	uart.c: 24: USART1_BRR2 = 0x03; USART1_BRR1 = 0x68; // 9600 baud
	ldw	x, #0x5233
	ld	a, #0x03
	ld	(x), a
	ldw	x, #0x5232
	ld	a, #0x68
	ld	(x), a
;	uart.c: 26: do {
00102$:
;	uart.c: 27: uart_write("Hello World!\n");
	ldw	x, #___str_0+0
	pushw	x
	call	_uart_write
	addw	sp, #2
;	uart.c: 28: for(i = 0; i < 147456; i++) { } // Sleep
	ldw	y, #0x4000
	ldw	x, #0x0002
00107$:
	subw	y, #0x0001
	ld	a, xl
	sbc	a, #0x00
	ld	xl, a
	ld	a, xh
	sbc	a, #0x00
	ld	xh, a
	tnzw	y
	jrne	00107$
	tnzw	x
	jreq	00102$
;	uart.c: 29: } while(1);
	jra	00107$
	ret
	.area CODE
___str_0:
	.ascii "Hello World!"
	.db 0x0A
	.db 0x00
	.area INITIALIZER
	.area CABS (ABS)
