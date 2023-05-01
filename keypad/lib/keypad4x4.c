char keypad4x4() {
  // P0 = 1110 1110
  //           0001, 0010, 0100, 1000

  /** Number matrix map to 7seg */
  const char keys[4][4] = {{0,4,8, 12},
                           {1,5,9, 13},
                           {2,6,10,14},
                           {3,7,11,15}};


  for (char c = 0; c < 4; c++) {
    P1 = ~(0x10 << c);
    for (char r = 0; r < 4; ++r) {
      if (!(P1 & (1 << r))) {
        return keys[r][c];
      }
    }
  }
  return -1;
}
