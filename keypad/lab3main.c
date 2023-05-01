#include "lib/keypad4x4.h"
#include "lib/LED_Display.h"
#include <8051.h>
#include <stdlib.h>

void setOut(int ans, int out[]) {
  out[3] = out[2];
  out[2] = out[1];
  out[1] = out[0];
  out[0] = ans;
}

void main() {
  int out[4] = {0, 0, 0, 0};
  int oldkey = -1, key = -1;
  int count = 0;
  while (1) {

    // read keyborad
    key = keypad4x4();

    // debounce keyboard every 30 cycle
    count++;
    if (count > 30) {
      count = 0;
      oldkey = -1;
    }

    if (key >= 0 && key <= 15 && key != oldkey) {
      count = 0; // reset counter
      setOut(key, out);
      oldkey = key;
    }
    delay(20);
    LED_Display(out);
  }
}
