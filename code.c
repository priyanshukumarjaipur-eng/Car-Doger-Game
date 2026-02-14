#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>    // _kbhit, _getch
#include <windows.h>  // Sleep

// --- Game Constants ---
#define ROAD_WIDTH 25
#define SCREEN_HEIGHT 20
#define MAX_OBSTACLES 4

// Structure for obstacles
typedef struct {
    int x;
    int y;
    char symbol;
} Obstacle;

// Globals
int score = 0;
int car_x, car_y;
int game_over = 0;
int game_speed = 100;   // milliseconds

Obstacle obstacles[MAX_OBSTACLES];

// Function declarations
void show_menu();
void setup();
void draw();
void input();
void logic();

// MAIN ---------------------------------------------------------
int main() {
    show_menu();
    setup();

    while (!game_over) {
        draw();
        input();
        logic();
        Sleep(game_speed);  // Sleep in milliseconds (Windows)
    }

    system("cls");
    printf("\n\n\n\n\n\n\n\n\n");
    printf("     GAME OVER!\n");
    printf("     Your final score: %d\n", score);
    printf("\n\n\n\n\n\n\n\n\n");

    // Pause so the console doesn't close immediately
    printf("Press any key to exit...");
    _getch();

    return 0;
}

// MENU ----------------------------------------------------------
void show_menu() {
    system("cls");
    printf("\n\n\n\n\n");
    printf("        🚗 CAR DODGER 🚗\n\n");
    printf("     Press 'a' to move left\n");
    printf("     Press 'd' to move right\n");
    printf("     Press 'w' to move up\n");
    printf("     Press 's' to move down\n");
    printf("     Press 'q' to quit\n");
    printf("     Avoid obstacles (0–9)!\n");
    printf("\n     Press ENTER to start!\n");
    getchar();      // Wait for ENTER
    system("cls");
}

// SETUP ---------------------------------------------------------
void setup() {
    srand((unsigned int)time(NULL));

    car_x = ROAD_WIDTH / 2;
    car_y = SCREEN_HEIGHT - 2;

    for (int i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i].x = rand() % ROAD_WIDTH;
        obstacles[i].y = -(rand() % SCREEN_HEIGHT);
        obstacles[i].symbol = '0' + (rand() % 10);
    }

    score = 0;
    game_over = 0;
    game_speed = 100;  // start slower
}

// DRAW ----------------------------------------------------------
void draw() {
    system("cls");  // Clear the console screen

    for (int i = 0; i < ROAD_WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        printf("#");

        for (int x = 0; x < ROAD_WIDTH; x++) {
            int printed = 0;

            for (int i = 0; i < MAX_OBSTACLES; i++) {
                if (x == obstacles[i].x && y == obstacles[i].y) {
                    printf("%c", obstacles[i].symbol);
                    printed = 1;
                    break;
                }
            }

            if (!printed) {
                if (x == car_x && y == car_y)
                    printf("V");
                else
                    printf(" ");
            }
        }

        printf("#\n");
    }

    for (int i = 0; i < ROAD_WIDTH + 2; i++) printf("#");
    printf("\nScore: %d\n", score);
}

// INPUT ---------------------------------------------------------
void input() {
    if (_kbhit()) {              // Check if a key was pressed
        char ch = _getch();      // Read it (non-blocking)
        switch (ch) {
            case 'a': case 'A':
                if (car_x > 0) car_x--;
                break;
            case 'd': case 'D':
                if (car_x < ROAD_WIDTH - 1) car_x++;
                break;
            case 'w': case 'W':
                if (car_y > 0) car_y--;
                break;
            case 's': case 'S':
                if (car_y < SCREEN_HEIGHT - 1) car_y++;
                break;
            case 'q': case 'Q':
                game_over = 1;
                break;
        }
    }
}

// LOGIC ---------------------------------------------------------
void logic() {
    for (int i = 0; i < MAX_OBSTACLES; i++) {

        // Collision BEFORE movement
        if (obstacles[i].x == car_x && obstacles[i].y == car_y) {
            game_over = 1;
            return;
        }

        obstacles[i].y++;

        // Collision AFTER movement
        if (obstacles[i].x == car_x && obstacles[i].y == car_y) {
            game_over = 1;
            return;
        }

        // Respawn obstacle
        if (obstacles[i].y >= SCREEN_HEIGHT) {
            score++;

            obstacles[i].x = rand() % ROAD_WIDTH;
            obstacles[i].y = 0;
            obstacles[i].symbol = '0' + (rand() % 10);

            if (score % 5 == 0 && game_speed > 25)
                game_speed -= 5;   // increase speed gradually
        }
    }
}
