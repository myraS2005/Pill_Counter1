#include <stdio.h>
#include <stdlib.h>
#include "ui.h"
#include "logic.h"
#include "file_manager.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

void clearscreen() {
	system(CLEAR);
}

void printDivider() {
	printf("--------------------------------------\n");
}

void printWelcomeMessage() {
	clearscreen();
	printf("💊 ============================ 💊\n");
        printf("       PILL COUNTER SYSTEM      \n");
        printf("💊 ============================ 💊\n\n");
}

void showMainMenu() {
	int choice;
	do {
		printWelcomeMessage();
		displayStatus();
		printDivider();
		printf("1. Take daily Dosage\n");
		printf("2. Refill pills\n");
        	printf("3. Check status\n");
	        printf("4. Exit\n");

		printDivider();
        	printf("Enter your choice: ");
	        scanf("%d", &choice);

		// make the choices for the user to use
		switch (choice) {
			case 1: 
				takeDose();
				break;
			case 2:
				refill();
				break;
			case 3: 
				displayStatus();
				break;
			case 4:
				printf("Exiting... Stay healthy!🌿\n");
				break;
			default:
				printf("❌ Invalid choice. Try again.\n");
		}

		// check the choice entered
		if (choice != 4) {
            	       printf("\nPress Enter to continue...");
        	       getchar(); getchar(); // Wait for user input
	        }

	} while (choice != 4);
}

void showlowpillWarning( int remaining) { // print warning message for less pills. 
	if (remaining < 5) {
		printf("⚠️  Warning: Only %d pills remaining! Please refill soon.\n", remaining);
	}
}
void displayStatus() {
	extern int currentPills;
	extern int dailyDosage;
	printf("Pills remaining: %d\n", currentPills);
	printf("Daily dose: %d\n", dailyDosage);
	if (currentPills < 5) {
		showlowpillWarning(currentPills);
	}
}

