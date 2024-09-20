/**
 * Header implementation
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=419368
 * @author Arman Sydikov
 */
#include <stdio.h>
#include <stdlib.h>
#include "Clock.h"

Clock* createNewClock(int h, int m, int s) {
    Clock *clock = (Clock*)malloc(sizeof(Clock));

    // Clock must not be empty
    if (clock == NULL) {
        printf("Clock is empty\n");
        return clock;
    }

    // Validate hours (0-23)
    if (h < 0 || h >= 24) {
        printf("Invalid hours\n");
        resetToMidnight(clock);
        return clock;
    }
    
    // Validate minutes
    if (m < 0 || m >= 60) {
        printf("Invalid minutes\n");
        resetToMidnight(clock);
        return clock;
    }

    // Validate seconds
    if (s < 0 || s >= 60) {
        printf("Invalid seconds\n");
        resetToMidnight(clock);
        return clock;
    }

    clock->hours = h;
    clock->minutes = m;
    clock->seconds = s;

    return clock;
}

void resetToMidnight(Clock *clk) {
    if (clk == NULL) {
        return;
    }

    clk->hours = 0;
    clk->minutes = 0;
    clk->seconds = 0;
}

// Morning is the period of time between midnight and noon
_Bool isMorning(Clock *clk) {
    if (clk == NULL) {
        printf("Clock is empty\n");
        return 0;
    }

    return clk->hours < 12;
}

void advanceSeconds(Clock *clk, int secs) {
    if (clk == NULL) {
        printf("Clock is empty\n");
        return;
    }

    if (secs < 0) {
        printf("Invalid seconds\n");
        return;
    }

    int totalSeconds = clk->seconds + secs;
    clk->seconds = totalSeconds % 60;
    
    int totalMinutes = clk->minutes + totalSeconds / 60;
    clk->minutes = totalMinutes % 60;
    
    int totalHours = clk->hours + totalMinutes / 60;
    clk->hours = totalHours % 24;
}

void printClock(Clock *clk) {
    if (clk == NULL) {
        printf("Clock is empty\n");
        return;
    }

    printf("%02d:%02d:%02d\n", clk->hours, clk->minutes, clk->seconds);
}
