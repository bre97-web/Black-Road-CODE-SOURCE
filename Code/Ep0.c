#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"

# include <stdio.h>
# include <conio.h>
# include <windows.h>

struct direction {
  int x, y;
}old, neww;
char arr[11][12] = { "1#       \n","2----    \n","3--     \n","4   -----\n","5--    -\n","6----    \n","7--   -- \n","8---     \n","9---    -\n","10   ----\n","11      --\n" };

void directionInitialization(void) {
  old.x = 1;
  old.y = 0;
  neww.x = 1;
  neww.y = 0;
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
  for (int count = 0; count < 11; count++) {
    printf("%s\n", arr[count]);
  }
}

int directionActiveSec(void) {
  if (neww.y + 1 >= 11 || arr[neww.y + 1][neww.x] != ' ') {
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

void fun_win() {
  if (neww.y == 10) {
    Sleep(1000);
    system("cls");
    system("color 47");
    printf("YOU WIN !!!");
  }

}

void operatingCenter(void) {
  switch (getch()) {
  case 'w':
    directionActive(-1, 0); directionUpdate(); diectionPrintf(); Sleep(50);
    directionActive(-1, 0); directionUpdate(); diectionPrintf(); Sleep(50);
    directionActive(-1, 0); directionUpdate(); diectionPrintf(); Sleep(50);
    break;
  case 'a':
    directionActive(0, -1);
    break;
  case 's':
    directionActive(1, 0);
    break;
  case 'd':
    directionActive(0, 1);
    break;
  }
  directionUpdate();
  diectionPrintf();
  while (directionActiveSec()) {
    Sleep(250);
    directionUpdate();
    diectionPrintf();
  }
  fun_win();
}

int api(void) {
  directionInitialization();
  diectionPrintf();
  while (1) {
    operatingCenter();
  }
}