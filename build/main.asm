;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.4.0 #8981 (Oct  6 2014) (Linux)
; This file was generated Sat Feb 14 15:53:52 2015
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _init
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
;	main.c: 95: ret_t init(void) {
;	-----------------------------------------
;	 function init
;	-----------------------------------------
_init:
;	main.c: 98: ENABLE_PULLUP(GPIOA,ALL_PINS);
	ldw	x, #0x5003
	ld	a, (x)
	ldw	x, #0x5003
	ld	a, #0xff
	ld	(x), a
;	main.c: 99: SET_INPUT(GPIOA,ALL_PINS);
	ldw	x, #0x5002
	ld	a, (x)
	ldw	x, #0x5002
	clr	(x)
;	main.c: 100: ENABLE_PULLUP(GPIOB,ALL_PINS);
	ldw	x, #0x5008
	ld	a, (x)
	ldw	x, #0x5008
	ld	a, #0xff
	ld	(x), a
;	main.c: 101: SET_INPUT(GPIOB,ALL_PINS);
	ldw	x, #0x5007
	ld	a, (x)
	ldw	x, #0x5007
	clr	(x)
;	main.c: 102: ENABLE_PULLUP(GPIOC,ALL_PINS);
	ldw	x, #0x500d
	ld	a, (x)
	ldw	x, #0x500d
	ld	a, #0xff
	ld	(x), a
;	main.c: 103: SET_INPUT(GPIOC,ALL_PINS);
	ldw	x, #0x500c
	ld	a, (x)
	ldw	x, #0x500c
	clr	(x)
;	main.c: 104: ENABLE_PULLUP(GPIOD,ALL_PINS);
	ldw	x, #0x5012
	ld	a, (x)
	ldw	x, #0x5012
	ld	a, #0xff
	ld	(x), a
;	main.c: 105: SET_INPUT(GPIOD,ALL_PINS);
	ldw	x, #0x5011
	ld	a, (x)
	ldw	x, #0x5011
	clr	(x)
;	main.c: 108: return EXIT_OK;
	clr	a
	ret
;	main.c: 114: int main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c: 117: init();
	call	_init
;	main.c: 120: while(1){}
00102$:
	jra	00102$
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
