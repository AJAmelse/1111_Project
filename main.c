//test
#include <stdio.h>
int main(){
    int location[3][3] = {{0,0,0},{0,1,0},{0,0,0}};
    int running = 1;
    char input = 'q';

    while(running){
        for(int i=0; i < 3; i++){
            for(int j=0; j<3; j++){
                if(location[i][j]){
                    if(i == 0 && j == 0){
                        printf("There is a torrential downpour and lightning crackles in the sky\n");
                        printf("move right(d), or down(s), or quit(q): ");
                        scanf(" %c", &input);
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
