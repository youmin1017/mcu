#include <8051.h>
#include <stdbool.h>
#include <stdint.h>

uint8_t SEG[] = {0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9};

#define DELAY 5
#define HIDE 0xdf
#define OFFSET 0x10
#define seg10(n) SEG[n / 10]
#define seg(n) SEG[n % 10] + OFFSET

void delay(int n) {
  for (uint32_t i = 0; i < n; i++)
    for (uint32_t j = 0; j < 120; j++)
      ;
}

void main() {
  uint8_t opt = 0; // false show 10 digit
  uint16_t count = 0;
  uint16_t clk = 0;

  while (1) { // render mode, [first digit flashing, second digit flashing,
              // decrement count and render it]
    switch (opt) {
    case 0:
      // if clock smaller than 250 show number, or hide it
      // to flashing number
      P0 = clk < 250 ? seg(count) : HIDE + OFFSET;
      delay(DELAY);
      P0 = seg10(count);
      delay(DELAY);
      break;
    case 1:
      P0 = seg(count);
      delay(DELAY);
      P0 = clk < 250 ? seg10(count) : HIDE;
      delay(DELAY);
      break;
    case 2:
      if (clk == 500 && count > 0)
        count--;
      P0 = seg(count);
      delay(DELAY);
      P0 = seg10(count);
      delay(DELAY);
      break;
    }
    if (clk > 500)
      clk = 0; // reset clk
    clk++;
    if (P1_0 == 0) {
      if (opt == 0 && count % 10 < 9) {
        count++; // first digit increment
      } else if (opt == 1 && (count / 10) < 9) {
        count += 10; // second digit increment
      }
      delay(1024);
    }
    if (P1_1 == 0) {
      opt = opt == 2 ? 0 : opt + 1;
      delay(1024);
    }
  }
}
