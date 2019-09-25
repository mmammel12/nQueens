#ifndef _QUEEN_H_
#define _QUEEN_H_

class Queen
{
private:
  int row;
  int col;

public:
  Queen(void);
  Queen(int row, int col);
  ~Queen(void);

  int getRow(void);
  int getCol(void);
};

#endif