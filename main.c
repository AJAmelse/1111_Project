/*
 * CSCI 1111 Project 1
 * Artemis, Jude, Cameron
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    //store player location as 3x3 grid of booleans
    int location[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int running = 1;
    char input = 'q';
    //set rand seed to unix timestamp to have variable output from program
    srand(time(NULL));

    while(running){
        //check through all values of 2d location array
        for(int i=0; i < 3; i++){
            for(int j=0; j<3; j++){
                //check if current value is set to true
                if(location[i][j]){
                    //different output based on location
                    if(i == 0 && j == 0){
                        printf("There is a torrential downpour and lightning crackles in the sky\n");
                        printf("move right(d), or down(s), or quit(q): ");
                        scanf(" %c", &input);
                        //change position in array
                        if(input == 's'){
                            location[i][j] = 0;
                            location[i+1][j] = 1;
                        }else if(input == 'd'){
                            location[i][j] = 0;
                            location[i][j+1] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 1 && j == 0){
                        printf("You come up to the side of a mountain \n");
                        printf("move up(w), right(d), or down(s), or quit(q): ");
                        scanf(" %c", &input);
                        if(input == 's'){
                            location[i][j] = 0;
                            location[i+1][j] = 1;
                        }else if(input == 'd'){
                            location[i][j] = 0;
                            location[i][j+1] = 1;
                        }else if(input == 'w'){
                            location[i][j] = 0;
                            location[i-1][j] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 2 && j == 0){
                        printf("A lava stream blocks off your path \n");
                        printf("move right(d), or up(w), or quit(q): ");
                        scanf(" %c", &input);
                        if(input == 'w'){
                            location[i][j] = 0;
                            location[i-1][j] = 1;
                        }else if(input == 'd'){
                            location[i][j] = 0;
                            location[i][j+1] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 0 && j == 1){
                        printf("It suddenly got cold and there is a foot of snow on the ground\n");
                        printf("move left(a), right(d), or down(s), or quit(q): ");
                        scanf(" %c", &input);
                        if(input == 's'){
                            location[i][j] = 0;
                            location[i-1][j] = 1;
                        }else if(input == 'a'){
                            location[i][j] = 0;
                            location[i][j-1] = 1;
                        }else if(input == 'd'){
                            location[i][j] = 0;
                            location[i][j+1] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 1 && j == 1){
                        printf("You are standing in the center of a forest path splitting in 4 directions\n");
                        printf("move up(w), left(a), right(d), or down(s): ");
                        scanf(" %c", &input);
                        if(input == 'w'){
                            location[i][j] = 0;
                            location[i-1][j] = 1;
                        }else if(input == 's'){
                            location[i][j] = 0;
                            location[i+1][j] = 1;
                        }else if(input == 'a'){
                            location[i][j] = 0;
                            location[i][j-1] = 1;
                        }else if(input == 'd'){
                            location[i][j] = 0;
                            location[i][j+1] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 2 && j == 1){
                        printf("A massive lake spreads out in front of you\n");
                        printf("move left(a), right(d), or up(w), or quit(q): ");
                        scanf(" %c", &input);
                        if(input == 'w'){
                            location[i][j] = 0;
                            location[i-1][j] = 1;
                        }else if(input == 'a'){
                            location[i][j] = 0;
                            location[i][j-1] = 1;
                        }else if(input == 'd'){
                            location[i][j] = 0;
                            location[i][j+1] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 0 && j == 2){
                        printf("A river blocks off your path\n");
                        printf("move left(a), or down(s), or quit(q): ");
                        scanf(" %c", &input);
                        if(input == 's'){
                            location[i][j] = 0;
                            location[i+1][j] = 1;
                        }else if(input == 'a'){
                            location[i][j] = 0;
                            location[i][j-1] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 1 && j == 2){
                        printf("The path goes through a dark cave\n");
                        printf("move left(a), up(w), or down(s), or quit(q): ");
                        scanf(" %c", &input);
                        if(input == 's'){
                            location[i][j] = 0;
                            location[i+1][j] = 1;
                        }else if(input == 'a'){
                            location[i][j] = 0;
                            location[i][j-1] = 1;
                        }else if(input == 'w'){
                            location[i][j] = 0;
                            location[i-1][j] = 1;
                        }else if(input == 'q'){
                            running = 0;
                        }else{
                            printf("invalid input\n");
                        }
                    }
                    if(i == 2 && j == 2){
                        printf("The path comes to a corner, with a button on a pedestal\n");
                        printf("move left(a), or up(w), or pess the button(e), or quit(q): ");
                        scanf(" %c", &input);
                        if(input == 'w'){
                            location[i][j] = 0;
                            location[i-1][j] = 1;
                        }else if(input == 'a'){
                            location[i][j] = 0;
                            location[i][j-1] = 1;
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
                    }
                }
            }
        }
    }
    return 0;
}
