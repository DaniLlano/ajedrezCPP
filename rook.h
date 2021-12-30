/*
    rook.h

    this class represents a chess rook piece
*/

#ifndef ROOK_H
#define ROOK_H

#include <iostream>
#include "restrictedPiece.h"
#include "square.h"

using namespace std;

class Rook : public RestrictedPiece
{
    public:

        /*
            creates a rook

            @param color the color of the piece
        */
        Rook(bool isWhite);

        /*
            default destructor
        */
        ~Rook();

        /*
            get the point of value of the piece

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
};

#endif