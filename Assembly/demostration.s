.global _start
.text
_start:	
	#open frame buffer 1 
	mov r0,#1
	bl openfb
	cmp r0,#0
	blt _start_exit

	#get the color blue and store it in r6
	mov r8,r0
	mov r0,#0
	mov r1,#0
	mov r2,#31	
	bl getColor
	mov r6,r0

	#set pixel 7,7 to the blue color stored in r6 
	mov r2,r6
	mov r0,#7
	mov r1,#7
	bl setPixel
	#set pixel 9,0 to the blue color stored in r6
	mov r2,r6
	mov r0,#0
	mov r1,#0
	bl setPixel
	#cleanup the data structures created by openfb and close the framebuffer device
	bl closefb

_start_exit: 
	#clean exit
	mov r7,#1
	svc #0

