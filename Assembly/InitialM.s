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
    #Opens the first frame buffer
    mov r0,#1
	bl openfb
	cmp r0,#0
	blt _start_exit

	#gets the color purple and store it in r6
	mov r8, r0
	mov r0, #31
	mov r1, #0
	mov r2, #31
	bl getColor
	mov r9, #0
	mov r10, #0

	

LOOP1: add r9,r9, #1
	#set each pixel in one row only the y val is changing for the first part of the M
	mov r0, r9
	mov r1, #0
	mov r2, r6
	bl setPixel
	cmp r9, #7
	blt LOOP1
	
	#set pixel 1,1 to be purple
	mov r2,r6
	mov r0,#1
	mov r1,#1
	bl setPixel


	#set pixel 2, 2 to be purple
	mov r2,r6
	mov r0,#2
	mov r1,#2
	bl setPixel

	#set pixel 3, 3 to be purple
	mov r2,r6
	mov r0,#3
	mov r1,#3
	bl setPixel

	#set pixel 4, 3 to be purple
	mov r2,r6
	mov r0,#4
	mov r1,#3
	bl setPixel

	#set pixel 5, 2 to be purple
	mov r2,r6
	mov r0,#5
	mov r1,#2
	bl setPixel
    
	#set pixel 6, 1 to be purple
	mov r2,r6
	mov r0,#6
	mov r1,#1
	bl setPixel

LOOP2: add r10,r10, #1
	#set each pixel in one row only the y val is changing for the second part of the M
	mov r0, r10
	mov r1, #0
	mov r2, r6
	bl setPixel
	cmp r10, #7
	blt LOOP2
	
	bl closefb

_start_exit:
    mov r7,#1
	svc #0