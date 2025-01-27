/**
 * The first level you play. 
 *
 * @author Joshua Decker
 * @version 0.02.12
 */
#pragma once
#include "Levels.h"
#include "Player.h"
#include "Combat.h"

using namespace std;

class LevelOne : public Levels
{
public:
    string nextAction;
    bool haveYouGoneSouth = false;
    bool optionNorth = false;
    bool optionSouth = false;
    bool optionEast = false;
    bool optionWest = false;
    Player* player;
    Combat* fight;
    Pause* pause;

    LevelOne(Player* p, Pause* pa)
    :player(p), pause(pa)
    {
        fight = new Combat(player);
    }

    void level01()
    {
        placeCounter = 0;
        level = 1;
        if(placeCounter == 0)
        {
            intro();
            firstChoice();
        }
        
        if(placeCounter == 1)
        {
            directionalEncounters();
        }
        
        
        level = 2;
    }

    void intro()
    {
        Writer::println("Brave " + player->getType() + ", your quest begins here, in the town of Lithonia.");
        Wait::stall(1000);
        Writer::print("This land was once prosperous, ");
        Wait::stall(345);
        Writer::println("until 17 years ago when the war began...");
        Wait::stall(1234);
        Writer::print("Our once great King, ");
        Wait::stall(345);
        Writer::print("Rohan Sarikir IV, ");
        Wait::stall(345);
        Writer::println("fought valiently but was slain by (insert dramatic enemy here).");
        Wait::stall(1000);
        Writer::println("Since then, the whole kingdom has fallen into disarray.");
        Wait::stall(345);
        Writer::print("(Enemy) has taken over, ");
        Wait::stall(345);
        Writer::print("roads and infrastructre have crumbled, ");
        Wait::stall(345);
        Writer::println("and nefarious creatures of all sorts roam the land.");
        Wait::stall(1000);
        Writer::println("I wonder what adventures await you, brave " + player->getType() + "...");
        Writer::printlnJava("");
    }

    void firstChoice()
    {
        if(haveYouGoneSouth == false)
        {
            placeCounter = 0;
        }
        

        Wait::stall(2000);
        Writer::println("You stand alone on the outskirts of town.");
        Wait::stall(1000);
        Writer::println("To the North lies the heart of the village, with all its shops and merchants.");
        Wait::stall(1000);
        Writer::print("To the East you can see the town hall, it's marble pillars cracked and faded. ");
        Wait::stall(456);
        Writer::println("It looks like it's empty.");
        Wait::stall(1000);
        Writer::println("To the West there is naught but the vast Arcadian Sea, sparkling beautifuly in the setting sun.");
        Wait::stall(1000);
        if(haveYouGoneSouth == false)
        {
            Writer::println("To the South there is a long winding path...");
        }
        else
        {
            Writer::print("To the South there is a long winding path... ");
            Wait::stall(345);
            Writer::println(" but you've already been that way.");
        }
        
        Wait::stall(1000);
        Writer::printlnJava("");
        Writer::print("What do you choose to do? ");
        
        int timesTriedSouth = 0;
        while(true)
        {
            
            cin >> nextAction;
            if(nextAction == "pause" || nextAction == "Pause")
            {
                pause->pauseGame();
            }
            if(nextAction == "Help" || nextAction == "help")
            {
                // Help.getHelp();
            }
            else if(nextAction == "North" || nextAction == "north" || nextAction == "Go North" || nextAction == "go North" || nextAction == "go north" || nextAction == "Go north" || nextAction == "n")
            {
                optionNorth = true;
                placeCounter++;
                break;
            }
            else if(nextAction == "South" || nextAction == "south" || nextAction == "Go South" || nextAction == "go South" || nextAction == "go south" || nextAction == "Go south" || nextAction == "s")
            {
                timesTriedSouth++;
                if(haveYouGoneSouth == false)
                {
                    optionSouth = true;
                    placeCounter++;
                    break;
                }
                if(timesTriedSouth > 10)
                {
                    Writer::println("You know what. Screw you.");
                    player->updatePlayerHealth();
                    player->takeDamage(player->getHealth());
                    Writer::println("The narrator deals " + to_string(player->getHealth()) + " damage to you, cause you're a jerk.");
                    Writer::println("You have died.");
                    Wait::stall(5000);
                    Writer::wipeScreen();
                    Writer::printlnJava("GAME OVER");
                    break;
                }
                else if(haveYouGoneSouth == true && timesTriedSouth < 2)
                {
                    Writer::println("You've already been that way.");
                    if(timesTriedSouth == 1)
                    {
                        Writer::println("Please don't try to go that way again.");
                    }
                } 
            }

            else if(nextAction == "East" || nextAction == "go east")
            {
                optionEast = true;
                placeCounter++;
                break;
            }
            else if(nextAction == "West" || nextAction == "west" || nextAction == "Go West" || nextAction == "go West" || nextAction == "go west" || nextAction == "Go west")
            {
                Writer::println("Are you certain you want to walk into the sea? ");
                cin >> nextAction;
                if(nextAction == "y" || nextAction == "Y" || nextAction == "Yes" || nextAction == "yes")
                {
                    Writer::print("You walk off majestically into the sunset, ");
                    Wait::stall(345);
                    Writer::println("and directly into the ocean, drowning yourself.");
                    Wait::stall(3500);
                    Writer::wipeScreen();
                    Writer::printlnJava("GAME OVER");
                    break;     
                
                }
            }
            else if(nextAction == "Attack" || nextAction == "attack")
            {
                // attackAir();
                // This needs to be roped into combat
                
            }
            else if(nextAction == "Save" || nextAction == "save")
            {
                // SaveGame.newSave(player, level, placeCounter, timesSaved);
                Wait::stall(1000);

            }
            else if(nextAction == "Resume" || nextAction == "resume")
            {
                Writer::println("Your game is not paused.");
            }
            else
            {
                Writer::println("That is not something you can do right now, please try again");
            }
        }
    }

    void directionalEncounters()
    {
        if(optionNorth == true)
        {
            theNorthernVillage();
        }

        if(optionEast == true)
        {
            Wait::stall(789);
            Writer::wipeScreen();
            Wait::stall(678);
            Writer::println("It's really an awful building, isn't it?");
            Wait::stall(456);
            Writer::println("All old and decrepit, it looks like it could collapse at any moment.");
            Wait::stall(456);
            Writer::println("You catch, out of the corner of your eye, something shifting in the shadows...");
            Wait::stall(567);
            if(isWeaponEquipped == true)
            {
                // Writer::println("You brandish your " + to_string(weaponEquipped.getType()) + " and step towards the darkness.");
            }
            else
            {
                Writer::println("You raise your fists and step further into the darkness.");
            }
            Wait::stall(678);
            


        }

        if(optionSouth == true && haveYouGoneSouth == false)
        {
            haveYouGoneSouth = true;
            placeCounter++;
            // swordOfTheSouth.setLevel(player->getLevel());
            Writer::wipeScreen();
            Writer::println("You notice a rusted piece of metal lodged in an aging stump...");
            Wait::stall(789);
            Writer::println("Do you want to pick it up? ");
            
            cin >> nextAction;

            if(nextAction == "yes" || nextAction == "y")
            {
                Wait::stall(345);
                // wepInv.addWeapon(swordOfTheSouth);
                Writer::printlnJava("");
                Wait::stall(789);
                Writer::println("You've found a sword!");
                Wait::stall(345);
                Writer::println("That blade looks strangely familiar... ");
                Wait::stall(789);
                Writer::println("It reminds of a sword our great King once carried. ");
                Wait::stall(789);
                Writer::printlnJava("");
                Writer::println("You best hold onto that blade.");
                Wait::stall(2000);
                // wepInv.equipWeapon(swordOfTheSouth);
            }
            
            Wait::stall(2500);
            Writer::printlnJava("");

            Enemy goblin = Enemy("Goblin", "monster", player->getLevel());
            fight->newEncounter(goblin);
            Wait::stall(2000);
            Writer::wipeScreen();
            firstChoice();

        }
    }

    void theNorthernVillage()
    {
        Writer::wipeScreen();
        Wait::stall(789);
        Writer::println("You walk into the town center...");
        Wait::stall(789);
        Writer::print("The gentle shuffle of people going about their day, ");
        Wait::stall(345);
        Writer::print("the scents, ");
        Wait::stall(345);
        Writer::print("the sights, ");
        Wait::stall(345);
        Writer::println("and sounds, all seem so peaceful, almost drearily so.");
        Wait::stall(789);
        Writer::printlnJava("");

    }
};
