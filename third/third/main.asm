;
; third.asm
;
; Created: 05/04/2018 14:07:55
; Author : Thiago
;

.equ n_vezes = 15
.equ valor = 0x2f
.equ end_origem = 0x0200
.equ end_destino = 0x0257

.def r_contador = r18
.def r_dados = r17

.org 0x0000
	rjmp inicio

.org 0x0040
inicio:
    ldi r16, 0x08
	out sph, r16
	ldi r16, 0xff
	out spl, r16

	call escreve_coisas

	ldi xl, low(end_origem)
	ldi xh, high(end_origem)

	ldi yl, low(end_destino)
	ldi yh, high(end_destino)

	ldi r_contador, n_vezes
loop_copia:
	ld r_dados, x+
	st y+, r_dados

	dec r_contador
	brne loop_copia

fim:    
	rjmp fim


.org 0x0100
escreve_coisas:
	ldi r_contador, n_vezes
	ldi r_dados, valor
	ldi xl, low(end_origem)
	ldi xh, high(end_origem)
loop_escreve:
	st x+, r_dados
	inc r_dados

	dec r_contador
	brne loop_escreve
	ret
