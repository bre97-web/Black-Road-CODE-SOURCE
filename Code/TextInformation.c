#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "DECLARATION.h"

//  Use GBK coding.

void pulseOn(void) {
  system("color f0");
  system("mode con cols=50 lines=30");

  _Console_Write_Repeatedly(100,"      ******       *******        ********       \n",
                                "      **   ***     **     **      **             \n",
                                "      **    **     **     **      **             \n");
  _Console_Write_Repeatedly(100,"      **   **      **     **      **             \n",
                                "      ******       **    **       *****          \n",
                                "      **   ***     ******         **             \n");
  _Console_Write_Repeatedly(100,"      **    ***    **    **       **             \n",
                                "      **    ***    **     **      **             \n",
                                "      ********     **      **     **             \n");
  _Console_Write_Repeatedly(100,"      ******       **       **    **********     \n",
                                "-------------------NINE - SEVEN-------------------\n",0);

  Sleep(2000);
  system("cls");
  system("mode con cols=120 lines=30");

  _Console_Write_Repeatedly(0,"\n\n\n\n                               -----------------------------------------------------------\n",
                              "                               |   ***             ***    **************       *******   |\n",
                              "                               |    ***           ***     **************     ***         |\n");
  _Console_Write_Repeatedly(0,"                               |     ***         ***      **                ***          |\n",
                              "                               |      ***       ***     ***********       ***            |\n",
                              "                               |       ***     ***      ***********       ***            |\n");
  _Console_Write_Repeatedly(0,"                               |        ***   ***         **                ***          |\n",
                              "                               |         *** ***          ***************    ***         |\n",
                              "                               |          *****           ****************     *******   |\n");
  _Console_Write_Repeatedly(0,"                               -----------------------------------------------------------\n",0,0);
  Sleep(2000);
  _Console_Write_Repeatedly(0,"                                       Born in 2020, it has no commercial character",0,0);
  Sleep(3000);
}

void writer(void) {
  char by[20] = {84, 104, 101, 32, 119, 114, 105, 116, 101, 114,
                 32, 105, 115, 32, 66,  114, 101, 57,  55,  0};

  system("cls");

  _Cut_puts_(by, 50, 50, 0, "                                        ");
}


