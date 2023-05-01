TARGET = test
CC = sdcc
CFLAGS = 

all: $(TARGET).c
	$(CC) $(CFLAGS) $(TARGET).c && packihx $(TARGET).ihx > $(TARGET).hex

.PHONY: clean
clean:
	@echo "Cleaning..."
	-RM *.lk *.map *rst *lst *mem *.rel *.sym *.asm *.ihx *.hex
