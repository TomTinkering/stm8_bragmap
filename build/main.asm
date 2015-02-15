;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.4.0 #8981 (Oct  6 2014) (Linux)
; This file was generated Sun Feb 15 12:53:05 2015
;--------------------------------------------------------
	.module main
	.optsdcc -mstm8
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _TOUCH_single_cycle
	.globl _init
	.globl _TOUCH_init
	.globl _TOUCH_keys
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DATA
_TOUCH_keys::
	.ds 36
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
;	main.c: 99: ret_t TOUCH_init(void) {
;	-----------------------------------------
;	 function TOUCH_init
;	-----------------------------------------
_TOUCH_init:
	sub	sp, #19
;	main.c: 104: TOUCH_keys[0].io_pin = P3;
	ldw	x, #_TOUCH_keys+0
	ld	a, #0x08
	ld	(x), a
;	main.c: 105: TOUCH_keys[0].io_port = GPIOC;
	ldw	x, #_TOUCH_keys+0
	ldw	(0x0c, sp), x
	ldw	x, (0x0c, sp)
	incw	x
	ldw	y, #0x500a
	ldw	(x), y
;	main.c: 106: TOUCH_keys[0].led_pin = P7;
	ldw	x, (0x0c, sp)
	ld	a, #0x80
	ld	(0x0003, x), a
;	main.c: 107: TOUCH_keys[0].led_port = GPIOC;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500a
	ldw	(0x0004, x), y
;	main.c: 109: TOUCH_keys[1].io_pin = P4;
	ldw	x, (0x0c, sp)
	ld	a, #0x10
	ld	(0x0006, x), a
;	main.c: 110: TOUCH_keys[1].io_port = GPIOC;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500a
	ldw	(0x0007, x), y
;	main.c: 111: TOUCH_keys[1].led_pin = P1;
	ldw	x, (0x0c, sp)
	ld	a, #0x02
	ld	(0x0009, x), a
;	main.c: 112: TOUCH_keys[1].led_port = GPIOD;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500f
	ldw	(0x000a, x), y
;	main.c: 114: TOUCH_keys[2].io_pin = P5;
	ldw	x, (0x0c, sp)
	ld	a, #0x20
	ld	(0x000c, x), a
;	main.c: 115: TOUCH_keys[2].io_port = GPIOC;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500a
	ldw	(0x000d, x), y
;	main.c: 116: TOUCH_keys[2].led_pin = P2;
	ldw	x, (0x0c, sp)
	ld	a, #0x04
	ld	(0x000f, x), a
;	main.c: 117: TOUCH_keys[2].led_port = GPIOD;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500f
	ldw	(0x0010, x), y
;	main.c: 119: TOUCH_keys[3].io_pin = P6;
	ldw	x, (0x0c, sp)
	ld	a, #0x40
	ld	(0x0012, x), a
;	main.c: 120: TOUCH_keys[3].io_port = GPIOC;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500a
	ldw	(0x0013, x), y
;	main.c: 121: TOUCH_keys[3].led_pin = P3;
	ldw	x, (0x0c, sp)
	ld	a, #0x08
	ld	(0x0015, x), a
;	main.c: 122: TOUCH_keys[3].led_port = GPIOD;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500f
	ldw	(0x0016, x), y
;	main.c: 124: TOUCH_keys[4].io_pin = P1;
	ldw	x, (0x0c, sp)
	ld	a, #0x02
	ld	(0x0018, x), a
;	main.c: 125: TOUCH_keys[4].io_port = GPIOA;
	ldw	x, (0x0c, sp)
	addw	x, #0x0019
	clr	(0x1, x)
	ld	a, #0x50
	ld	(x), a
;	main.c: 126: TOUCH_keys[4].led_pin = P4;
	ldw	x, (0x0c, sp)
	ld	a, #0x10
	ld	(0x001b, x), a
;	main.c: 127: TOUCH_keys[4].led_port = GPIOD;
	ldw	x, (0x0c, sp)
	ldw	y, #0x500f
	ldw	(0x001c, x), y
;	main.c: 129: TOUCH_keys[5].io_pin = P2;
	ldw	x, (0x0c, sp)
	ld	a, #0x04
	ld	(0x001e, x), a
;	main.c: 130: TOUCH_keys[5].io_port = GPIOA;
	ldw	x, (0x0c, sp)
	addw	x, #0x001f
	clr	(0x1, x)
	ld	a, #0x50
	ld	(x), a
;	main.c: 131: TOUCH_keys[5].led_pin = P3;
	ldw	x, (0x0c, sp)
	ld	a, #0x08
	ld	(0x0021, x), a
;	main.c: 132: TOUCH_keys[5].led_port = GPIOA;
	ldw	x, (0x0c, sp)
	addw	x, #0x0022
	clr	(0x1, x)
	ld	a, #0x50
	ld	(x), a
;	main.c: 135: for(i=0;i<TOUCH_NR_KEYS;i++){
	clr	(0x01, sp)
	clrw	x
	ldw	(0x04, sp), x
00102$:
;	main.c: 137: SET_OUTPUT(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
	ldw	x, (0x0c, sp)
	addw	x, (0x04, sp)
	ldw	(0x0f, sp), x
	ldw	x, (0x0f, sp)
	addw	x, #0x0004
	ldw	(0x02, sp), x
	ldw	x, (0x02, sp)
	ldw	x, (x)
	incw	x
	incw	x
	ld	a, (x)
	ld	(0x06, sp), a
	ldw	y, (0x0f, sp)
	addw	y, #0x0003
	ldw	(0x0a, sp), y
	ldw	y, (0x0a, sp)
	ld	a, (y)
	or	a, (0x06, sp)
	ld	(x), a
;	main.c: 138: SET_OUTPUT(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
	ldw	x, (0x0f, sp)
	incw	x
	ldw	(0x07, sp), x
	ldw	x, (0x07, sp)
	ldw	x, (x)
	incw	x
	incw	x
	ld	a, (x)
	ld	(0x13, sp), a
	ldw	y, (0x0f, sp)
	ld	a, (y)
	or	a, (0x13, sp)
	ld	(x), a
;	main.c: 140: DISABLE_PULLUP(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
	ldw	x, (0x02, sp)
	ldw	x, (x)
	addw	x, #0x0003
	ld	a, (x)
	ld	(0x0e, sp), a
	ldw	y, (0x0a, sp)
	ld	a, (y)
	or	a, (0x0e, sp)
	ld	(x), a
;	main.c: 141: DISABLE_PULLUP(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
	ldw	x, (0x07, sp)
	ldw	x, (x)
	addw	x, #0x0003
	ld	a, (x)
	ld	(0x09, sp), a
	ldw	y, (0x0f, sp)
	ld	a, (y)
	or	a, (0x09, sp)
	ld	(x), a
;	main.c: 143: SET_LOW(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
	ldw	x, (0x02, sp)
	ldw	x, (x)
	ld	a, (x)
	ld	(0x12, sp), a
	ldw	y, (0x0a, sp)
	ld	a, (y)
	cpl	a
	and	a, (0x12, sp)
	ld	(x), a
;	main.c: 144: SET_LOW(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
	ldw	x, (0x07, sp)
	ldw	x, (x)
	ld	a, (x)
	ld	(0x11, sp), a
	ldw	y, (0x0f, sp)
	ld	a, (y)
	cpl	a
	and	a, (0x11, sp)
	ld	(x), a
;	main.c: 135: for(i=0;i<TOUCH_NR_KEYS;i++){
	ldw	x, (0x04, sp)
	addw	x, #0x0006
	ldw	(0x04, sp), x
	inc	(0x01, sp)
	ld	a, (0x01, sp)
	cp	a, #0x06
	jrnc	00115$
	jp	00102$
00115$:
;	main.c: 150: return EXIT_OK;
	clr	a
	addw	sp, #19
	ret
;	main.c: 159: ret_t init(void) {
;	-----------------------------------------
;	 function init
;	-----------------------------------------
_init:
;	main.c: 162: ENABLE_PULLUP(GPIOA,ALL_PINS);
	ldw	x, #0x5003
	ld	a, (x)
	ldw	x, #0x5003
	ld	a, #0xff
	ld	(x), a
;	main.c: 163: SET_INPUT(GPIOA,ALL_PINS);
	ldw	x, #0x5002
	ld	a, (x)
	ldw	x, #0x5002
	clr	(x)
;	main.c: 164: ENABLE_PULLUP(GPIOB,ALL_PINS);
	ldw	x, #0x5008
	ld	a, (x)
	ldw	x, #0x5008
	ld	a, #0xff
	ld	(x), a
;	main.c: 165: SET_INPUT(GPIOB,ALL_PINS);
	ldw	x, #0x5007
	ld	a, (x)
	ldw	x, #0x5007
	clr	(x)
;	main.c: 166: ENABLE_PULLUP(GPIOC,ALL_PINS);
	ldw	x, #0x500d
	ld	a, (x)
	ldw	x, #0x500d
	ld	a, #0xff
	ld	(x), a
;	main.c: 167: SET_INPUT(GPIOC,ALL_PINS);
	ldw	x, #0x500c
	ld	a, (x)
	ldw	x, #0x500c
	clr	(x)
;	main.c: 168: ENABLE_PULLUP(GPIOD,ALL_PINS);
	ldw	x, #0x5012
	ld	a, (x)
	ldw	x, #0x5012
	ld	a, #0xff
	ld	(x), a
;	main.c: 169: SET_INPUT(GPIOD,ALL_PINS);
	ldw	x, #0x5011
	ld	a, (x)
	ldw	x, #0x5011
	clr	(x)
;	main.c: 174: return EXIT_OK;
	clr	a
	ret
;	main.c: 179: ret_t TOUCH_single_cycle(){
;	-----------------------------------------
;	 function TOUCH_single_cycle
;	-----------------------------------------
_TOUCH_single_cycle:
;	main.c: 185: SET_HIGH(GPIOA,TOUCH_GPIOA_A_PINS);
	ldw	x, #0x5000
	ld	a, (x)
	or	a, #0x02
	ld	(x), a
;	main.c: 186: SET_HIGH(GPIOB,TOUCH_GPIOB_A_PINS);
	ldw	x, #0x5005
	ld	a, (x)
	ldw	x, #0x5005
	ld	(x), a
;	main.c: 187: SET_HIGH(GPIOC,TOUCH_GPIOC_A_PINS);
	ldw	x, #0x500a
	ld	a, (x)
	or	a, #0x28
	ld	(x), a
;	main.c: 188: SET_HIGH(GPIOD,TOUCH_GPIOD_A_PINS);
	ldw	x, #0x500f
	ld	a, (x)
	ldw	x, #0x500f
	ld	(x), a
;	main.c: 190: SET_HIGH(GPIOA,TOUCH_GPIOA_B_PINS);
	ldw	x, #0x5000
	ld	a, (x)
	or	a, #0x04
	ld	(x), a
;	main.c: 191: SET_HIGH(GPIOB,TOUCH_GPIOB_B_PINS);
	ldw	x, #0x5005
	ld	a, (x)
	ldw	x, #0x5005
	ld	(x), a
;	main.c: 192: SET_HIGH(GPIOC,TOUCH_GPIOC_B_PINS);
	ldw	x, #0x500a
	ld	a, (x)
	or	a, #0x50
	ld	(x), a
;	main.c: 193: SET_HIGH(GPIOD,TOUCH_GPIOD_B_PINS);
	ldw	x, #0x500f
	ld	a, (x)
	ldw	x, #0x500f
	ld	(x), a
;	main.c: 199: return EXIT_OK;
	clr	a
	ret
;	main.c: 209: int main() {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	main.c: 212: init();
	call	_init
;	main.c: 215: while(1){}
00102$:
	jra	00102$
	ret
	.area CODE
	.area INITIALIZER
	.area CABS (ABS)
