#include "Other.Platform.vec.NonGraphic.h"
#include "Declaration.h"

int main(void) {
  system("color F0");
  _IO_File_Log(".exe start core.",1);

  pulseOn();
  _Console_Write_LoadingAnimationSec();
  
  userLogin();
  getMenu();

  _IO_File_Log(".exe end core.",1);

  //  puts("\n By:Bre97 \n");
  return 0;
}

int getMenu(void) {
  system("cls");
  _Console_Write_CutToEnd("1. Game Start\n2. Game Passage\n3. Help\n4. Back User\n5. Game Exit\n", 25, 25, 0);
  _Console_Write_Frame("Which:" , 2);

  char strTemp[16] = "\0" , stv;
  scanf_s("%s" , &strTemp , 16);
  scanf_s("%c" , &stv , 1);

  if (strcmp(strTemp, "1") == 0) {
    EP0_Start000();
  } else if (strcmp(strTemp, "2") == 0) {
    getGamePassage();
  } else if (strcmp(strTemp, "3") == 0) {
    getHelp();
  } else if (strcmp(strTemp, "4") == 0) {
    userLogin();
  } else if (strcmp(strTemp, "5") == 0) {
    return 1;
  }

  getMenu();
  return 1;
}

void getGamePassage(void) {
  system("cls");
  _Console_Write_CutToEnd("GIVE_PLAYER_PASSAGE: DISPLAY\n"
                          "1. Start[EP0_000]----------PLAYER_PASSAGE_ZERO\n"
                          "2. NorthLight[EP0_011]----------PLAYER_PASSAGE_ONE\n"
                          "\n"
                          ,25,25,0);

  char strTemp[32] = "\0" , stv;
  scanf_s("%s" , &strTemp , 32);
  scanf_s("%c", &stv, 1);

  if (strcmp(strTemp, "1") == 0) {
    EP0_Start000();
  } else if (strcmp(strTemp, "2") == 0) {
    EP0_NorthLight011();
  }
}

void getHelp(void) {
  system("cls");
  _Console_Write_CutToEnd("In the v0.1 alpha.2 version.\n"
                          "a lot of user operations have been reduced. Now you can enter 1 to indicate the first item.\n"
                          "Plan to expand and support the expansion in the future.\n"
                          , 25, 25, 0);

  char strTemp , stv;
  scanf_s("%c" , &strTemp , 1);
  scanf_s("%c", &stv, 1);
}



