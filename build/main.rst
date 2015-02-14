                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.4.0 #8981 (Oct  6 2014) (Linux)
                                      4 ; This file was generated Sat Feb 14 15:53:52 2015
                                      5 ;--------------------------------------------------------
                                      6 	.module main
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _init
                                     14 ;--------------------------------------------------------
                                     15 ; ram data
                                     16 ;--------------------------------------------------------
                                     17 	.area DATA
                                     18 ;--------------------------------------------------------
                                     19 ; ram data
                                     20 ;--------------------------------------------------------
                                     21 	.area INITIALIZED
                                     22 ;--------------------------------------------------------
                                     23 ; Stack segment in internal ram 
                                     24 ;--------------------------------------------------------
                                     25 	.area	SSEG
      000000                         26 __start__stack:
      000000                         27 	.ds	1
                                     28 
                                     29 ;--------------------------------------------------------
                                     30 ; absolute external ram data
                                     31 ;--------------------------------------------------------
                                     32 	.area DABS (ABS)
                                     33 ;--------------------------------------------------------
                                     34 ; interrupt vector 
                                     35 ;--------------------------------------------------------
                                     36 	.area HOME
      008000                         37 __interrupt_vect:
      008000 82 00 80 83             38 	int s_GSINIT ;reset
      008004 82 00 00 00             39 	int 0x0000 ;trap
      008008 82 00 00 00             40 	int 0x0000 ;int0
      00800C 82 00 00 00             41 	int 0x0000 ;int1
      008010 82 00 00 00             42 	int 0x0000 ;int2
      008014 82 00 00 00             43 	int 0x0000 ;int3
      008018 82 00 00 00             44 	int 0x0000 ;int4
      00801C 82 00 00 00             45 	int 0x0000 ;int5
      008020 82 00 00 00             46 	int 0x0000 ;int6
      008024 82 00 00 00             47 	int 0x0000 ;int7
      008028 82 00 00 00             48 	int 0x0000 ;int8
      00802C 82 00 00 00             49 	int 0x0000 ;int9
      008030 82 00 00 00             50 	int 0x0000 ;int10
      008034 82 00 00 00             51 	int 0x0000 ;int11
      008038 82 00 00 00             52 	int 0x0000 ;int12
      00803C 82 00 00 00             53 	int 0x0000 ;int13
      008040 82 00 00 00             54 	int 0x0000 ;int14
      008044 82 00 00 00             55 	int 0x0000 ;int15
      008048 82 00 00 00             56 	int 0x0000 ;int16
      00804C 82 00 00 00             57 	int 0x0000 ;int17
      008050 82 00 00 00             58 	int 0x0000 ;int18
      008054 82 00 00 00             59 	int 0x0000 ;int19
      008058 82 00 00 00             60 	int 0x0000 ;int20
      00805C 82 00 00 00             61 	int 0x0000 ;int21
      008060 82 00 00 00             62 	int 0x0000 ;int22
      008064 82 00 00 00             63 	int 0x0000 ;int23
      008068 82 00 00 00             64 	int 0x0000 ;int24
      00806C 82 00 00 00             65 	int 0x0000 ;int25
      008070 82 00 00 00             66 	int 0x0000 ;int26
      008074 82 00 00 00             67 	int 0x0000 ;int27
      008078 82 00 00 00             68 	int 0x0000 ;int28
      00807C 82 00 00 00             69 	int 0x0000 ;int29
                                     70 ;--------------------------------------------------------
                                     71 ; global & static initialisations
                                     72 ;--------------------------------------------------------
                                     73 	.area HOME
                                     74 	.area GSINIT
                                     75 	.area GSFINAL
                                     76 	.area GSINIT
      008083                         77 __sdcc_gs_init_startup:
      008083                         78 __sdcc_init_data:
                                     79 ; stm8_genXINIT() start
      008083 AE 00 00         [ 2]   80 	ldw x, #l_DATA
      008086 27 07            [ 1]   81 	jreq	00002$
      008088                         82 00001$:
      008088 72 4F 00 00      [ 1]   83 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   84 	decw x
      00808D 26 F9            [ 1]   85 	jrne	00001$
      00808F                         86 00002$:
      00808F AE 00 00         [ 2]   87 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   88 	jreq	00004$
      008094                         89 00003$:
      008094 D6 80 EF         [ 1]   90 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 00         [ 1]   91 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   92 	decw	x
      00809B 26 F7            [ 1]   93 	jrne	00003$
      00809D                         94 00004$:
                                     95 ; stm8_genXINIT() end
                                     96 	.area GSFINAL
      00809D CC 80 80         [ 2]   97 	jp	__sdcc_program_startup
                                     98 ;--------------------------------------------------------
                                     99 ; Home
                                    100 ;--------------------------------------------------------
                                    101 	.area HOME
                                    102 	.area HOME
      008080                        103 __sdcc_program_startup:
      008080 CC 80 EA         [ 2]  104 	jp	_main
                                    105 ;	return from main will return to caller
                                    106 ;--------------------------------------------------------
                                    107 ; code
                                    108 ;--------------------------------------------------------
                                    109 	.area CODE
                                    110 ;	main.c: 95: ret_t init(void) {
                                    111 ;	-----------------------------------------
                                    112 ;	 function init
                                    113 ;	-----------------------------------------
      0080A0                        114 _init:
                                    115 ;	main.c: 98: ENABLE_PULLUP(GPIOA,ALL_PINS);
      0080A0 AE 50 03         [ 2]  116 	ldw	x, #0x5003
      0080A3 F6               [ 1]  117 	ld	a, (x)
      0080A4 AE 50 03         [ 2]  118 	ldw	x, #0x5003
      0080A7 A6 FF            [ 1]  119 	ld	a, #0xff
      0080A9 F7               [ 1]  120 	ld	(x), a
                                    121 ;	main.c: 99: SET_INPUT(GPIOA,ALL_PINS);
      0080AA AE 50 02         [ 2]  122 	ldw	x, #0x5002
      0080AD F6               [ 1]  123 	ld	a, (x)
      0080AE AE 50 02         [ 2]  124 	ldw	x, #0x5002
      0080B1 7F               [ 1]  125 	clr	(x)
                                    126 ;	main.c: 100: ENABLE_PULLUP(GPIOB,ALL_PINS);
      0080B2 AE 50 08         [ 2]  127 	ldw	x, #0x5008
      0080B5 F6               [ 1]  128 	ld	a, (x)
      0080B6 AE 50 08         [ 2]  129 	ldw	x, #0x5008
      0080B9 A6 FF            [ 1]  130 	ld	a, #0xff
      0080BB F7               [ 1]  131 	ld	(x), a
                                    132 ;	main.c: 101: SET_INPUT(GPIOB,ALL_PINS);
      0080BC AE 50 07         [ 2]  133 	ldw	x, #0x5007
      0080BF F6               [ 1]  134 	ld	a, (x)
      0080C0 AE 50 07         [ 2]  135 	ldw	x, #0x5007
      0080C3 7F               [ 1]  136 	clr	(x)
                                    137 ;	main.c: 102: ENABLE_PULLUP(GPIOC,ALL_PINS);
      0080C4 AE 50 0D         [ 2]  138 	ldw	x, #0x500d
      0080C7 F6               [ 1]  139 	ld	a, (x)
      0080C8 AE 50 0D         [ 2]  140 	ldw	x, #0x500d
      0080CB A6 FF            [ 1]  141 	ld	a, #0xff
      0080CD F7               [ 1]  142 	ld	(x), a
                                    143 ;	main.c: 103: SET_INPUT(GPIOC,ALL_PINS);
      0080CE AE 50 0C         [ 2]  144 	ldw	x, #0x500c
      0080D1 F6               [ 1]  145 	ld	a, (x)
      0080D2 AE 50 0C         [ 2]  146 	ldw	x, #0x500c
      0080D5 7F               [ 1]  147 	clr	(x)
                                    148 ;	main.c: 104: ENABLE_PULLUP(GPIOD,ALL_PINS);
      0080D6 AE 50 12         [ 2]  149 	ldw	x, #0x5012
      0080D9 F6               [ 1]  150 	ld	a, (x)
      0080DA AE 50 12         [ 2]  151 	ldw	x, #0x5012
      0080DD A6 FF            [ 1]  152 	ld	a, #0xff
      0080DF F7               [ 1]  153 	ld	(x), a
                                    154 ;	main.c: 105: SET_INPUT(GPIOD,ALL_PINS);
      0080E0 AE 50 11         [ 2]  155 	ldw	x, #0x5011
      0080E3 F6               [ 1]  156 	ld	a, (x)
      0080E4 AE 50 11         [ 2]  157 	ldw	x, #0x5011
      0080E7 7F               [ 1]  158 	clr	(x)
                                    159 ;	main.c: 108: return EXIT_OK;
      0080E8 4F               [ 1]  160 	clr	a
      0080E9 81               [ 4]  161 	ret
                                    162 ;	main.c: 114: int main() {
                                    163 ;	-----------------------------------------
                                    164 ;	 function main
                                    165 ;	-----------------------------------------
      0080EA                        166 _main:
                                    167 ;	main.c: 117: init();
      0080EA CD 80 A0         [ 4]  168 	call	_init
                                    169 ;	main.c: 120: while(1){}
      0080ED                        170 00102$:
      0080ED 20 FE            [ 2]  171 	jra	00102$
      0080EF 81               [ 4]  172 	ret
                                    173 	.area CODE
                                    174 	.area INITIALIZER
                                    175 	.area CABS (ABS)
