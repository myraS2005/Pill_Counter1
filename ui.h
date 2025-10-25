#ifndef UI_H
#define UI_H

// function list
void clearScreen();              // Clears terminal screen
void printDivider();             // Prints divider for layout
void printWelcomeMessage();      // Prints program header
void showLowPillWarning(int remaining); // Shows low-pill alert
void displayStatus();            // Displays current pill status
void setPrescription();          // saves the original prescription from the user. 
void showMainMenu();             // Main menu and user interaction

#endif
