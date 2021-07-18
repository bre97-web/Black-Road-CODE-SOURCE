#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

#include <stdbool.h>

// Ep0.c
int ptr(char fileNameAddress[]);
void directionValueInitialization(unsigned int x, unsigned int y);
void directionValueUpdate(void);
void diectionPrintf(void);
int directionControlCenter(int a, int b);
void fun();
int manualAttack();
int manualAttackSec();
int operatingCenter(void);
int game(char numID[2]);

// Main.c
int Menu(int Position, char MenuList[][16], bool Reset);
inline int __MenuOperate(int mode, int num, int Min, int Max);
inline int __MenuList(int mode, int num);

inline void SetMenuListMax(int Number);
inline int GetMenuListMax();


int list(int num, int mode);
int getMenu(int num);
int getGamePassage(int num);
void getHelp(void);
void pulseOn(void);

// UserGroup.c
void userAddrssProcess(char id[]);
int systemAddressProceed(char id[]);
int userLogin(void);
int userNameDefend(char id[]);
int userNameSakeDefend(char id[], char userId[]);
void sendValueToDataFile(char message[]);
int getProceed(void);

//int eggControlCenter();
//int newYear();

#endif
