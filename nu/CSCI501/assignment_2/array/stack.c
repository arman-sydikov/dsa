/**
 * Array based stack implementation
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=423823
 * @author Arman Sydikov
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

// Initial size of the stack's array
#define INITIAL_ARRAY_SIZE 10

stack* create_stack() {
    // Creates a stack on the heap
    stack *stk = (stack *)malloc(sizeof(stack));

    // Set stack size to zero
    stk->stack_size = 0;

    // Set array size to 10
    stk->array_size = INITIAL_ARRAY_SIZE;

    // Create an array of size 10 on the heap
    stk->values = (int *)malloc(stk->array_size * sizeof(int));

    // Return a pointer to the stack
    return stk;
}

void destroy_stack(stack *stk) {
    if (stk) {
        // Remove array from the heap
        free(stk->values);

        // Remove stack structure from the heap
        free(stk);
    }
}

void resize_stack(stack *stk) {
    // Create a new array of double the size
    size_t new_size = stk->array_size * 2;
    int *new_values = (int *)malloc(new_size * sizeof(int));
    
    // Copy the old values to the new array
    for (size_t i = 0; i < stk->stack_size; i++) {
        new_values[i] = stk->values[i];
    }

    // Free the old array
    free(stk->values);
    
    // Update the stack with the new array and size
    stk->values = new_values;
    stk->array_size = new_size;
}

void push(stack *stk, int val) {
    // Make sure we have enough space on our array
    if (stk->stack_size == stk->array_size) {
        resize_stack(stk);
    }

    // Add a new value to the end of the stack
    stk->values[stk->stack_size] = val;

    // Increment stack size by 1
    stk->stack_size++;
}

int pop(stack *stk) {
    // Popping off an empty stack is not allowed
    if (stk->stack_size == 0) {
        // Print an error message
        fprintf(stderr, "Error: Cannot pop an empty stack.\n");

        // Return a special value to indicate an error
        return INT_MIN;
    }

    // Decrement stack size by 1
    stk->stack_size--;

    // Return a value that has been removed
    return stk->values[stk->stack_size];
}

int peek_top(stack *stk) {
    // Peek top from an empty stack is not allowed
    if (stk->stack_size == 0) {
        // Print an error message
        fprintf(stderr, "Error: Cannot peek the top element from an empty stack.\n");

        // Return a special value to indicate an error
        return INT_MIN;
    }

    // Return top element of the stack
    return stk->values[stk->stack_size - 1];
}

size_t stack_size(stack *stk) {
    return stk->stack_size;
}

void clear_stack(stack *stk) {
    stk->stack_size = 0;
}

void print_stack(stack *stk) {
    // Print stack slements from top to bottom
    for (int i=stk->stack_size-1; i>=0 ; i--) {
        printf("%d ", stk->values[i]);
    }
    printf("\n");
}
