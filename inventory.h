#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdlib.h>
typedef struct{
    char* contents;
    size_t str_length;
    size_t item_count;
    size_t max_items;
} Inventory;

Inventory* new_inventory(size_t str_len, size_t max_items);

int addItem(Inventory* self, char* item);

int removeItem(Inventory* self, char* item);

void printInventory(Inventory* self);

#endif
