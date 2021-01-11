#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"

# include <stdio.h>
# include <conio.h>
# include <windows.h>

#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"

struct direction {
  int x, y;
}old, neww;
char arr[11][12] = { "1#       \n","2----    \n","3--     \n","4   -----\n","5--    -\n","6----    \n","7--   -- \n","8---     \n","9---    -\n","10   ----\n","11      --\n" };

void loading() {
  old.x = 1;
  old.y = 0;
  neww.x = 1;
  neww.y = 0;
}

void fun_update() {
  if (old.x != neww.x || old.y != neww.y) {
    arr[old.y][old.x] = ' ';
    arr[neww.y][neww.x] = '#';
    old.y = neww.y;
    old.x = neww.x;
  }
}

void fun_printf() {
  system("cls");
  for (int count = 0; count < 11; count++) {
    printf("%s\n", arr[count]);
  }
}

int fun_activeSec() {
  if (neww.y+1 >=11) {
    return 0;
  }
  if (arr[neww.y + 1][neww.x] != ' ') {
    return 0;
  }
  neww.y += 1;
  return 1;
}

int fun_active(int a, int b) {
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

void fun_gets() {
  switch (getch()) {
  case 'w':
    fun_active(-1, 0); fun_update(); fun_printf(); Sleep(50);
    fun_active(-1, 0); fun_update(); fun_printf(); Sleep(50);
    fun_active(-1, 0); fun_update(); fun_printf(); Sleep(50);
    break;
  case 'a':
    fun_active(0, -1);
    break;
  case 's':
    fun_active(1, 0);
    break;
  case 'd':
    fun_active(0, 1);
    break;
  }
  fun_update();
  fun_printf();
  while (fun_activeSec()) {
    Sleep(250);
    fun_update();
    fun_printf();
  }
  fun_win();
}

int api(void) {
  loading();
  fun_printf();
  while (1) {
    fun_gets();
  }
}