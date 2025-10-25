#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

extern int pillCount;
extern int dailyDose;

void loadPillData();
void savePillData();
void logAction(const char *action);

#endif

//   Header file for file_manager.c

// related files= main.c , logic.c, ui.c

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

extern int pillCount;    // Current #of pills remaining
extern int dailyDose;    // # of pills per dose/day

void loadPillData();// loads pill count+ daily dose from file / if missing ,corrupted file --initializes fresh data

void savePillData(); //saves current pill and daily dose to file

void logAction(const char *action); //logs user action with timestap

#endif 


