/**
 * BST-based map implementation
 * https://moodle.nu.edu.kz/mod/assign/view.php?id=430030
 * @author Arman Sydikov
 */
#include "map.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>

map* create_map() {
    // Create a map on the heap
    map *mp = (map*)malloc(sizeof(map));

    // Set map size to zero
    mp->map_size = 0;

    // Set root element to null
    mp->root = NULL;

    return mp;
}


void destroy_map(map *mp) {
    if (mp == NULL) {
        return;
    }

    // Remove all children of the map from the heap
    clear_map(mp);

    // Remove map structure from the heap
    free(mp);
}

tree_node* create_node(char *key, int val) {
    // Create a new node on the heap
    tree_node *node = (tree_node*)malloc(sizeof(tree_node));

    // Set node key
    node->key = strdup(key);

    // Set node value
    node->value = val;

    // Set left child
    node->left = NULL;

    // Set right child
    node->right = NULL;

    return node;
}

tree_node* insert_node(map *mp, tree_node *node, char *key, int val) {
    if (node == NULL) {
        // Increment map size
        mp->map_size++;

        // Create a new node
        return create_node(key, val);
    }

    // Compare keys
    int cmp = strcmp(key, node->key);

    if (cmp < 0) {
        // Key is smaller than the current node key
        node->left = insert_node(mp, node->left, key, val);
    } else if (cmp > 0) {
        // Key is bigger than the current node key
        node->right = insert_node(mp, node->right, key, val);
    } else {
        // Key is equal to the current node key, just update the value
        node->value = val;
    }

    return node;
}

void define(map *mp, char *key, int val) {
    // Insert a new key/value pair
    mp->root = insert_node(mp, mp->root, key, val);
}

tree_node* search_key(tree_node *node, char *key) {
    if (node == NULL) {
        return NULL;
    }

    // Compare keys
    int cmp = strcmp(key, node->key);

    if (cmp < 0) {
        // Key is smaller than the current node key
        return search_key(node->left, key);
    } else if (cmp > 0) {
        // Key is bigger than the current node key
        return search_key(node->right, key);
    } else {
        // Key is equal to the current node key
        return node;
    }
}

_Bool contains_key(map *mp, char *key) {
    if (mp == NULL) {
        return 0;
    }

    return search_key(mp->root, key) != NULL;
}

int get_value(map *mp, char *key) {
    if (mp == NULL) {
        return INT_MIN;
    }

    // Search a node by key
    tree_node *node = search_key(mp->root, key);

    if (node) {
        // Node with a given key has been found, return its value
        return node->value;
    } else {
        // Node with a given key doesn't exist, print error
        printf("Error: Key '%s' not found in the map.\n", key);

        // Return a special value, indicating an error
        return INT_MIN;
    }
}

void remove_children(tree_node *node) {
    if (node == NULL) {
        return;
    }

    // Remove all children smaller than the current node
    remove_children(node->left);

    // Remove all children bigger than the current node
    remove_children(node->right);

    // Remove the key
    free(node->key);

    // Remove the node
    free(node);
}

void clear_map(map *mp) {
    if (mp == NULL) {
        return;
    }

    // Recursively remove all children from the heap
    remove_children(mp->root);

    // Set root to null
    mp->root = NULL;

    // Set map size to zero
    mp->map_size = 0;
}

size_t map_size(map *mp) {
    if (mp == NULL) {
        return 0;
    }

    return mp->map_size;
}

void print_tree(tree_node *node) {
    if (node == NULL) {
        return;
    }

    // Print all key/value pairs on the left
    print_tree(node->left);

    // Print current key/value pair
    printf("'%s': %d\n", node->key, node->value);

    // Print all key/value pairs on the right
    print_tree(node->right);
}

void print_map(map *mp) {
    if (mp == NULL) {
        return;
    }

    print_tree(mp->root);
}
