;
; first.asm
;
; Created: 29/03/2018 16:13:04
; Author : THIAGO
; Version: v1.0.0 (29-03-2018-16:13:04)

.equ CONTAGEM1 = 0xCA; = 202
.equ CONTAGEM2 = 0xA4; = 164

.org 0x0000
	rjmp inicio

; Replace with your application code
.org 0x0040
inicio:
	ldi r18, 0x08
	out sph, r18
	ldi r18, 0x00
	out spl, r18

program:
	inc r16
	;call other_function(maybe with LEDs)
    call timer_100ms
	dec r16
    rjmp program


.org 0x0400
timer_100ms:
	nop
	nop
	ldi r22, CONTAGEM1
outer_loop:
		ldi r21, CONTAGEM2
inner_loop:
			dec r21
			brne inner_loop
		dec r22
		brne outer_loop
	ret
	