;
; second.asm
;
; Created: 05/04/2018 13:14:30
; Author : Thiago
;

.equ n_vezes = 15
.equ valor = 0x2f
.equ end_init = 0x0200

.def r_contador = r18

.org 0x0000
	rjmp inicio

.org 0x0040
inicio:
    ldi r16, 0x08
	out sph, r16
	ldi r16, 0xff
	out spl, r16

	ldi r_contador, n_vezes
	ldi r17, valor
	ldi xl, low(end_init)
	ldi xh, high(end_init)
	ldi r20, 5
loop1:
	st x+, r17
	sub r17, r20

	dec r_contador
	brne loop1
fim:    
	rjmp fim
