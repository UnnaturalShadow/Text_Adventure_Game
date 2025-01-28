#pragma once
#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include "Writer.h"
// #include "Weapon.h"
#include "WeaponInventory.h"

using namespace std;

class Levels
{
public:
    //long term progression variables(should be saved)
    int level = 0; 
    int placeCounter = 0;
    int timesSaved = 0;
    int deaths = 0;
    bool firstPause = true;
    bool firstCombat = true;
    string playerName = "";
    string playerType = "";

    int triedAttack = 0;
    bool inCombat = false;
    bool isWeaponEquipped;
    Weapon weaponEquipped = Weapon("Fists", "Fists", 0);
    Weapon* swordOfTheSouth = new Weapon("Sword of The South", "sword", 0);
    int chanceToFlee = 20;
    bool startFromSave = false;
    bool hasBeenHelped = false;

    

    int coinFlip() {
        srand(static_cast<unsigned>(std::time(nullptr)));
        int coin = std::rand() % 10; // Generate a random number between 0 and 9
        if (coin % 2 != 0) {
            return 1; // Odd
        } else {
            return 2; // Even
        }
    }

    int rollDie(int sides) {
        srand(static_cast<unsigned>(std::time(nullptr)));
        return std::rand() % sides + 1; // Generate a number between 1 and 'sides'
    }
    
    // void attackAir()
    // {
    //     if(triedAttack < 1)
    //     {
    //         if(wepInv.isWepOn() == true)
    //         {
    //             Writer.println("You swing " + wepInv.getWepInUse() + "wildly at the air. Much to your dismay, the air does not die. ");
    //         }
    //         Writer.println("You swing your fists wildly at the air. Much to your dismay, the air does not die.");
    //         triedAttack++;
    //     }
    //     else
    //     {
    //         Writer.println("You already tried that silly!");
    //     }
    // }

};

/*
                       \jjjjjj|     jjj|                                              /dddddddddd|      
                        \jjjjj|     jjj|                                             dddddddddddd|
                         jjjjj|     jjj|                            _               ddddd/
                         jjjjj|     jjj|                           &&&             ddddd/
                         jjjjj|     jjj|                          }} {{           ddddd/
                         jjjjj|     jjj|                         ]]   [[         ddddd/
       \\\\             jjjjj/      jjj|                        <|     |>       ddddd|
        \\\\           jjjjj/       jjj|                         ]]   [[       dddddd|
         \\\\         jjjjj/        jjj|                          }} {{       ddddddd|
          \\\\       jjjjj/         jjj|                           &&&        ddddddd|
           ----     jjjjj/          jjj|                            !         ddddddd|
                   jjjjj/           jjj|                            @          ddddddd\
                  jjjjj/            jjj|                            #           ddddddd\
                 jjjjj/             jjj|                            $            ddddddd|
                jjjjj/              jjj|                            %            ddddddd/
               jjjjj/               jjj|                                        ddddddd/
              jjjjj/                                      ____                 ddddddd/
             jjjjj/                 /\\\                  dddd\              /ddddddd/
 __________/jjjjj/                 //M\\\                 ddddd\____________/ddddddd/
 \jjjjjjjjjjjjjj/                  \\V///                  dddddddddddddddddddddddd/
  \jjjjjjjjjjjj/                    \///                    dddddddddddddddddddddd/
                        


*/