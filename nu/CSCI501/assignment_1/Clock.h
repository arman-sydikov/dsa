/**
 * Header declaration
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=419368
 * @author Arman Sydikov
 */
#ifndef CLOCK_H
#define CLOCK_H

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Clock;

Clock* createNewClock(int h, int m, int s);
void resetToMidnight(Clock *clk);
_Bool isMorning(Clock *clk);
void advanceSeconds(Clock *clk, int secs);
void printClock(Clock *clk);

#endif