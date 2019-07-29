/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Board.hpp, Board Class Definition
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

class Board
{
  private:
    int maxRows;
    int maxCols;
    int** arrMatrix = nullptr;

    //Private Functions
    int getColor(int, int);
    void flipColor(int, int);
    int validateRowMove(int);
    int validateColMove(int);

  public:
    //Constructors and Deconstructor
    Board();
    virtual ~Board();

    //Modifiers
    void setBoardSize(const int, const int);

    //Functions
    void printBoard(Ant* ant);
    void moveAnt(Ant* ant);
};
#endif
