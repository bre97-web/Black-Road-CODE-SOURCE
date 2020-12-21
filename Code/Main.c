#include <stdlib.h>
#include <string.h>

#include "MUSTER.h"
#include "DECLARATION.h"

// 12/12/2020

int main(void) {

  system("color F0");
  _logEvent_(".exe start core.",1);

  writer();
  pulseOn();
  _Loading_();
  userLogin();
  getMenu();

  _logEvent_(".exe end core.",1);

  //  puts("\n By:Bre97 \n");
  return 0;
}

void getMenu(void) {
  re:;

  system("cls");
  _Cut_puts_("-gameProceed\n-gamePassage\n-gameStart\n-gameHelp\n-gameWriter\n-gameSetting\n-backUser\n-exit\n", 25, 25, 0, "");
  
  char strTemp[16];
  _l_Puts_("Which:" , 2);
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
  } else if (strcmp(strTemp, "-gameWriter") == 0) {
    getWriter();
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
  _Console_Write_Repeatedly(0,"GIVE_PLAYER_PASSAGE: DISPLAY\n",
                      "No.1:Start[EP0_000]", "----------PLAYER_PASSAGE_ZERO\n");
  _Console_Write_Repeatedly(0,"No.2:NorthLight[EP0_011]", "----------PLAYER_PASSAGE_ONE\n",
                      "No.3:");

  char strTemp[32];
  gets_s(strTemp, 32);

  if (strcmp(strTemp, "PLAYER_PASSAGE_ZERO") == 0) {
    EP0_Start000();
  } else if (strcmp(strTemp, "PLAYER_PASSAGE_ONE") == 0) {
    EP0_NorthLight011();
  }
}

void getHelp(void) {
  _Cut_puts_("None", 25, 25, 0, "");

  system("pause");

  char strValue[32];
  gets_s(strValue, 32);
}

void getWriter(void) {
  _Cut_puts_("Drama : Bre 97\nAuthor : Bre 97\nCompose : Bre 97\nCode : Bre 97", 50,
            50, 1,"\n\n\n\n\n\n\n\n\n\n\n"
            "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
            "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20");
  _Cut_puts_ASCII_(
      "Thank you to play this game.", 100, 100,
      "\n\n\n\n\n\n\n\n\n\n\n"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20");
  system("cls");
}



