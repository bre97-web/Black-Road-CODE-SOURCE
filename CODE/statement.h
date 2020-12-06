#pragma once

#ifndef statement_H_INCLUDED
#define statement_H_INCLUDED

// muster.h
void _Sleep_puts(int sleepTime, char call[]);
void Sleep_puts_(char call[], int sleepTime);
void _Repeatedly_puts_(int sleepTime, int frequency, char call[],char callAgain[], char callAgainAndAgain[]);
int _ASCII_num(int *asc);
int ASCII_num_(int *num);
int _ASCII_arr(char call);
int ASCII_arr_(char call);
int _Arr_add_arr(char toCall[], char call[], char result[]);
int Arr_add_arr_(char toCall[], char call[], char result[]);
void _Create_file_(char fileName[], char mode[]);
void _Create_file_puts_(char fileName[], char mode[], char message[]);
int _Read_file_(char fileName[]);
void _Cut_puts_(char call[], int start, int end, int endSure, char addCall[]);
void _Cut_puts_ASCII_(char call[], int start, int end, char addCall[]);
int _For_puts_(int startNum, int mode, int endObjective, int addStartNum,char call[]);
void _logEvent_(char log[]);
void _Square_puts_(int padding,int width,int height,char message);
//int _Function_exponent_(double a, int n, double *result);

// gameCore.c
void EP0_friend011(void);
void EP0_friend012(void);

// conGrapgics.c
void pulseOn(void);
void getCharacter(void);
void roleInf(void);
void worldTimeList(void);
void worldInf(void);
void worldWar(void);
void roleInfBattle(void); 
void getOver(void);
void writer(void);

// main.c
void getMenu(void);
void getPassageMenu(void);
void getHelp(void);
void getWriter(void);

// report.c
void addUserData(void);
void userAddressCreate(char *userName);
void getProceed(void);
void dataFile(char data[]);
void plotInitial(int sure, int addNumOne, int addNumTwo, int addNumThree);
int plotValueAnalysis(int *put);
void plotFileAnalysis(void);
void plotFile(void);
void report(void);
int gameProceedIf(void);

#endif
