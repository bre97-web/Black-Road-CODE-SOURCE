#include "Declaration.h"
#include "Other.Platform.H.vec.Description.h"
#include "Error.h"

#include <conio.h>
#include <Windows.h>
#include <stdio.h>

int main(void) {
  system("color F0");

  _IO_File_Log(".exe start core.", '=');

  //eggControlCenter();

  pulseOn();
  _Console_Write_LoadingAnimationSec();

  userLogin();
  getMenu(0);

  _IO_File_Log(".exe end core.", '=');

  return 0;
}

int getMenu(int num) {
  system("cls");
  _Console_Write_CutToEnd(0, 0, 0,
      "1. Game Start\n2. Game Passage\n3. Help\n4. Back User\n0. Game Exit\n");
  _Console_Write_Frame("Which:", '=', 1);
  char arr[5][20] = {"Game Start", "Game Passage", "Help", "Back User",
                     "Game Exit"};
  printf("%s", arr[num]);

  switch (_getch()) {
    case 119:
      if (num != 0) {
        num--;
      }
      break;
    case 115:
      if (num != 4) {
        num++;
      }
      break;
    case 13:
      if (list(num, 1) == 0) {
        return REPORT_ACTIVE_FALSE;
      }
      break;
  }
  getMenu(num);
  return REPORT_ACTIVE_FUNCTION_END;
}

int list(int num, int mode) {
  switch (mode) {
    case 1:
      switch (num) {
        case 0:getProceed();break;
        case 1:getGamePassage(0);break;
        case 2:getHelp();break;
        case 3:userLogin();break;
        case 4:return REPORT_ACTIVE_FALSE;break;
      }
      break;
    case 2:
      switch (num) {
        case 0:game("00");break;
        case 3:return REPORT_ACTIVE_FALSE;break;
      }
      break;
  }
  return REPORT_ACTIVE_FUNCTION_END;
}

int getGamePassage(int num) {
  system("cls");
  _Console_Write_CutToEnd(0, 0, 0,
      "GIVE_PLAYER_PASSAGE: DISPLAY\n"
      "1. Start[EP0_000]\n"
      "2. NorthLight[EP0_011]\n"
      "0. Passage Back\n");
  _Console_Write_Frame("Which:", '=', 1);
  char arr[5][20] = {"Start[EP0_000]", "NorthLight[EP0_011]", "Passage Back"};
  printf("%s", arr[num]);

  switch (_getch()) {
    case 119:
      if (num != 0) {
        num--;
      }
      break;
    case 115:
      if (num != 4) {
        num++;
      }
      break;
    case 13:
      if (list(num, 2) == 0) {
        return REPORT_ACTIVE_FALSE;
      }
      break;
  }
  getGamePassage(num);
  return REPORT_ACTIVE_FUNCTION_END;
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

void pulseOn(void) {
  system("color f0");
  system("mode con cols=120 lines=30");

  _Console_Write_Repeatedly(0,
      "\n\n\n\n                               "
      "------------------------------------------------------------\n",
      "                               |     **           **      "
      "************       *******     |\n",
      "                               |    ***           ***     **          "
      "     **       *    |\n");
  _Console_Write_Repeatedly(0,
                            "                               |     ***        "
                            " ***      **              **             |\n",
                            "                               |      ***       "
                            "***     *********        **              |\n",
                            "                               |       ***     "
                            "***        **             **              |\n");
  _Console_Write_Repeatedly(0,
                            "                               |        ***   "
                            "***         **              **             |\n",
                            "                               |         *** "
                            "***          **               **       *    |\n",
                            "                               |           ***  "
                            "          *************      *******     |\n");
  _Console_Write_Repeatedly(
      0,
      "                               "
      "------------------------------------------------------------\n",
      0, 0);
  Sleep(2000);
}
