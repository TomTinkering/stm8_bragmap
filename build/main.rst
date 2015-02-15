                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.4.0 #8981 (Oct  6 2014) (Linux)
                                      4 ; This file was generated Sun Feb 15 12:53:05 2015
                                      5 ;--------------------------------------------------------
                                      6 	.module main
                                      7 	.optsdcc -mstm8
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _main
                                     13 	.globl _TOUCH_single_cycle
                                     14 	.globl _init
                                     15 	.globl _TOUCH_init
                                     16 	.globl _TOUCH_keys
                                     17 ;--------------------------------------------------------
                                     18 ; ram data
                                     19 ;--------------------------------------------------------
                                     20 	.area DATA
      000001                         21 _TOUCH_keys::
      000001                         22 	.ds 36
                                     23 ;--------------------------------------------------------
                                     24 ; ram data
                                     25 ;--------------------------------------------------------
                                     26 	.area INITIALIZED
                                     27 ;--------------------------------------------------------
                                     28 ; Stack segment in internal ram 
                                     29 ;--------------------------------------------------------
                                     30 	.area	SSEG
      000000                         31 __start__stack:
      000000                         32 	.ds	1
                                     33 
                                     34 ;--------------------------------------------------------
                                     35 ; absolute external ram data
                                     36 ;--------------------------------------------------------
                                     37 	.area DABS (ABS)
                                     38 ;--------------------------------------------------------
                                     39 ; interrupt vector 
                                     40 ;--------------------------------------------------------
                                     41 	.area HOME
      008000                         42 __interrupt_vect:
      008000 82 00 80 83             43 	int s_GSINIT ;reset
      008004 82 00 00 00             44 	int 0x0000 ;trap
      008008 82 00 00 00             45 	int 0x0000 ;int0
      00800C 82 00 00 00             46 	int 0x0000 ;int1
      008010 82 00 00 00             47 	int 0x0000 ;int2
      008014 82 00 00 00             48 	int 0x0000 ;int3
      008018 82 00 00 00             49 	int 0x0000 ;int4
      00801C 82 00 00 00             50 	int 0x0000 ;int5
      008020 82 00 00 00             51 	int 0x0000 ;int6
      008024 82 00 00 00             52 	int 0x0000 ;int7
      008028 82 00 00 00             53 	int 0x0000 ;int8
      00802C 82 00 00 00             54 	int 0x0000 ;int9
      008030 82 00 00 00             55 	int 0x0000 ;int10
      008034 82 00 00 00             56 	int 0x0000 ;int11
      008038 82 00 00 00             57 	int 0x0000 ;int12
      00803C 82 00 00 00             58 	int 0x0000 ;int13
      008040 82 00 00 00             59 	int 0x0000 ;int14
      008044 82 00 00 00             60 	int 0x0000 ;int15
      008048 82 00 00 00             61 	int 0x0000 ;int16
      00804C 82 00 00 00             62 	int 0x0000 ;int17
      008050 82 00 00 00             63 	int 0x0000 ;int18
      008054 82 00 00 00             64 	int 0x0000 ;int19
      008058 82 00 00 00             65 	int 0x0000 ;int20
      00805C 82 00 00 00             66 	int 0x0000 ;int21
      008060 82 00 00 00             67 	int 0x0000 ;int22
      008064 82 00 00 00             68 	int 0x0000 ;int23
      008068 82 00 00 00             69 	int 0x0000 ;int24
      00806C 82 00 00 00             70 	int 0x0000 ;int25
      008070 82 00 00 00             71 	int 0x0000 ;int26
      008074 82 00 00 00             72 	int 0x0000 ;int27
      008078 82 00 00 00             73 	int 0x0000 ;int28
      00807C 82 00 00 00             74 	int 0x0000 ;int29
                                     75 ;--------------------------------------------------------
                                     76 ; global & static initialisations
                                     77 ;--------------------------------------------------------
                                     78 	.area HOME
                                     79 	.area GSINIT
                                     80 	.area GSFINAL
                                     81 	.area GSINIT
      008083                         82 __sdcc_gs_init_startup:
      008083                         83 __sdcc_init_data:
                                     84 ; stm8_genXINIT() start
      008083 AE 00 24         [ 2]   85 	ldw x, #l_DATA
      008086 27 07            [ 1]   86 	jreq	00002$
      008088                         87 00001$:
      008088 72 4F 00 00      [ 1]   88 	clr (s_DATA - 1, x)
      00808C 5A               [ 2]   89 	decw x
      00808D 26 F9            [ 1]   90 	jrne	00001$
      00808F                         91 00002$:
      00808F AE 00 00         [ 2]   92 	ldw	x, #l_INITIALIZER
      008092 27 09            [ 1]   93 	jreq	00004$
      008094                         94 00003$:
      008094 D6 82 72         [ 1]   95 	ld	a, (s_INITIALIZER - 1, x)
      008097 D7 00 24         [ 1]   96 	ld	(s_INITIALIZED - 1, x), a
      00809A 5A               [ 2]   97 	decw	x
      00809B 26 F7            [ 1]   98 	jrne	00003$
      00809D                         99 00004$:
                                    100 ; stm8_genXINIT() end
                                    101 	.area GSFINAL
      00809D CC 80 80         [ 2]  102 	jp	__sdcc_program_startup
                                    103 ;--------------------------------------------------------
                                    104 ; Home
                                    105 ;--------------------------------------------------------
                                    106 	.area HOME
                                    107 	.area HOME
      008080                        108 __sdcc_program_startup:
      008080 CC 82 6D         [ 2]  109 	jp	_main
                                    110 ;	return from main will return to caller
                                    111 ;--------------------------------------------------------
                                    112 ; code
                                    113 ;--------------------------------------------------------
                                    114 	.area CODE
                                    115 ;	main.c: 99: ret_t TOUCH_init(void) {
                                    116 ;	-----------------------------------------
                                    117 ;	 function TOUCH_init
                                    118 ;	-----------------------------------------
      0080A0                        119 _TOUCH_init:
      0080A0 52 13            [ 2]  120 	sub	sp, #19
                                    121 ;	main.c: 104: TOUCH_keys[0].io_pin = P3;
      0080A2 AE 00 01         [ 2]  122 	ldw	x, #_TOUCH_keys+0
      0080A5 A6 08            [ 1]  123 	ld	a, #0x08
      0080A7 F7               [ 1]  124 	ld	(x), a
                                    125 ;	main.c: 105: TOUCH_keys[0].io_port = GPIOC;
      0080A8 AE 00 01         [ 2]  126 	ldw	x, #_TOUCH_keys+0
      0080AB 1F 0C            [ 2]  127 	ldw	(0x0c, sp), x
      0080AD 1E 0C            [ 2]  128 	ldw	x, (0x0c, sp)
      0080AF 5C               [ 2]  129 	incw	x
      0080B0 90 AE 50 0A      [ 2]  130 	ldw	y, #0x500a
      0080B4 FF               [ 2]  131 	ldw	(x), y
                                    132 ;	main.c: 106: TOUCH_keys[0].led_pin = P7;
      0080B5 1E 0C            [ 2]  133 	ldw	x, (0x0c, sp)
      0080B7 A6 80            [ 1]  134 	ld	a, #0x80
      0080B9 E7 03            [ 1]  135 	ld	(0x0003, x), a
                                    136 ;	main.c: 107: TOUCH_keys[0].led_port = GPIOC;
      0080BB 1E 0C            [ 2]  137 	ldw	x, (0x0c, sp)
      0080BD 90 AE 50 0A      [ 2]  138 	ldw	y, #0x500a
      0080C1 EF 04            [ 2]  139 	ldw	(0x0004, x), y
                                    140 ;	main.c: 109: TOUCH_keys[1].io_pin = P4;
      0080C3 1E 0C            [ 2]  141 	ldw	x, (0x0c, sp)
      0080C5 A6 10            [ 1]  142 	ld	a, #0x10
      0080C7 E7 06            [ 1]  143 	ld	(0x0006, x), a
                                    144 ;	main.c: 110: TOUCH_keys[1].io_port = GPIOC;
      0080C9 1E 0C            [ 2]  145 	ldw	x, (0x0c, sp)
      0080CB 90 AE 50 0A      [ 2]  146 	ldw	y, #0x500a
      0080CF EF 07            [ 2]  147 	ldw	(0x0007, x), y
                                    148 ;	main.c: 111: TOUCH_keys[1].led_pin = P1;
      0080D1 1E 0C            [ 2]  149 	ldw	x, (0x0c, sp)
      0080D3 A6 02            [ 1]  150 	ld	a, #0x02
      0080D5 E7 09            [ 1]  151 	ld	(0x0009, x), a
                                    152 ;	main.c: 112: TOUCH_keys[1].led_port = GPIOD;
      0080D7 1E 0C            [ 2]  153 	ldw	x, (0x0c, sp)
      0080D9 90 AE 50 0F      [ 2]  154 	ldw	y, #0x500f
      0080DD EF 0A            [ 2]  155 	ldw	(0x000a, x), y
                                    156 ;	main.c: 114: TOUCH_keys[2].io_pin = P5;
      0080DF 1E 0C            [ 2]  157 	ldw	x, (0x0c, sp)
      0080E1 A6 20            [ 1]  158 	ld	a, #0x20
      0080E3 E7 0C            [ 1]  159 	ld	(0x000c, x), a
                                    160 ;	main.c: 115: TOUCH_keys[2].io_port = GPIOC;
      0080E5 1E 0C            [ 2]  161 	ldw	x, (0x0c, sp)
      0080E7 90 AE 50 0A      [ 2]  162 	ldw	y, #0x500a
      0080EB EF 0D            [ 2]  163 	ldw	(0x000d, x), y
                                    164 ;	main.c: 116: TOUCH_keys[2].led_pin = P2;
      0080ED 1E 0C            [ 2]  165 	ldw	x, (0x0c, sp)
      0080EF A6 04            [ 1]  166 	ld	a, #0x04
      0080F1 E7 0F            [ 1]  167 	ld	(0x000f, x), a
                                    168 ;	main.c: 117: TOUCH_keys[2].led_port = GPIOD;
      0080F3 1E 0C            [ 2]  169 	ldw	x, (0x0c, sp)
      0080F5 90 AE 50 0F      [ 2]  170 	ldw	y, #0x500f
      0080F9 EF 10            [ 2]  171 	ldw	(0x0010, x), y
                                    172 ;	main.c: 119: TOUCH_keys[3].io_pin = P6;
      0080FB 1E 0C            [ 2]  173 	ldw	x, (0x0c, sp)
      0080FD A6 40            [ 1]  174 	ld	a, #0x40
      0080FF E7 12            [ 1]  175 	ld	(0x0012, x), a
                                    176 ;	main.c: 120: TOUCH_keys[3].io_port = GPIOC;
      008101 1E 0C            [ 2]  177 	ldw	x, (0x0c, sp)
      008103 90 AE 50 0A      [ 2]  178 	ldw	y, #0x500a
      008107 EF 13            [ 2]  179 	ldw	(0x0013, x), y
                                    180 ;	main.c: 121: TOUCH_keys[3].led_pin = P3;
      008109 1E 0C            [ 2]  181 	ldw	x, (0x0c, sp)
      00810B A6 08            [ 1]  182 	ld	a, #0x08
      00810D E7 15            [ 1]  183 	ld	(0x0015, x), a
                                    184 ;	main.c: 122: TOUCH_keys[3].led_port = GPIOD;
      00810F 1E 0C            [ 2]  185 	ldw	x, (0x0c, sp)
      008111 90 AE 50 0F      [ 2]  186 	ldw	y, #0x500f
      008115 EF 16            [ 2]  187 	ldw	(0x0016, x), y
                                    188 ;	main.c: 124: TOUCH_keys[4].io_pin = P1;
      008117 1E 0C            [ 2]  189 	ldw	x, (0x0c, sp)
      008119 A6 02            [ 1]  190 	ld	a, #0x02
      00811B E7 18            [ 1]  191 	ld	(0x0018, x), a
                                    192 ;	main.c: 125: TOUCH_keys[4].io_port = GPIOA;
      00811D 1E 0C            [ 2]  193 	ldw	x, (0x0c, sp)
      00811F 1C 00 19         [ 2]  194 	addw	x, #0x0019
      008122 6F 01            [ 1]  195 	clr	(0x1, x)
      008124 A6 50            [ 1]  196 	ld	a, #0x50
      008126 F7               [ 1]  197 	ld	(x), a
                                    198 ;	main.c: 126: TOUCH_keys[4].led_pin = P4;
      008127 1E 0C            [ 2]  199 	ldw	x, (0x0c, sp)
      008129 A6 10            [ 1]  200 	ld	a, #0x10
      00812B E7 1B            [ 1]  201 	ld	(0x001b, x), a
                                    202 ;	main.c: 127: TOUCH_keys[4].led_port = GPIOD;
      00812D 1E 0C            [ 2]  203 	ldw	x, (0x0c, sp)
      00812F 90 AE 50 0F      [ 2]  204 	ldw	y, #0x500f
      008133 EF 1C            [ 2]  205 	ldw	(0x001c, x), y
                                    206 ;	main.c: 129: TOUCH_keys[5].io_pin = P2;
      008135 1E 0C            [ 2]  207 	ldw	x, (0x0c, sp)
      008137 A6 04            [ 1]  208 	ld	a, #0x04
      008139 E7 1E            [ 1]  209 	ld	(0x001e, x), a
                                    210 ;	main.c: 130: TOUCH_keys[5].io_port = GPIOA;
      00813B 1E 0C            [ 2]  211 	ldw	x, (0x0c, sp)
      00813D 1C 00 1F         [ 2]  212 	addw	x, #0x001f
      008140 6F 01            [ 1]  213 	clr	(0x1, x)
      008142 A6 50            [ 1]  214 	ld	a, #0x50
      008144 F7               [ 1]  215 	ld	(x), a
                                    216 ;	main.c: 131: TOUCH_keys[5].led_pin = P3;
      008145 1E 0C            [ 2]  217 	ldw	x, (0x0c, sp)
      008147 A6 08            [ 1]  218 	ld	a, #0x08
      008149 E7 21            [ 1]  219 	ld	(0x0021, x), a
                                    220 ;	main.c: 132: TOUCH_keys[5].led_port = GPIOA;
      00814B 1E 0C            [ 2]  221 	ldw	x, (0x0c, sp)
      00814D 1C 00 22         [ 2]  222 	addw	x, #0x0022
      008150 6F 01            [ 1]  223 	clr	(0x1, x)
      008152 A6 50            [ 1]  224 	ld	a, #0x50
      008154 F7               [ 1]  225 	ld	(x), a
                                    226 ;	main.c: 135: for(i=0;i<TOUCH_NR_KEYS;i++){
      008155 0F 01            [ 1]  227 	clr	(0x01, sp)
      008157 5F               [ 1]  228 	clrw	x
      008158 1F 04            [ 2]  229 	ldw	(0x04, sp), x
      00815A                        230 00102$:
                                    231 ;	main.c: 137: SET_OUTPUT(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
      00815A 1E 0C            [ 2]  232 	ldw	x, (0x0c, sp)
      00815C 72 FB 04         [ 2]  233 	addw	x, (0x04, sp)
      00815F 1F 0F            [ 2]  234 	ldw	(0x0f, sp), x
      008161 1E 0F            [ 2]  235 	ldw	x, (0x0f, sp)
      008163 1C 00 04         [ 2]  236 	addw	x, #0x0004
      008166 1F 02            [ 2]  237 	ldw	(0x02, sp), x
      008168 1E 02            [ 2]  238 	ldw	x, (0x02, sp)
      00816A FE               [ 2]  239 	ldw	x, (x)
      00816B 5C               [ 2]  240 	incw	x
      00816C 5C               [ 2]  241 	incw	x
      00816D F6               [ 1]  242 	ld	a, (x)
      00816E 6B 06            [ 1]  243 	ld	(0x06, sp), a
      008170 16 0F            [ 2]  244 	ldw	y, (0x0f, sp)
      008172 72 A9 00 03      [ 2]  245 	addw	y, #0x0003
      008176 17 0A            [ 2]  246 	ldw	(0x0a, sp), y
      008178 16 0A            [ 2]  247 	ldw	y, (0x0a, sp)
      00817A 90 F6            [ 1]  248 	ld	a, (y)
      00817C 1A 06            [ 1]  249 	or	a, (0x06, sp)
      00817E F7               [ 1]  250 	ld	(x), a
                                    251 ;	main.c: 138: SET_OUTPUT(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
      00817F 1E 0F            [ 2]  252 	ldw	x, (0x0f, sp)
      008181 5C               [ 2]  253 	incw	x
      008182 1F 07            [ 2]  254 	ldw	(0x07, sp), x
      008184 1E 07            [ 2]  255 	ldw	x, (0x07, sp)
      008186 FE               [ 2]  256 	ldw	x, (x)
      008187 5C               [ 2]  257 	incw	x
      008188 5C               [ 2]  258 	incw	x
      008189 F6               [ 1]  259 	ld	a, (x)
      00818A 6B 13            [ 1]  260 	ld	(0x13, sp), a
      00818C 16 0F            [ 2]  261 	ldw	y, (0x0f, sp)
      00818E 90 F6            [ 1]  262 	ld	a, (y)
      008190 1A 13            [ 1]  263 	or	a, (0x13, sp)
      008192 F7               [ 1]  264 	ld	(x), a
                                    265 ;	main.c: 140: DISABLE_PULLUP(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
      008193 1E 02            [ 2]  266 	ldw	x, (0x02, sp)
      008195 FE               [ 2]  267 	ldw	x, (x)
      008196 1C 00 03         [ 2]  268 	addw	x, #0x0003
      008199 F6               [ 1]  269 	ld	a, (x)
      00819A 6B 0E            [ 1]  270 	ld	(0x0e, sp), a
      00819C 16 0A            [ 2]  271 	ldw	y, (0x0a, sp)
      00819E 90 F6            [ 1]  272 	ld	a, (y)
      0081A0 1A 0E            [ 1]  273 	or	a, (0x0e, sp)
      0081A2 F7               [ 1]  274 	ld	(x), a
                                    275 ;	main.c: 141: DISABLE_PULLUP(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
      0081A3 1E 07            [ 2]  276 	ldw	x, (0x07, sp)
      0081A5 FE               [ 2]  277 	ldw	x, (x)
      0081A6 1C 00 03         [ 2]  278 	addw	x, #0x0003
      0081A9 F6               [ 1]  279 	ld	a, (x)
      0081AA 6B 09            [ 1]  280 	ld	(0x09, sp), a
      0081AC 16 0F            [ 2]  281 	ldw	y, (0x0f, sp)
      0081AE 90 F6            [ 1]  282 	ld	a, (y)
      0081B0 1A 09            [ 1]  283 	or	a, (0x09, sp)
      0081B2 F7               [ 1]  284 	ld	(x), a
                                    285 ;	main.c: 143: SET_LOW(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
      0081B3 1E 02            [ 2]  286 	ldw	x, (0x02, sp)
      0081B5 FE               [ 2]  287 	ldw	x, (x)
      0081B6 F6               [ 1]  288 	ld	a, (x)
      0081B7 6B 12            [ 1]  289 	ld	(0x12, sp), a
      0081B9 16 0A            [ 2]  290 	ldw	y, (0x0a, sp)
      0081BB 90 F6            [ 1]  291 	ld	a, (y)
      0081BD 43               [ 1]  292 	cpl	a
      0081BE 14 12            [ 1]  293 	and	a, (0x12, sp)
      0081C0 F7               [ 1]  294 	ld	(x), a
                                    295 ;	main.c: 144: SET_LOW(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
      0081C1 1E 07            [ 2]  296 	ldw	x, (0x07, sp)
      0081C3 FE               [ 2]  297 	ldw	x, (x)
      0081C4 F6               [ 1]  298 	ld	a, (x)
      0081C5 6B 11            [ 1]  299 	ld	(0x11, sp), a
      0081C7 16 0F            [ 2]  300 	ldw	y, (0x0f, sp)
      0081C9 90 F6            [ 1]  301 	ld	a, (y)
      0081CB 43               [ 1]  302 	cpl	a
      0081CC 14 11            [ 1]  303 	and	a, (0x11, sp)
      0081CE F7               [ 1]  304 	ld	(x), a
                                    305 ;	main.c: 135: for(i=0;i<TOUCH_NR_KEYS;i++){
      0081CF 1E 04            [ 2]  306 	ldw	x, (0x04, sp)
      0081D1 1C 00 06         [ 2]  307 	addw	x, #0x0006
      0081D4 1F 04            [ 2]  308 	ldw	(0x04, sp), x
      0081D6 0C 01            [ 1]  309 	inc	(0x01, sp)
      0081D8 7B 01            [ 1]  310 	ld	a, (0x01, sp)
      0081DA A1 06            [ 1]  311 	cp	a, #0x06
      0081DC 24 03            [ 1]  312 	jrnc	00115$
      0081DE CC 81 5A         [ 2]  313 	jp	00102$
      0081E1                        314 00115$:
                                    315 ;	main.c: 150: return EXIT_OK;
      0081E1 4F               [ 1]  316 	clr	a
      0081E2 5B 13            [ 2]  317 	addw	sp, #19
      0081E4 81               [ 4]  318 	ret
                                    319 ;	main.c: 159: ret_t init(void) {
                                    320 ;	-----------------------------------------
                                    321 ;	 function init
                                    322 ;	-----------------------------------------
      0081E5                        323 _init:
                                    324 ;	main.c: 162: ENABLE_PULLUP(GPIOA,ALL_PINS);
      0081E5 AE 50 03         [ 2]  325 	ldw	x, #0x5003
      0081E8 F6               [ 1]  326 	ld	a, (x)
      0081E9 AE 50 03         [ 2]  327 	ldw	x, #0x5003
      0081EC A6 FF            [ 1]  328 	ld	a, #0xff
      0081EE F7               [ 1]  329 	ld	(x), a
                                    330 ;	main.c: 163: SET_INPUT(GPIOA,ALL_PINS);
      0081EF AE 50 02         [ 2]  331 	ldw	x, #0x5002
      0081F2 F6               [ 1]  332 	ld	a, (x)
      0081F3 AE 50 02         [ 2]  333 	ldw	x, #0x5002
      0081F6 7F               [ 1]  334 	clr	(x)
                                    335 ;	main.c: 164: ENABLE_PULLUP(GPIOB,ALL_PINS);
      0081F7 AE 50 08         [ 2]  336 	ldw	x, #0x5008
      0081FA F6               [ 1]  337 	ld	a, (x)
      0081FB AE 50 08         [ 2]  338 	ldw	x, #0x5008
      0081FE A6 FF            [ 1]  339 	ld	a, #0xff
      008200 F7               [ 1]  340 	ld	(x), a
                                    341 ;	main.c: 165: SET_INPUT(GPIOB,ALL_PINS);
      008201 AE 50 07         [ 2]  342 	ldw	x, #0x5007
      008204 F6               [ 1]  343 	ld	a, (x)
      008205 AE 50 07         [ 2]  344 	ldw	x, #0x5007
      008208 7F               [ 1]  345 	clr	(x)
                                    346 ;	main.c: 166: ENABLE_PULLUP(GPIOC,ALL_PINS);
      008209 AE 50 0D         [ 2]  347 	ldw	x, #0x500d
      00820C F6               [ 1]  348 	ld	a, (x)
      00820D AE 50 0D         [ 2]  349 	ldw	x, #0x500d
      008210 A6 FF            [ 1]  350 	ld	a, #0xff
      008212 F7               [ 1]  351 	ld	(x), a
                                    352 ;	main.c: 167: SET_INPUT(GPIOC,ALL_PINS);
      008213 AE 50 0C         [ 2]  353 	ldw	x, #0x500c
      008216 F6               [ 1]  354 	ld	a, (x)
      008217 AE 50 0C         [ 2]  355 	ldw	x, #0x500c
      00821A 7F               [ 1]  356 	clr	(x)
                                    357 ;	main.c: 168: ENABLE_PULLUP(GPIOD,ALL_PINS);
      00821B AE 50 12         [ 2]  358 	ldw	x, #0x5012
      00821E F6               [ 1]  359 	ld	a, (x)
      00821F AE 50 12         [ 2]  360 	ldw	x, #0x5012
      008222 A6 FF            [ 1]  361 	ld	a, #0xff
      008224 F7               [ 1]  362 	ld	(x), a
                                    363 ;	main.c: 169: SET_INPUT(GPIOD,ALL_PINS);
      008225 AE 50 11         [ 2]  364 	ldw	x, #0x5011
      008228 F6               [ 1]  365 	ld	a, (x)
      008229 AE 50 11         [ 2]  366 	ldw	x, #0x5011
      00822C 7F               [ 1]  367 	clr	(x)
                                    368 ;	main.c: 174: return EXIT_OK;
      00822D 4F               [ 1]  369 	clr	a
      00822E 81               [ 4]  370 	ret
                                    371 ;	main.c: 179: ret_t TOUCH_single_cycle(){
                                    372 ;	-----------------------------------------
                                    373 ;	 function TOUCH_single_cycle
                                    374 ;	-----------------------------------------
      00822F                        375 _TOUCH_single_cycle:
                                    376 ;	main.c: 185: SET_HIGH(GPIOA,TOUCH_GPIOA_A_PINS);
      00822F AE 50 00         [ 2]  377 	ldw	x, #0x5000
      008232 F6               [ 1]  378 	ld	a, (x)
      008233 AA 02            [ 1]  379 	or	a, #0x02
      008235 F7               [ 1]  380 	ld	(x), a
                                    381 ;	main.c: 186: SET_HIGH(GPIOB,TOUCH_GPIOB_A_PINS);
      008236 AE 50 05         [ 2]  382 	ldw	x, #0x5005
      008239 F6               [ 1]  383 	ld	a, (x)
      00823A AE 50 05         [ 2]  384 	ldw	x, #0x5005
      00823D F7               [ 1]  385 	ld	(x), a
                                    386 ;	main.c: 187: SET_HIGH(GPIOC,TOUCH_GPIOC_A_PINS);
      00823E AE 50 0A         [ 2]  387 	ldw	x, #0x500a
      008241 F6               [ 1]  388 	ld	a, (x)
      008242 AA 28            [ 1]  389 	or	a, #0x28
      008244 F7               [ 1]  390 	ld	(x), a
                                    391 ;	main.c: 188: SET_HIGH(GPIOD,TOUCH_GPIOD_A_PINS);
      008245 AE 50 0F         [ 2]  392 	ldw	x, #0x500f
      008248 F6               [ 1]  393 	ld	a, (x)
      008249 AE 50 0F         [ 2]  394 	ldw	x, #0x500f
      00824C F7               [ 1]  395 	ld	(x), a
                                    396 ;	main.c: 190: SET_HIGH(GPIOA,TOUCH_GPIOA_B_PINS);
      00824D AE 50 00         [ 2]  397 	ldw	x, #0x5000
      008250 F6               [ 1]  398 	ld	a, (x)
      008251 AA 04            [ 1]  399 	or	a, #0x04
      008253 F7               [ 1]  400 	ld	(x), a
                                    401 ;	main.c: 191: SET_HIGH(GPIOB,TOUCH_GPIOB_B_PINS);
      008254 AE 50 05         [ 2]  402 	ldw	x, #0x5005
      008257 F6               [ 1]  403 	ld	a, (x)
      008258 AE 50 05         [ 2]  404 	ldw	x, #0x5005
      00825B F7               [ 1]  405 	ld	(x), a
                                    406 ;	main.c: 192: SET_HIGH(GPIOC,TOUCH_GPIOC_B_PINS);
      00825C AE 50 0A         [ 2]  407 	ldw	x, #0x500a
      00825F F6               [ 1]  408 	ld	a, (x)
      008260 AA 50            [ 1]  409 	or	a, #0x50
      008262 F7               [ 1]  410 	ld	(x), a
                                    411 ;	main.c: 193: SET_HIGH(GPIOD,TOUCH_GPIOD_B_PINS);
      008263 AE 50 0F         [ 2]  412 	ldw	x, #0x500f
      008266 F6               [ 1]  413 	ld	a, (x)
      008267 AE 50 0F         [ 2]  414 	ldw	x, #0x500f
      00826A F7               [ 1]  415 	ld	(x), a
                                    416 ;	main.c: 199: return EXIT_OK;
      00826B 4F               [ 1]  417 	clr	a
      00826C 81               [ 4]  418 	ret
                                    419 ;	main.c: 209: int main() {
                                    420 ;	-----------------------------------------
                                    421 ;	 function main
                                    422 ;	-----------------------------------------
      00826D                        423 _main:
                                    424 ;	main.c: 212: init();
      00826D CD 81 E5         [ 4]  425 	call	_init
                                    426 ;	main.c: 215: while(1){}
      008270                        427 00102$:
      008270 20 FE            [ 2]  428 	jra	00102$
      008272 81               [ 4]  429 	ret
                                    430 	.area CODE
                                    431 	.area INITIALIZER
                                    432 	.area CABS (ABS)
