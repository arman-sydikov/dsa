/**
 * https://sst-csci.com/151/lessons/extended-exercise-b-minesweeper/
 * @author Arman Sydikov
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h> 

const char NO_MINE = '.';
const char MINE = '*';
const int width = 12;
const int length = 30;
const int mines = 10;

void printMap(char map[width][length]) {
    for (int row = 0; row < width; row++) {
        for (int column = 0; column < length; column++) {
            printf("%c", map[row][column]);
        }
        printf("\n");
    }
}

void printUncovered(char map[width][length], _Bool view[width][length]) {
    for (int row = 0; row < width; row++) {
        for (int column = 0; column < length; column++) {
            if (view[row][column]) {
                printf("%c", map[row][column]);
            } else {
                printf("?");
            }
        }
        printf("\n");
    }
}

void addProximities(char map[width][length]) {
    for (int row = 0; row < width; row++) {
        
        for (int column = 0; column < length; column++) {
            // Don’t bother with cells that have stars in them
            if (map[row][column] == MINE) {
                continue;
            }

            // Variable that is incremented for each neighboring cell that contains a star
            int count = 0;

            // Make sure we do not access a cell that is out of bounds
            if (row > 0) {
                if (column > 0 && map[row-1][column-1] == MINE) {
                    count++;
                }
                if (column < length-1 && map[row-1][column+1] == MINE) {
                    count++;
                }
                if (map[row-1][column] == MINE) {
                    count++;
                }
            }
            if (row < width-1) {
                if (column > 0 && map[row+1][column-1] == MINE) {
                    count++;
                }
                if (column < length-1 && map[row+1][column+1] == MINE) {
                    count++;
                }
                if (map[row+1][column] == MINE) {
                    count++;
                }
            }
            if (column > 0 && map[row][column-1] == MINE) {
                count++;
            }
            if (column < length-1 && map[row][column+1] == MINE) {
                count++;
            }

            // Don’t modify the cells that have proximity number 0
            if (count == 0) {
                continue;
            }

            // Display a proximity number
            map[row][column] = count + '0';
        }
    }
}

int main()
{
    // for random postiitons of mines
    srand(time(NULL));
    setvbuf(stdout, NULL, _IONBF, 0);

    // Declare a 12 x 30 row-column matrix of chars
    char map[width][length];

    // For keeping track of what is visible
    _Bool view[width][length] = {0};

    // Initialize map so that all spots have a period
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            map[i][j] = NO_MINE;
        }
    }

    int row, column;

    // Randomly generate 10 mine coordinate pairs
    for (int i = 0; i < mines; i++) {

        // Choose new coordinates if a mine already exists in the same spot
        do {
            row = rand() % width;
            column = rand() % length;
        } while (map[row][column] == MINE);

        // Set the corresponding spot in map to a star
        map[row][column] = MINE;
    }

    // Add proximities to the map
    addProximities(map);

    // Counts the number of uncovered cells on the map
    int uncoveredCells = 0;

    // Game over
    _Bool gameOver = 0;
    
    // main loop of the game
    do {

        // Print uncovered part of the map
        printUncovered(map, view);
        
        // Obtain user input (which cell to uncover)
        printf("input coordinates, please: ");
        scanf(" %i %i", &row, &column);

        // Ignore illegal coordinates
        if (row < 0 || row > width-1) {
            continue;
        }
        if (column < 0 || column > length-1) {
            continue;
        }

        // Ignore already uncovered cells
        if (view[row][column]) {
            continue;
        }

        // Uncover a cell
        view[row][column] = 1;
        uncoveredCells++;

        // If a mine is uncovered, the game is over
        if (map[row][column] == MINE) {
            // Print out “BOOOOM!!!”
            printf("BOOOOM!!!\n");
            gameOver = 1;
            break;
        }

    } while (uncoveredCells < width * length - mines);

    if (gameOver) {
        // Print the full contents of map
        printMap(map);
    } else {
        printUncovered(map, view);
    }

    return 0;
}
