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

void getHelp(void) {
}
void getCharacter(void) {
}
void roleInf(void) {
}
void worldTimeList(void) {
}
void worldWar(void) {
}
void roleInfBattle(void) {
}
void getOver(void) {
}

void writer(void) {
  char by[20] = {84, 104, 101, 32, 119, 114, 105, 116, 101, 114,
                 32, 105, 115, 32, 66,  114, 101, 57,  55,  0};

  system("cls");

  _Cut_puts_(by, 50, 50, 0, "                                        ");
}

void getWriter(void) {
  char drama[32] = "Drama : Bre 97";
  char author[32] = "Author : Bre 97";
  char compose[32] = "Compose : Bre 97";
  char by[32] = "Code : Bre 97";
  char thanks[64] = "Thank you to play this game with enjoing";
  char centerOne[64] =
      "\n\n\n\n\n\n\n\n\n\n\n"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20";

  system("cls");

  _Cut_puts_(drama, 50, 50, 1, centerOne);
  system("cls");
  _Cut_puts_(author, 50, 50, 1, centerOne);
  system("cls");
  _Cut_puts_(compose, 50, 50, 1, centerOne);
  system("cls");
  _Cut_puts_(by, 50, 200, 1, centerOne);
  system("cls");
  _Cut_puts_ASCII_(thanks, 100, 100, centerOne);
  system("cls");
}
