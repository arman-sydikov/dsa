/**
 * Test map
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=430032
 * @author Arman Sydikov
 */
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

void testPrintMap() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    define(m, "test5", 5);
    define(m, "test4", 4);
    define(m, "test3", 3);
    define(m, "test2", 2);
    define(m, "test1", 1);
    print_map(m);

    // Clean up memory
    destroy_map(m);
}

void testContainsKey() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    define(m, "test1", 1);
    assert(contains_key(m, "test1") == 1);
    assert(contains_key(m, "test2") == 0);

    // Clean up memory
    destroy_map(m);
}

void testClearMap() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    define(m, "test1", 1);
    define(m, "test2", 2);
    define(m, "test3", 3);
    assert(map_size(m) == 3);
    clear_map(m);
    assert(map_size(m) == 0);

    // Clean up memory
    destroy_map(m);
}

void testMapSizeWhenKeysAreEqual() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    assert(map_size(m) == 0);
    define(m, "test1", 1);
    define(m, "test1", 2);
    assert(map_size(m) == 1);

    // Clean up memory
    destroy_map(m);
}

void testMapSizeWhenKeysAreNotEqual() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    assert(map_size(m) == 0);
    define(m, "test1", 1);
    define(m, "test2", 2);
    assert(map_size(m) == 2);

    // Clean up memory
    destroy_map(m);
}

void testGetValueWhenKeysAreEqual() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    define(m, "test1", 1);
    define(m, "test1", 2);
    assert(get_value(m, "test1") == 2);

    // Clean up memory
    destroy_map(m);
}

void testGetValueWhenKeysAreNotEqual() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    define(m, "test1", 1);
    define(m, "test2", 2);
    assert(get_value(m, "test1") == 1);
    assert(get_value(m, "test2") == 2);

    // Clean up memory
    destroy_map(m);
}

void testGetValueWhenMapIsEmpty() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    assert(get_value(m, "test1") == INT_MIN);

    // Clean up memory
    destroy_map(m);
}

void testLoadFactor() {
    // Prepare test data
    map *m = create_map();

    // Execute function and assert results
    for (int i=1; i<=25; i++) {
        char numStr[3];
        sprintf(numStr, "%d", i);
        define(m, numStr, i);
        printf("%i %f %f\n", i, load_factor(m), bucket_size_stdev(m));
    }

    assert(load_factor(m) == 1.5625);

    // Clean up memory
    destroy_map(m);
}

int main() {
    testPrintMap();
    testContainsKey();
    testClearMap();
    testMapSizeWhenKeysAreEqual();
    testMapSizeWhenKeysAreNotEqual();
    testGetValueWhenKeysAreEqual();
    testGetValueWhenKeysAreNotEqual();
    testGetValueWhenMapIsEmpty();
    testLoadFactor();

    return 0;
}
