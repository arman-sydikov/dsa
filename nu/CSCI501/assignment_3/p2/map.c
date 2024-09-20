/**
 * Hashtable-based map implementation
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=430032
 * @author Arman Sydikov
 */
#include "map.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

size_t hash_function(const char *key, size_t num_of_buckets) {
    // Hashcode
    size_t hash = 0;

    for (size_t i = 0; key[i] != '\0'; i++) {
        // Java's hashCode logic (31 * current hash + char value)
        hash = 31 * hash + key[i];
    }

    // Use modulo to fit into the bucket array
    return hash % num_of_buckets;
}


map* create_map() {
    // Create a map on the heap
    map *mp = malloc(sizeof(map));

    // Set map size to zero
    mp->map_size = 0;

    // Set number of buckets
    mp->num_of_buckets = INITIAL_BUCKETS;

    // Create buckets on the heap, initialised with zeros
    mp->buckets = calloc(mp->num_of_buckets, sizeof(node*));

    return mp;
}

void destroy_map(map *mp) {
    if (mp == NULL) {
        return;
    }

    // Remove all children of the map from the heap
    clear_map(mp);

    // Remove buckets from the heap
    free(mp->buckets);

    // Remove map structure from the heap
    free(mp);
}

void resize(map *mp) {
    // Double the number of buckets
    size_t new_num_of_buckets = mp->num_of_buckets * 2;

    // Create new buckets on the heap, initialised with zeros
    node **new_buckets = calloc(new_num_of_buckets, sizeof(node*));

    for (size_t i = 0; i < mp->num_of_buckets; i++) {
        // Get the first node of the linked list from the bucket
        node *current = mp->buckets[i];

        // Iterate over linked list
        while (current) {
            // Get next node
            node *next = current->link;

            // Calculate a new index of the key
            size_t new_index = hash_function(current->key, new_num_of_buckets);

            // Put current node at the beginning of the linkded list
            current->link = new_buckets[new_index];
            new_buckets[new_index] = current;

            // Move to the next node
            current = next;
        }
    }
    
    // Remove old buckets from the heap
    free(mp->buckets);

    // Set buckets pointer to new buckets
    mp->buckets = new_buckets;

    // Update number of backets
    mp->num_of_buckets = new_num_of_buckets;
}

void define(map *mp, char *key, int val) {
    // Calculate the bucket index of the key
    size_t index = hash_function(key, mp->num_of_buckets);

    // Get the first node of the linked list from the bucket
    node *current = mp->buckets[index];
    
    // Iterate over linked list to find a node with a given key
    while (current) {
        if (strcmp(current->key, key) == 0) {

            // Node with a given key has been found, just update its value
            current->value = val;

            // Exit function
            return;
        }

        // Move to the next node
        current = current->link;
    }

    // Node with a given key doesn't exist, so we need to create a new one
    node *new_node = malloc(sizeof(node));

    // Set node key
    new_node->key = strdup(key);

    // Set node value
    new_node->value = val;

    // Put this node at the beginning of the linked list
    new_node->link = mp->buckets[index];
    mp->buckets[index] = new_node;

    // Increment map size
    mp->map_size++;

    if (load_factor(mp) > MAX_LOAD_FACTOR) {
        resize(mp);
    }
}

_Bool contains_key(map *mp, char *key) {
    // Calculate the bucket index of the key
    size_t index = hash_function(key, mp->num_of_buckets);

    // Get the first node of the linked list from the bucket
    node *current = mp->buckets[index];

    // Iterate over linked list to find a node with a given key
    while (current) {
        if (strcmp(current->key, key) == 0) {

            // Node with a given key has been found
            return 1;
        }

        // Move to the next node
        current = current->link;
    }

    // Node with a given key doesn't exist
    return 0;
}

int get_value(map *mp, char *key) {
    // Calculate the bucket index of the key
    size_t index = hash_function(key, mp->num_of_buckets);

    // Get the first node of the linked list from the bucket
    node *current = mp->buckets[index];

    // Iterate over linked list to find a node with a given key
    while (current) {
        if (strcmp(current->key, key) == 0) {

            // Node with a given key has been found, return its value
            return current->value;
        }

        // Move to the next note
        current = current->link;
    }
    
    printf("Error: Key not found.\n");
    return INT_MIN;
}

size_t map_size(map *mp) {
    return mp->map_size;
}

void clear_map(map *mp) {
    for (size_t i = 0; i < mp->num_of_buckets; i++) {

        // Get the first node of the linked list from the bucket
        node *current = mp->buckets[i];

        // Iterate over linked list
        while (current) {
            node *next = current->link;

            // Remove current node key from the heap
            free(current->key);

            // Remove current node from the heap
            free(current);

            // Move to the next node
            current = next;
        }

        // Set bucket to null
        mp->buckets[i] = NULL;
    }

    // Set map size to zero
    mp->map_size = 0;
}

void print_map(map *mp) {
    for (size_t i = 0; i < mp->num_of_buckets; i++) {

        // Get the first node of the linked list from the bucket
        node *current = mp->buckets[i];

        // Iterate over linked list
        while (current) {

            // Print current key/value pair
            printf("'%s': %d\n", current->key, current->value);

            // Move to the next
            current = current->link;
        }
    }
}

double load_factor(map *mp) {
    return (double)mp->map_size / mp->num_of_buckets;
}

double bucket_size_stdev(map *mp) {
    // Mean
    double mean = (double)mp->map_size / mp->num_of_buckets;

    // Sum of squared differences
    double sum_squared_diff = 0.0;

    for (size_t i = 0; i < mp->num_of_buckets; i++) {
        size_t bucket_size = 0;

        // Get the first node of the linked list from the bucket
        node *current = mp->buckets[i];

        // Iterate over linked list
        while (current) {

            // Increment bucket size
            bucket_size++;

            // Move to the next node
            current = current->link;
        }

        sum_squared_diff += (bucket_size - mean) * (bucket_size - mean);
    }
    
    return sqrt(sum_squared_diff / mp->num_of_buckets);
}
