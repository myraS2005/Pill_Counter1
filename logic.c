#include "logic.h"

//from header file
Pill medications[MAX_MEDICATIONS];
int numPills = 0;

//Functions
void logic_initialize() {
    numPills = 0;
    //set everything at 0 to start
    for (int i = 0; i < MAX_MEDICATIONS; i++) {
        memset(g_medications[i].name, 0, MAX_NAME_LEN);
        g_medications[i].total = 0;
        g_medications[i].dose = 0;
        g_medications[i].remaining = 0;
    }
}

bool logic_addPill(const char* name, int total, int dose, int remaining) {
    
    //make sure everything is in valid ranges
    if (numPills >= MAX_MEDICATIONS) {
        printf("Error: Cannot add more medications. Array is full.\n");
        return false; 
    }
    if (name == NULL || name[0] == '\0') {
        printf("Error: Pill name cannot be empty.\n");
        return false; //invalid name
    }
    if (dose <= 0) {
        printf("Error: Dose must be greater than 0.\n");
        return false;
    }
     if (remaining < 0) {
        printf("Error: Remaining pills cannot be negative.\n");
        return false;
    }
    //if from a file, 'total' might be 0, but for a new pill, it shouldn't be
    if (total > 0 && remaining > total) {
        printf("Warning: Remaining pills (%d) greater than total (%d). Setting remaining to total.\n", remaining, total);
        remaining = total;
    }

    //copy data into the next available slot
    int index = numPills;

    strncpy(medications[index].name, name, MAX_NAME_LEN - 1);
    medications[index].name[MAX_NAME_LEN - 1] = '\0'; 
    
    medications[index].total = total;
    medications[index].dose = dose;
    medications[index].remaining = remaining;

    numPills++; // Increment the count of tracked pills
    return true;
}

/**
 * @brief Finds a pill in the array by its name.
 */
int logic_findPill(const char* name) {
    if (name == NULL) { //invalid name
        return -1;
    }
    for (int i = 0; i < g_numPills; i++) {
        if (strncmp(medications[i].name, name, MAX_NAME_LEN) == 0) {
            return i;
        }
    }
    return -1; //not found
}