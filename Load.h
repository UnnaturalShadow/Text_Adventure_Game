/**
 * The Load class consists of only one method, and its sole purpose is to generate a loading dialouge for a given number of seconds.
 * For the purposes of my game, it is completely unecessary; nothing is complex enough to necessitate load times.
 * But it was still a fun thing to add. 
 *
 * @author Joshua Decker
 * @version 1.20.00
 */

#pragma once
#include "Writer.h"
class Load
{
    //Really long method that prints a loading dialogue for a given number of seconds(roughly accurate), even though we never actually need to load.
public:
    void loading(int time)
    {
        //write.prints "Loading..."
        Writer::print("Loading...");
        
        //Waits 0.5 seconds
        Wait::stall(500);
        
        //The actual ..., delete ... portion. Repeats for however many seconds, minus one for the earlier dealys in the startup.
        //There's a lot in here, but essentially it has two parts. One desletes the dots, the other retypes them, and theres the associated delays.
        for(int t = 0; t < (time - 1); t++)
        {
            Writer::wipeScreen();
            Writer::printJava("Loading");
            Writer::printSlow("...");
            
            Wait::stall(550);
        }
        //Wipes the loading line
        Writer::wipeScreen();
        
        //Waits 3/4 of a second. 
        Wait::stall(750);
        
        //write.prints "Loading complete!"
        Writer::print("Loading complete!");
        
        //Waits about 3.5 seconds.
        Wait::stall(2500);
        
        //Clears all text 
        Writer::wipeScreen();
    }
};