/**
 * What you need to pause the game.
 *
 * @author Joshua Decker
 * @version 1.01.07
 */
#pragma once
#include "Writer.h"
#include "Levels.h"
#include "Player.h"

using namespace std;

class Pause : public Levels
{
private:
    string pauseAction;
    Player* player;
    
public: 

    Pause(Player* p)
    :player(p)
    {

    }

    void pauseGame()
    {
        bool checkForMain = false;
        while(true)
        { 
            if(checkForMain == false)
            {
                printMain();
                checkForMain = true;
            }
            if(firstPause)
            {
                Writer::println("What would you like to do now?");
                Writer::println("(Type \"resume\" to resume)");
                Writer::println("(Type \"inventory\" to view your inventory)");
                firstPause = false;
            }
            else
            {
                Writer::println("What would you like to do now? ");
            }
            cin >> pauseAction;
            if(pauseAction == "Resume" || pauseAction == "resume" || pauseAction == "play" || pauseAction == "Play")
            {
                break;
            }
            else if(pauseAction == "Inventory" || pauseAction == "inventory")
            {
                borders();
                // Writer::println("|" + toString(wepInv));        Inventories not defined yet. Will be hosted in PlayGame and passed through constructor.
                // Writer::println("|" + toString(armInt));
                borders();
            }
            else
            {
                break;
            }
        }
        Wait::stall(1000);
        Writer::wipeScreen();
        
        // findResume();
        /*
         * Okay, hear me out. What if, you built these control structures directly into the levels. So that instead of having this massive pause function
         * you can just have your loop and your break. Ideally, you would only wipe the pause menu, but life isn't perfect and neither is Java.
         * 
         */
        
    }

    //I want to rework this monster of if statements into a "pulls last line of text and reprints it type thing, which seems doable."
    
    // private static void findResume()
    // {
    //     if(level == 0)
    //     {
    //         if(placeCounter >= 3) //You'll need an && for the upper bound too. 
    //         {
    //             Writer::printlnJava("Your quest will progress in mostly linear fashion.");
    //             Writer::printlnJava("Things will happen, and you will have to react, just as you have thus far.");
    //             Writer::printlnJava("There are some actions that are viable in practically all given situations:");
    //             Writer::printlnJava("    - Help: This aforementioned option will give you additional guidance should you ever feel lost or confused.");
    //             Writer::printlnJava("    - Pause: This will open the pause menu, from which you can explore character paths and manage your inventory.");
    //             Writer::printlnJava("    - Attack: Most things can be attacked, so you can attack most things. Use this power wisely. Or recklessly, it's fun either way.");
    //             Writer::printlnJava();
    //             Writer::printlnJava("If you still don't know what you're doing, don't worry.");
    //             Writer::printlnJava("I will continue to explain things as your quest progresses, and if you ever are lost, just type \"help\"");
    //             Writer::printlnJava();
    //             Writer::printlnJava("Are you ready to begin?");
    //         }
    //     }
    //     if(level == 1)
    //     {
    //         if(placeCounter == 0)
    //         {
    //             Writer::printlnJava("Brave " + player.getType() + ", your quest begins here, in the town of Lithonia.");
    //             Writer::printlnJava("This land was once prosperous, until 17 years ago when the war began...");
    //             Writer::printlnJava("Our once great King, Rohan Sarikir IV, fought valiently but was slain by (insert dramatic enemy here).");
    //             Writer::printlnJava("Since then, the whole kingdom has fallen into disarray.");
    //             Writer::printlnJava("(Enemy) has taken over, roads and infrastructre have crumbled, and nefarious creatures of all sorts roam the land.");
    //             Writer::printlnJava("I wonder what adventures await you, brave " + player.getType() + "...");
    //             Writer::printlnJava();
    //             Writer::printlnJava("You stand alone on the outskirts of town.");
    //             Writer::printlnJava("To the North lies the heart of the village, with all its shops and merchants.");
    //             Writer::printlnJava("To the East you can see the town hall, it's marble pillars cracked and faded. It looks like it's empty.");
    //             Writer::printlnJava("To the West there is naught but the vast Arcadian Sea, sparkling beautifuly in the setting sun.");
    //             Writer::printlnJava("To the South there is a long winding path...");
    //             Writer::printlnJava();
    //             System.out.print("What do you choose to do?");
    //         }
    //     }
    // }

    void printMain()
    {
        borders();
        Writer::printlnJava(player->toString());
        Writer::printlnJava("You have " + to_string(player->getWealth()) + " gold coins.");
    

        //System.out.println("Inventory: " + inventory.getHowFull() + "/" + inventory.getCapacity());
        //I should probably make an inventory object. 
        //And item objects...
        //Thats a lot of work.
        
        
        //Eventually we will need skill tree/level path options.
        //Maybe a quest line history or map thingy
        //Inventory
        //Yeah, lots of cool stuff.
        //But first we need to find a way to resume at the right point.
        borders();
    }

    /**
     * Literally just prints this : <--------------------------------------------------------->
     */
    void borders()
    {
        Writer::printlnJava("<--------------------------------------------------------->");
    }

};