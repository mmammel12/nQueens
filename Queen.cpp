#include "Queen.h"

Queen::Queen()
    : row(0),
      col(0)
{
}

Queen::Queen(int row, int col)
    : row(row),
      col(col)
{
}

Queen::~Queen()
{
}

/// return row
int Queen::getRow(void)
{
  return this->row;
}

/// return column
int Queen::getCol(void)
{
  return this->col;
}