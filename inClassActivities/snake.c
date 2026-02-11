/*
    snake.c
    YOUR NAMES HERE

    This is a simplified snake game that you can play in your terminal!

    Complete the TODOs below with your group to get it working.

    NOTE: This uses a custom header file to handle some of the real-time
        behavior for moving the snake around the board and capturing input
        without waiting. You will need to make sure jit.h is in the same folder
        as this file and use a flag to compile with the math libraries!

            gcc snake.c -Wall -lm

        (The "lm" here means we are linking the math library.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jit.h"

#define WIDTH 20
#define HEIGHT 20
#define FPS 3

int main() {
    // Seed the random calls.
    srand(time(NULL));

    // Game assets:
    char board[HEIGHT][WIDTH + 1];  // The characters for displaying the board.
    int snake[HEIGHT * WIDTH];      // The positions of the snake parts.
    int snakeLength;                // An easy reference to the current length.
    int gameOver = 0;               // Controls the game loop.
    int dx = 0, dy = -1;            // Directional controls for the snake.
    int row, column;                // Helpful variables to be reused when converting 1D -> 2D.

    // Construct the border that's placed at the top and bottom of the board.
    for (int i = 0; i < WIDTH; i++) {
        board[0][i] = '#';
        board[HEIGHT - 1][i] = '#';
    }
    // Add a null terminator to make printing easier.
    board[0][WIDTH] = '\0';
    board[HEIGHT - 1][WIDTH] = '\0';

    // Fill the board with blank spaces.
    for (int i = 1; i < HEIGHT - 1; i++) {
        board[i][0] = '#';          // Left border.
        for (int j = 1; j < WIDTH - 1; j++) {
            board[i][j] = ' ';
        }
        board[i][WIDTH - 1] = '#';  // Right border.
        board[i][WIDTH] = '\0'; // Add a null terminator to make printing easier.
    }

    // Set the snake values with all negatives to signal "empty" positions.
    for (int i = 0; i < HEIGHT * WIDTH; i++) {
        snake[i] = -1;
    }

    // Set up the start of the snake.
    snakeLength = 3;
    for (int i = 0; i < snakeLength; i++) {
        snake[i] = (HEIGHT / 2 + i) * WIDTH + WIDTH / 2;
    }
    // Draw the head as bigger.
    board[snake[0] / WIDTH][snake[0] % WIDTH] = 'S';
    // Draw the body smaller.
    for (int i = 1; i < snakeLength; i++) {
        board[snake[i] / WIDTH][snake[i] % WIDTH] = 's';
    }

    // Find a random spot to put the food.
    do {
        column = rand() % (WIDTH - 2) + 1;
        row = rand() % (HEIGHT - 2) + 1;
    } while (board[row][column] != ' ');
    board[row][column] = 'F';

    printf("You are about to play a game of snake!\n");
    printf("The controls are:\n");
    printf("        W\n      (up)\n    A       D\n (left)   (right)\n        S\n     (down)\n");
    printf("\nYou may also press Q to quit at any time.\n");
    printf("Press any other key to begin.\n");

    // Wait for the user to get ready.
    while (!pending_key()) {
        wait(0.1);
    }
    char key = get_key();
    if (key == 'q') { // User decided not to play!
        gameOver = 1;
    }

    while (!gameOver) {
        // Draw the main board.
        clear_screen();     // Give a fresh canvas to draw on.
        for (int i = 0; i < HEIGHT; i++) {
            printf("%s\n", board[i]);     // Print one whole row at a time.
        }

        // Display score at the bottom
        printf("Score: %d\n", snakeLength - 3);

        // Watch for any key presses.
        if (pending_key()) {
            key = get_key();
            // Check both the key and the current direction to prevent instant collisions with self.
            if (key == 'w' && !dy) { // Up
                dx = 0;
                dy = -1;
            } else if (key == 's' && !dy) { // Down
                dx = 0;
                dy = 1;
            } else if (key == 'a' && !dx) { // Left
                dx = -1;
                dy = 0;
            } else if (key == 'd' && !dx) { // Right
                dx = 1;
                dy = 0;
            } else if (key == 'q') { // Stop the game!
                gameOver = 1;
                break;
            }
        }

        //// TODO: Figure out the new coordinates for the head of the snake.
        for(int i = 0; i < snakeLength; i++){
            snake[i] += dx + dy*WIDTH;
        }
        row = snake[0]/WIDTH;
        column = snake[0]%WIDTH;

        // Check for collisions with anything in the board.
        switch (board[row][column]) {
            case 'F': // Eating food.
                //// TODO: Determine what to do when food is eaten.
                break;
            case ' ': // Passing through an empty space.
                //// TODO: Figure out what to do if we are just moving.
                // Draw the head as bigger.
                board[snake[0] / WIDTH][snake[0] % WIDTH] = 'S';
                // Draw the body smaller.
                for (int i = 1; i < snakeLength; i++) {
                    board[snake[i] / WIDTH][snake[i] % WIDTH] = 's';
                }

                break;
            case '#': // Collision with wall.
            case 's': // Collision with body.
            default:  // Unknown symbol on board.
                gameOver = 1;
                break;
        }

        wait(1.0 / FPS); // Control the game speed
    }

    printf("Game Over! Your final score is: %d\n", snakeLength - 3);
    return 0;
}
