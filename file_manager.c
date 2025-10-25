 # Handles loading/saving data


 #include <stdio.h>
#include <time.h>
#include "file_manager.h"

int pillCount = 0;
int dailyDose = 0;

// Load existing data or start new
void loadPillData() {
    FILE *file = fopen("pill_data.txt", "r");
    if (file == NULL) {
        pillCount = 0;
        dailyDose = 0;
        printf("No existing data. Starting fresh!\n");
        return;
    }
    fscanf(file, "%d %d", &pillCount, &dailyDose);
    fclose(file);
}

// Save updated data
void savePillData() {
    FILE *file = fopen("pill_data.txt", "w");
    if (file == NULL) {
        printf("Error saving file.\n");
        return;
    }
    fprintf(file, "%d %d", pillCount, dailyDose);
    fclose(file);
}

// Optional logging feature
void logAction(const char *action) {
    FILE *logFile = fopen("pill_log.txt", "a");
    if (logFile == NULL) return;

    time_t t;
    time(&t);
    fprintf(logFile, "%s - %s", action, ctime(&t));
    fclose(logFile);
}
