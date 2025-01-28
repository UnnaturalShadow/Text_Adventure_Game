#include "Player.h"
#include "Levels.h"
#include "Wait.h"
#include "Writer.h"
#include "Tutorial.h"
#include "LevelOne.h"
#include "Setup.h"

int main()
{
    Writer::testing = true;
    Player* player = new Player();
    Pause* pause = new Pause(player);
    SaveGame* save = new SaveGame(player);
    Setup setup = Setup(player, save);
    setup.runSetUp();
    if(!setup.savedGame())
    {
        Tutorial tutorial = Tutorial(player, pause);
        tutorial.runTutorial();
    }
    LevelOne one = LevelOne(player, pause, save);
    one.level01();

    return 0;
}