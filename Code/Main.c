#include "Other.Platform.vec.NonGraphic.h"
#include "Declaration.h"

// 12/12/2020

int main(void) {

  system("color F0");
  _IO_File_Log(".exe start core.",1);

  writer();
  pulseOn();
  _Console_Write_LoadingAnimationSec();
  userLogin();
  getMenu();

  _IO_File_Log(".exe end core.",1);

  //  puts("\n By:Bre97 \n");
  return 0;
}

void getMenu(void) {
  re:;

  system("cls");
  _Console_Write_CutToEnd("-gameProceed\n-gamePassage\n-gameStart\n-gameHelp\n-gameWriter\n-gameSetting\n-backUser\n-exit\n", 25, 25, 0);

  char strTemp[16];
  _Console_Write_Frame("Which:" , 2);
  gets_s(strTemp, 16);

  system("cls");

  if (strcmp(strTemp, "-gamePassage") == 0) {
    getPassageMenu();
  } else if (strcmp(strTemp, "-gameStart") == 0) {
    EP0_Start000();
  } else if (strcmp(strTemp, "-gameHelp") == 0) {
    getHelp();
  } else if (strcmp(strTemp, "-gameProceed") == 0) {
    getProceed();
  } else if (strcmp(strTemp, "-gameSetting") == 0) {
    
  } else if (strcmp(strTemp, "-backUser") == 0) {
    userLogin();
  } else if (strcmp(strTemp, "-exit") == 0) {
    goto end;
  }
  
  goto re;
  end:;
}

void getPassageMenu(void) {
  _Console_Write_CutToEnd("GIVE_PLAYER_PASSAGE: DISPLAY\n"
                          "No.1:Start[EP0_000]----------PLAYER_PASSAGE_ZERO\n"
                          "No.2:NorthLight[EP0_011]----------PLAYER_PASSAGE_ONE\n"
                          "No.3:"
                          ,25,25,0);

  char strTemp[32];
  gets_s(strTemp, 32);

  if (strcmp(strTemp, "PLAYER_PASSAGE_ZERO") == 0) {
    EP0_Start000();
  } else if (strcmp(strTemp, "PLAYER_PASSAGE_ONE") == 0) {
    EP0_NorthLight011();
  }
}

void getHelp(void) {
  _Console_Write_CutToEnd("In the v0.1 alpha.2 version.\n"
                          "a lot of user operations have been reduced. Now you can enter 1 to indicate the first item.\n"
                          "Plan to expand and support the expansion in the future.\n"
                          , 25, 25, 0);
}



