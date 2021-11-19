/*
    This class represents a chess bishop piece
*/

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include "piece.h"
#include "square.h"

using namespace std;

class Bishop : public Piece
{
    public:

    /*
        creates a bishop

        @param color the color of the piece
    */
   Bishop(bool isWhite);


   /*
        default destructor
   */
    ~Bishop();
    /*
    get the point value of the piece
    @return the value
    */

   int value() const;
   /*
   determines if the piece can legally move to a given square

   @param square the square to move to
   @return of move is legal
   */

    int canMoveTo(Square& location) const;
    /*
    display the piece
    @param outStream the output stream
    */

   void display() const;
} //bishop

#endif