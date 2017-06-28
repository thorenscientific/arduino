PROG=cam

CC=C:\avrgcc\bin\avr-gcc
SP12=E:\elec\sp12\sp12.exe
DOXYGEN=doxygen.exe
AVR_INCLUDE_PATH=C:\avrgcc\avr\include

MCU = at90s4433
FORMAT	= ihex

CFLAGS	=-O2 -Wall -mmcu=$(MCU) -DCLK=8000 -I$(AVR_INCLUDE_PATH)
OBJ = uart.o main.o adc.o cam.o

all : $(PROG).rom

clean :
	rm *.o *.bak $(PROG).rom *.elf

$(PROG).rom: $(PROG).elf
	avr-objcopy -O $(FORMAT) $(PROG).elf $(PROG).rom

$(PROG).elf : $(OBJ)
	$(CC) $(OBJ) -o $(PROG).elf $(CFLAGS) $(LDFLAGS) $(LIB)

main.o : main.c uart.h adc.h cam.h camCom.h
	$(CC) -c main.c $(CFLAGS) $(LDFLAGS) $(LIB)

cam.o : cam.c cam.h camCom.h adc.h util.h
	$(CC) -c cam.c $(CFLAGS) $(LDFLAGS) $(LIB)

uart.o : uart.c uart.h
	$(CC) -c uart.c $(CFLAGS) $(LDFLAGS) $(LIB)

adc.o : adc.c adc.h util.h
	$(CC) -c adc.c $(CFLAGS) $(LDFLAGS) $(LIB)

download : download-init $(PROG).rom
	$(SP12) -wpfC $(PROG).rom

download-init :
	$(SP12) -i

doc :
	$(DOXYGEN) $(PROG).dox