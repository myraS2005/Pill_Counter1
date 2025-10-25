// has all the entry points and counting logic and header for logic functions
#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include "file_manager.h"
#include "ui.h"
#include "time_manager.h"

int main() {
    // Initialize data and load saved pill info
    loadPillData();  
    printWelcomeMessage();  

    // Optional: Log session start time
    logSessionStart();  

    // Main menu loop (handles user interaction)
    showMainMenu();  

    // Save pill data before exiting
    savePillData();  

    printf("💾 Data saved successfully. Goodbye!\n");

    return 0;
}
