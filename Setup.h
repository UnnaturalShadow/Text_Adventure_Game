#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Writer.h"
#include "Wait.h"
#include "SaveGame.h"
#include "Player.h"

using namespace std;


class Setup : public Levels{
private:
    bool startFromSave;
    int level;
    int placeCounter;
    int timesSaved;
    Player* player;
    SaveGame* save;

public:
    Setup(Player* p, SaveGame* s): player(p), save(s){}

    void runSetUp() {
        Writer::println("Would you like to load from a save?");
        string nextAction;
        getline(cin, nextAction);

        if (nextAction == "Yes" || nextAction == "yes" || nextAction == "y" || nextAction == "Y") {
            startFromSave = true;
            string loadingSave = save->findSave();
            save->pullInfo(loadingSave);
            level = save->getLevel();
            placeCounter = save->getPlace();
            timesSaved = save->getNumSaves();
            player->setName(save->getPlayerName());
            player->setPlayerClass(save->getPlayerType());
            player->setLevel(save->getPlayerLevel());
            player->setWealth(save->getPlayerGold());
            cout << player->toString() << endl;

            // Clear screen (platform-specific implementation may be needed)
            Writer::wipeScreen();
        } else {
            // Clear screen
            Writer::wipeScreen();

            // Type-prints a greeting
            Writer::println("Hello, and welcome to Ikarris!");
            
            // Wait 1 second
            Wait::stall(1000);

            // Type-prints asking for name
            Writer::print("What is your name? ");
            
            // Input takes name
            string name;
            getline(cin, name);

            if (name == "skip") {
                startFromSave = true;
            } else {
                // Generate a player object giving it the inputted name
                player->setName(name);
                player->setLevel(1);

                // Type-prints personalized greeting
                Writer::println("Hello " + player->getName() + "!");
                
                // Waits 1.5 seconds
                Wait::stall(1500);

                // Type-prints intro
                Writer::println("Welcome to a world of wonder and adventure! Your quest will begin shortly...");
                
                // Waits 1.5 seconds
                Wait::stall(1500);

                // Type-prints question intro
                Writer::print("But first, we have one more question for you: ");
                
                // Waits 2.5 seconds
                Wait::stall(2500);

                // Type-print the class options with dramatic pauses
                Writer::print("Would you like to be a Wizard");
                Wait::stall(750);
                Writer::print(", a Soldier");
                Wait::stall(750);
                Writer::print(", or an Adventurer? ");

                // Takes the user input for what class they would like to be
                string playerClass;
                getline(cin, playerClass);
                player->setPlayerClass(playerClass);

                // Welcomes them to their class, confirming they are in the right class
                if (player->getType() == "Wizard") {
                    Writer::println("Excellent choice! It is my great pleasure to welcome you to the Wizards' Guild!");
                } else if (player->getType() == "Soldier") {
                    Writer::println("A bold decision! The King commends your bravery and thanks you for your service!");
                } else {
                    Writer::println("An Adventurer eh? You've got quite the journey ahead of you, I wish you the best of luck!");
                }

                Wait::stall(2500);
                Writer::println("Your quest begins... ");
                Wait::stall(750);
                Writer::print("Now!");
                Wait::stall(2000);

                // Clear screen
                Writer::wipeScreen();
            }
        }
    }

    bool savedGame()
    {
        return startFromSave;
    }
};