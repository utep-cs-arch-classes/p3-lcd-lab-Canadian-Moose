
	.arch msp430g2553
	.p2align 1,0
	.text
	.global 
	
# globally declared variables 
state:          .word  
lives:          .word  3
countdown:      .word  11
newGamePlus:    .word  1
countdownBool:  .word  0

# imported variables 
.extern switch1_down
.extern switch2_down
.extern switch3_down
.extern switch4_down
.extern frogColStart
.extern frogRowStart
.extern frogColor

# void chooseState(void)
chooseState: 
	jmp_table:  .word case_0
		        .word case_1
		        .word case_2
	
	cmp &state, #2
	jn default
	
	mov.w &state, r12
	add.w r12, r12
	mov.w jump_table(r12), pc
	
	case_0:
		CALL play_game
		jmp end
	case_1: 
		CALL switch_interrupt_handler
		CALL you_win
		jmp end
	case_2:
		CALL switch_interrupt_handler
		CALL game_over
		jmp end
	default:
		CALL play_game
	
	end: 
pop r0

# void newGame(void)
newGame:
	mov.w #3, &lives
	mov.w #11, &countdown
	CALL init_shapes
	mov.w #0, state
pop r0

# void play_game(void) 
play_game: 
	# switch 1
	cmp &switch1_down, #0
	jne end_1
		mov.w #1000, r12
		CALL buzzer_set_period
		CALL eraseFrog
		sub.w #10, &frogColStart
		mov.w &frogColor, r12
		CALL frog
		mov.w #0, switch1_down
	end_1:
	
	# switch 2
	cmp &switch2_down, #0
	jne end_2
		mov.w #1000, r12
		CALL buzzer_set_period
		CALL eraseFrog
		sub.w #32, &frogRowStart
		mov.w &frogColor, r12
		CALL frog
		mov.w #0, switch2_down
	end_2:
	
	# switch 3
	cmp &switch3_down, #0
	jne end_3
		mov.w #1000, r12
		CALL buzzer_set_period
		CALL eraseFrog
		add.w #32, &frogRowStart
		mov.w &frogColor, r12
		CALL frog
		mov.w #0, switch3_down
	end_3:
	
	# switch 4
	cmp &switch4_down, #0
	jne end_4
		mov.w #1000, r12
		CALL buzzer_set_period
		CALL eraseFrog
		add.w #10, &frogColStart
		mov.w &frogColor, r12
		CALL frog
		mov.w #0, switch4_down
	end_4:
pop r0

# void you_win(void)
you_win: 
	CALL drawWinScreen
	cmp &switch1_down, #0
	jz if
	cmp &switch2_down, #0
	jz if
	cmp &switch3_down, #0
	jz if
	cmp &switch4_down, #0
	jz if
	cmp &countdown, #0 
	jn endif
	
	if: 
		add.w #1, &newGamePlus
		CALL newGame
	
	endif:
	cmp countdownBool, #1
	jne end 
		sub.w #1, &countdown
		mov.w #0, &countdownBool
	end: 
pop r0

# void game_over(void)
game_over: 
	CALL drawGameOver
	cmp &switch1_down, #0
	jz if
	cmp &switch2_down, #0
	jz if
	cmp &switch3_down, #0
	jz if
	cmp &switch4_down, #0
	jz if
	cmp &countdown, #0 
	jn endif
	
	if: 
		mov.w #0, r12
		CALL buzzer_set_period
		CALL newGame
	
	endif:
	cmp countdownBool, #1
	jne end 
		sub.w #1, &countdown
		mov.w #0, &countdownBool
	end: 
pop r0
