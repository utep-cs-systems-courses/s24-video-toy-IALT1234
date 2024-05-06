CPU          = msp430g2553
CFLAGS       = -mmcu=${CPU} -Os -I../h
LDFLAGS      = -L../lib -L/opt/ti/msp430_gcc/include/
LIBS         = -lTimer -lLcd
# Compiler
CC           = msp430-elf-gcc


TARGET       = figures.elf

OBJECTS      = figures.o buzzer.o advancing.o 

# Rules

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

# Load command for figures.elf

load: $(TARGET)
	msp430loader.sh $^

# Load command for advancing.s

load_advancing: advancing.o
	msp430loader.sh $^

clean:
	rm -f *.o *.elf
