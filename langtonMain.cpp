/***************************************************************************
** Program Name: langtonMain.cpp
** Name:         Story Caplain
** Date:         01/08/19
** Description:  This program creates a board of user specified size for
**               an "Ant" to travel around on. The ant moves based on the
**               direction it is facing and rotates based on the color tile
**               it lands on. If the ant lands on a black tile it is flipped
**               to white and vice versa. After the ant moves a user 
**               specified number of times the board is printed.
***************************************************************************/
#include <iostream>
#include "menu.hpp"
#include "Ant.hpp"
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main() {
  int val  = 1; //will be used for input validation
  int play = 0; //will be used to see if user wants to play

  play = menu();

  while(play == 1) {
    int rows   = 5;
    int cols   = 5;
    int rowPos = 0;
    int colPos = 0;
    int moves  = 0;
    char dir;
    Ant langton;

    cout << "\n"
         << "Thanks for playing! In this game you will choose a size that\n"
         << "you would like for your gameboard, a starting position,     \n"
         << "and a number of moves to make on the board.\n"
         << "\n"

         << "Then an ant will be placed at the position you choose       \n"
         << "and it will move in a direction that you choose as well.    \n"
         << "\n"

         << "At first all spaces will be black (a blank space) except for\n"
         << "the location of the ant which is represented by a * key.    \n"
         << "\n"

         << "Once an ant touches a black space it flips it to a white    \n"
         << "space ( a # symbol). Later if it lands back on a white      \n"
         << "space it flips it to black.                                 \n"
         << "\n"

         << "Once the ant has completed its moves, the board prints out  \n"
         << endl;
    
    //Get rows from user
    cout << "Enter how many rows you would like your board to have: ";
    cin  >> rows;
    val = 1;
    //input validation
    while(val == 1) {
      //40 is the max because it is the max that will fit on an 80 width 
      //screen with a space after each number
      if(cin.fail() || rows < 5 || rows > 40) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << std::endl;
        cout << "Enter an integer in the range 5 to 40: " << std::endl;
        cin  >> rows;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');
    
    //Get columns from user
    cout << "\nEnter how many columns you would like your board to have: ";
    cin  >> cols;
    val = 1;
    //input validation
    while(val == 1) {
      //40 is the max because it is the max that will fit on an 80 width
      //screen with a space after each number
      if(cin.fail() || cols < 5 || cols > 40) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << std::endl;
        cout << "Enter an integer in the range 5 to 40: " << std::endl;
        cin  >> rows;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');

    //Get starting row from user
    cout << "\nEnter the row you would like to start in: ";
    cin  >> rowPos;
    val = 1;
    //input validation
    while(val == 1) {
      if(cin.fail() || rowPos < 1 || rowPos > rows) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << std::endl;
        cout << "Enter an integer in the range 1 to " << rows << ": ";
        cin  >> rowPos;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');
    rowPos--;
    langton.setAntRow(rowPos); //set the starting row

    //Get starting column from user
    cout << "\nEnter the column you would like to start in: ";
    cin  >> colPos;
    val = 1;
    //input validation
    while(val == 1) {
      if(cin.fail() || colPos < 1 || colPos > cols) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << std::endl;
        cout << "Enter an integer in the range 1 to " << cols << ": ";
        cin  >> colPos;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');
    colPos--;
    langton.setAntCol(colPos); //set the starting column

    //Get starting direction from user
    cout << "\nNow enter the direction you would like to start in.\n";
    cout << "the direction should be entered as a lowercase n, e, w, or s.";
    cout << endl;
    cout << "\nn is north(up), e is east(right), w is west(left)";
    cout << "\nand s is south(down).";
    cout << "\nEnter the direction you would like: ";
    cin  >> dir;
    val = 1;
    while(val == 1) {
      if(cin.fail() || ((dir!='n')&&(dir!='e')&&(dir!='w')&&(dir!='s'))) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Oops! Invalid input.\n";
        cout << "Enter a lowercase n, e, w, or s only: ";
        cin  >> dir;
      }
      else if(!cin.fail()) {
        val = 0;
      }
    }
    cin.clear();
    cin.ignore(256, '\n');
    langton.setAntDir(dir); //set the starting direction

    //Get number of moves from user
    cout << "\nEnter the number of moves you would like the ant to make: ";
    cin  >> moves;
    val = 1;
    //input validation
    while(val == 1) {
      if(cin.fail() || moves < 0) {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nOops! Invalid input." << std::endl;
        cout << "Enter an integer greater than 1: ";
        cin  >> moves;
      }   
      else if(!cin.fail()) {
        val = 0;
      }   
    }   
    cin.clear();
    cin.ignore(256, '\n');
    cout << "\n";

    /*
    cout << endl;
    cout << "rows: " << rows << endl;
    cout << "cols: " << cols << endl;
    cout << "moves: " << moves << endl;
    cout << "rowPos: " << rowPos++ << endl;
    cout << "colPos: " << colPos++ << endl;
    cout << "dir: " << dir << endl;
    cout << endl;
    */

    //create game board
    int** gboard = new int*[rows];
    for(int i = 0; i < rows; i++) {
      gboard[i] = new int[cols];
    }
    
    //fill board with 0's, which represent black tiles for now
    for(int i=0; i<rows; i++) {
     for(int j=0; j<cols; j++) {
       gboard[i][j] = 0;
      }
    }

    //move through board
    for(int i=0; i<moves; i++) {
      langton.move(rows, cols, gboard);
    }

    //Place ant at its last location
    (gboard[langton.getAntRow()][langton.getAntCol()]) = 2;

    //display game board
    for(int i=0; i<rows; i++) {
      for(int j=0; j<cols; j++) {
        if((gboard[i][j]) == 0) {
          cout << "  ";
        }
        else if((gboard[i][j]) == 1) {
          cout << "# ";
        }
        else if((gboard[i][j]) == 2) {
          cout << "* ";
        }
      }
      cout << endl;
    }

    //loop through gboard and delete dynamically allocated memory
    for(int i=0; i < cols; i++) {
      delete [] gboard[i];
      gboard[i] = 0;
    }

    //delete gboard and set ptr to null
    delete [] gboard;
    gboard = 0;
  
    //ask user for another game
    char again;
    cout << "\nWould you like to play again?\n";
    cout << "Enter p to play again, press anything else to quit: ";
    cin  >> again;

    if(cin.fail() || ((again!='p')&&(again!='P'))) {
      play = 0;
    } 
    else {
      play = 1;
      for(int i=0; i<10; i++) {
        cout << "\n";
      }
    }
  } 
  
  cout << "\n\nYou have quit, goodbye!\n\n";

  cout << "\n\n";
  return 0;
}  
