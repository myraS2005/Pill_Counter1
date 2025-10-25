#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

extern int pillCount;
extern int dailyDose;

void loadPillData();
void savePillData();
void logAction(const char *action);

#endif

