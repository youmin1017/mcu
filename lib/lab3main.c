#include "keypad4x4.h"
#include <stdint.h>

void delay(int n) {
  for (uint32_t i = 0; i < n; i++)
    for (uint32_t j = 0; j < 120; j++)
      ;
}

void main() {
  const char true = 1;
  char key = -1, oldkey = -1;
  while(true) {
    key = keypad4x4();
    delay(20);
    
    if(oldkey != key) {
      // setOut(oldkey, ...);
      // oldkey = key;
    }
  }
}
