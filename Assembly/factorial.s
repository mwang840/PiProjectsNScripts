.text
.global _start
_start:
	MOV r0, #5
	MOV r1, #3
	MOV r2, r0
LOOP: 	
      ADD r0, r2, r0
      SUB r1, r1, #1
      CMP r1, #1	
      BEQ EXIT			
      B LOOP
	
EXIT: MOV r0,#0
      MOV r8,#93
      SVC #0
