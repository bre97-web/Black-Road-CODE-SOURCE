#include <direct.h>
#include <io.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "statement.h"

//  Use UTF-8 coding.
//  Judge-pan'duan , result-jie'guo , change-geng'gai , range-fan'wei

struct Contralet {
  int life, operation, activity;
  char userName1[32];
  char userAddress[32], userAddressPlot[32], userAddressData[32];
};
struct Contralet plot, addUser;

/*
  *  Function : addUserData()
  *  Effect : Use placing address of user, Founding new "addUser.userAddress" , or Delete Struct "addUser.userAddress" value
  *  Update : FALSE
 */
void addUserData(void) {
  system("cls");

  // User Delete mode
  delete:;

  char user_0[32] = "";
  char user_8[32] = "";
  char user_16[32] = "";
  char user_24[32] = "";
  char user_32[32] = "";
  char userLocal[32] = "";
  char strValue[32];
  size_t stTemp = 0;

  if (_access("userSave", 0)) {
    _mkdir("userSave");
  }

  FILE *userCreatePlot = NULL;
  fopen_s(&userCreatePlot, "userSave/user.txt", "r+");
  if (userCreatePlot == NULL) {
    fopen_s(&userCreatePlot, "userSave/user.txt", "w+");
  }
  //  Read local "user.txt" file with value to Var "userLocal"
  fgets(userLocal, 33, userCreatePlot);

  fclose(userCreatePlot);

  //  Cut local 32quantity "user.txt" for Var 8quantity "user_"
  for (stTemp = 0; stTemp < 8; stTemp++) {
    user_8[stTemp] = userLocal[stTemp];
    user_16[stTemp] = userLocal[stTemp + 8];
    user_24[stTemp] = userLocal[stTemp + 16];
    user_32[stTemp] = userLocal[stTemp + 24];
  }

  _Repeatedly_puts_(1000, 3, "", "", "Choose user:");
  printf("\nuser1:%s\nuser2:%s\nuser3:%s\nuser4:%s\n", user_8, user_16, user_24,
         user_32);

//  Re process
re:;

  //  User put one-name to Var "user_0"
  scanf_s("%s", &user_0, 32);
  gets_s(strValue, 32);

  //  Judge user putting value
  switch (*user_0) {
    //  '0' is User Delete mode
    case '0':;

      char userAddress[32];
      char userSaveAddress[] = "./userSave/";
      char userSaveDataAddress[] = "/data";
      char userSaveDataPlotAddress[] = "/dataPlot";
      char localUserSave[20];
      char localUserSaveData[26];
      char localUserSaveDataPlot[30];

      printf("Delete user:");

      scanf_s("%s", &userAddress, 32);
      gets_s(strValue, 32);

      //  link address to delete local file
      _Arr_add_arr(userSaveAddress, userAddress, localUserSave);
      _Arr_add_arr(localUserSave, userSaveDataAddress, localUserSaveData);
      _Arr_add_arr(localUserSave, userSaveDataPlotAddress,
                   localUserSaveDataPlot);

      //  put result
      puts(localUserSave);
      puts(localUserSaveData);
      puts(localUserSaveDataPlot);

      //  Delete local "./userSave/userName/data" file
      remove(localUserSaveData);
      //  Delete local "./userSave/userName/dataPlot" file
      remove(localUserSaveDataPlot);
      //  Delete local "./userSave/userName"
      _rmdir(localUserSave);

      //  Delete local "./userSave/userAddress.txt" , after re-write this file
      remove("userSave/user.txt");

      //  Founding local "./userSave/user.txt" file
      FILE *newUserCreatePlot = NULL;
      fopen_s(&newUserCreatePlot, "userSave/user.txt", "a+");

      //  Judge user putting value , re-write this file for value
      if (strcmp(userAddress, user_8) == 0) {
        fputs(user_16, newUserCreatePlot);
        fputs(user_24, newUserCreatePlot);
        fputs(user_32, newUserCreatePlot);
      } else if (strcmp(userAddress, user_16) == 0) {
        fputs(user_8, newUserCreatePlot);
        fputs(user_24, newUserCreatePlot);
        fputs(user_32, newUserCreatePlot);
      } else if (strcmp(userAddress, user_24) == 0) {
        fputs(user_8, newUserCreatePlot);
        fputs(user_16, newUserCreatePlot);
        fputs(user_32, newUserCreatePlot);
      } else if (strcmp(userAddress, user_32) == 0) {
        fputs(user_8, newUserCreatePlot);
        fputs(user_16, newUserCreatePlot);
        fputs(user_24, newUserCreatePlot);
      }

      fclose(newUserCreatePlot);

      goto delete;
      break;
    default:
      break;
  }

  //  User put one-name , Judge this Var
  if (user_0[7] < 48 || user_0[7] > 57) {
    puts("8bit number 0~9");
    goto re;
  }

  // Judge user putting value , change Struct "addUser.userName1" value , and
  // addUserCreateFile()
  if (strcmp(user_0, user_8) == 0) {
    _Arr_add_arr(user_8, addUser.userName1, addUser.userName1);
    addUserCreateFile(user_8);
  } else if (strcmp(user_0, user_16) == 0) {
    _Arr_add_arr(user_16, addUser.userName1, addUser.userName1);
    addUserCreateFile(user_16);
  } else if (strcmp(user_0, user_24) == 0) {
    _Arr_add_arr(user_24, addUser.userName1, addUser.userName1);
    addUserCreateFile(user_24);
  } else if (strcmp(user_0, user_32) == 0) {
    _Arr_add_arr(user_32, addUser.userName1, addUser.userName1);
    addUserCreateFile(user_32);
  } else {
    FILE *userCreatePlotNew = NULL;
    fopen_s(&userCreatePlotNew, "userSave/user.txt", "a+");

    fputs(user_0, userCreatePlotNew);

    fclose(userCreatePlotNew);

    addUserCreateFile(user_0);
  }
}

/*
 *  Function : addUserCreateFile()
 *  Effect : Created Struct "addUser.userAddressPlot" and "addUser.userAddressData" value
 *  Update : FALSE
 */
void addUserCreateFile(char *userName) {
  char address[32] = "./userSave/";
  char dataPlot[32] = "/dataPlot";
  char data[32] = "/data";

  //  Found address : ./userSave
  _mkdir(address);

  //  address Link userName
  _Arr_add_arr(address, userName, address);
  //  Found address: ./userSave/userName
  _mkdir(address);

  //  Link between to "addUser.userAddressPlot" and "User.userAddressData"
  _Arr_add_arr(address, dataPlot, addUser.userAddressPlot);
  _Arr_add_arr(address, data, addUser.userAddressData);
}

/*
 *  Function : getProceed()
 *  Effect : Read local "data" file , Judge value
 *  Update : TRUE
 */
void getProceed(void) {
  //  Get value
  char userData[4];

  //  Read local "data" file
  FILE *userDataRead = NULL;
  fopen_s(&userDataRead, addUser.userAddressData, "r");
  if (userDataRead == NULL) {
    dataFile("0011");

    _logEvent_("function.getProceed() : FILE * = NULL , function.dataFile()");
  }

  //  Get local file value to Var "userData"
  fgets(userData, 5, userDataRead);

  fclose(userDataRead);

  // Get Var "userData[0]"
  if (userData[0] == '0') {
    goto ep;
  } else {
    //  function end
    goto end;
  }

ep:;

  //  EP0__0xx
  switch (userData[1]) {
    case '0':

      switch (userData[2]) {
        case '1':

          //  EP0__01x
          switch (userData[3]) {
            case '1':
              EP0_friend011();
              break;
            case '2':
              EP0_friend012();
              break;
          }
          break;

        case '2':

          //  EP0__02x
          switch (userData[3]) {
            case '1':
              break;
          }
          break;
      }
      break;

    //  EP1__1xx
    case '1':
      break;
    default:
      break;
  }

end:;
}

/*
 *  Function : dataFile
 *  Effect : Var "data" towards local "data" file with write
 *  Update : FALSE
 */
void dataFile(char data[]) {
  //  Write local "data" file
  FILE *userDataWrite = NULL;
  fopen_s(&userDataWrite, addUser.userAddressData, "w");

  //  Var "data" value in local "data" file
  fprintf(userDataWrite, "%s", data);

  fclose(userDataWrite);

  _logEvent_("function.dataFile() : write file");
}

/*
 *  Function : plotInitial()
 *  Effect : Control center , control Struct "plot." -= and entering function
 *  Update : FALSE
 */
void plotInitial(int sure, int addNumOne, int addNumTwo, int addNumThree) {
  //  Read local "dataPlot" file
  plotFileAnalysis();

  plot.life -= addNumOne;
  plot.operation -= addNumTwo;
  plot.activity -= addNumThree;

  //  Write local "dataPlot" file
  plotFile();

  if (sure == 1) {
    //  puts("=");
    report();
  }
}

/*
 *  Function : plotValueAnalysis()
 *  Effect : Judge Struct "plot.life" value , and return result
 *  Update : FALSE
 */
int plotValueAnalysis(int *put) {
  //  Judge Struct "plot.life" , value range is 0~9 , return range is 1~3
  if (plot.life != 0) {
    if (plot.life > 7) {
      *put = 1;
      return *put;
    } else if (plot.life < 7 && plot.life > 4) {
      *put = 2;
      return *put;
    } else if (plot.life < 4) {
      *put = 3;
      return *put;
    }

  } else if (plot.life == 0) {
    getOver();
  }

  return 0;
}

/*
 *  Function : plotFileAnalysis()
 *  Effect : Read local "dataPlot" file , change Struct "plot." value
 *  Update : FALSE
 */
void plotFileAnalysis(void) {
  //  Get value
  char dataPlot[5];

  //  Read local "dataPlot" file
  FILE *userAnalysisIf = NULL;
  fopen_s(&userAnalysisIf, addUser.userAddressPlot, "r");
  if (userAnalysisIf != NULL) {
    fscanf_s(userAnalysisIf, "%s", dataPlot, 6);

    //  Judge Var "dataPlot" is false or true
    if (_ASCII_arr(dataPlot[1]) != 0 && _ASCII_arr(dataPlot[3]) != 0) {
      Sleep_puts_("local file dataPlot.txt error", 1000);

      _logEvent_(dataPlot);

      //  This time , local "dataPlot" file is ERROR , so Struct "plot." is
      //  Default value
      plot.life = 9;
      plot.operation = 9;
      plot.activity = 1;
    } else {
      _logEvent_(dataPlot);

      // Var char * to int , _ASCII_arr() function is char *[] to int , '9' to 9
      plot.life = _ASCII_arr(dataPlot[0]);
      plot.operation = _ASCII_arr(dataPlot[2]);
      plot.activity = _ASCII_arr(dataPlot[4]);
    }

    fclose(userAnalysisIf);
  }
  if (userAnalysisIf == NULL) {
    Sleep_puts_("local file dataPlot.txt NULL", 1000);

    //  This time , local "dataPlot" file is NULL , so Struct "plot." is Default
    //  value
    plot.life = 9;
    plot.operation = 9;
    plot.activity = 1;
  }
}

/*
 *  Function : plotFile()
 *  Effect : Because plotFileAnalysis() function Read local file value , this
 * function Write Struct "plot." value Update : FALSE
 */
void plotFile(void) {
  //  Write local "dataPlot" file
  FILE *userAnalysis = NULL;
  fopen_s(&userAnalysis, addUser.userAddressPlot, "w+");

  //  of Struct "plot." value
  fprintf(userAnalysis, "%d0", plot.life);
  fprintf(userAnalysis, "%d0", plot.operation);
  fprintf(userAnalysis, "%d", plot.activity);

  fclose(userAnalysis);
}

/*
 *  Function : report()
 *  Effect : Out Struct "plot." value , it is used number quantity
 *  Update : FALSE
 */
void report(void) {}

/*
 *  Function : gameProceedIf()
 *  Effect : Judge local "data" file , if TRUE , return of function
 * gameCenterGra() Update : FALSE
 */
int gameProceedIf(void) {
  if (_Read_file_(addUser.userAddressData) == 1) {
    return 1;
  } else {
    return -1;
  }
}