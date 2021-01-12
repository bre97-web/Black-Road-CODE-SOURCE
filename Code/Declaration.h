#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

// Ep0.c
void directionInitialization(unsigned int x, unsigned int y);
void directionUpdate(void);
void diectionPrintf(void);
int directionActiveSec(void);
int directionActive(int a, int b);
int attack();
int attackSec();
void operatingCenter(void);
int Ep0(void);

// Main.c
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
