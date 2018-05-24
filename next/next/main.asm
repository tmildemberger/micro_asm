;
; next.asm
;
; Created: 24/05/2018 13:55:10
; Author : THIAGO
;

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
	
	call atraso_15ms

	
end:
    rjmp end

atraso_15ms:
	ldi r18, 0x4c
	ldi r21, 0x29
	rjmp loop1

atraso_5ms:
	ldi r18, 0x34
	ldi r21, 0x1c
	
loop1:
	mov r19, r18
loop2:
	mov r20, r19
loop3:
	dec r20
	brne loop3
	dec r19
	brne loop2
	dec r18
	brne loop1

loop4:
	mov r22, r21
loop5:
	dec r22
	brne loop5
	dec r21
	brne loop4
	ret