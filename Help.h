/**
 * Provides the help dialouges that appear throughout the game.
 *
 * @author Joshua Decker
 * @version 1.00.01
 */

#pragma once
#include "Levels.h"

using namespace std;

class Help : public Levels
{
public:
    /*
     * Lots of work to do on this one, but you get the idea
     * For each level and place, offer help.
     * Maybe do this retroactively, after you have the game more fleshed out. 
     */
    
    void getHelp()
    {
        if(inCombat == true)
        {
            Writer::println("(You can choose to either attack, or flee.)");
        }
        else
        {
            if(Levels::level == 1)
            {
                if(placeCounter == 0)
                {
                    Writer::println("(Choose a direction.)");
                }
            }
        }
    }
};