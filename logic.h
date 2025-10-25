#ifndef LOGIC_H
#define LOGIC_H

#include <stdbool.h> 

#define LOW_STOCK_LIMIT 5 //for warning

//to be used in ui.c & filemanager.c
extern int pillRemaining; //current number of pills
extern int dailyDose; //however many medications we're tracking currently
extern int prescription; //amount of pills in one prescription

//Functions
/**
 * @brief Initializes the pill data array.
 * Resets the pill count to 0 and clears old data.
 * Should be called once at startup before loading data.
 */
void logic_initialize();

/**
 * @brief Sets the values from file.
 * @param remaining The current remaining pill count.
 * @param dose The daily dosage.
 */
void logic_setValues(int remaining, int dose, int prescr);

/**
 * @brief Simulates taking a dose of a specific medication.
 * Decrements the 'remaining' count by the 'dose' amount.
 * @return true if dose was taken, false if not (e.g., insufficient pills).
 */
bool logic_takeDose();

/**
 * @brief Adds pills to a medication's remaining count (e.g., a refill).
 * @param amount The number of pills to add.
 * @return true if refill was successful, false if amount is invalid.
 */
bool logic_refill();

/**
 * @brief Checks if a medication is low on stock.
 * @return true if remaining pills are at or below LOW_STOCK_THRESHOLD, false otherwise.
 */
bool logic_checkLowStock();

#endif
