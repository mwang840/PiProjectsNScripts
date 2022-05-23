.data
	FILENAME: .asciz "/dev/fb1"
	FD: .word 0
	FB: .word 0
	
.global openfb
.global closefb
.global getColor
.global setPixel
.text
#openfb(fb#) returns a pointer to a memory mapped 8x8x16 grid.
openfb:	ldr r8,=FILENAME
	add r0,r0,#48
	strb r0,[r8,#7]
	mov r0,r8
	mov r1,#2
	ldr r2,=0666
	mov r7,#5
	svc #0
	cmp r0,#0
	blt openfb_exit
	ldr r1,=FD
	str r0,[r1,#0]
	mov r5,#0
	mov r4,r0
	mov r3,#1
	mov r2,#3
	mov r1,#128
	mov r0,#0
	mov r7,#192
	swi #0
	ldr r1,=FB
	str r0,[r1,#0]
openfb_exit:
	mov pc,lr
	
#closefb() Unmaps file and closes it.  Returns the status code for closing the file
closefb:
	ldr r0,=FB
	mov r1,#128
	mov r7,#215
	swi #0
	ldr r3,=FD
	ldr r0,[r3]
	mov r7,#6
	svc #0
	mov pc,lr

#uint_16 getColor(r,g,b) gets a valid color code from r,g,b values between 0-31
getColor:
	mov r4,r0
	lsl r4,#6
	add r1,r1,r1
	add r4,r4,r1
	lsl r4,#5
	add r4,r4,r2
	mov r0,r4
	mov pc,lr
	
#setPixel(x,y,color) where x,y 0-7 and color returned by getcolor.  Turns on that light
setPixel:
	ldr r3,=FB
	lsl r1,#4
	lsl r0,#1
	add r1,r1,r0
	ldr r3,[r3,#0]
	strh r2,[r3,r1]
	mov pc,lr

