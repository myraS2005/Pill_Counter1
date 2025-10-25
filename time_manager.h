#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

enum Limits {
	LIMIT_DOSAGES = 100
};

typedef struct DoseTime {
	int day;
	int month;
	int year;
	bool used;

} dose_time_t;


//extern dose_time_t allDoseTimes[LIMIT_DOSAGES];




void setMaxDosage(int dose);

bool doseTakenToday();

int newDose();


#endif 

