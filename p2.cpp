// Matthew Rutigliano
// P2: TicTacToe
// Purpose: Implements the "tictactoe" class to run a game of tictactoe.
// Inputs: Array Coordinates from users
// Process: A tictactoe object is created, dynamically allocating a 3*3 array. Users are then
//          asked to input coordinates for their symbols in an alternating order, with the board
//          being checked for three symbols in a row after every guess. The board array is then
//          printed, with the game continuing until one player wins or the board fills up. At this
//          point, the appropriate score counter is incremented and displayed and the board is reset,
//          with the users being prompted if they'd like to play again.
// Outputs: TicTacToe board array graphics and contents, player turn reminder, score counter

#include<iostream>
#include "tictactoe.h"

using namespace std;

int main()
{
  // Initializing player attributes
  char x = 'x';
  char o = 'o';
  bool done = false;
  bool p1Win = false;
  bool p2Win = false;
  bool repeat = false;
  char ans = ' ';

  // Creation of TicTacToe object
  TicTacToe game;

  // Screen is cleared and welcome message is outputted, with the users being asked if they'd like to play
  for (int i = 0; i < 25; i++)
    cout << endl;
  cout << "Welcome to TicTacToe!\n TicTacToe is a stunning graphical feat allowing"
       << " two very lucky users to play a computerized version of the game revolutionalizing children's menus\n across the world."
       << " Taking place on a 3X3 grid, Player 1 controls the nefarious X's, with Player 2 commandeering the cunning O's.\n Each player takes turns placing their symbol"
       << " on a grid space, with the game ending once either three have been placed in a row\n or it has become impossible to do so." << endl << endl;

  cout << "Would you like to play TicTacToe? Y/N ";
  cin >> ans;
  ans = toupper(ans);
  
  if (ans == 'Y')
    repeat = true;

  while (repeat)
    {
      // Attributes reinitialized if game was reset
      done = false;
      p1Win = false;
      p2Win = false;
      
      while (!done)
        {
          // Board printed
          game.displayGame();

          cout << "Player 1's turn:" << endl;

          // Player 1 takes their turn
          game.takeTurn(x,done,p1Win);

          // Updated board printed
          game.displayGame();

          // If the game hasn't ended, Player 2 takes their turn
          if (!done)
            {
              cout << "Player 2's turn:" << endl;
              game.takeTurn(o,done,p2Win);
              if (p2Win == true)
                // Updated board printed
                game.displayGame();
            }
        }

      // Statistics are printed
      game.displayStatistics();

      // Users are asked if they'd like to play again
      cout << "Would you like to play again? Y/N ";
      cin >> ans;
      ans = toupper(ans);
      
      if (ans == 'N')
        {
          repeat = false;
          cout << "Thank you for being two of the first to experience the mind-boggling strategy experience"
               << " ravaging the world!" << endl;
        }
      // Board is reset
      game.resetBoard();
    }
  
  return 0;
}
