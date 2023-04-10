#include <8051.h>
#include <stdint.h>
#define START 64 // 起始位置

typedef struct
{
   uint8_t a; // P0
   uint8_t b; // P1
   uint8_t c; // P2
} IO;

union {
   IO bits;
   uint32_t idx;
} U; // 用 index 去控制 P0 P1 P2

void main()
{
   uint8_t flag = 1;
   unsigned d1, d2;
   U.idx = START;

   while (1)
   {
      if (flag)  // 順時鐘
      {
         U.idx = U.idx > 1 ? U.idx >> 1 : 1lu << 23; //當一個 port 到最後一個時，到下一個 port 的第一個
      }
      else // 逆時鐘
      {
         U.idx = U.idx < 1lu << 23 ? U.idx << 1 : 1;
      }
      if (U.idx == START) // 到起始位置反轉 flag 方向
         flag = flag ? 0 : 1;
      P0 = ~U.bits.a; // assign result to port to light led
      P1 = ~U.bits.b;
      P2 = ~U.bits.c;
      for (d1 = 0; d1 < 1024; d1++)
      {
         for (d2 = 0; d2 < 100; d2++)
         {
         }
      }
   }
}
