	.arch msp430g2553
	.p2align 1,0
	.text
	.global greenControl
	.extern P1OUT
	.equ DELAY_CYCLES, 1000000 

advancing_f:

	cmp #0, r12		
	jz off
	call delay
	bis #64, &P1OUT	
	call delay		

	and #~64, &P1OUT	
	call delay		

	bis #1, &P1OUT	
	call delay		



	and #~1, &P1OUT	
	call delay		



	jmp greenControl


off:

	and #~(64 | 1), &P1OUT 
	ret

delay:

	mov #DELAY_CYCLES, r13 

delay_loop:

	dec r13		

	jnz delay_loop	

	ret
