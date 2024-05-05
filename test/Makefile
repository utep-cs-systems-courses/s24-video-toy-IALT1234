CPU          = msp430g2553

CFLAGS       = -mmcu=${CPU} -Os -I../h

LDFLAGS      = -L../lib -L/opt/ti/msp430_gcc/include/

LIBS         = -lTimer -lLcd

# Compiler

CC           = msp430-elf-gcc



# Target and object files

TARGET       = figures.elf

OBJECTS      = figures.o buzzer.o

# Rules

all: $(TARGET)

$(TARGET): $(OBJECTS)

	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

load: $(TARGET)

	msp430loader.sh $^

clean:
	rm -f *.o *.elf
