#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "logic.h"
#include "file_manager.h"


// define the color codes for ANSI
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_BLUE    "\033[1;34m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_MAGENTA "\033[1;35m"

// clear screen command for windows and unix 
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void clearscreen() {
	system(CLEAR);
}

void printDivider() {
	printf(COLOR_CYAN "--------------------------------------\n" COLOR_RESET);
}

void printWelcomeMessage() {
	clearscreen();
	printf(COLOR_MAGENTA "💊 ============================ 💊\n"COLOR_RESET);
        printf(COLOR_BLUE "       PILL COUNTER SYSTEM      \n"COLOR_RESET);
        printf(COLOR_MAGENTA"💊 ============================ 💊\n\n"COLOR_RESET);
}

void showMainMenu() {
	int choice;
	do {
		printWelcomeMessage();
		displayStatus();
		printDivider();

		// print the options 
		printf(COLOR_CYAN "1. Take daily dose\n" COLOR_RESET);
        	printf(COLOR_CYAN "2. Refill pills\n" COLOR_RESET);
        	printf(COLOR_CYAN "3. Check status\n" COLOR_RESET);
        	printf(COLOR_CYAN "4. Exit\n" COLOR_RESET);
		printDivider();

		// wait for user_input 
        	printf(COLOR_YELLOW "Enter your choice: " COLOR_RESET);
	        scanf("%d", &choice);

		// make the choices for the user to use
		switch (choice) {
			case 1: 
				logic_takeDose();
				printf(COLOR_GREEN "✅ Dose taken successfully!\n" COLOR_RESET);
				break;
			case 2:
				logic_refill();
				printf(COLOR_GREEN "✨ Pills refilled successfully!\n" COLOR_RESET);
				break;
			case 3: 
				displayStatus();
				break;
			case 4:
				printf(COLOR_BLUE "Exiting... Stay healthy! 🌿\n" COLOR_RESET);
				break;
			default:
				printf(COLOR_RED "❌ Invalid choice. Please try again.\n" COLOR_RESET);
		}

		// check the choice entered
		if (choice != 4) {
            	       printf("\nPress Enter to continue...");
        	       getchar(); getchar(); // Wait for user input
	        }

	} while (choice != 4);
}

void showlowpillWarning(int remaining) { // print warning message for less pills. 
	if (remaining < 5) {
		printf(COLOR_RED "⚠️  Warning: Only %d pills remaining! Please refill soon.\n"COLOR_RESET, remaining);
	}
}
 }

                // check the choice entered
                if (choice != 4) {
                       printf("\nPress Enter to continue...");
                       getchar(); getchar(); // Wait for user input
                }

        } while (choice != 4);
}
void displayStatus() { // show the status of the total pills and dose.
	extern int pillRemaining;
	extern int dailyDose;
	printf(COLOR_YELLOW pillRemaining"Pills remaining: %d\n" COLOR_RESET, currentPills);
	printf(COLOR_YELLOW "Daily dose: %d\n" COLOR_RESET, dailyDose);
	if (currentPills < 5) { 
		showlowpillWarning(currentPills);
	} 
	else {
		printf(COLOR_GREEN "✅ Stock level is sufficient.\n" COLOR_RESET);
	}
}

