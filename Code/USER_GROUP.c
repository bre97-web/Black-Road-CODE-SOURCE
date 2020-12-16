#include <direct.h>
#include <io.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#include "DECLARATION.h"

struct Contralet {
  char userAddress[32], localUserAddressFolder[32], localUserAddressData_DataFile[32],
      localuserAddressData_AchievementFile[32];
};
struct Contralet userAddress;


/*
 *  Sure local file/folder life.
 *  List:
 *    1:./userSave/
 *    2:userSave/user.txt
 *    3:userSave/userName/data
 *    4:userSave/userName/achievement
 */
void userAddrssProcess(char id[]) {
  //  link address to delete local file
  _Arr_add_arr("./userSave/",id,
               userAddress.localUserAddressFolder);
  _Arr_add_arr(userAddress.localUserAddressFolder, "/data",
               userAddress.localUserAddressData_DataFile);
  _Arr_add_arr(userAddress.localUserAddressFolder, "/achievement",
               userAddress.localuserAddressData_AchievementFile);
}
void userAddressProcessDefend(char id[]) {
  if (_access("userSave", 0)) {
    _mkdir("userSave");
  }

  _Create_file_("userSave/user.txt", "a+");

  if (id[0] != '0') {
    _mkdir(userAddress.localUserAddressFolder);
    _Create_file_(userAddress.localUserAddressData_DataFile, "a+");
    _Create_file_( userAddress.localuserAddressData_AchievementFile, "a+");

    _logEvent_(userAddress.userAddress, 2);
    _logEvent_(userAddress.localUserAddressFolder, 2);
    _logEvent_(userAddress.localUserAddressData_DataFile, 2);
    _logEvent_(userAddress.localuserAddressData_AchievementFile, 2);
  }
}

/*
 *  Function : userLogin()
 *  Effect : Use placed address of user, Find new "userAddress.userAddress" , or Delete.
 *  Update : FALSE - 12-10-2020
 */
void userLogin(void) {
  startPut:;

  userAddressProcessDefend("0");

  FILE *userAddressOpen = NULL;
  fopen_s(&userAddressOpen, "userSave/user.txt", "r");
  
  size_t userLocalSize = 0;
  char userLocal[128];
  while(!feof(userAddressOpen)){
    userLocal[userLocalSize] = (char)fgetc(userAddressOpen);
    userLocalSize ++;
  }
  fclose(userAddressOpen);
  
  userLocal[userLocalSize] = '\0'; 
  
  size_t userNameWidth = strlen(userLocal) / 8 , stTemp = 0 , numCount = 0 , numCountAdd = 0;
  char userName[1][9];  

  system("cls");
  if(userLocalSize == 1){
    _l_Puts_("User null",2);
  } else {
    _Sleep_puts(200,"User List");
    for (stTemp = 0; stTemp < userNameWidth;stTemp++) {
      for (numCount = 0;numCount < 8;numCount ++) {
  	    userName[stTemp][numCount] = userLocal[numCountAdd];
  	    numCountAdd ++;
     	}
  	  userName[stTemp][8] = '\0';
  	  _l_Puts_(userName[stTemp],1);
    }
  }  

  reProcess:;

  _l_Puts_("0:Delete  0~8:Use This user name" , 2);
  _Sleep_puts(200,"Put your user name:");
  scanf_s("%s", &userAddress.userAddress, 9);
  getchar();

  //  Judge user putting value
  if (userAddress.userAddress[0] == '0') {
    //  '0' is User Delete mode
    rePutDeleteName:;
    
    _Sleep_puts(200,"Delete your user name:");
    scanf_s("%s", &userAddress.userAddress, 9);
    getchar();

    if (userNameDefend(userAddress.userAddress) == 0) {
      goto rePutDeleteName;
    }

    userAddrssProcess(userAddress.userAddress);

    _Repeatedly_puts_(100,1,userAddress.localUserAddressFolder,userAddress.localUserAddressData_DataFile,userAddress.localuserAddressData_AchievementFile);
    //  Delete local "./userSave/userName/data" file
    remove(userAddress.localUserAddressData_DataFile);
    //  Delete local "./userSave/userName/dataPlot" file
    remove(userAddress.localuserAddressData_AchievementFile);
    //  Delete local "./userSave/userName"
    _rmdir(userAddress.localUserAddressFolder);
    //  Delete local "./userSave/userAddress.txt" , after reProcess-write this file
    remove("userSave/user.txt");

    for (stTemp = 0;stTemp < userNameWidth;stTemp ++) {
      if (strcmp(userAddress.userAddress,userName[stTemp]) != 0) {
        _Create_file_puts_("userSave/user.txt", "a+", userName[stTemp]);
      }
    }
    goto startPut;
  } else {
    if (userNameDefend(userAddress.userAddress) == 0){
      goto reProcess; 
    }
    numCount = 0;
    if (userNameWidth != 0) {
      for (stTemp = 0; stTemp < userNameWidth;stTemp++) {
        if (userNameSakeDefend(userAddress.userAddress,userName[stTemp]) == 0) {
          goto end;
        } else {
          numCount = 1;
        }
      }
    } else {
      _Create_file_puts_( "userSave/user.txt", "a+",userAddress.userAddress);  
    }
  }
  if (numCount != 0) {
    _Create_file_puts_( "userSave/user.txt", "a+",userAddress.userAddress);  
  }
  end:;
  userAddrssProcess(userAddress.userAddress);        
  userAddressProcessDefend(userAddress.userAddress);
  
  _Sleep_puts(200 , "Opened user name:");
  _l_Puts_(userAddress.userAddress , 2);
}

/*
 *  user name sake :123456789(1~9) and 8bit
 */
int userNameDefend(char id[]) {
  size_t stTemp = 0;
  if (id[7] == 0 || id[8] != 0) {
    puts("8bit number");
    return 0;
  }
  for (stTemp = 0; stTemp < 8; stTemp++) {
    if (id[stTemp] < 48 || id[stTemp] > 57) {
      puts("8bit number 0~9");
      return 0;
    }
  }
  return 1;
} 
int userNameSakeDefend(char id[] , char userId[]) {
  if (strcmp(id,userId) == 0) {
    return 0;
  }
  return 1;
}

//  Write local "data".
void sendValueToDataFile(char message[]) {
  _Create_file_puts_(userAddress.localUserAddressData_DataFile, "w+", message);
}

/*
 *  Function : getProceed()
 *  Effect : Read local "data" file.
 *  Update : TRUE
 */
void getProceed(void) {
  char userData[4];

  //  Read local "data" file
  FILE *userDataRead = NULL;
  fopen_s(&userDataRead, userAddress.localUserAddressData_DataFile, "r");
  if (userDataRead == NULL || feof(userDataRead)) {
    _Create_file_puts_(userAddress.localUserAddressData_DataFile,"w+","0011");
  }
  fgets(userData, 5, userDataRead);
  fclose(userDataRead);

  //  EP0__xxx
  if (userData[0] == '0') {
    //  EP0_0xx
    if (userData[1] == '0') {
      //  EP0_00x
      if (userData[2] == '0') {
        //  EP0_000
        if (userData[3] == '0') {
          EP0_Start000();
        
        }
      //  EP0_01x
      } else if (userData[2] == '1') {
        //  EP0_011
        if (userData[3] == '1') {
          EP0_NorthLight011();

        } 

      }
    } else if (userData[1] == '1') {
    } else if (userData[1] == '2') {
    }
  } else if (userData[0] == '1') {
  }




}



