#include "Player.h"
#include "Levels.h"
#include "Wait.h"
#include "Writer.h"
#include "Tutorial.h"
#include "LevelOne.h"
#include "Setup.h"

int main()
{
    Writer::testing = false;
    // Writer::println("Hello world!");
    Player* player = new Player();
    Pause* pause = new Pause(player);
    SaveGame* save = new SaveGame(player);
    Setup setup = Setup(player, save);
    setup.runSetUp();
    Tutorial tutorial = Tutorial(player, pause);
    tutorial.runTutorial();
    LevelOne one = LevelOne(player, pause);
    one.level01();

    return 0;
}