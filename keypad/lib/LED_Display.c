
#include "LED_Display.h"
#include <stdint.h>

void delay(int n) {
  unsigned d1, d2;
  for (d1 = 0; d1 < n; d1++) {
    for (d2 = 0; d2 < 120; d2++) {
    }
  }
}

void LED_Display(int out[]) {
  P0 = (out[0] + (0xE0));
  delay(25);
  P0 = (out[1] + (0xD0));
  delay(25);
  P0 = (out[2] + (0xB0));
  delay(25);
  P0 = (out[3] + (0x70));
  delay(25);
}
