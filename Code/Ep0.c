#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"

# include <stdio.h>
# include <conio.h>
# include <windows.h>

struct direction {
  int x, y;
}old, neww;
char arr[30][60] = {"#                                                         \n",
                    "----                                                      \n",
                    "--                                                        \n",
                    "                                                     -----\n",
                    "--                                                       -\n",
                    "----                                                      \n",
                    "-                                                  -   -- \n",
                    "---                                                       \n",
                    "---                                                      -\n",
                    "                                                      ----\n",
                    "                                                        --\n",
                    "----                                                      \n",
                    "--                                                        \n",
                    "                                                     -----\n",
                    "---                                                      -\n",
                    "                    ----------------------------      ----\n",
                    "             --------                                   --\n",
                    "----                                                      \n",
                    "--         -           !!                ---------- ---   \n",
                    "  !!!    --          ----------------                -----\n",
                    "---------     --------                                   -\n",
                    "            -----                                     ----\n",
                    "                                            ---------   --\n",
                    "----!!!!                                                  \n",
                    "---------------                                           \n",
                    "       !!!                                !!         -----\n",
                    "------------------- !                    -----------------\n",
                    "------------------------!         !    -------------------\n",
                    "----------------------------------------------------------\n"};

void directionInitialization(unsigned int x, unsigned int y) {
  old.x = x;
  old.y = y;
  neww.x = old.x;
  neww.y = old.y;
}

void directionUpdate(void) {
  if (old.x != neww.x || old.y != neww.y) {
    arr[old.y][old.x] = ' ';
    arr[neww.y][neww.x] = '#';
    old.y = neww.y;
    old.x = neww.x;
  }
}

void diectionPrintf(void) {
  system("cls");
  for (int count = 0; count < 30; count++) {
    printf("%s", arr[count]);
  }
}

int directionActiveSec(void) {
  if (neww.y + 1 >= sizeof(arr) || arr[neww.y + 1][neww.x] != ' ') {
    return 0;
  }
  neww.y += 1;
  return 1;
}

int directionActive(int a, int b) {
  if (arr[neww.y + a][neww.x + b] != ' ') {
    return 0;
  }
  neww.y += a;
  neww.x += b;
  return 1;
}

void operatingCenter(void) {
  switch (getch()) {
    //  Move
    case 'a':
      directionActive(0, -1);
      break;
    case 'd':
      directionActive(0, 1);
      break; 
    case 'w':
      for (int count = 0; count < 3;count ++) {
        directionActive(-1, 0); directionUpdate(); diectionPrintf(); Sleep(50);
      }
      
      break;
    case ' ':
      //  Move : Jump
      switch (getch()) {
        case 'a':
          for (int count = 0; count < 3; count++) {
            directionActive(-1, 0); directionUpdate(); diectionPrintf(); Sleep(50);
          }
          directionActive(0, -1);
          break;
        case 'd':
          for (int count = 0; count < 3; count++) {
            directionActive(-1, 0); directionUpdate(); diectionPrintf(); Sleep(50);
          }
          directionActive(0, 1);
          break;
        case 'w':
          for (int count = 0; count < 3; count++) {
            directionActive(-1, 0); directionUpdate(); diectionPrintf(); Sleep(50);
          }
        default:
          break;
      }
      break;
    //  Attack
    case 'e':
      attack();
      break;
  }
  directionUpdate();
  diectionPrintf();
  while (directionActiveSec()) {
    Sleep(250);
    directionUpdate();
    diectionPrintf();
  }
  attackSec();
}

int attack() {
  if (arr[neww.y][neww.x - 1] == '!' || arr[neww.y][neww.x + 1] == '!') {
    arr[neww.y][neww.x - 1] = ' ';
    arr[neww.y][neww.x + 1] = ' ';
    return 1;
  }
  return 0;
}
int attackSec() {
  if (arr[neww.y + 1][neww.x] == '!') {
    arr[neww.y + 1][neww.x] = ' ';
    return 1;
  }
  return 0;
}

int Ep0(void) {
  directionInitialization(0,0);
  diectionPrintf();
  while (1) {
    operatingCenter();
  }
}