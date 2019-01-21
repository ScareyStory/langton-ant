/***************************************************************************
** Program name: ant.cpp
** Name:         Story Caplain
** Date:         01/14/19
** Description:  This program keeps track of an "ant" on a gameboard and
**               updates the gameboard based on where the ant moves and
**               what kind of tile the ant lands on.
***************************************************************************/
#include <iostream>
#include "Ant.hpp"

int Ant::getAntRow() {
  return antRow;
}

void Ant::setAntRow(int rowInput) {
  antRow = rowInput;
}

int Ant::getAntCol() {
  return antCol;
}

void Ant::setAntCol(int colInput) {
  antCol = colInput;
}

char Ant::getAntDir() {
  return antDir;
}

void Ant::setAntDir(char dirInput) {
  antDir = dirInput;
}

void Ant::move(int cols, int rows, int **gboard) {
   
  char dir   = getAntDir();
  int rowPos = getAntRow();
  int colPos = getAntCol();

  switch (dir) {

    case 'n':

      if(((gboard[rowPos][colPos]) == 0) && rowPos != 0) {
        (gboard[rowPos][colPos]) = 1; //if 0 & not at top, flip to 1, go up
        rowPos--; //go up
        if((gboard[rowPos][colPos]) == 0 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 0 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 0 and at right side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != 0) {
          dir = 'w'; //if tile is 1 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == 0) {
          dir = 'e'; //if tile is 1 and not at left side of board go right 
        }
      }

      else if(((gboard[rowPos][colPos]) == 1) && rowPos != 0) {
        (gboard[rowPos][colPos]) = 0; //if 1 & not at top, flip to 0, go up
        rowPos--; //go up
        if((gboard[rowPos][colPos]) == 0 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 0 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 0 and at right side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != 0) {
          dir = 'w'; //if tile is 1 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == 0) {
          dir = 'e'; //if tile is 1 and not at left side of board go right 
        }
      }

      else if(((gboard[rowPos][colPos]) == 0) && rowPos == 0) {
        (gboard[rowPos][colPos]) = 1; //if 0 & at top, flip to 1, go down
        rowPos++; //go down
        if((gboard[rowPos][colPos]) == 0 && colPos != 0) {
          dir = 'w'; //if tile is 0 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == 0) {
          dir = 'e'; //if tile is 0 and at left side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 1 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 1 and at right side of board go left 
        }
      }
      
      else if(((gboard[rowPos][colPos]) == 1) && rowPos == 0) {
        (gboard[rowPos][colPos]) = 0; //if 1 & at top, flip to 0, go down
        rowPos++; //go down
        if((gboard[rowPos][colPos]) == 0 && colPos != 0) {
          dir = 'w'; //if tile is 0 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == 0) {
          dir = 'e'; //if tile is 0 and at left side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 1 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 1 and at right side of board go left 
        }
      }
      break;

    case 'w':

      if(((gboard[rowPos][colPos]) == 0) && colPos != 0) {
        (gboard[rowPos][colPos]) = 1; //if 0 & not at edge, flip to 1
        colPos--; //go left
        if((gboard[rowPos][colPos]) == 0 && rowPos != 0) {
          dir = 'n'; //if tile is 0 and not at top of board go up
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == 0) {
          dir = 's'; //if tile is 0 and at top of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 1 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 1 and at bottom of board go up 
        }
      }

      else if(((gboard[rowPos][colPos]) == 1) && colPos != 0) {
        (gboard[rowPos][colPos]) = 0; //if 1 & not at edge, flip to 0
        colPos--; //go left
        if((gboard[rowPos][colPos]) == 0 && rowPos != 0) {
          dir = 'n'; //if tile is 0 and not at top of board go up
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == 0) {
          dir = 's'; //if tile is 0 and at top of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 1 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 1 and at bottom of board go up 
        }
      }

      else if(((gboard[rowPos][colPos]) == 0) && colPos == 0) {
        (gboard[rowPos][colPos]) = 1; //if 0 & at edge, flip to 1
        colPos++; //go right
        if((gboard[rowPos][colPos]) == 0 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 0 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 0 and at bottom of board go up
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos != 0) {
          dir = 'n'; //if tile is 1 and not at top of board go up
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == 0) {
          dir = 's'; //if tile is 1 and at top of board go down
        }
      }
      
      else if(((gboard[rowPos][colPos]) == 1) && colPos == 0) {
        (gboard[rowPos][colPos]) = 0; //if 1 & at edge, flip to 0
        colPos++; //go right
        if((gboard[rowPos][colPos]) == 0 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 0 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 0 and at bottom of board go up
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos != 0) {
          dir = 'n'; //if tile is 1 and not at top of board go up
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == 0) {
          dir = 's'; //if tile is 1 and at top of board go down
        }
      }
      break;

    case 'e':

      if(((gboard[rowPos][colPos]) == 0) && colPos != (cols-1)) {
        (gboard[rowPos][colPos]) = 1; //if 0 & not at edge, flip to 1
        colPos++; //go right
        if((gboard[rowPos][colPos]) == 1 && rowPos != 0) {
          dir = 'n'; //if tile is 1 and not at top of board go up
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == 0) {
          dir = 's'; //if tile is 1 and at top of board go down
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 0 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 0 and at bottom of board go up 
        }
      }

      else if(((gboard[rowPos][colPos]) == 1) && colPos != (cols-1)) {
        (gboard[rowPos][colPos]) = 0; //if 1 & not at edge, flip to 0
        colPos++; //go right
        if((gboard[rowPos][colPos]) == 1 && rowPos != 0) {
          dir = 'n'; //if tile is 1 and not at top of board go up
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == 0) {
          dir = 's'; //if tile is 1 and at top of board go down
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 0 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 0 and at bottom of board go up 
        }
      }

      else if(((gboard[rowPos][colPos]) == 0) && colPos == (cols-1)) {
        (gboard[rowPos][colPos]) = 1; //if 0 & at edge, flip to 1
        colPos--; //go left
        if((gboard[rowPos][colPos]) == 0 && rowPos != 0) {
          dir = 'n'; //if tile is 0 and not top of board go up
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == 0) {
          dir = 's'; //if tile is 0 and at top of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 1 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 1 and at bottom of board go up
        }
      }
      
      else if(((gboard[rowPos][colPos]) == 1) && colPos == (cols-1)) {
        (gboard[rowPos][colPos]) = 0; //if 1 & at edge, flip to 0
        colPos--; //go left
        if((gboard[rowPos][colPos]) == 0 && rowPos != 0) {
          dir = 'n'; //if tile is 0 and not at top of board go up
        }
        else if((gboard[rowPos][colPos]) == 0 && rowPos == 0) {
          dir = 's'; //if tile is 0 and at top of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos != (rows-1)) {
          dir = 's'; //if tile is 1 and not at bottom of board go down
        }
        else if((gboard[rowPos][colPos]) == 1 && rowPos == (rows-1)) {
          dir = 'n'; //if tile is 1 and at bottom of board go up
        }
      }
      break;
    
    case 's':
      
      if(((gboard[rowPos][colPos]) == 0) && rowPos != (rows-1)) {
        (gboard[rowPos][colPos]) = 1; //if 0 & not at bottom, flip to 1
        rowPos++; //go down
        if((gboard[rowPos][colPos]) == 0 && colPos != 0) {
          dir = 'w'; //if tile is 0 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == 0) {
          dir = 'e'; //if tile is 0 and at left side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 1 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 1 and at right side of board go left 
        }
      }

      else if(((gboard[rowPos][colPos]) == 1) && rowPos != (rows-1)) {
        (gboard[rowPos][colPos]) = 0; //if 1 & not at bottom, flip to 0
        rowPos++; //go down
        if((gboard[rowPos][colPos]) == 0 && colPos != 0) {
          dir = 'w'; //if tile is 0 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == 0) {
          dir = 'e'; //if tile is 0 and at left side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 1 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 1 and at right side of board go left 
        }
      }

      else if(((gboard[rowPos][colPos]) == 0) && rowPos == (rows-1)) {
        (gboard[rowPos][colPos]) = 1; //if 0 & at bottom, flip to 1
        rowPos--; //go up
        if((gboard[rowPos][colPos]) == 0 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 0 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 0 and at right side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != 0) {
          dir = 'w'; //if tile is 1 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == 0) {
          dir = 'e'; //if tile is 1 and at left side of board go right 
        }
      }
      
      else if(((gboard[rowPos][colPos]) == 1) && rowPos == (rows-1)) {
        (gboard[rowPos][colPos]) = 0; //if 0 & at bottom, flip to 1
        rowPos--; //go up
        if((gboard[rowPos][colPos]) == 0 && colPos != (cols-1)) {
          dir = 'e'; //if tile is 0 and not at right side of board go right
        }
        else if((gboard[rowPos][colPos]) == 0 && colPos == (cols-1)) {
          dir = 'w'; //if tile is 0 and at right side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos != 0) {
          dir = 'w'; //if tile is 1 and not at left side of board go left
        }
        else if((gboard[rowPos][colPos]) == 1 && colPos == 0) {
          dir = 'e'; //if tile is 1 and at left side of board go right 
        }
      }
      break;

    }//end of switch

    setAntDir(dir);
    setAntRow(rowPos);
    setAntCol(colPos);

} //end of move
