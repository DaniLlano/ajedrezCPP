/*
    board.h

    this class represents a game board
*/

#ifndef BOARD_H
#define BOARD_H

#include <ostream>
#include "square.h"

using namespace std;

class Board
{
    public:

    /*
        default constructor
    */
   ~Board();

   /*
        get the board

        @return the board
   */
    static Board* getBoard();

    /*
        get a specific square on the board

        @params x, y the location of the square on the board
        @returns the square
    */
    Square* squareAt(int x, int y) const

    /*
       determine if the path between two squares is a clear vertical

       @param from the starting square
       @param to the ending square
       @return if the path is a clear vertical
    */
    bool isClearVertical(Square& from, Square& to) const;

    /*
        determine if the path between two squares is a clear horizontal

        @param from the starting square
        @param fo the ending square
        @return if the path is a clear horizontal
    */
   bool isEndRow(Square& location) const;

   /*
        display the core

        @param outStream the output stream
   */
    void display(ostream& outStream) const;

private:

    /*
        creates an 8*8 board
    */
   Board();

   // private attributes
   static Board* _theBoard;
   static const int _DIMENSION = 8;
   Square* _squares[_DIMENSION][_DIMENSION];

};

#endif