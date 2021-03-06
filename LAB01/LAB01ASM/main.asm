;
; LAB01ASM.asm
;
; Created: 26/01/2017 09:23:41
; Author : KasperSK
;


;******** INITIALIZATION ********
.include "M32DEF.INC"
   LDI  R16,HIGH(RAMEND) ;Initialize Stack Pointer
   OUT  SPH,R16
   LDI  R16,LOW(RAMEND)
   OUT  SPL,R16           
   SER  R16              ;PORTB = Outputs
   OUT  DDRB,R16

;********** PROGRAM LOOP ********
   CLR  R16
LOOP:
   CALL DISP_AND_DELAY  ;Display R16
   INC  R16
   RJMP LOOP            ;Jump to "LOOP"

;********** DISPLAYS R16 ********
;********** + SHORT DELAY *******
DISP_AND_DELAY:
   MOV  R17,R16
   COM  R17
   OUT  PORTB,R17
   CLR  R17
   CLR  R18
   LDI  R19,10
AGAIN:
   DEC  R17
   BRNE AGAIN
   DEC  R18
   BRNE AGAIN
   DEC  R19
   BRNE AGAIN
   RET	
;********************************