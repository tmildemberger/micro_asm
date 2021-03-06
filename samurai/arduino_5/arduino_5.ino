/**
 * Aluno: Thiago de Mendonça Mildemberger. Data: 24/05/2018
 */

/**
 * O sketch usa 584 bytes (1%) de espaço de armazenamento para programas. O máximo são 32.256 bytes.
 * Variáveis globais usam 9 bytes (0%) de memória dinâmica, deixando 2.039 bytes para variáveis locais. O máximo são 2.048 bytes.
 */


void setup(){

asm("sbi 0x04, 5");
asm("cbi 0x0A, 2");
asm("cbi 0x0A, 3");

}

void loop(){

asm("start:");
asm("sbic 0x09, 3");
asm("rjmp pino_3_em_um");
asm("rjmp pino_3_em_zero");

asm("pino_3_em_zero:");
asm("sbic 0x09, 2");
asm("rjmp zero_um");
asm("rjmp zero_zero");


asm("pino_3_em_um:");
asm("sbic 0x09, 2");
asm("rjmp um_um");
asm("rjmp um_zero");

asm("zero_zero:");
asm("sbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("cbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("rjmp start");

asm("zero_um:");
asm("sbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("cbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_15ms");
asm("rcall atraso_15ms");
asm("rjmp start");

asm("um_zero:");
asm("sbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("cbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("rjmp start");

asm("um_um:");
asm("sbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("cbi 0x05, 5");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("rcall atraso_15ms");
asm("rcall atraso_5ms");
asm("rjmp start");

asm("atraso_15ms:");
asm("ldi r18, 0x4c");
asm("ldi r21, 0x29");
asm("rjmp loop1");

asm("atraso_5ms:");
asm("ldi r18, 0x34");
asm("ldi r21, 0x1c");
asm("  ");
asm("loop1:");
asm("mov r19, r18");
asm("loop2:");
asm("mov r20, r19");
asm("loop3:");
asm("dec r20");
asm("brne loop3");
asm("dec r19");
asm("brne loop2");
asm("dec r18");
asm("brne loop1");

asm("loop4:");
asm("mov r22, r21");
asm("loop5:");
asm("dec r22");
asm("brne loop5");
asm("dec r21");
asm("brne loop4");
asm("ret");

}

