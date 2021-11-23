/*
    this class represents a chess king piece
*/

#ifndef KING_H
#define KING_H

#include <iostream>
#include "restrictedPiece.h"

using namespace std;

class King : public RestrictedPiece
{
    public:
        /*
            creates a king

            @param color the color of the piece
        */
       King(bool isWhite);

       /*
        default constructor
       */
        ~King();

        /*
            get the point value of the piece

            @return the value
        */
        int value() const;

        /*
            determines if the piece can legally move to a given square

            @param square the square to move to
            @return if move is legal
        */
       bool canMoveTo(Square& location) const;

       /*
        display the piece
        @param outStream the output stream
       */
        void display() const;
}

#endif