/*
 * CSCI 1111 Project 1
 * Artemis, Jude, Cameron
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inventory.h"

int main(){
    //store player location as 3x3 grid of booleans
    enum location {downpour, mountain, lava, snow, forest, lake, river, cave, button};
    enum location current = forest;
    int running = 1;
    char input = 'q';
    Inventory* inventory = new_inventory(20, 5);
    char* item = malloc(sizeof(char)*inventory->str_length);
    //set rand seed to unix timestamp to have variable output from program
    srand(time(NULL));

    while(running){
        switch (current) {
            case downpour:
                printf("There is a torrential downpour and lightning crackles in the sky\n");
                printf("move right(d), or down(s), or quit(q): ");
                scanf(" %c", &input);
                //change position in array
                if(input == 's'){
                    current = mountain;
                }else if(input == 'd'){
                    current = snow;
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
 
                break;
            case mountain:
                printf("You come up to the side of a mountain \n");
                printf("move up(w), right(d), or down(s), or quit(q): ");
                scanf(" %c", &input);
                if(input == 's'){
                    current = lava;
                }else if(input == 'd'){
                    current = forest;
                }else if(input == 'w'){
                    current = downpour;
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case lava:
                printf("A lava stream blocks off your path \n");
                printf("move right(d), or up(w), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = mountain;
                }else if(input == 'd'){
                    current = lake;
                }else if(input == 'q'){
                running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case snow:
                printf("It suddenly got cold and there is a foot of snow on the ground\n");
                printf("move left(a), right(d), or down(s), or quit(q): ");
                scanf(" %c", &input);
                if(input == 's'){
                    current = forest;
                }else if(input == 'a'){
                    current = downpour;
                }else if(input == 'd'){
                    current = river;
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case forest:
                printf("You are standing in the center of a forest path splitting in 4 directions\n");
                printf("list inventory(r), add to inventory(t), move up(w), left(a), right(d), or down(s): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = snow;
                }else if(input == 's'){
                    current = lake;
                }else if(input == 'a'){
                    current = mountain;
                }else if(input == 'd'){
                    current = cave;
                }else if(input == 'r'){
                    printInventory(inventory);
                }else if(input == 't'){
                    printf("Item to add: ");
                    scanf(" %[^\n]s", item);
                    printf("%s\n", item);
                    addItem(inventory, item);
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case lake:
                printf("A massive lake spreads out in front of you\n");
                printf("move left(a), right(d), or up(w), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = forest;
                }else if(input == 'a'){
                    current = lava;
                }else if(input == 'd'){
                    current = button;
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case river:
                printf("A river blocks off your path\n");
                printf("move left(a), or down(s), or quit(q): ");
                scanf(" %c", &input);
                if(input == 's'){
                    current = cave;
                }else if(input == 'a'){
                    current = snow;
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case cave:
                printf("The path goes through a dark cave\n");
                printf("move left(a), up(w), or down(s), or quit(q): ");
                scanf(" %c", &input);
                if(input == 's'){
                    current = button;
                }else if(input == 'a'){
                    current = forest;
                }else if(input == 'w'){
                    current = river;
                }else if(input == 'q'){
                    running = 0;
                }else{
                    printf("invalid input\n");
                }
                break;
            case button:
                printf("The path comes to a corner, with a button on a pedestal\n");
                printf("move left(a), or up(w), or pess the button(e), or quit(q): ");
                scanf(" %c", &input);
                if(input == 'w'){
                    current = cave;
                }else if(input == 'a'){
                    current = lake;
                }else if(input == 'q'){
                    running = 0;
                }else if(input == 'e'){
                    int num = rand() % 101;
                    if(num > 75){
                        printf("Confetti shoots into the sky\n");
                    }else if(num >50){
                        printf("Lightning strikes a tree next to you\n");
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
    return 0;
}
