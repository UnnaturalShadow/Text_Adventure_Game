
/**
 * Write a description of class Tutorial here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */

#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Levels.h"
#include "Player.h"
#include "Writer.h"
#include "Pause.h"
#include "Wait.h"

using namespace std;

class Tutorial : public Levels {
private:
    Player* player;
    Pause* pause;

public:
    Tutorial(Player* p, Pause* pa):player(p), pause(pa){}
    void runTutorial() {
        // Start place counter at 0
        Writer::print("Have you played (game name here) before? ");
        string playedBefore;
        cin >> playedBefore;

        if (playedBefore == "Yes" || playedBefore == "yes" || playedBefore == "Y" || playedBefore == "y") {
            placeCounter++; // Counter is now 1
            Writer::println("Excellent! Welcome back brave " + player->getType() + "!");
            Wait::stall(1500);
            Writer::print("Are you ready to begin? ");

            while (true) {
                string nextAction;
                cin >> nextAction;
                if (nextAction == "pause" || nextAction == "Pause") {
                    pause->pauseGame();
                } else if (nextAction == "Yes" || nextAction == "yes" || nextAction == "y" || nextAction == "Y") {
                    Writer::println("Excellent! Let's begin.");
                    break;
                } else {
                    Writer::println("That's too bad. Let's begin anyhow!");
                    break;
                }
            }
        } else {
            placeCounter++; // Counter is now 1
            Writer::println("Ah, a newcomer! Fear not, I will teach you everything you need to know.");
            Wait::stall(750);
            Writer::println("A few quick tips before we go any further:");
            Writer::println("    - For any yes or no questions, you can simply respond with \"y\" or \"n\"");
            Writer::println("    - If at any time you don't know what to do, simply type \"help\" and I will offer you guidance.");
            Wait::stall(750);
            cout << endl;
            Writer::print("Are you ready to begin? ");

            string yon;
            cin >> yon;
            if (yon == "Yes" || yon == "yes" || yon == "Y" || yon == "y") {
                placeCounter++; // Counter is now 2
                Writer::println("Excellent!");
            } else {
                placeCounter++; // Counter is now 2
                Writer::println("Too bad, I'm going to continue anyhow.");
            }

            Wait::stall(1000);
            cout << string(50, '\n'); // Clear screen
            placeCounter++; // Counter is now 3
            Writer::println("Your quest will progress in a mostly linear fashion.");
            Writer::println("Things will happen, and you will have to react, just as you have thus far.");
            Writer::println("There are some actions that are viable in practically all given situations:");
            Writer::println("    - Help: This option will give you additional guidance should you ever feel lost or confused.");
            Writer::println("    - Pause: This will open the pause menu, where you can explore character paths and manage your inventory.");
            Writer::print("    - Attack: Most things can be attacked, so you can attack most things. Use this power wisely. ");
            Wait::stall(1000);
            Writer::println("Or recklessly, it's fun either way.");
            Wait::stall(1000);
            Writer::println("    - You can navigate your environment by choosing a cardinal direction (such as North),");
            Writer::println("      or a regular one (such as forwards). Just know that sometimes forwards isn't North, and you might get yourself into a mess you hoped to avoid!");
            cout << endl;

            Writer::print("If you still don't know what you're doing, ");
            Wait::stall(987);
            Writer::println("don't worry.");
            Writer::println("I will continue to explain things as your quest progresses, and if you ever are lost, just type \"help\".");
            cout << endl;
            Writer::println("Are you ready to begin?");

            while (true) {
                string nextAction;
                cin >> nextAction;
                if (nextAction == "pause" || nextAction == "Pause") {
                    pause->pauseGame();
                } else if (nextAction == "Yes" || nextAction == "yes" || nextAction == "y" || nextAction == "Y") {
                    Writer::println("Excellent! Let's begin.");
                    break;
                } else {
                    Writer::println("That's too bad, I hope you catch on quickly! Let's begin.");
                    break;
                }
            }
        }
        Wait::stall(2500);
        cout << string(50, '\n'); // Clear screen
        level = 1;
    }
};