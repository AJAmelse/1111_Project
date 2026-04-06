#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdlib.h>

/**
 *  contents contains a string list of inventory
 *  str_length is the max item name length
 *  item_count is the number of items in the inventory
 *  max_items is the maximum storage space
 */
typedef struct{
    char* contents;
    size_t str_length;
    size_t item_count;
    size_t max_items;
} Inventory;

/**
 *  allocates new inventory and returns pointer to it
 *  str_len is the maximum length of an item string
 *  max_items is the maximum storage space
 */
Inventory* new_inventory(size_t str_len, size_t max_items);

/**
 * adds an item to the inventory
 * returns 1 if successful
 * returns 0 if there is no space available
 */
int addItem(Inventory* self, char* item);

/**
 *  removes an item from the inventory at the given index
 */
void removeItem(Inventory* self, int index);

/**
 * checks if an item is in the inventory and returns index + 1 of the item if found
 */
int hasItem(Inventory* self, char* item);

/**
 *  prints out the inventory contents
 */
void printInventory(Inventory* self);

/**
 * frees the inventory contents and inventory pointer
 */
void freeInventory(Inventory** self);

#endif
