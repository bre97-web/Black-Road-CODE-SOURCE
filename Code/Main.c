#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"
#include "Platform.Rmdust.Error.h"

#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <stdbool.h>



int main(void) {

  Rmdust_Reset();

  Rmdust_System_Log_SetTitle("Start Core");
  Rmdust_System_Log_SetTitleAddons("Non");
  Rmdust_System_Log_SetLableLevel(2);
  Rmdust_System_Log_SetLogActive(TRUE);
  Rmdust_System_IO_Error_Log_Write();

  //userLogin();

  char arr[][16] = { "Game Start", "Game Passage", "Help", "Back User","Game Exit","\0" };
  Menu(0,arr,TRUE);


  return 0;
}





int Menu(int Position, char MenuList[][16],bool Reset) {
  // 初次使用 Menu() 时 Position 应为 0 
  // 当 num 为 < 0 时终止 Menu() 及菜单响应中心 
  if (Position < 0) {
    return 0;
  }

  // Get size for MenuList the min and max
  if (Reset) {
    for (int OutIndex = 0; 1; OutIndex += 1) {
      SetMenuListMax(OutIndex - 1);

      if (MenuList[OutIndex][0] == '\0') {
        break;
      }

      for (int InIndex = 0; 1; InIndex += 1) {
        if (MenuList[OutIndex][InIndex] == '\0') {
          break;
        }
      }
    }
  }

  system("cls");

  for (int in = 0; in < GetMenuListMax();in += 1) {
    printf("%s\n",MenuList[in]);
  }
  printf("%s\n",MenuList[Position]);


  Menu(__MenuOperate(1, Position, 0, GetMenuListMax()),MenuList,FALSE);

  return 0;
}

static struct System {
  struct SystemMenu {
    int Line;
    int Vertical;
  } Menu;


} System;

inline void SetMenuListMax(int Number) {
  System.Menu.Line = Number;
}

inline int GetMenuListMax() {
  return System.Menu.Line;
}



// 操作菜单选项,只有这个函数才能调用菜单响应中心 
inline int __MenuOperate(int mode, int num, int Min, int Max) {
  switch (getch()) {
  case 119:
    if (num != Min) {
      num--;
    }
    break;
  case 115:
    if (num != Max) {
      num++;
    }
    break;
  case 13:
    if (__MenuList(mode, num) == -1) {
      return -1;
    }
    break;
  }

  return num;
}

// 所有菜单的超级响应中心 
inline int __MenuList(int Mode, int OperationType) {

  switch (Mode) {
    
      
    // Main-Menu
    case 1:
      switch (OperationType) {
        case 0:
          getProceed();
          break;
        case 1:
          //getGamePassage(0);
          break;
        case 2:
          getHelp();
          break;
        case 3:
          userLogin();
          break;
        case 4:
          return -1;
          break;
      }
      break;
  }

  return 1;
}

void getHelp(void) {
  system("cls");
  _Console_Write_CutToEnd(25, 25, 0,
    "In version 0.1-Alpha.1c.\n\n"
    "Regarding the operation of the main interface : \n    W S is the option switch key.\n"
    "Regarding the operation of the game : \n    A D(S) is the parallel displacement Key, and SPACE Key + A W D is the special displacement Key.\n    At any time in the game, -Key to disconnect the game, = Key to have no effect.\n\n");
  _Console_Write_Frame("Author Information:", '=',0);
  _Console_Write_Frame("Google - Mail:BY.SGATN3@Gmail.com", '-',0);
  _Console_Write_Frame("Outlook - Mail:PRIVATE.BY_SGATN3.re@Outlook.com", '-',1);

  system("pause");
}
