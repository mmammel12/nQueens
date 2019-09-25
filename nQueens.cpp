#include <iostream>
#include <stack>
#include <string>

#include "Queen.h"

void nQueens()
{
  int n = getN();

  // initialize the stack
  std::stack<Queen *> *queens = new std::stack<Queen *>();

  // do the n queens stuff
  placeQueens(queens, n);

  // print board
  printBoard(queens, n);

  // delete queens from heap
  delete queens;
  queens = nullptr;
}

int getN()
{
  std::string n;
  std::cout << "Enter number of rows:\n";
  std::cin >> n;
  return std::stoi(n);
}

bool noConflict(const std::stack<Queen *> &queens, int n)
{
  std::stack<Queen *> temp(queens);
  bool noConflict = false;
  if (temp.size() > 1)
  {
    // get current queen
    Queen current = *temp.top();
    for (int i = 0; i < temp.size(); i++)
    {
      // pop temp to check against queen below
      temp.pop();
      // get queen below
      Queen check = *temp.top();
      // check for illegal placement
      if (current.getRow() != check.getRow())
      {
        if (current.getCol() != check.getCol())
        {
          for (int i = 0; i < n; i++)
          {
            // diagonal down left
            if (current.getRow() != check.getRow() - i && current.getRow() != check.getRow() - i)
            {
              // diagonal down right
              if (current.getRow() != check.getRow() - i && current.getRow() != check.getRow() + i)
              {
                noConflict = true;
              }
            }
          }
        }
      }
    }
  }
  else
  {
    noConflict = true;
  }

  return noConflict;
}

void placeQueens(std::stack<Queen *> *queens, int n)
{
  // push the first queen onto the stack and filled = 0
  queens->push(new Queen());
  int filled = 0;

  do
  {
    // if no conflicts with queens
    if (noConflict(*queens, n))
    {
      filled++;
      if (filled != n)
      {
        // place queen in next row, column 0
        queens->push(new Queen(filled, 0));
      }
    }
    // else if there is a conflict and there is room to shift right
    else if (queens->top()->getCol() < n)
    {
      int col = queens->top()->getCol() + 1;
      queens->pop();
      queens->push(new Queen(filled, col));
    }
    // else there is a conflict and no room to shift right
    else
    {
      do
      {
        queens->pop();
        filled--;
      } while (!noConflict(*queens, n) && queens->top()->getCol() == n - 1);
    }
  } while (filled < n);
}

void printBoard(std::stack<Queen *> *queens, int n)
{
  // print board
  for (int i = 0; i < n; i++)
  {
    // row
    for (int i = 0; i < n; i++)
    {
      if (queens->top()->getCol() == i)
      {
        std::cout << "1 ";
      }
      else
      {
        std::cout << "0 ";
      }

      std::cout << std::endl;
    }
  }
}

int main(int argc, char const *argv[])
{
  nQueens();
  return 0;
}