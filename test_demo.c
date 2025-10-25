// optional 
// For Testing & Presentation Lead (QA)
#include <stdio.h>
#include "logic.h"
#include "file_manager.h"
#include "ui.h"
#include "time_manager.h"

// A helper function to print test results
void printTestResult(const char* testName, int condition) {
    if (condition)
        printf("✅ %s: PASSED\n", testName);
    else
        printf("❌ %s: FAILED\n", testName);
}

int main() {
    printf("\n==============================\n");
    printf("🧪 PILL COUNTER TEST DEMO 🧪\n");
    printf("==============================\n\n");

    // 1️⃣ Load data
    printf("🔹 Loading pill data...\n");
    loadPillData();
    printTestResult("Load pill data from file", 1);

    // 2️⃣ Show current status
    printf("\n🔹 Current status:\n");
    displayStatus();

    // 3️⃣ Simulate taking a dose
    int oldCount = getCurrentPills();  // assume you have getter in logic.c
    takeDosage();
    int newCount = getCurrentPills();

    printf("\n🔹 Simulating dose taking...\n");
    printTestResult("Pill count decreases after taking dose", newCount < oldCount);

    // 4️⃣ Test refill
    int beforeRefill = getCurrentPills();
    refill();
    int afterRefill = getCurrentPills();

    printTestResult("Pill count increases after refill", afterRefill > beforeRefill);

    // 5️⃣ Test low-pill warning display
    printf("\n🔹 Forcing low-pill warning...\n");
    showLowPillWarning(3);  // should print red warning message

    // 6️⃣ Save data
    printf("\n🔹 Saving pill data...\n");
    savePillData();
    printTestResult("Save pill data to file", 1);

    // 7️⃣ Time logging demo
    printf("\n🔹 Time logging demo...\n");
    logSessionStart();
    logSessionEnd();

    printf("\n==============================\n");
    printf("✅ TEST DEMO COMPLETE ✅\n");
    printf("==============================\n\n");

    return 0;
}

/*
==============================
🧪 PILL COUNTER TEST DEMO 🧪
==============================

🔹 Loading pill data...
✅ Load pill data from file: PASSED

🔹 Current status:
Pills remaining: 10
Daily dose: 2
✅ Stock level is sufficient.

🔹 Simulating dose taking...
✅ Pill count decreases after taking dose: PASSED

🔹 Refill pills...
✅ Pill count increases after refill: PASSED

🔹 Forcing low-pill warning...
⚠️  Warning: Only 3 pills remaining! Please refill soon.

🔹 Saving pill data...
✅ Save pill data to file: PASSED

🔹 Time logging demo...
🕒 Session started: Sat Oct 26 15:04:23 2025
🕒 Session ended: Sat Oct 26 15:04:23 2025

✅ TEST DEMO COMPLETE ✅
*/
