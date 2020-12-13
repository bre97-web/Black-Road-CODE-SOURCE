#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "statement.h"

//  Use GBK coding.

void pulseOn(void) {
  _Repeatedly_puts_(100, 3, "", "",
                    "                                                 ");
  _Repeatedly_puts_(100, 1,
                    "                                ******       *******      "
                    "  ********       ",
                    "                                **   ***     **     **    "
                    "  **             ",
                    "                                **    **     **     **    "
                    "  **             ");
  _Repeatedly_puts_(100, 1,
                    "                                **   **      **     **    "
                    "  **             ",
                    "                                ******       **    **     "
                    "  *****          ",
                    "                                **   ***     ******       "
                    "  **             ");
  _Repeatedly_puts_(100, 1,
                    "                                **    ***    **    **     "
                    "  **             ",
                    "                                **    ***    **     **    "
                    "  **             ",
                    "                                ********     **      **   "
                    "  **             ");
  _Repeatedly_puts_(100, 1,
                    "                                ******       **       **  "
                    "  **********     ",
                    "                          ",
                    "                         -------------------NINE - "
                    "SEVEN-------------------");

  system("cls");
}

void writer(void) {
  char by[20] = {84, 104, 101, 32, 119, 114, 105, 116, 101, 114,
                 32, 105, 115, 32, 66,  114, 101, 57,  55,  0};

  system("cls");

  _Cut_puts_(by, 50, 50, 0, "                                        ");
}


