#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <raylib.h>

#include "timer.hpp"

int main()
{
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int ms = 0;
    bool isRunning = false;
    bool spacePressedLastFrame = false;  // Track space key state across frames
    Timer timer;
    std::string secondsString;
    std::string minutesString;
    std::string timerString;
    std::string msString;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 600, "Timer");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Check if space key is pressed
        bool spacePressed = IsKeyDown(KEY_SPACE);

        // Check if space key was pressed in this frame and wasn't pressed in the last frame
        if (spacePressed && !spacePressedLastFrame)
        {
            if (isRunning)
            {
                timer.stop();
                isRunning = false;
            }
            else
            {
                timer.start();
                isRunning = true;
            }
        }

        // Check if backspace key is pressed
        if (IsKeyDown(KEY_BACKSPACE))
        {
            hours = 0;
            minutes = 0;
            seconds = 0;
            timer.resetMilliseconds(ms);
            isRunning = false;
        }

        spacePressedLastFrame = spacePressed;  // Update space key state for the next frame

        ms = timer.elapsedMilliseconds();

        if (ms > 999)
        {
            timer.resetMilliseconds(ms);
            seconds++;
        }

        if (ms == 0)
        {
            msString = "000";
        }
        else
        {
            msString = std::to_string(ms);
        }

        if (seconds > 59)
        {
            seconds = 0;
            minutes++;
        }

        if (minutes > 59)
        {
            minutes = 0;
            hours++;
        }

        if (seconds > 9)
        {
            secondsString = std::to_string(seconds);
        }
        else
        {
            secondsString = "0" + std::to_string(seconds);
        }

        if (minutes > 9)
        {
            minutesString = std::to_string(minutes);
        }
        else
        {
            minutesString = "0" + std::to_string(minutes);
        }

        if (hours > 0)
        {
            timerString = std::to_string(hours) + ":" + minutesString + ":" + secondsString + "." + msString;
        }
        else
        {
            timerString = minutesString + ":" + secondsString + "." + msString;
        }

        BeginDrawing();
        ClearBackground(WHITE);
        int drawWidth = (GetScreenWidth() - MeasureText(timerString.c_str(), 20)) / 2;
        DrawText(timerString.c_str(), drawWidth, 300, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
