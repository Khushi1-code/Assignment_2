#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
/*for bg sound*/
#include <mmsystem.h>

/*to remove flicker*/
void clear_screen_fast()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

int start_menu()
{
    int choice = 0;
    while (1)
    {
        clear_screen_fast();
        printf("=== SIMPLE OBSTACLE GAME ===\n\n");
        printf("1. Start Game\n");
        printf("2. Exit\n\n");
        printf("Enter choice (1-2): ");
        char ch = getch();
        if (ch == '1')
            return 1;
        if (ch == '2')
            return 0;
    }
}

int main()
{
    system("color 4F");
    srand(time(0));

    int lives = 3;
    int score = 0;
    int x = 1;                    // player position (0 to 2)
    int step = 0;                 // obstacle vertical movement
    int obstaclePos = rand() % 3; // 0,1,2 lane

    while (1)
    {

        // ---- INPUT ----
        if (_kbhit())
        {
            char ch = getch();
            if (ch == 0 || ch == 224) // check for arrow key prefix
            {
                ch = getch(); // get actual arrow key code
                if (ch == 75 && x > 0)
                    x--; // LEFT arrow
                if (ch == 77 && x < 2)
                    x++; // RIGHT arrow
            }
        }

        // ---- DRAW ----
        // system("cls");
        clear_screen_fast();
        printf("|--- --- ---|\n");

        for (int i = 0; i < 10; i++)
        {
            if (i == step)
            {

                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);

                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);

                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);
            }
            else
            {
                printf("|           |\n");
            }
        }

        // ---- PLAYER ----
        if (x == 0)
            printf("| %c         |\n", 6);
        else if (x == 1)
            printf("|     %c     |\n", 6);
        else if (x == 2)
            printf("|        %c  |\n", 6);

        printf("\nScore: %d    Lives: %d\n", score, lives-1);

        // ---- COLLISION ----
        if (step == 10 && x == obstaclePos)
        {
            lives--;
            if (lives == 0)
            break; // Game over
            step = 0;
            obstaclePos = rand() % 3;
            continue; // Skip incrementing score on collision
        }

        Sleep(120);

        // Move obstacle down
        step++;

        // Reset when reaches bottom
        if (step > 10)
        {
            step = 0;
            obstaclePos = rand() % 3; // new lane
            score++;
        }
    }

    // ---- GAME OVER ----
    clear_screen_fast();
    printf("=== GAME OVER ===\n");
    printf("Press any key to return to menu...\n");
    getch();

    if (start_menu())
        main(); // Restart game
    return 0;
}
