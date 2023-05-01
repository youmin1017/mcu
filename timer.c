#include <8051.h>

typedef unsigned char u8;

// interrupt per 50ms
#define _TH0 (65536 - 50000) / 256;
#define _TL0 (65536 - 50000) % 256;

int count = 0;
int time = 0;

_Bool ff = 0;


void delay(int n) {
  unsigned d1, d2;
  for (d1 = 0; d1 < n; d1++) {
    for (d2 = 0; d2 < 120; d2++) {
    }
  }
}

void timer0_isr(void) __interrupt(1) __using(1) {
  TH0 = _TH0;
  TL0 = _TL0;
  if (count == 10) {
    count = 0; // speed
    ff = 1;
  } else {
    count++;
  }
}

void main() {
  u8 seg1 = 0xe0; // 0b11100000
  u8 seg2 = 0xd0; // 0b11010000

  TH0 = _TH0;
  TL0 = _TL0;
  TMOD = 0x01; // 16-bit timer/counter
  TR0 = 1;     // enable timer0
  EA = 1;      // enable all overflow interrupt
  ET0 = 1;     // enable Timer0 overflow interrupt

  while (1) {
    if (ff) {
      time = time < 100 ? time+1 : 0;
      ff = 0;
    }
    delay(5);
    P2 = seg1;
    P2 += time % 10;
    delay(5);
    P2 = seg2;
    P2 += time / 10;
  }
}
