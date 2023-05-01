my_prog :
	sdcc -c Keypad4x4.c
	sdcc -c LED_Display.c
	sdar -o myIO.lib -rc LED_Display.rel Keypad4x4.rel
	sdcc Lab3-main.c myIO.lib
	packihx Lab3-main.ihx > Lab3-main.hex
clean :
	del Lab3-main.lk
	del Lab3-main.lst
	del Lab3-main.map
	del Lab3-main.mem
	del Lab3-main.rel
	del Lab3-main.asm
	del Lab3-main.hexx
	del Lab3-main.rst
	del Lab3-main.sym
	del *.sym
	del *.rel
	del *.lst
	del *.asm
