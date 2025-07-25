#include <stdio.h>
#include <stdlib.h>

#define MAX_MAP_SIZE 1000  // Adjust as needed

// Structure to represent a key-value pair
struct MapEntry {
    int key;
    int value;
};

// Structure to represent the map
struct Map {
    struct MapEntry entries[MAX_MAP_SIZE];
    int size;
};

// Function to insert/update a key-value pair
void put(struct Map* map, int key, int value) {
    // Check if key already exists, update it
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            map->entries[i].value = value;
            return;
        }
    }

    // Else, insert new entry
    if (map->size < MAX_MAP_SIZE) {
        map->entries[map->size].key = key;
        map->entries[map->size].value = value;
        map->size++;
    } else {
        printf("Map is full!\n");
    }
}

// Function to get value by key
int get(struct Map* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return map->entries[i].value;
        }
    }
    return -1;  // Not found
}

// Function to check if key exists
int contains(struct Map* map, int key) {
    for (int i = 0; i < map->size; i++) {
        if (map->entries[i].key == key) {
            return 1;
        }
    }
    return 0;
}
