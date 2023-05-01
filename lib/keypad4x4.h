#pragma once
#include "8051.h"

char keys[4][4] = {{0,4,8, 12},
                   {1,5,9, 13},
                   {2,6,10,14},
                   {3,7,11,15}};

char keypad4x4();
