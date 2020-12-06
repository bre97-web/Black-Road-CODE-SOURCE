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
  char userAddress[32], localUserAddress[32], localUserAddressFolderData[32],
      localuserAddressFolderDataAchievement[32];
};
struct Contralet userAddress;

void userAddrssProcess(char id[]) {
  //  link address to delete local file
  _Arr_add_arr("./userSave/",id,
               userAddress.localUserAddress);
  _Arr_add_arr(userAddress.localUserAddress, "/data",
               userAddress.localUserAddressFolderData);
  _Arr_add_arr(userAddress.localUserAddress, "/achievement",
               userAddress.localuserAddressFolderDataAchievement);
}
void userAddressProcessCreate() {
  _mkdir("./userSave/");
  _mkdir(userAddress.localUserAddress);

  FILE *userCreate = NULL;
  fopen_s(&userCreate, userAddress.localUserAddressFolderData, "a+");
  fclose(userCreate);
  userCreate = NULL;
  fopen_s(&userCreate, userAddress.localuserAddressFolderDataAchievement, "a+");
  fclose(userCreate);
}

/*
 *  Function : addUserData()
 *  Effect : Use placing address of user, Founding new "addUser.userAddress" ,
 * or Delete Struct "addUser.userAddress" value Update : FALSE
 */
void addUserData(void) {
  // User Delete mode
  delete:;

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

  puts("Choose user:");
  printf("\nuser1:%s\nuser2:%s\nuser3:%s\nuser4:%s\n", user_8, user_16, user_24,
         user_32);

  //  Re process
  re:;

  //  User put one-name to Var "user_0"
  scanf_s("%s", &userAddress.userAddress, 32);
  gets_s(strValue, 32);

  //  Judge user putting value
  if (userAddress.userAddress[0] == '0') {
    //  '0' is User Delete mode
    char userPutAddress[32];

    printf("Delete user:");

    rePutUserPutAddress:;
    scanf_s("%s", &userPutAddress, 32);
    gets_s(strValue, 32);

    //  User put one-name , Judge this Var
    if (userPutAddress[7] == 0 || userPutAddress[8] != 0) {
      puts("8bit number");
      goto rePutUserPutAddress;
    }
    int temp;
    for (temp = 0; temp < 8; temp++) {
      if (userPutAddress[temp] < 48 || userPutAddress[temp] > 57) {
        puts("8bit number 0~9");
        goto rePutUserPutAddress;
      }
    }

    userAddrssProcess(userPutAddress);

    //  put result
    puts(userAddress.localUserAddress);
    puts(userAddress.localUserAddressFolderData);
    puts(userAddress.localuserAddressFolderDataAchievement);

    //  Delete local "./userSave/userName/data" file
    remove(userAddress.localUserAddressFolderData);
    //  Delete local "./userSave/userName/dataPlot" file
    remove(userAddress.localuserAddressFolderDataAchievement);
    //  Delete local "./userSave/userName"
    _rmdir(userAddress.localUserAddress);

    //  Delete local "./userSave/userAddress.txt" , after re-write this file
    remove("userSave/user.txt");

    //  Founding local "./userSave/user.txt" file
    FILE *newUserCreatePlot = NULL;
    fopen_s(&newUserCreatePlot, "userSave/user.txt", "a+");

    //  Judge user putting value , re-write this file for value
    if (strcmp(userPutAddress, user_8) == 0) {
      fputs(user_16, newUserCreatePlot);
      fputs(user_24, newUserCreatePlot);
      fputs(user_32, newUserCreatePlot);
    } else if (strcmp(userPutAddress, user_16) == 0) {
      fputs(user_8, newUserCreatePlot);
      fputs(user_24, newUserCreatePlot);
      fputs(user_32, newUserCreatePlot);
    } else if (strcmp(userPutAddress, user_24) == 0) {
      fputs(user_8, newUserCreatePlot);
      fputs(user_16, newUserCreatePlot);
      fputs(user_32, newUserCreatePlot);
    } else if (strcmp(userPutAddress, user_32) == 0) {
      fputs(user_8, newUserCreatePlot);
      fputs(user_16, newUserCreatePlot);
      fputs(user_24, newUserCreatePlot);
    }
    fclose(newUserCreatePlot);
    goto delete;
  } else {
    //  User put one-name , Judge this Var
    if (userAddress.userAddress[7] == 0 || userAddress.userAddress[8] != 0) {
      puts("8bit number");
      goto re;
    }
    int temp;
    for (temp = 0; temp < 8; temp++) {
      if (userAddress.userAddress[temp] < 48 ||
          userAddress.userAddress[temp] > 57) {
        puts("8bit number 0~9");
        goto re;
      }
    }
    userAddrssProcess(userAddress.userAddress);
  }

  if (strcmp(userAddress.userAddress, user_8) == 0) {
  } else if (strcmp(userAddress.userAddress, user_16) == 0) {
  } else if (strcmp(userAddress.userAddress, user_24) == 0) {
  } else if (strcmp(userAddress.userAddress, user_32) == 0) {
  } else {
    FILE *userCreatePlotNew = NULL;
    fopen_s(&userCreatePlotNew, "userSave/user.txt", "a+");
    fputs(userAddress.userAddress, userCreatePlotNew);
    fclose(userCreatePlotNew);

    userAddressProcessCreate();
  }
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
  fopen_s(&userDataRead,userAddress.localUserAddress, "r");
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
  fopen_s(&userDataWrite,userAddress.localUserAddressFolderData, "w");

  //  Var "data" value in local "data" file
  fprintf(userDataWrite, "%s", data);

  fclose(userDataWrite);

  _logEvent_("function.dataFile() : write file");
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
  if (_Read_file_(userAddress.localUserAddress) == 1) {
    return 1;
  } else {
    return 0;
  }
}