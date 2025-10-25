#include "time_manager.h"
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int MAX_DOSAGES = 0;
int DOSES_COMPLETE = 0;

dose_time_t allDoseTimes[LIMIT_DOSAGES] = {0};

void setMaxDosage(int dose) {
	//if(dose < 0 || dose > LIMIT_DOSAGES){
	//	printf("%s\n", "The dose you have entered is not valid or exceeds the max of 100");
	//	return;
	//}
	//MAX_DOSAGES = dose;
	//allDoseTimes = malloc(sizeof(dose_time_t) * MAX_DOSAGES);
	//if(!allDoseTimes) {
	//	exit(1);
	//}
}

bool doseTakenToday() {
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	dose_time_t last_dose = allDoseTimes[MAX_DOSAGES];
	if(last_dose.day == t->tm_mday && last_dose.month == (t->tm_mon + 1) && last_dose.year == (t->tm_year + 1900)) {
		return true; 
	}
	return false;
}

int newDose() {
	if(DOSES_COMPLETE == MAX_DOSAGES) return -1; //if all doses are finished then -1 returned, cannot take new dose
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	allDoseTimes[DOSES_COMPLETE].day = t->tm_mday;
	allDoseTimes[DOSES_COMPLETE].month = (t->tm_mon) + 1;
	allDoseTimes[DOSES_COMPLETE].year = (t->tm_year) + 1900;
	allDoseTimes[DOSES_COMPLETE].used = true;
	DOSES_COMPLETE++;
	return 0;
}




