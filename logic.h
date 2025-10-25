#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h> 
#include <string.h>  
#include <stdio.h>

#define MAX_NAME_LEN 50      //medication name
#define MAX_MEDICATIONS 10   //if we want to track multiple medications
#define LOW_STOCK_LIMIT 5 //for warning

/**
 * @struct Pill
 * @brief Characteristics of one medication.
 */
typedef struct {
    char name[MAX_NAME_LEN];
    int total;       // How much was in one prescription
    int dose;        // Number of pills taken per dose
    int remaining;   // Current number of pills left
} Pill;

//to be used in ui.c & filemanager.c
extern Pill medications[MAX_MEDICATIONS];
extern int numPills; //however many medications we're tracking currently

//Functions
/**
 * @brief Initializes the pill data array.
 * Resets the pill count to 0 and clears old data.
 * Should be called once at startup before loading data.
 */
void logic_initialize();

/**
 * @brief Adds a new medication to be tracked.
 * Used by the UI for adding new pills or by the file_manager when loading data.
 * @param name The name of the medication.
 * @param total The total amount of pills (e.g., from a new prescription).
 * @param dose The daily dosage.
 * @param remaining The current remaining amount (used when loading from file).
 * @return true if pill was added successfully, false if array is full or data is invalid.
 */
bool logic_addPill(const char* name, int total, int dose, int remaining);

/**
 * @brief Finds a pill in the global array by its name.
 * @param name The name of the pill to find.
 * @return The index of the pill if found, otherwise -1.
 */
int logic_findPill(const char* name);

/**
 * @brief Simulates taking a dose of a specific medication.
 * Decrements the 'remaining' count by the 'dose' amount.
 * @param pillIndex The index of the pill in the g_medications array.
 * @return true if dose was taken, false if not (e.g., insufficient pills).
 */
bool logic_takeDose(int pillIndex);

/**
 * @brief Adds pills to a medication's remaining count (e.g., a refill).
 * @param pillIndex The index of the pill in the g_medications array.
 * @param amount The number of pills to add.
 * @return true if refill was successful, false if amount is invalid.
 */
bool logic_refill(int pillIndex, int amount);

/**
 * @brief Checks if a medication is low on stock.
 * @param pillIndex The index of the pill in the g_medications array.
 * @return true if remaining pills are at or below LOW_STOCK_THRESHOLD, false otherwise.
 */
bool logic_checkLowStock(int pillIndex);

#endif