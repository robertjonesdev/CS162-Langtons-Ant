/*********************************************************************
** Author:        Robert Jones
** Date:          January 7, 2019
** Description:   Menu.hpp, Menu Class Definition
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <vector>
#include <string>

class Menu
{
  private:
    bool quit;
    std::string menuTitle;
    std::vector<std::string> menuList;

  public:
    //Constructors and Deconstructor
    Menu(std::string menuTitle, std::vector<std::string> menuList);
    virtual ~Menu();

    //Accessors
    bool getQuit();

    //Modifiers
    void addOption(std::string strOption);
    void rmOption(int option);
    void changeTitle(std::string strTitle);

    //Functions
    void printMenu() const;
    int getChoice();
};

#endif
