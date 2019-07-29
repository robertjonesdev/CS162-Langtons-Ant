/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Board.cpp, Board Class Implementation
**                The board class holds a dynamic 2d-array of the game board.
**                setBoardSize: resizes the board for initialization.
**                getColor: accessor for the white/black color at a specific coordinate.
**                flipColor: method that changes a black space to white and white space to black.
**                printBoard: prints the entire board to the console.
**                moveAnt: method to move the ant in the direction it is pointed.
**                validateMove: method to handle edge cases and wrap the ant to
**                  the other side of the board.
*********************************************************************/

#include <iostream>
#include "Board.hpp"
#include "Ant.hpp"

//Constructors and Deconstructor
Board::Board()
{
  this->maxRows = 0;
  this->maxCols = 0;
}

Board::~Board()
{
  //Deallocate memory for the dynamic arrow.
  for (int i = 0; i < this->maxRows; i++)
  {
    delete [] this->arrMatrix[i];
  }
  delete [] this->arrMatrix;
  this->arrMatrix = nullptr;
}

//Modifiers
void Board::setBoardSize(const int numRows, const int numCols)
{
  //Dynamically allocate the 2d array for the board.
  this->maxRows = numRows;
  this->maxCols = numCols;
  this->arrMatrix = new int*[this->maxRows];
  for (int i = 0; i < this->maxRows; i++)
  {
    this->arrMatrix[i] = new int[this->maxCols];
  }

  //Initialize values of the board.
  for (int i = 0; i < this->maxRows; i++)
  {
    for (int j = 0; j < this->maxCols; j++)
    {
      this->arrMatrix[i][j] = 0;
    }
  }
}

//Accessors
int Board::getColor(int row, int col)
{
  return this->arrMatrix[row][col];
}

//Functions
void Board::flipColor(int row, int col)
{
  //Bitwise XOR operator. 0 will switch to 1, and 1 will switch to 0.
  //0 = White, 1 = Black
  this->arrMatrix[row][col] ^= 1;
}

/****************************************************************
** Function: Board::printBoard
** This function takes a pointer to an ant to know the ant's
** location and then prints the board to the console.
*****************************************************************/
void Board::printBoard(Ant* ant)
{
  //Print upper border.
  for (int i = 0; i < this->maxCols + 2; i++)
  {
    std::cout << '-';
  }
  std::cout << '\n';

  //Print contents
  for (int row = 0; row < this->maxRows; row++)
  {
    std::cout << '|';
    for (int col = 0; col < this->maxCols; col++)
    {
      if (row == ant->getRow() && col == ant->getCol())
      {
        std::cout << '*';
      }
      else
      {
        switch(this->arrMatrix[row][col])
        {
          case 0: //white space
            std::cout << ' ';
            break;
          case 1: //black space
            std::cout << '#';
            break;
        }
      }
    }
    std::cout << "|\n";
  }

  //Print lower border.
  for (int i = 0; i < this->maxCols + 2; i++)
  {
    std::cout << '-';
  }
  std::cout << std::endl;
}

/****************************************************************
** Function: Board::moveAnt
** Taking the parameter of a pointer to the ant, the function
** first gets the direction the ant is pointed. Then moves The
** ant forward in that direction. It calls validateRowMove() or
** validateColMove() for edge cases, then assigns the ant a new
** location. The ant's direction is changed based on the square
** color, and then the color is flipped (1 black/0 white).
*****************************************************************/
void Board::moveAnt(Ant* ant)
{
  //Get the ants direction and move it one space in that direction.
  switch(ant->getDirection())
  {
    case 0: //north
    {
      ant->setRow(validateRowMove(ant->getRow() - 1));
      break;
    }
    case 1: //east
    {
      ant->setCol(validateColMove(ant->getCol() + 1));
      break;
    }
    case 2: //south
    {
      ant->setRow(validateRowMove(ant->getRow() + 1));
      break;
    }
    case 3: //west
    {
      ant->setCol(validateColMove(ant->getCol() - 1));
      break;
    }
    default:
    {
      break;
    }
  }

  //Turn the ant based on the new space's color
  switch(this->getColor(ant->getRow(), ant->getCol()))
  {
    case 0: //When encountering a white space, turn the ant right.
    {
      ant->turnRight();
      break;
    }
    case 1: //When encountering a black space, turn the ant left.
    {
      ant->turnLeft();
      break;
    }
    default:
    {
      break;
    }
  }
  //Flip the color of the space.
  flipColor(ant->getRow(), ant->getCol());
}

/****************************************************************
** Function: Board::validateRowMove
** When the ant arraives at the western or eastern edge
** of the board, the function will effectively wrap the board
** around so the ant will appear on the opposite side.
*****************************************************************/
int Board::validateRowMove(int nextRow)
{
  int validatedRow = 0;
  if (nextRow >= this->maxRows)
  {
    validatedRow = 0;
  }
  else if (nextRow < 0)
  {
    validatedRow = this->maxRows-1;
  }
  else
  {
    validatedRow = nextRow;
  }
  return validatedRow;
}

/****************************************************************
** Function: Board::validateColMove
** When the ant arraives at the northern or southern edge
** of the board, the function will effectively wrap the board
** around so the ant will appear on the opposite side.
*****************************************************************/
int Board::validateColMove(int nextCol)
{
  int validatedCol = 0;
  if (nextCol >= this->maxCols)
  {
    validatedCol = 0;
  }
  else if (nextCol < 0)
  {
    validatedCol = this->maxCols-1;
  }
  else
  {
    validatedCol = nextCol;
  }
  return validatedCol;
}
