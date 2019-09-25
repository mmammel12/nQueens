#include <iostream>
#include <stack>
#include <string>

#include "Queen.h"

int getN()
{
  std::string n;
  std::cout << "\nEnter number of rows:\n";
  std::cin >> n;
  return std::stoi(n);
}

bool noConflict(const std::stack<Queen> &queens, int n)
{
  std::stack<Queen> temp(queens);
  bool noConflict = true;
  if (temp.size() > 1)
  {
    // get current queen
    Queen current = temp.top();
    // pop temp to check against queen below
    temp.pop();
    // check for illegal placement
    for (int i = 0; i < n; i++)
    {
      // get queen below
      Queen check = temp.top();
      if (current.getCol() == check.getCol())
      {
        noConflict = false;
        // diagonal down left
        if (current.getRow() == check.getRow() - i && current.getCol() == check.getCol() - i)
        {
          noConflict = false;
          // diagonal down right
          if (current.getRow() == check.getRow() - i && current.getCol() == check.getCol() + i)
          {
            noConflict = false;
          }
        }
      }
      if (temp.size() > 1)
      {
        temp.pop();
      }
    }
  }

  return noConflict;
}

void placeQueens(std::stack<Queen> *queens, int n)
{
  // push the first queen onto the stack and filled = 0
  queens->push(Queen());
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
        queens->push(Queen(filled, 0));
      }
    }
    // else if there is a conflict and there is room to shift right
    else if (queens->top().getCol() < n)
    {
      int col = queens->top().getCol() + 1;
      queens->pop();
      queens->push(Queen(filled, col));
    }
    // else there is a conflict and no room to shift right
    else
    {
      do
      {
        queens->pop();
        filled--;
      } while (!noConflict(*queens, n) && queens->top().getCol() == n - 1);
    }
  } while (filled < n);
}

void printBoard(std::stack<Queen> *queens, int n)
{
  std::cout << std::endl;
  // print board
  for (int i = 0; i < n; i++)
  {
    // row
    for (int i = 0; i < n; i++)
    {
      if (queens->top().getCol() == i)
      {
        std::cout << "1 ";
      }
      else
      {
        std::cout << "0 ";
      }
    }
    queens->pop();
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void nQueens()
{
  int n = getN();

  // initialize the stack
  std::stack<Queen> *queens = new std::stack<Queen>();

  // do the n queens stuff
  placeQueens(queens, n);

  // print board
  printBoard(queens, n);

  // delete queens from heap
  delete queens;
  queens = nullptr;
}

int main(int argc, char const *argv[])
{
  nQueens();
  return 0;
}