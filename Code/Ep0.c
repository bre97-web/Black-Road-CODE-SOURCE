#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"

# include <stdio.h>
# include <conio.h>
# include <windows.h>

struct direction {
  int x, y;
}old, neww;
struct active {
  int life, operation;
}set;

char worldArr[30][61];

int ptr() {
  FILE *ptrAddress = NULL;
  fopen_s(&ptrAddress,"./resource/core/ptr/ptr.txt","r");
  if (ptrAddress == NULL) {
    return -1;
  }

  int width = 0;
  while (!feof(ptrAddress)) {
    if (width == 30) {
      return 0;
    }
    for (int count = 0; count < 60;count ++) {
      worldArr[width][count] = (char)fgetc(ptrAddress);
    }
    worldArr[width][60] = '\0';
    width++;
  }
  return 0;
}

//  struct direction : old.x & old.y & neww.x & neww.y
void directionValueInitialization(unsigned int x, unsigned int y) {
  old.x = x;
  old.y = y;
  neww.x = old.x;
  neww.y = old.y;
  set.life = 100;
  set.operation = 100;
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
  for (int count = 0; count < 29; count++) {
    printf("%s\n", worldArr[count]);
  }
  printf("LIFE : %d  |  OPERATION : %d" , set.life,set.operation);


}

int directionControlCenter(int a, int b) {
  if (a == 0 && b == 0) {
    return 0;
  }
  if (neww.y + 1 >= (int)sizeof(worldArr) || worldArr[neww.y + a][neww.x + b] != ' ') {
    return 0;
  }
  neww.y += a;
  neww.x += b;
  return 1;
}

void operatingCenter(void) {
  int valueOne = 0 , valueTwo = 0 , control = 0 , jump = 0;
  
  switch (getch()) {
    //  Attack
    case 'e':manualAttack();break;
    //  Move �� Foot
    case 'a':valueTwo = -1;break;
    case 'd':valueTwo = 1;break; 
    case 'w':valueOne = -1;control = 3;break;
    //  Move : Jump
    case ' ':
      switch (getch()) {
        case 'a':valueOne = -1;valueTwo = -1;break;
        case 'd':valueOne = -1;valueTwo = 1;break;
        case 'w':valueOne = 0;jump = 1;break;
        default:
          break;
      }
      control = 3;
      break;
  }
  int count = 0;

  if (jump == 1) {
    fun();
  }
  do {
    directionControlCenter(valueOne , valueTwo);
    directionValueUpdate();
    diectionPrintf();
    Sleep(25);
    count ++;
  } while (count < control);
  do {
    manualAttackSec();
    directionValueUpdate();
    Sleep(25);
    diectionPrintf();
  } while (directionControlCenter(1, 0));
}

void fun() {
  neww.y--;
  for (int count = 3;count >= 0;count --) {
    if (worldArr[neww.y][neww.x - 1] == ' ' && worldArr[neww.y + 1][neww.x - 1] != ' ') {
      neww.x --;
      break;
    } else if (worldArr[neww.y][neww.x + 1] == ' ' && worldArr[neww.y + 1][neww.x + 1] != ' ') {
      neww.x ++;
      break;
    } else {
      directionControlCenter(-1,0);
      directionValueUpdate();
      Sleep(25);
      diectionPrintf();
    }
  }

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
    neww.y += 1;
    return 1;
  }
  return 0;
}

int Ep0(void) {
  ptr();
  directionValueInitialization(0,0);
  diectionPrintf();
  while (1) {
    operatingCenter();
    
  }
}