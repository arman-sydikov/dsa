/**
 * Test clock library
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=419368
 * @author Arman Sydikov
 */
#include "Clock.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void testIsMorningWhenHourIsLessThan12() {
    // Prepare test data
    Clock *clock = createNewClock(11, 0, 0);

    // Execute function and assert results
    assert(isMorning(clock) == 1);

    // Clean up memory
    free(clock);
}

void testIsMorningWhenHourIsEqual12() {
    // Prepare test data
    Clock *clock = createNewClock(12, 0, 0);

    // Execute function and assert results
    assert(isMorning(clock) == 0);

    // Clean up memory
    free(clock);
}

void testIsMorningWhenClkIsNull() {
    // Prepare test data
    Clock *clock = NULL;

    // Execute function and assert results
    assert(isMorning(clock) == 0);

    // Clean up memory
    free(clock);
}

void testCreateNewClockWhenHourIsLessThanZero() {
    // Execute function
    Clock *clock = createNewClock(-1, 0, 0);
    
    // Assert results
    assert(clock->hours == 0);
    assert(clock->minutes == 0);
    assert(clock->seconds == 0);

    // Clean up memory
    free(clock);
}

void testCreateNewClockWhenHourEquals24() {
    // Execute function
    Clock *clock = createNewClock(24, 0, 0);
    
    // Assert results
    assert(clock->hours == 0);
    assert(clock->minutes == 0);
    assert(clock->seconds == 0);

    // Clean up memory
    free(clock);
}

void testCreateNewClockWhenMinuteIsLessThanZero() {
    // Execute function
    Clock *clock = createNewClock(0, -1, 0);
    
    // Assert results
    assert(clock->hours == 0);
    assert(clock->minutes == 0);
    assert(clock->seconds == 0);

    // Clean up memory
    free(clock);
}

void testCreateNewClockWhenMinuteEquals60() {
    // Execute function
    Clock *clock = createNewClock(0, 60, 0);
    
    // Assert results
    assert(clock->hours == 0);
    assert(clock->minutes == 0);
    assert(clock->seconds == 0);

    // Clean up memory
    free(clock);
}

void testCreateNewClockWhenSecondIsLessThanZero() {
    // Execute function
    Clock *clock = createNewClock(0, 0, -1);
    
    // Assert results
    assert(clock->hours == 0);
    assert(clock->minutes == 0);
    assert(clock->seconds == 0);

    // Clean up memory
    free(clock);
}

void testCreateNewClockWhenSecondEquals60() {
    // Execute function
    Clock *clock = createNewClock(0, 0, 60);
    
    // Assert results
    assert(clock->hours == 0);
    assert(clock->minutes == 0);
    assert(clock->seconds == 0);

    // Clean up memory
    free(clock);
}

void testAdvanceSecondsWhenSecsMoreThanZero() {
    // Prepare test data
    Clock *clock = createNewClock(22, 45, 50);

    // Execute function
    advanceSeconds(clock, 8000);

    // Execute function and assert results
    assert(clock->hours == 0);
    assert(clock->minutes == 59);
    assert(clock->seconds == 10);

    // Clean up memory
    free(clock);
}

void testAdvanceSecondsWhenSecsLessThanZero() {
    // Prepare test data
    Clock *clock = createNewClock(22, 45, 50);

    // Execute function
    advanceSeconds(clock, -1);

    // Execute function and assert results
    assert(clock->hours == 22);
    assert(clock->minutes == 45);
    assert(clock->seconds == 50);

    // Clean up memory
    free(clock);
}

void testAdvanceSecondsWhenClkIsNull() {
    // Prepare test data
    Clock *clock = NULL;

    // Execute function
    advanceSeconds(clock, 10);

    // Execute function and assert results
    assert(clock == NULL);

    // Clean up memory
    free(clock);
}

void testResetToMidnightWhenClkIsNull() {
    // Prepare test data
    Clock *clock = NULL;

    // Execute function
    resetToMidnight(clock);

    // Execute function and assert results
    assert(clock == NULL);

    // Clean up memory
    free(clock);
}

void testPrintClock() {
    // Prepare test data
    Clock* arr[8] = {
        createNewClock(0, 0, 0),
        createNewClock(0, 23, 54),
        createNewClock(4, 55, 2),
        createNewClock(11, 59, 59),
        createNewClock(12, 0, 0),
        createNewClock(15, 1, 2),
        createNewClock(20, 20, 20),
        createNewClock(23, 59, 59),
    };

    // Execute function
    for (int i=0; i<8; i++) {
        printClock(arr[i]);
    }
    printClock(NULL);

    // Clean up memory
    for (int i=0; i<8; i++) {
        free(arr[i]);
    }
}

int main() {
    // Test isMorning
    testIsMorningWhenHourIsLessThan12();
    testIsMorningWhenHourIsEqual12();
    testIsMorningWhenClkIsNull();

    // Test createNewClock
    testCreateNewClockWhenHourIsLessThanZero();
    testCreateNewClockWhenHourEquals24();
    testCreateNewClockWhenMinuteIsLessThanZero();
    testCreateNewClockWhenMinuteEquals60();
    testCreateNewClockWhenSecondIsLessThanZero();
    testCreateNewClockWhenSecondEquals60();

    // Test advanceSeconds
    testAdvanceSecondsWhenSecsMoreThanZero();
    testAdvanceSecondsWhenSecsLessThanZero();
    testAdvanceSecondsWhenClkIsNull();

    // Test resetToMidnight
    testResetToMidnightWhenClkIsNull();

    // Test printClock
    testPrintClock();

    return 0;
}
