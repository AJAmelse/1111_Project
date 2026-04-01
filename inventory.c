#include "inventory.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

Inventory* new_inventory(size_t str_len, size_t max_items){
    Inventory* new_storage = malloc(sizeof(Inventory));
    if(new_storage){
       new_storage->item_count = 0;
       new_storage->max_items = max_items;
       new_storage->str_length = str_len;
       new_storage->contents = malloc(sizeof(char)*str_len*max_items);
       if(new_storage->contents){
           return new_storage;
       }
       free(new_storage);
    }
    return NULL;
}

int addItem(Inventory* self, char* item){
    if(self->item_count < self->max_items){
        for(int i = 0; i < self->str_length; i++){
            self->contents[self->item_count * self->str_length + i] = item[i];
        }
        self->item_count++;
        return 1;
    }
    return 0;
}

void printInventory(Inventory* self){
    for(int i = 0; i < self->item_count; i++){
        for(int j = 0; j < self->str_length; j++){
            printf("%c", self->contents[j + (i*self->str_length)]);
        }
        printf(" ");
    }
    printf("\n");
}

int hasItem(Inventory* self, char* item){
    int inArray = 0;
    for(int i = 0; i < self->item_count; i++){
        if(strcmp(item, &(self->contents[i * self->str_length])) == 0){
            inArray++;
        } 
    }
    return inArray;
}

void removeItem(Inventory* self, int index){
    for(int i = index; i < self->item_count - 1; i++){
        for(int j = 0; j < self->str_length; j++){
            self->contents[j + (i*self->str_length)] =  self->contents[j + ((i+1)*self->str_length)];
        }

    }
    self->item_count--;
}
