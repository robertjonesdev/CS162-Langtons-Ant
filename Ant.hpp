/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Ant.hpp, Ant Class Definition
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
  private:
    int antRow;
    int antCol;
    int antDirection;

  public:
    Ant();
    virtual ~Ant();

    void setRow(int);
    void setCol(int);
    void setPosition(int, int);
    void setDirection(int);
    void turnRight();
    void turnLeft();
    int getRow();
    int getCol();
    int getDirection();
};

#endif
