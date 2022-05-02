	.arch msp430g2553
	.p2align 1,0
	.text
	.global chooseState
	
# variables 
.extern  state

# void chooseState(void)
chooseState: 
jump_table:  .word case_0
	.word case_1
	.word case_2
	
	cmp &state, #2
	jl default
	
	mov.w &state, r12
	add.w r12, r12
	mov.w jump_table(r12), pc
	
case_0:
	CALL play_game
	jmp end_state
case_1: 
	CALL switch_interrupt_handler
	CALL you_win
	jmp end_state
case_2:
	CALL switch_interrupt_handler
	CALL game_over
	jmp end_state
default:
	CALL play_game
	
end_state: 
pop r0
