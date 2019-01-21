/***************************************************************************
** Program name: ant.hpp
** Name:         Story Caplain
** Date:         01/14/19
** Description:  This is the implementation file for the ant class
***************************************************************************/
#ifndef ANT_HPP
#define ANT_HPP
#include <iostream>

class Ant {

private:

  int  antRow, antCol;
  char antDir;

public:

  void move(int, int, int**);

  int  getAntCol();

  void setAntCol(int);

  int  getAntRow();

  void setAntRow(int);

  char getAntDir();

  void setAntDir(char);

#endif
};
