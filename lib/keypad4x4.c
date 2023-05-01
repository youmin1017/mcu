#include "keypad4x4.h"

char keypad4x4() {
  // P0 = 1110 0000
  //           0001, 0010, 0100, 1000

  for(char c=0; c < 4; c++) {
    P0 = (0x10 << c);
    for(char r=0; r < 4; ++r) {
      if(P0 ^ (1 << r)) {
        return keys[r][c];
      }
    }
  }
  return -1;
}
