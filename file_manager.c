<<<<<<< HEAD
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
=======
//   Handles saving and loading of pill data to/from files.
//   Also provides a simple log feature to track user actions
//   (e.g., refilling pills or taking doses).
// related files:  file_manager.h  , logic.c, ui.c , main.c

#include <stdio.h>
#include <time.h>
#include "file_manager.h"

// Global Variables
// Shared by other modules (declared in headers)

int pillCount = 0;    // Current # of pills remaining
int dailyDose = 0;    // Pills taken per dose/day

//Loads pill count & daily dose values from file.
//           If file doesn't exist --> it initializes new data.
void loadPillData() {
    FILE *file = fopen("pill_data.txt", "r");

    if (file == NULL) {    // No data file found (first run or missing file)
        pillCount = 0;
        dailyDose = 0;
        printf("📂 No existing data found. Starting fresh!\n");
        return;
    }

    // Try reading stored values
    if (fscanf(file, "%d %d", &pillCount, &dailyDose) != 2) {
        // File  corrupted —> reset data
        printf("⚠️ Error reading data file. Resetting values.\n");
        pillCount = 0;
        dailyDose = 0;
    }

    fclose(file);
}

//  Writes updated pill data back to file.
void savePillData() {
    FILE *file = fopen("pill_data.txt", "w");

    if (file == NULL) {
        printf("❌ Error: Could not save pill data.\n");
        return;
    }

>>>>>>> main
    fprintf(file, "%d %d", pillCount, dailyDose);
    fclose(file);
}

<<<<<<< HEAD
// Optional logging feature
void logAction(const char *action) {
    FILE *logFile = fopen("pill_log.txt", "a");
    if (logFile == NULL) return;

    time_t t;
    time(&t);
    fprintf(logFile, "%s - %s", action, ctime(&t));
    fclose(logFile);
}
=======
//appends an action (like "Took dose" or "Refilled")to a log file with a timestamp.
// eg."Refilled pills - Sat Oct 26 10:15:32 2025"

void logAction(const char *action) {
    FILE *logFile = fopen("pill_log.txt", "a");

    if (logFile == NULL) {
        printf("⚠️ Could not open log file for writing.\n");
        return;
    }

    time_t currentTime;
    time(&currentTime);

    // Write log entry: action + timestamp
    fprintf(logFile, "%s - %s", action, ctime(&currentTime));
    fclose(logFile);
}

>>>>>>> main
