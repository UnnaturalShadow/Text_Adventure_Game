/**
 * Designed to unify a lot of the different combat methods into a singular class
 *
 * @author Joshua Decker
 * @version 0.06.50
 */
#pragma once
#include <string>
#include "Writer.h"
#include "Levels.h"
#include "Enemy.h"
#include "Player.h"

class Combat : public Levels
{
private: 
    Player * player;
public:
    Combat(Player* p)
    : player(p)
    {
        
    }

    void newEncounter(Enemy enemy)
    {
        inCombat = true;
        player->updatePlayerHealth();
        player->setBasicAttackPower();
        Writer::println(to_string(player->getBasicAttack()));
        string nextAction;
        Writer::println("A " + enemy.getType() + " has appeared!");
        while(enemy.getHealth() > 0 && player->getHealth() > 0)
        {
             Writer::println(enemy.getName() + " has " + to_string(enemy.getHealth()) + " health remaining.");
             Writer::println("What would you like to do?");
            if(firstCombat == true)
            {
                Writer::println("(You can choose to either attack, or flee.)");
                firstCombat = false;
            }

            cin >> nextAction;
            if(nextAction == "attack" || nextAction == "Attack" || nextAction == "attack " || nextAction == "Attack " )
            {
                basicAttack(enemy);
            }

            if(nextAction == "flee" || nextAction == "Flee" || nextAction == "flee " || nextAction == "Flee ")
            {
                if(coinFlip() == 1)
                { 
                    break;
                }
            }
            
            if(nextAction == "pause" || nextAction == "Pause")
            {
                Writer::printSlow("Coward.");
                Wait::stall(3000);
                // Pause::pauseGame();
            }

            if((enemy.getHealth() < (enemy.getMaxHealth()/2)) && (player->getHealth() < (player->getMaxHealth()/2)))
            {
                if(rollDie(chanceToFlee) == chanceToFlee)
                {
                    Writer::println("The " + enemy.getName()  + " flees from before you.");
                    Wait::stall(567);
                    Writer::println("You got lucky that time.");
                    break;
                }

            }
            player->takeDamage(enemy.getPower());
            Writer::println(enemy.getName() + " deals " + to_string(enemy.getPower()) + " to you.");
        }

        if(player->getHealth() <= 0)
        {
            Writer::wipeScreen();
            Writer::println("You have been slain by " + enemy.getName() + ".");
            Wait::stall(3000);
            Writer::wipeScreen();
            Writer::println("GAME OVER");

        }

        if(enemy.getHealth() <= 0)
        {
             Writer::wipeScreen();
             Writer::println("Nicely done! You just slew " + enemy.getName() + ", a level " + to_string(enemy.getLevel()) + " " + enemy.getType());
            inCombat = false;
        }
    }

    void basicAttack(Enemy foe)
    {
        player->setBasicAttackPower();
        int damage = player->getBasicAttack();
        foe.takeDamage(damage);
         Writer::println("You use your basic attack on " + foe.getName() + ".");
         Writer::println("You deal " + to_string(player->getBasicAttack()) + " damage.");
        foe.takeDamage(player->getBasicAttack());

    }

    /**
     * Designed to pull all relevant information from weapons, armor, and the player that affects combat. 
     * Since combat extends levels, it shouldn't need any parameters(?).
     */
    // void checkForAttributes()
    // {
    //     if(weaponEquipped.equals(largeWoodenClub))
    //     {
    //         chanceToFlee = 6;
    //     }

        //check for weapon
            //checks weapon name; if theres an attribute to be applied
                //apply it

        //check for armor
            //Checks armor stats

        //check for player attributes
    // }

};
