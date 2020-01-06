// Matthew Rutigliano
// TicTacToe Implementation file
// Purpose: Implementation for TicTacToe class described in tictactoe.h

#include "tictactoe.h"
#ifndef TICTACTOE_H
#define TICTACTOE_H

// Constructor
TicTacToe::TicTacToe()
{
  p1GamesWon = p2GamesWon = gamesTied = 0;

  // Creates 2D board array of SIZE*SIZE
  board = new char*[SIZE];

  for (int i = 0; i < SIZE; i++)
    {
      board[i] = new char[SIZE];
    }

  // Populates each array place with a space
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
        {
          board[i][j] = ' ';
        }
    }
}

// Overloaded Assignment Operator
TicTacToe& TicTacToe::operator=(const TicTacToe &obj)
{
  if (this!= &obj)
    {
      // Deallocating Memory
      for (int i = 0; i < SIZE; i++)
        {
          delete[] board[i];
        }
      delete[] board;

      // Allocating New Memory
      for (int i = 0; i < SIZE; i++)
        {
          board[i] = new char[SIZE];
        }

      // Copying object to new memory
      for (int i = 0; i < SIZE; i++)
        {
          for (int j = 0; j < SIZE; j++)
            {
              board[i][j] = obj.board[i][j];
            }
        }
      
      p1GamesWon = obj.p1GamesWon;
      p2GamesWon = obj.p2GamesWon;
      gamesTied = obj.gamesTied;
    }
  return *this;
}

// Copy Constructor
TicTacToe::TicTacToe(const TicTacToe &obj)
{
  // Allocate new memory
  for (int i = 0; i < SIZE; i++)
    {
      board[i] = new char[SIZE];
    }

  // Copy Object to new Memory
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
        {
          board[i][j] = obj.board[i][j];
        }
    }
  
  p1GamesWon = obj.p1GamesWon;
  p2GamesWon = obj.p2GamesWon;
  gamesTied = obj.gamesTied;
}

// Destructor
TicTacToe::~TicTacToe()
{
  for (int i = 0; i < SIZE; i++)
    {
      delete[] board[i];
    }
  delete[] board;
}

// Display Statistics
void TicTacToe::displayStatistics()
{
  cout << "Player 1 games won: " << p1GamesWon << endl;
  cout << "Player 2 games won: " << p2GamesWon << endl;
  cout << "Tie games: " << gamesTied << endl;
}

// Display Game:
void TicTacToe::displayGame()
{
  // Prints Column labels
  cout << "  ";
  for (int i = 0; i < SIZE; i++)
    {
      cout << i << "  ";
    }

  cout << endl;

  //Prints Row labels, followed by each row with board graphics between each value
  for (int i = 0; i < SIZE; i++)
    {
      cout << i;
      for (int j = 0; j < SIZE; j++)
        {
          cout << " " << board[i][j] << "|";
        }
      cout << endl << " ---------" << endl;
    }
}

// Take turn;
bool TicTacToe::takeTurn(char letter, bool& done, bool& won)
{
  int row;
  int column;
  bool repeat = true;

  done = false;
  won = false;

  // User is asked to input row and column coordinates until they have been verified
  // to exist within the array
  while (repeat)
    {
      cout << "Which row? ";
      cin >> row;
      cout << "Which column? ";
      cin >> column;

      if (row < SIZE && column < SIZE && board[row][column] == ' ')
        {
          repeat = false;
          board[row][column] = letter;
        }
      else
        cout << "Bad location, try again" << endl;
    }

  // Win Conditions: The amount of the player's symbols in each row, column and diagonal
  //                 is tallied. If one of those values is equal to the size value of the
  //                 board, won is set to true.
  
  // Row Win
  for (int i = 0; i < SIZE; i++)
    {
      int sum = 0;
      for (int j = 0; j < SIZE; j++)
        {
          if (board[i][j] == letter)
            sum += 1;
        }
      if (sum == SIZE)
        {
          won = true;
          done = true;
        }
    }

  // Column Win
  for (int i = 0; i < SIZE; i++)
    {
      int sum = 0;
      for (int j = 0; j < SIZE; j++)
        {
          if (board[j][i] == letter)
            sum++;
        }
      if (sum == SIZE)
        {
          won = true;
          done = true;
        }
    }
  
  // Left Diagonal Win
  int sum = 0;
  for (int i = 0; i < SIZE; i++)
    {
      if (board[i][i] == letter)
        sum++;
    }
  if (sum == SIZE)
    {
      won = true;
      done = true;
    }

  sum = 0;

  // Right Diagonal Win
  for (int i = 0; i < SIZE; i++)
    {
      if (board[SIZE - (i + 1)][i] == letter)
        sum += 1;
    }
  if (sum == SIZE)
    {
      won = true;
      done = true;
    }

  // Win Incrementor: The winning player is found by checking which symbol it was, with
  //                  that player's count going up as a result
  if (won == true)
    {
      if (letter == 'x')
        {
          p1GamesWon++;
          cout << "Player 1 wins!" << endl;
        }
      
      else
        {
          p2GamesWon++;
          cout << "Player 2 wins!" << endl;
        }
    }
  
  // Tie Check: As a final test, the amount of spaces left on the board is tallied.
  //            if this value equals 0 with won still being false, done is set to true
  //            and the tied games count goes up
  sum = 0;
  
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
        {
          if (board[i][j] == ' ')
            sum++;
        }
    }

  if (sum == 0)
    {
      done = true;
      gamesTied++;
      cout << "Tie game" << endl;
    }
          
  return true;
}

// Reset board function: The board array contents are reset to their default state
void TicTacToe::resetBoard()
{
  for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
        {
          board[i][j] = ' ';
        }
    }
}

#endif
