.global _start
.data
	FILENAME: .asciz "/dev/fb1"
	FD: .word 0
	FB: .word 0
	
.global openfb
.global closefb
.global getColor
.global setPixel
.text
_start:
        #open frame buffer 1
        mov r0,#1
        bl openfb
        cmp r0,#0
        blt _start_exit

        #Sets color to blank then get the color securing the blank
        mov r8,r0
        mov r0, #0
        mov r1, #0
        mov r2, #0
        bl getColor
        mov r6, #0

        #sets up the variables for the loop
        mov r0, #0
        mov r1, #0
        mov r2, r6
        mov r9, #0
        mov r10, #0
        b INNERLOOP
        #initializes outer loop
  OUTERLOOP: 
        cmp r0, #8
        beq _start_exit
        ADD r10, #1
        mov r1,#0
        mov r9, #0
        b INNERLOOP
        #initializes inner loop and calls the outer after each iteration
  INNERLOOP:
        cmp r1, #8
        beq OUTERLOOP
        bl setPixel
        mov r0, r10
        ADD r9, #1
        mov r1, r9
        b INNERLOOP
    
        bl closefb

_start_exit:
    mov r7,#1
	svc #0

