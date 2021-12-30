#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include "square.h"
#include "restrictedPiece.h"

using namespace std;

class Pawn : public RestrictedPiece
{
    public:

    /*
    creates a pawn

    @param color the color of the piece
    */
    Pawn(bool isWhite);

    /*
    default destructor
    */
    ~Pawn();

    /*
    set which square the piece is located on

    @param location the square
    */
    void setLocation(Square* location);

    /*
    get the point value of the piece

    @return the value
    */
    int value() const;

    /*
    move the piece to another square

    @return succesful move
    */
    bool moveTo(Player& byPlayer, Square& to);

    /*
    determines if the piece can legally move to a given square
    based on the geometry of the move

    @param square the square to move to
    @return if move is legal
    */
    bool canMoveTo(Square& location) const;

    /*
    display the piece
    @param outStream the output stream
    */
    void display() const;

private:

    // private attributes
    Piece* _delegate;
};

#endif