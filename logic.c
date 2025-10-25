#include "logic.h"
#include <stdio.h>

//from header file
int pillRemaining = 0;
int dailyDose = 0;

//Functions
void logic_initialize() { //initial values
    int pillRemaining = 0;
    int dailyDose = 0;
    int precription = 0;
}

/**
 * @brief Sets the values.
 */
void logic_setValues(int remaining, int dose, int prescr) {
    if (remaining < 0) {
        pillRemaining = 0;
    } else {
        pillRemaining = remaining;
    }

    if (dose <= 0) {
        dailyDose = 1; // Default to 1 if dose is invalid
    } else {
        dailyDose = dose;
    }

    if (prescr < 0) {
        prescription = 0;
    } else {
        prescr = prescription;
    }
}

/**
 * @brief Taking 1 dose of a medication
 */
bool logic_takeDose() {
    if (pillRemaining >= dailyDose) {
        pillRemaining -= dailyDose;
        return true; //take dose
    } else {
        return false; //not enough pills
    }
}

/**
 * @brief Adds pills to a medication's remaining count.
 */
bool logic_refill() {
    //must be a posiitve amount
    pillRemaining = precription;
}

/**
 * @brief Checks if a medication is low on stock.
 */
bool logic_checkLowStock(int pillIndex) {
    return pillRemaining <= LOW_STOCK_THRESHOLD;
}