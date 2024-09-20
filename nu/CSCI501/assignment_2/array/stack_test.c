/**
 * Test stack
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=423823
 * @author Arman Sydikov
 */
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

void testPush() {
    // Prepare test data
    stack *stk = create_stack();

    // Execute function and assert results
    assert(stack_size(stk) == 0);
    for (int i=1; i<=20; i++) {
        push(stk, i);
    }
    assert(stack_size(stk) == 20);

    // Clean up memory
    destroy_stack(stk);
}

void testPopWhenStackIsNotEmpty() {
    // Prepare test data
    stack *stk = create_stack();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);

    // Execute function and assert results
    assert(pop(stk) == 3);
    assert(stack_size(stk) == 2);
    assert(pop(stk) == 2);
    assert(stack_size(stk) == 1);
    assert(pop(stk) == 1);
    assert(stack_size(stk) == 0);

    // Clean up memory
    destroy_stack(stk);
}

void testPopWhenStackIsEmpty() {
    // Prepare test data
    stack *stk = create_stack();

    // Execute function and assert results
    assert(stack_size(stk) == 0);
    assert(pop(stk) == INT_MIN);
    assert(stack_size(stk) == 0);

    // Clean up memory
    destroy_stack(stk);
}

void testPeekTopWhenStackIsNotEmpty() {
    // Prepare test data
    stack *stk = create_stack();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);

    // Execute function and assert results
    assert(peek_top(stk) == 3);

    // Clean up memory
    destroy_stack(stk);
}

void testPeekTopWhenStackIsEmpty() {
    // Prepare test data
    stack *stk = create_stack();

    // Execute function and assert results
    assert(stack_size(stk) == 0);
    assert(peek_top(stk) == INT_MIN);

    // Clean up memory
    destroy_stack(stk);
}

void testClearStack() {
    // Prepare test data
    stack *stk = create_stack();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);

    // Execute function and assert results
    assert(stack_size(stk) == 3);
    clear_stack(stk);
    assert(stack_size(stk) == 0);

    // Clean up memory
    destroy_stack(stk);
}

void testPrintStackWhenStackIsNotEmpty() {
    // Prepare test data
    stack *stk = create_stack();
    push(stk, 1);
    push(stk, 2);
    push(stk, 3);

    // Execute function and assert results
    print_stack(stk);

    // Clean up memory
    destroy_stack(stk);
}

void testPrintStackWhenStackIsEmpty() {
    // Prepare test data
    stack *stk = create_stack();

    // Execute function and assert results
    print_stack(stk);

    // Clean up memory
    destroy_stack(stk);
}

int main() {
    testPush();
    testPopWhenStackIsNotEmpty();
    testPopWhenStackIsEmpty();
    testPeekTopWhenStackIsNotEmpty();
    testPeekTopWhenStackIsEmpty();
    testClearStack();
    testPrintStackWhenStackIsNotEmpty();
    testPrintStackWhenStackIsEmpty();

    return 0;
}
