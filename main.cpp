/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Main.cpp: The program implements Langton's Ant Simulation
**                that moves an ant around a board, by predefined rules,
**                changing the board color from white to black or black to white.
**                The proram begins (and loops) in a menu state that allows for
**                consecutive game play or exiting the program.
*********************************************************************/

#include <vector>
#include <string>
#include <iostream>
#include "Menu.hpp"
#include "Game.hpp"

int main()
{
  std::cout << "\nExtra credit (random start) included." << std::endl;

  std::string menuTitle = "    --- MENU ---";

  std::vector<std::string> menuList;
  menuList.push_back("Start Langton's Ant simulation");

  Menu menu(menuTitle, menuList);

  while (!menu.getQuit())
  {
    menu.printMenu();
    switch (menu.getChoice())
    {
      case 1:
      {
        Game game;
        game.initialize();
        game.startSimulation();
        break;
      }
    }
  }
  return 0;
}
