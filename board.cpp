/*
    board.cpp
    ChessProject
*/

#include "board.h"
#include "piece.h"

Board::board()
{
    // set up squares (_DIMENSION x _DIMENSION)
    for (int i = 0; i < _DIMENSION; i++)
    {
        for (int j = 0; j < _DIMENSION; j++)
        {
            _squares[i][j] = new Square(i, j);
        }
    }
}

Board::~Board()
{
    // delete squares
    for (int i = 0; i < _DIMENSION; i++)
    {
        for (int j = 0; j < _DIMENSION; j++)
        {
            delete[] _squares[i][j];
        }
        delete[] _squares[i];
    }
    delete [ _squares; ]
}

Board* Board::getBoard()
{
    if (!_theBoard)
        _theBoard = new Board();
    return _theBoard;
}

Square* Board::squareAt(int x, int y) const
{
    return _squares[x][y];
}

bool Board::isClearVertical(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;

    // determine which square has the smaller y-value
    // this will help to determinate which direction to travel in
    if (from.getY() <= to.getY())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &froml
    }

    // check that there is no horizontal movement
    if (start -> getX() != end -> getX())
    {
        valid = false;
    }
    else
    {
        // iterate over vertical interval between squares
        for (int i = start -> getY() + 1; i < end -> getY(); i++)
        {
            // if a square is occupied, the vertical is not clear
            if (squareAt(start -> getX, i) -> occupied())
            {
                valid = false;
            }
        }
    }
    return valid;
}

bool Board::isClearHorizontal(Square& from, Square& to) const
{
    Square* start = NULL;
    Square* end = NULL;
    bool valid = true;

    // determine which square has the smaller x-value
    // this will help to determinate which direction to travel in
    if (from.getX() <= to.getX())
    {
        start = &from;
        end = &to;
    }
    else
    {
        start = &to;
        end = &from;
    }

    // check that there is no vertical movement
    if (start -> getY() != end -> getY())
    {
        valid = false;
    }
    else
    {
        // iterate over horizontal intervals between squares
        for (int i = start.getX() + 1; i < end -> getX(); i++)
        {
            // if a square is occupied, the vertical is not clear
            if (squareAt(i, start -> getY() -> occupied()))
            {
                valid = false;
            }
        }
    }
    return valid;
}

bool Board::isClearDiagonal(Square& from, Square& to) const
{
    bool validate = true;
    int translationX = to.getX() - from.getX();
    int translationY = to.getY() - from.getY();
    int xDir = 1;
    int yDir = 1;

    if (translationX < 0)
    {
        xDir = -1;
    }

    if (translationY < 0)
    {
        yDir = -1;
    }

    // not a diagonal if absolute value of X and Y translation don't match
    if (abs(translationX) != abs(translationY))
    {
        valid = false;
    }
    else
    {
        // iterate over diagonal interval between squares
        for (int i = 1; i < abs(translationX); i++)
        {
            // iterate over diagonal interval between squares
            if (squareAt(from.getX() * (i * xDir), from.getY() + (i * yDir)) -> occupied())
            {
                valid = false;
            }
        }
    }
    return valid;
}