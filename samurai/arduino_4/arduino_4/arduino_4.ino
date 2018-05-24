void setup(){
asm("sbi 0x04, 5"); //DDRB = 0x24 pin 5
asm("cbi 0x0A, 2"); //DDRD = 0x2A pin 2
}
void loop(){
asm("start:");
asm("sbic 0x09, 2");
asm("rjmp start2");
asm("rjmp start1");

asm("start1:");
asm("ldi r17, 0xff");
asm("mov r8, r17");
asm("ldi r17, 0x40");
asm("mov r9, r17");
asm("ldi r19, 0x10");
asm("sbi 0x05, 5"); //PORTB = 0x25
asm("rcall atraso");
asm("ldi r17, 0xff");
asm("mov r8, r17");
asm("ldi r17, 0x40");
asm("mov r9, r17");
asm("ldi r19, 0x10");
asm("cbi 0x05, 5"); //PORTB = 0x25
asm("rcall atraso");
asm("rjmp start");

asm("start2:");
asm("ldi r17, 0xff");
asm("mov r8, r17");
asm("ldi r17, 0x40");
asm("mov r9, r17");
asm("ldi r19, 0x20");
asm("sbi 0x05, 5"); //PORTB = 0x25
asm("rcall atraso");
asm("ldi r17, 0xff");
asm("mov r8, r17");
asm("ldi r17, 0x40");
asm("mov r9, r17");
asm("ldi r19, 0x20");
asm("cbi 0x05, 5"); //PORTB = 0x25
asm("rcall atraso");
asm("rjmp start");

asm("atraso:");
asm("dec r8");
asm("brne atraso");
asm("dec r9");
asm("brne atraso");
asm("dec r19");
asm("brne atraso");
asm("ret");
}
