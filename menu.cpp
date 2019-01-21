/***************************************************************************
** Program name: menu.cpp
** Name:         Story Caplain
** Date:         01/08/19
** Description:  This .cpp file is an easily modifiable menu function.
***************************************************************************/
#include "menu.hpp"
#include <iostream>

int menu() {

  //if int check remains 0 user does not want to play, else if 1, they do.
  int check = 0;

  //typing p will start the game.
  char play;
  std::cout << "\nHello! Would you like to play Langton's Ant?\n" <<
               "Enter p to play or press any other key to quit: ";
  std::cin >> play;
  
  //if anything besides p or P, dont play
  if(std::cin.fail() || ((play != 'p')&&(play != 'P'))) {
    check = 0;
  }
  //if p or P, play
  else if(play == 'p' || play == 'P') {
    check = 1;
  }

  //return a 0 or a 1
  return check;
}
