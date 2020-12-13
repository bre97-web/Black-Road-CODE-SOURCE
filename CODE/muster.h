#pragma once

#include <process.h>
#include <stdio.h>
#include <windows.h>

#ifndef muster_H_INCLUDED
#define muster_H_INCLUDED

//  Console  --------------------
// Sleep(sleepTime) and puts(call)
void _Sleep_puts(int sleepTime, char call[]) {
  Sleep(sleepTime);
  puts(call);
}
// puts(call) and Sleep(sleepTime)
void Sleep_puts_(char call[], int sleepTime) {
  puts(call);
  Sleep(sleepTime);
}
// frequency : 1.puts(call) 2.puts(callAgain) 3.puts(callAgainAndAgain) ,
// Sleeeeee(sleepTime)
void _Repeatedly_puts_(int sleepTime, int frequency, char call[],char callAgain[], char callAgainAndAgain[]) {
  switch (frequency) {
    case 1:
      puts(call);
      Sleep(sleepTime);
    case 2:
      puts(callAgain);
      Sleep(sleepTime);
    case 3:
      puts(callAgainAndAgain);
      Sleep(sleepTime);
    default:
      break;
  }
}
// ASCII >> num : 48 >> 0
int _ASCII_num(int *asc) {
  if (*asc >= 48 && *asc <= 57) {
    *asc -= 48;
    return *asc;
  }
  return 0;
}
// num >> ASCII : 1 >> 49
int ASCII_num_(int *num) {
  if (*num <= 9 && *num >= 0) {
    *num += 48;
    return *num;
  }
  return 0;
}
// NO ABCs! : 50 >> 2
int _ASCII_arr(char call) {
  int asc = call;
  if (asc >= 48 && asc <= 57) {
    asc -= 48;
    return asc;
  }
  return 0;
}
// NO ABCs! : 2 >> 50
int ASCII_arr_(char call) {
  int num = call;
  if (num <= 9 && num >= 0) {
    num += 48;
    return num;
  }
  return 0;
}
// _Arr_add_arr(toCall,call,result) = "1" + "2" = "12"
int _Arr_add_arr(char toCall[], char call[], char result[]) {
  size_t callWidth = strlen(call);
  size_t toCallWidth = strlen(toCall);
  size_t temp = 0;
  for (temp = 0; temp < toCallWidth; temp++) {
    result[temp] = toCall[temp];
  }
  for (temp = 0; temp < callWidth; temp++) {
    result[toCallWidth + temp] = call[temp];
  }
  return *result;
}
// Arr_add_arr_(call,toCall,result) = "1" + "2" = "21"
int Arr_add_arr_(char call[], char toCall[], char result[]) {
  size_t callWidth = strlen(call);
  size_t toCallWidth = strlen(toCall);
  size_t temp = 0;
  for (temp = 0; temp < toCallWidth; temp++) {
    result[temp] = toCall[temp];
  }
  for (temp = 0; temp < callWidth; temp++) {
    result[toCallWidth + temp] = call[temp];
  }
  return *result;
}
void _Cut_puts_(char call[], int start, int end, int endSure, char addCall[]) {
  size_t TEMP;
  size_t callWidth = strlen(call);
  printf("%s", addCall);
  for (TEMP = 0; TEMP < callWidth; TEMP++) {
    Sleep(start);
    printf("%c", call[TEMP]);
  }
  if (endSure == 1) {
    Sleep(end);
    for (TEMP = 0; TEMP < callWidth; TEMP++) {
      call[TEMP] = ' ';
      system("cls");
      printf("%s%s", addCall, call);
      Sleep(end);
    }
  }
  Sleep(end);
}
void _Cut_puts_ASCII_(char call[], int start, int end, char addCall[]) {
  unsigned int buff;
  unsigned int TEMP = 0;
  unsigned int ntemp = 0;
  system("cls");
  printf("%s", addCall);
  for (TEMP = 0; TEMP < strlen(call); TEMP++) {
    Sleep(start);
    printf("%c", call[TEMP]);
  }
  system("cls");
  for (TEMP = 0; TEMP < strlen(call); TEMP++) {
    buff = TEMP;
    for (ntemp = 0; ntemp < strlen(call); ntemp++) {
      if (call[ntemp] > call[buff]) {  // T>T h>T a>T
        buff = ntemp;                  //	   0=1
      }
    }
    if (buff != TEMP) {
      call[buff] = ' ';
    }
    printf("%s%s", addCall, call);
    Sleep(end);
    system("cls");
  }
  Sleep(end);
}
// _For_puts_() = for(int var = startNum;var < endObjective;var += addStartNum){
// puts(call) }    ps:1.< 2.>
int _For_puts_(int startNum, int mode, int endObjective, int addStartNum,char call[]) {
  switch (mode) {
    case 1:
      goto s;
      break;
    case 2:
      goto ms;
      break;
  }
  int startVar = 0;
  int endVar = 0;

  s:
  for (startVar = startNum; startVar < (endVar = endObjective);
       startVar += addStartNum) {
    puts(call);
  }
  goto end;
ms:
  for (startVar = startNum; startVar > (endVar = endObjective);
       startVar += addStartNum) {
    puts(call);
  }
end:
  return 0;
}

//  File  --------------------
// _Create_file_(fileName,mode) = fopen_s(fileName,mode)
void _Create_file_(char fileName[], char mode[]) {
  FILE *fileAddress = NULL;
  fopen_s(&fileAddress, fileName, mode);
  fclose(fileAddress);
}
// _Create_file_puts_(filename,mode,message) = fopen_s(fileName,mode) +
// fputs(massage);
void _Create_file_puts_(char fileName[], char mode[], char message[]) {
  FILE *fileAddress = NULL;
  fopen_s(&fileAddress, fileName, mode);
  fprintf(fileAddress , "%s" , message);
  fclose(fileAddress);
}
// _Read_file_() = fopen_s("","r") + return 1/-1
int _Read_file_live_(char fileName[]) {
  FILE *fileAddress = NULL;
  fopen_s(&fileAddress, fileName, "r");
  if (fileAddress == NULL) {
    return -1;
  } else {
    fclose(fileAddress);
    return 1;
  }
}
// _logEvent_ write Local log
void _logEvent_(char log[] , unsigned int mode) {
  FILE *logWrite = NULL;
  fopen_s(&logWrite, "./log", "a+");
  
  size_t stTemp = 0 , count = 0 , logWidth = strlen(log);
  
  if (mode == 1) {
   fprintf(logWrite, "\n-----------------------------------------------\n\x20\x20");
  } else if (mode == 2) {
   fprintf(logWrite, "\n===============================================\n\x20\x20");
  }
  
  for (stTemp = 0;stTemp < logWidth;stTemp ++) {
    fprintf(logWrite, "%c" , log[stTemp]);
    count ++;
    if (count == 43) {
      fprintf(logWrite , "\n\x20\x20");
      count = 0;
    }
  }
  
  if (mode == 1) {
   fprintf(logWrite, "\n-----------------------------------------------\n");
  } else if (mode == 2) {
   fprintf(logWrite, "\n===============================================\n");
  }
  
  fclose(logWrite);
}

void _Square_puts_(int padding,int width,int height,char message) {
  char arr[2][2];
  int countOutside,countInside;
  switch(padding) {
    case 0:
      for(countOutside = 0;countOutside < height;countOutside ++) {
        for(countInside = 0;countInside < width;countInside ++) {
          if(countOutside != 0 && countOutside != (height-1)) {
            arr[countInside+1][countOutside] = ' ';
            if((countInside+1) == width || countInside == 0) {
              arr[countInside][countOutside] = message;
            }
          } else {
            arr[countInside][countOutside] = message;  
          }
        }
      }
      break;
    case 1:
      for(countOutside = 0;countOutside < height;countOutside ++) {
        for(countInside = 0;countInside < width;countInside ++) {
          arr[countInside][countOutside] = message;
        } 
      }
      break;
    default :
      break;
  }
  for(countOutside = 0;countOutside < height;countOutside ++) {
    for(countInside = 0;countInside < width;countInside ++) {
      printf("%c", arr[countInside][countOutside]);      
    }
    puts("");     
  }
}

void _Triangle_puts_(int height){
  int heightWidth = height;
  int countOutside,countInside;
  int i = 0;

  s:;  
  for(countOutside = 0;countOutside < heightWidth;countOutside ++) {
    printf("  ");
  }
  printf("+");
  for(countInside = 0;countInside < i;countInside ++) {
    printf("+");
  }
  i += 2;
  if(i != 0) {
    printf("+");
  }
  printf("\n");
  heightWidth = heightWidth - 1;
  if(heightWidth != 0) {
    goto s;
  }
  
}

void _l_Puts_(char log[] , unsigned mode) {
  size_t stTemp = 0 , count = 0 , logWidth = strlen(log);
  
  if (mode == 1) {
   printf("\n-----------------------------------------------\n\x20\x20");
  } else if (mode == 2) {
   printf("\n===============================================\n\x20\x20");
  }
  
  for (stTemp = 0;stTemp < logWidth;stTemp ++) {
    printf("%c" , log[stTemp]);
    count ++;
    if (count == 43) {
      printf("\n\x20\x20");
      count = 0;
    }
  }
  
  if (mode == 1) {
   printf("\n-----------------------------------------------\n");
  } else if (mode == 2) {
   printf("\n===============================================\n");
  }
}

#endif

/*
 *  Writer : Bre 97
 *    Writer Information:
 *      Twitter-ID:           Tisnlu
 *      Google-Mail:       BY.SGATN3@Gmail.com
 *      OUTLOOK-Mail:   BY_SGATN3@Outlook.com
 *      GitHub-Name:     Bre 97
 *    Writer Words:
 *      My Information is above this.
 *      You can give me with "Error Report",I will look Carefully.
 *      You can Upgrade the "this.h" File,but you should have told me.
 *
 *    I had been learning the C-Language short time,to hope Up Up Up to myself!
 *    I note down the "this.h",because me heeding fun.XD.
 *
 *  Use Information:
 *    _Function1_function2
 *    Function1 >> Function2
 *    Function1 First with function2
 *
 *    Function1_function2_
 *    fuction2 >> Function1
 *    function2 First with Function1
 *
 *    _Function1_function2_
 *    Function1 => function2
 *    Function1 and function2
 *
 */
