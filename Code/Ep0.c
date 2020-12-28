#include "Declaration.h"

void EP0_Start000(void) {
  _IO_File_Log("function.EP0_Start000() : start", 1);
  _IO_File_Log("function.EP0_Start000() : end", 1);
  _Console_Write_WriteSleep(1000,"This mode haven't done");
}

void EP0_NorthLight011(void) {
  _IO_File_Log("function.EP0_NorthLight000() : start", 1);
  _IO_File_Log("function.EP0_NorthLight000() : end", 1);
  _Console_Write_WriteSleep(1000, "This mode haven't done");
}