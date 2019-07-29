/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Game.cpp, Game Class Implementation
**                First, call the initialize method, then call the
**                startSimulation method. Game object instantiates a Board
**                and Ant object. Initialize takes user input to set board
**                demensions, ant location, and number of steps. startSimulation
**                runs the ant simulation for the number of steps.
*********************************************************************/

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include "Game.hpp"
#include "Board.hpp"
#include "Ant.hpp"

//Constructors & Deconstructor
Game::Game()
{
  srand(time(NULL));
  this->numSteps = 0;
}

Game::~Game()
{

}

//Accessors

//Modifiers

//Functions

int Game::getChoice(const int min, const int max)
{
  //SOURCE CITATION: Adapted from the following tutorial:
  //Lesson 17: Data validation / Type checking with StringStream
  //http://beginnerscpp.com/lesson-17-data-validation-type-checking-with-stringstream/
  std::string strInput = "";
  int choice = 0;
  bool isValid = false;
  while (!isValid)
  {
    getline(std::cin, strInput);
    std::stringstream ss(strInput);
    if (ss >> choice && choice >= min && choice <= max)
    {
      isValid = true;
    }
    else
    {
      std::cout << "Invalid input. Re-enter choice: ";
    }
  }
  return choice;
}

void Game::initialize()
{
  int numRows = 0;
  int numCols = 0;
  int startRow = 0;
  int startCol = 0;
  //Console user input for size of the board.
  std::cout << "\nLangston's Ant Simulation - Setup" << std::endl;
  std::cout << "\nEnter the number of rows for the board (1 - " << BOARD_ROW_MAX << "): ";
  numRows = this->getChoice(1, BOARD_ROW_MAX);

  std::cout << "\nEnter the number of columns for the board (1 - " << BOARD_COL_MAX << "): ";
  numCols = this->getChoice(1, BOARD_COL_MAX);

  board.setBoardSize(numRows, numCols);

  std::cout << "\nEnter the number of steps during simulation (1 - " << STEP_MAX << "): ";
  this->numSteps = this->getChoice(1, STEP_MAX);

  //Bonus: Allow the option for a random location of the ant's start.
  std::cout << "\nWould you like a random starting row and column of the ant? (0 NO, 1 YES)\n";
  std::cout << "(Note: by selecting NO, user is allowed to input the starting row and column.): ";

  if (this->getChoice(0, 1))
  {
    startRow = rand() % numRows;
    startCol = rand() % numCols;
    std::cout << "The Ant will start at row " << startRow << " and column " << startCol << std::endl;
  }
  else
  {
    std::cout << "Enter the starting row of the ant (0 - " << numRows - 1 << "): ";
    startRow = this->getChoice(0, numRows - 1);
    std::cout << "Enter the starting column of the ant (0 - " << numCols - 1 << "): ";
    startCol = this->getChoice(0, numCols - 1);
  }
  ant.setPosition(startRow, startCol);
}

void Game::startSimulation()
{
  board.printBoard(&ant);
  for (int stepCount = 1; stepCount <= this->numSteps; stepCount++)
  {
    board.moveAnt(&ant);
    board.printBoard(&ant);
  }
}
