# makfile configuration
COMMON_OBJECTS		= draw_shapes.o wdtInterruptHandler.o stateMachines.o switches.o p2_interrupt_handler.o buzzer.o
CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: canopus.elf

#additional rules for files
canopus.elf: ${COMMON_OBJECTS} main.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd 

load: canopus.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
