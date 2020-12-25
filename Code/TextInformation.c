#include <windows.h>

#include "Declaration.h"

void pulseOn(void) {
  system("color f0");
  system("mode con cols=120 lines=30");

  _Console_Write_Repeatedly(0,"\n\n\n\n                               ------------------------------------------------------------\n",
                              "                               |     **           **      ************       *******     |\n",
                              "                               |    ***           ***     **               **       *    |\n");
  _Console_Write_Repeatedly(0,"                               |     ***         ***      **              **             |\n",
                              "                               |      ***       ***     *********        **              |\n",
                              "                               |       ***     ***        **             **              |\n");
  _Console_Write_Repeatedly(0,"                               |        ***   ***         **              **             |\n",
                              "                               |         *** ***          **               **       *    |\n",
                              "                               |           ***            *************      *******     |\n");
  _Console_Write_Repeatedly(0,"                               ------------------------------------------------------------\n",0,0);
  Sleep(2000);
  _Console_Write_Repeatedly(0,"                                    Born in 2020, it has no commercial character\n\n",0,0);
  Sleep(3000);
}


