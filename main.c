/*
 * CSCI 1111 Project 1
 * Artemis, Jude, Cameron
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "inventory.h"

int addToInventory(char* thing, Inventory* inv){
    if(addItem(inv, thing)){
        printf("Added %s to inventory\n", thing);
        return 1;
    }else{
        printf("Inventory full\n");
        return 0;
    }
}

int useItem(char* thing, Inventory* inv){
    if(hasItem(inv, thing)){
        printf("Used %s\n", thing);
        removeItem(inv, hasItem(inv, thing)-1);
        return 1;
    }else{
        printf("not in inventory\n");
        return 0;
    }
}

int main(){
    //store player location as 3x3 grid of booleans
    enum location {downpour, mountain, lava, snow, forest, lake, river, cave, button};
    enum location current = forest;
    int running = 1;
    char input = 'q';
    Inventory* inventory = new_inventory(20, 5);
    char* item = (char*)malloc(sizeof(char)*inventory->str_length);
    //set rand seed to unix timestamp to have variable output from program
    srand(time(NULL));
    int caveLit = 0;
    int boatUsed = 0;
    int boatPickedUp = 0;
    int lightningRodPickedUp = 0;
    int lightningRodPlaced = 0;

    while(running){
        switch (current) {
            case downpour:
                printf("There is a torrential downpour and lightning crackles in the sky\n");
                printf("move right(d), or down(s),or list inventory(i), or search area(r), or use item(f), or quit(q): ");
                scanf(" %c", &input);
                //change position in array
                if(input == 's'){
                    current = snow;
                }else if(input == 'd'){
                    current = forest;
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    if(!lightningRodPickedUp){
                        printf("You found a lightning rod!\n");
                        strcpy(item, "lightning rod");
                        lightningRodPickedUp = addToInventory(item, inventory);
                    }else{
                        printf("nothing left\n");
                    }
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    printf("There was no use for that item here\n");
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
 
                break;
            case mountain:
                printf("You come up to the side of a mountain \n");
                printf("move  right(d), or down(s), or list inventory(i), or search area(r), or use item(f) or quit(q): ");
                scanf(" %c", &input);
                if(input == 's'){
                    current = forest;
                }else if(input == 'd'){
                    current = lava;
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    printf("You couldn't find anything\n");
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    printf("There was no use for that item here\n");
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case lava:
                printf("A lava stream blocks off your path \n");
                printf("move left(a), or list inventory(i),or search area(r), or use item(f), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'a'){
                    current = mountain;
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    printf("You couldn't find anything\n");
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    printf("There was no use for that item here\n");
                }else if(input == 'q'){
                running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case snow:
                printf("It suddenly got cold and there is a foot of snow on the ground\n");
                printf("move up(w), or down(s), or list inventory(i), or search area(r), or use item(f), or quit(q): ");
                scanf(" %c", &input);
                if(input == 's'){
                    current = button;
                }else if(input == 'w'){
                    current = downpour;
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    printf("You couldn't find anything\n");
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    printf("There was no use for that item here\n");
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case forest:
                printf("You are standing in the center of a forest path splitting in 4 directions\n");
                printf("use item(f), list inventory(i), search area(r), move up(w), left(a), right(d), or down(s): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = mountain;
                }else if(input == 's'){
                    current = river;
                }else if(input == 'a'){
                    current = downpour;
                }else if(input == 'd'){
                    current = lake;
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    printf("You couldn't find anything\n");
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    printf("There was no use for that item here\n");
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case lake:
                printf("A massive lake spreads out in front of you\n");
                printf("move left(a), right(d), or list inventory(i), or search area(r), or use item(f), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'a'){
                    current = forest;
                }else if(input == 'd'){
                    if(boatUsed){
                        current = cave;
                    }
                    else{
                        printf("Couldn't cross the lake\n");
                    }
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    printf("You couldn't find anything\n");
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    if(!strcmp(item, "boat")){
                        boatUsed = useItem(item, inventory);
                    }else{
                        printf("There was no use for that item here\n");
                    }
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case river:
                printf("A river blocks off your path\n");
                printf("move up(w), or list inventory(i), or search area(r), or use item(f), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = forest;
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    if(!boatPickedUp){
                        printf("You found a boat");
                        strcpy(item, "boat");
                        boatPickedUp = addToInventory(item, inventory);
                    }else{
                        printf("nothing left to find");
                    }
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    printf("There was no use for that item here\n");
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case cave:
                printf("The path goes through a dark cave\n");
                printf("move up(w), or down(s), or list inventory(i), or search area(r), or use item(f), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = lake;
                }else if(input == 's'){
                    if(caveLit){
                        printf("You Won!!!\n");
                        running = 0;
                    }else{
                        printf("The cave is too dark to navigate\n");
                    }
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    printf("You couldn't find anything\n");
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    printf("There was no use for that item here\n");
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case button:
                printf("The path comes to a corner, with a button on a pedestal\n");
                printf("move up(w), or list inventory(i), or search the area(r), or use item(f), or press the button(e), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = snow;
                }else if(input == 'i'){
                    printInventory(inventory);
                }else if(input == 'r'){
                    printf("You couldn't find anything\n");
                }else if(input == 'f'){
                    printf("Item to use:");
                    scanf(" %[^\n]s", item);
                    if(!strcmp(item, "lightning rod")){
                        lightningRodPlaced = useItem(item, inventory);
                    }else{
                        printf("There was no use for that item here\n");
                    }
                }else if(input == 'q'){
                    running = 0;
                }else if(input == 'e'){
                    int num = rand() % 101;
                    if(num > 75){
                        printf("Confetti shoots into the sky\n");
                    }else if(num >50){
                        if(lightningRodPlaced){
                            printf("Lightning strikes the lightning rod and you hear a click\n");
                            caveLit = 1;
                        }else{
                            printf("Lightning strikes a tree next to you\n");
                        }
                    }else if(num > 25){
                        printf("The Northern Lights appear in the sky\n");
                    }else{
                        printf("Nothing happens\n");
                    }
                }else{
                    printf("invalid input\n");
                }
                break;
        }
    }

    free(item);
    item = NULL;
    freeInventory(&inventory);
    inventory = NULL;

    return 0;
}
