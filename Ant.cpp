/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Ant.cpp, Ant Class Implementation
**                The ant class holds variables of the ant's location of row
**                and column and also the ant's direction (north, south east,
**                west). Methods are accessors and modifiers, and 2 functions to
**                turn the ant to the left (counter-clockwise) or right
**                (clockwise).
*********************************************************************/

#include "Ant.hpp"

//Constructors and Deconstructor
Ant::Ant()
{
  this->antRow = 0;
  this->antCol = 0;
  this->antDirection = 0; //north, starting direction
}

Ant::~Ant()
{

}

//Accessors
int Ant::getRow()
{
  return this->antRow;
}

int Ant::getCol()
{
  return this->antCol;
}

int Ant::getDirection()
{
  return this->antDirection;
}

//Modifiers
void Ant::setRow(int row)
{
  this->antRow = row;
}

void Ant::setCol(int col)
{
  this->antCol = col;
}

void Ant::setPosition(int row, int col)
{
  this->antRow = row;
  this->antCol = col;
}

void Ant::setDirection(int dir)
{
  this->antDirection = dir;
}

//Functions
void Ant::turnRight()
{
  //0 = North, 1 = East, 2 = South, 3 = West.
  if (this->antDirection == 3)
  {
    this->antDirection = 0;
  }
  else
  {
    this->antDirection += 1;
  }
}

void Ant::turnLeft()
{
  //0 = North, 1 = East, 2 = South, 3 = West.
  if (this->antDirection == 0)
  {
    this->antDirection = 3;
  }
  else
  {
    this->antDirection -= 1;
  }
}
