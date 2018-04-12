;
; forth.asm
;
; Created: 12/04/2018 13:16:34
; Author : THIAGO
;

.macro SET_STACK
	ldi r18, high(RAMEND)
	out sph, r18
	ldi r18, low(RAMEND)
	out spl, r18
.endmacro

.org 0x0000
	rjmp inicio

.org 0x0002
	rjmp rotina_int0

.org 0x0004
	rjmp rotina_int1

.org 0x0040
inicio:
	SET_STACK

	ldi r17, 0b00000011
	out EIMSK, r17

	ldi r17, 0b00001111
	sts EICRA, r17

	sei

	ldi r17, 0xaa
loop:
	nop
	nop
	nop
	dec r17
	brne loop

end:
    rjmp end

rotina_int0:
	inc r18
	dec r18
	reti

rotina_int1:
	inc r19
	dec r19
	reti