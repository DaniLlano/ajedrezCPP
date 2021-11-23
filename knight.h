#ifndef KNIGHT_H
#define KNIGHT_H

#include <iostream>
#include "square.h"
#include "piece.h"

using namespace std;

class Knight : public Piece
{
    public:

    /*
        creates a knight

        @param color the color of the piece
    */
    Knight(bool isWhite);

    /*
        default destructor
    */
    ~Knight();

    /*
        get the point value of the piece

        @return the value
    */
    int value() const;

    /*
        determines if the piece can legally move to a given square
    */
    bool canMoveTo(Square& location) const;

    /*
        display the piece
        @param outStream the output stream
    */
    void display() const;
};

#endif