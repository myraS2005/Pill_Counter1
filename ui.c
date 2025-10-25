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

// global variable
int choice = 0;

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

void setPrescription() {
	extern int pillRemaining;
	extern int dailyDose;

	printf(COLOR_YELLOW "Enter total pills in prescription: " COLOR_RESET);
	scanf("%d", &pillRemaining);

	printf(COLOR_YELLOW "Enter daily dose: " COLOR_RESET);
	scanf("%d", &dailyDose);

	savePillData(); // saves it immediately after setup
	printf(COLOR_GREEN "\n✅ Prescription set successfully!\n" COLOR_RESET);
}

int main() {
	loadPillData();
	do {
		printWelcomeMessage();
		displayStatus();
		printDivider();

		// print the options 
		printf(COLOR_CYAN "1. Take daily dose\n" COLOR_RESET);
        	printf(COLOR_CYAN "2. Refill pills\n" COLOR_RESET);
        	printf(COLOR_CYAN "3. Check status\n" COLOR_RESET);
        	printf(COLOR_CYAN "4. Set prescription\n" COLOR_RESET);
		printf(COLOR_CYAN "5. Exit\n" COLOR_RESET);
		printDivider();

		// wait for user_input 
        	printf(COLOR_YELLOW "Enter your choice: " COLOR_RESET);
	        scanf("%d", &choice);

		// make the choices for the user to use
		switch (choice) {
			case 1: 
				extern int pillRemaining;
				extern int dailyDose;

				if (pillRemaining >= dailyDose) {
					logic_takeDose();
					printf(COLOR_GREEN "✅ Dose taken successfully!\n" COLOR_RESET);
				}
				else if (pillRemaining > 0 && pillRemaining < dailyDose) {
					printf(COLOR_RED "⚠️ Not enough pills left for a full dose! Only %d pill(s) remain.\n" COLOR_RESET, pillRemaining);
				}
				else {
					printf(COLOR_RED "❌ No pills remaining! Please refill your prescription.\n" COLOR_RESET);
				}
				break;
			case 2:
				logic_refill();
				printf(COLOR_GREEN "✨ Pills refilled successfully!\n" COLOR_RESET);
				break;
			case 3: 
				displayStatus();
				break;
			case 4:
				setPrescription();
				break;
			case 5: 
				printf(COLOR_BLUE "Exiting... Stay healthy! 🌿\n" COLOR_RESET);
				break;
			default:
				printf(COLOR_RED "❌ Invalid choice. Please try again.\n" COLOR_RESET);
		}

		// check the choice entered
		if (choice != 5) {
            	       printf("\nPress Enter to continue...");
        	       getchar(); getchar(); // Wait for user input
	        }

	} while (choice != 5); 
	return 0;
}

void showlowpillWarning(int remaining) { // print warning message for less pills. 
	if (remaining < 5) {
		printf(COLOR_RED "⚠️  Warning: Only %d pills remaining! Please refill soon.\n"COLOR_RESET, remaining);
	}
        // check the choice entered
        if (choice != 5) {
                       printf("\nPress Enter to continue...");
                       getchar(); getchar(); // Wait for user input
        }

}

void displayStatus() { // show the status of the total pills and dose.
	extern int pillRemaining;
	extern int dailyDose;
	printf(COLOR_YELLOW "Pills remaining: %d\n" COLOR_RESET, pillRemaining);
	printf(COLOR_YELLOW "Daily dose: %d\n" COLOR_RESET, dailyDose);
	if (pillRemaining < 5) { 
		showlowpillWarning(pillRemaining);
	} 
	else {
		printf(COLOR_GREEN "✅ Stock level is sufficient.\n" COLOR_RESET);
	}
}

