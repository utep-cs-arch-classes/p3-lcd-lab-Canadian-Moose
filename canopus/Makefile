# makfile configuration
COMMON_OBJECTS		= main.o draw_shapes.o wdtInterruptHandler.o switches.o p2_interrupt_handler.o buzzer.o stateMachines.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: canopus_c.elf canopus_s.elf

#additional rules for files
canopus_c.elf: ${COMMON_OBJECTS} chooseState_c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

canopus_s.elf: ${COMMON_OBJECTS} chooseState_s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load_c: canopus_c.elf
	msp430loader.sh $^

load_s: canopus_s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf \#* \~*

chooseState_c.o: chooseState_c.c

chooseState_s.o: chooseState_s.s
