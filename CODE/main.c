#include <stdlib.h>
#include <string.h>

#include "muster.h"
#include "statement.h"

//  Use Google-Code-Style
//  Use UTF-8 coding.

int main(void) {
  system("mode con cols=105 lines=30 color 70");

  _logEvent_(".exe start core...");

  writer();
  pulseOn();
  addUserData();

  getMenu();

  _logEvent_(".exe return 0...");

  //  puts("\n By:Bre97 \n");
  return 0;
}

void getMenu(void) {
  re:;

  system("cls");

  if (gameProceedIf() == 1) {
    _Cut_puts_("-gameProceed\n", 25, 25, 0, "");
  }
  _Cut_puts_("-gamePassage\n", 25, 25, 0, "");
  _Cut_puts_("-gameStart\n", 25, 25, 0, "");
  _Cut_puts_("-gameHelp\n", 25, 25, 0, "");
  _Cut_puts_("-gameWriter\n", 25, 25, 0, "");
  _Cut_puts_("-gameSetting\n", 25, 25, 0, "");

  char strTemp[32];
  gets_s(strTemp, 32);

  system("cls");

  if (strcmp(strTemp, "-gamePassage") == 0) {
    getPassageMenu();
  } else if (strcmp(strTemp, "-gameStart") == 0) {
    EP0_friend011();
  } else if (strcmp(strTemp, "-gameHelp") == 0) {
    getHelp();
    goto re;
  } else if (strcmp(strTemp, "-gameProceed") == 0) {
    getProceed();
  } else if (strcmp(strTemp, "-gameWriter") == 0) {
    getWriter();
    goto re;
  } else if (strcmp(strTemp, "-gameSetting") == 0) {
    getCharacter();
    goto re;
  } else {
    goto re;
  }
}

void getPassageMenu(void) {
  _Repeatedly_puts_(0, 1, "GIVE_PLAYER_PASSAGE: DISPLAY\n",
                    "No.1:Friend[EP0_01]", "----------PLAYER_PASSAGE_ONE\n");
  _Repeatedly_puts_(0, 1, "No.2:[EP0_02]", "----------PLAYER_PASSAGE_TWO\n",
                    "No.3:");

  char strTemp[32];
  gets_s(strTemp, 32);

  if (strcmp(strTemp, "PLAYER_PASSAGE_ONE") == 0) {
    EP0_friend011();
  } else if (strcmp(strTemp, "PLAYER_PASSAGE_TWO") == 0) {
  }
}

void getHelp(void) {
  _Cut_puts_("None", 25, 25, 0, "");

  system("pause");

  char strValue[32];
  gets_s(strValue, 32);
}

void getWriter(void) {
  _Cut_puts_(
      "Drama : Bre 97\nAuthor : Bre 97\nCompose : Bre 97\nCode : Bre 97", 50,
      50, 1,
      "\n\n\n\n\n\n\n\n\n\n\n"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20");
  _Cut_puts_ASCII_(
      "Thank you to play this game.", 100, 100,
      "\n\n\n\n\n\n\n\n\n\n\n"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20"
      "\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20");
  system("cls");
}
