/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Game.hpp, Game Class Definition
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include "Ant.hpp"
#include "Board.hpp"

class Game
{
  private:
    const int BOARD_ROW_MAX = 100;
    const int BOARD_COL_MAX = 150;
    const int STEP_MAX = 20000;
    int numSteps;
    Ant ant;
    Board board;

    //Modifiers
    void setRandomStart();

    //Functions
    int getChoice(const int min, const int max);

  public:
    //Constructors and Deconstructor
    Game();
    virtual ~Game();

    //Functions
    void initialize();
    void startSimulation();
};

#endif
