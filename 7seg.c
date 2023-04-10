#include <8051.h>
#include <stdint.h>
#include <stdbool.h>

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
  bool hide = true;
  bool isinc = true;      // false increment 10
  uint16_t count = 0;
  uint16_t clk = 0;
  while (1) {
    switch(opt % 3) {
      case 0:
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
        if(clk == 500 && count > 0) count--;
        P0 = seg(count);
        delay(DELAY);
        P0 = seg10(count);
        delay(DELAY);
        break;
    }
    if(clk > 500) clk = 0;
    clk++;
    hide = ~hide;
    if(P1_0 == 0) {
      if(opt%3 == 0 && count%10 < 9) {
        count++;
      } else if(opt%3 == 1 && (count/10) < 9) {
        count+=10;
      }
      delay(1024);
    }
    if(P1_1 == 0) {
      opt++;
      delay(1024);
    }
  }
}
