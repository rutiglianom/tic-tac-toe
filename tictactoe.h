// Matthew Rutigliano
// TicTacToe Class Header file
// Purpose: The TicTacToe class has all the attributes necessary to run a game of tictactoe.
//          A 3*3 array is dynamically allocated, with players taking turns placing symbols
//          at coordinates of their choice. The array is checked to see if three symbols are
//          in a row, and if so that player's win count goes up and the game resets. If the
//          board fills up with neither player winning, the game still resets with the tie
//          game count going up. Once the players decide to stop playing, the memory is
//          deallocated and the program closes.

#include<iostream>
using namespace std;

class TicTacToe
{
 public:

  TicTacToe();
  // Default Constructor
  // Precondition: None
  // Postcondition: All private attributes have been initialized, memory has been allocated

  void displayStatistics();
  // Display the players' statistics
  // Precondition: Statistic integers must have been initialized
  // Postcondition: None

  void displayGame();
  // Outputs board graphic with player's symbols at the appropriate location
  // Precondition: Dynamic board array must have been initialized
  // Postcondition: None

  bool takeTurn(char letter, bool& done, bool& won);
  // Player inputs the desired coordinates for their system, with the board being
  // processed to see if the game has been won or tied
  // Precondition: User has inputted coordinates within the array, the array has
  //               been allocated
  // Postcondition: Coordinate becomes populated with the player's symbol and unavailable
  //                to the other player, done and/or won is set to true depending on board

  ~TicTacToe();
  // Default destructor
  // Precondition: Array has been dynamically allocated
  // Postcondition: Memory is released

  TicTacToe(const TicTacToe&);
  // Copy Constructor
  // Precondition: TicTacToe object has already been created
  // Postcondition: A new TicTacToe object with identical attributes is created

  // Overloaded Assignment Operator
  TicTacToe& operator=(const TicTacToe &);
  // Overloaded assignment operator
  // Precondition: Two TicTacToe objects have been created
  // Postcondition: One of them is now identical to the other

  // Board reset
  void resetBoard();
  // Board is reset at the end of the game
  // Precondition: Board has been dynamically allocated
  // Postcondition: Board has been returned to default state

 private:

  // 2D board array
  char **board;

  // Constant size of board
  const int SIZE = 3;

  // ties,wins
  int p1GamesWon;
  int p2GamesWon;
  int gamesTied;

};

  
