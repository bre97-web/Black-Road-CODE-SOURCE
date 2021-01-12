#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"

# include <stdio.h>
# include <conio.h>
# include <windows.h>

struct direction {
  int x, y;
}old, neww;
char worldArr[30][60] = {"#                                                         \n",
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


//  struct direction : old.x & old.y & neww.x & neww.y
void directionValueInitialization(unsigned int x, unsigned int y) {
  old.x = x;
  old.y = y;
  neww.x = old.x;
  neww.y = old.y;
}
void directionValueUpdate(void) {
  if (old.x != neww.x || old.y != neww.y) {
    worldArr[old.y][old.x] = ' ';
    worldArr[neww.y][neww.x] = '#';
    old.y = neww.y;
    old.x = neww.x;
  }
}

void diectionPrintf(void) {
  system("cls");
  for (int count = 0; count < 30; count++) {
    printf("%s", worldArr[count]);
  }
}

int directionControlCenterSec(void) {
  if (neww.y + 1 >= sizeof(worldArr) || worldArr[neww.y + 1][neww.x] != ' ') {
    return 0;
  }
  neww.y += 1;
  return 1;
}
int directionControlCenter(int a, int b) {
  if (worldArr[neww.y + a][neww.x + b] != ' ') {
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
      directionControlCenter(0, -1);
      break;
    case 'd':
      directionControlCenter(0, 1);
      break; 
    case 'w':
      for (int count = 0; count < 3;count ++) {
        directionControlCenter(-1, 0); directionValueUpdate(); diectionPrintf(); Sleep(50);
      }
      
      break;
    case ' ':
      //  Move : Jump
      switch (getch()) {
        case 'a':
          for (int count = 0; count < 3; count++) {
            directionControlCenter(-1, 0); directionValueUpdate(); diectionPrintf(); Sleep(50);
          }
          directionControlCenter(0, -1);
          break;
        case 'd':
          for (int count = 0; count < 3; count++) {
            directionControlCenter(-1, 0); directionValueUpdate(); diectionPrintf(); Sleep(50);
          }
          directionControlCenter(0, 1);
          break;
        case 'w':
          for (int count = 0; count < 3; count++) {
            directionControlCenter(-1, 0); directionValueUpdate(); diectionPrintf(); Sleep(50);
          }
        default:
          break;
      }
      break;
    //  Attack
    case 'e':
      manualAttack();
      break;
  }
  directionValueUpdate();
  diectionPrintf();
  while (directionControlCenterSec()) {
    Sleep(250);
    directionValueUpdate();
    diectionPrintf();
  }
  manualAttackSec();
}

int manualAttack() {
  if (worldArr[neww.y][neww.x - 1] == '!' || worldArr[neww.y][neww.x + 1] == '!') {
    worldArr[neww.y][neww.x - 1] = ' ';
    worldArr[neww.y][neww.x + 1] = ' ';
    return 1;
  }
  return 0;
}
int manualAttackSec() {
  if (worldArr[neww.y + 1][neww.x] == '!') {
    worldArr[neww.y + 1][neww.x] = ' ';
    return 1;
  }
  return 0;
}

int Ep0(void) {
  directionValueInitialization(0,0);
  diectionPrintf();
  while (1) {
    operatingCenter();
  }
}