/**
 * Stack implementation with linked list
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=423823
 * @author Arman Sydikov
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

stack* create_stack() {
    // Create a stack on the heap
    stack *stk = (stack *)malloc(sizeof(stack));

    // Set stack size to zero
    stk->stack_size = 0;

    // Set top element to null
    stk->top = NULL;

    // Return a pointer to the stack
    return stk;
}

void destroy_stack(stack *stk) {
    if (stk) {
        // Remove all nodes
        clear_stack(stk);

        // Remove stack structure from the heap
        free(stk);
    }
}

void push(stack *stk, int val) {
    // Create a node on the heap
    node *new_node = (node *)malloc(sizeof(node));

    // Set the new node's value
    new_node->value = val;

    // Link the new node to the current top
    new_node->link = stk->top;
    
    // Update the top to the new node
    stk->top = new_node;

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

    // Copy the value of the node that we want to remove
    int value = stk->top->value;

    // Copy the pointer to the node that we want to remove
    node *temp = stk->top;

    // Update the top to the next node
    stk->top = temp->link;

    // Remove the old top node from the heap
    free(temp);

    // Decrement stack size by 1
    stk->stack_size--;

    // Return a value of the node that has been removed
    return value;
}

int peek_top(stack *stk) {
    // Peek top from an empty stack is not allowed
    if (stk->stack_size == 0) {
        // Print an error message
        fprintf(stderr, "Error: Cannot peek the top element from an empty stack.\n");

        // Return a special value to indicate an error
        return INT_MIN;
    }

    return stk->top->value;
}

size_t stack_size(stack *stk) {
    return stk->stack_size;
}

void clear_stack(stack *stk) {
    while (stk->top) {
        node *temp = stk->top;
        stk->top = stk->top->link;

        // Remove the node from the heap
        free(temp);
    }
    stk->stack_size = 0;
}

void print_stack(stack *stk) {
    // Print stack slements from top to bottom
    node *current = stk->top;
    while (current) {
        printf("%d ", current->value);
        current = current->link;
    }
    printf("\n");
}
