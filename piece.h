/*
    piece.h

    this class represents a game piece
*/

#ifndef PIECE_H
#define PIECE_H

#include <ostream>
#include "square.h"
#include "board.h"
class Player;

using namespace std;

class Piece
{
    public:

        /*
            creates a piece

            @param isWhite if the color of the piece is white
        */
        Piece(bool isWhite);

        /*
            default destructor
        */
        virtual ~Piece();

        /*
            move the piece to the square, making sure that the move
            is legal

            @param piece the piece on the square
            @return if legal move was made
        */
        virtual bool moveto(Player& byPlayer, Square& toSquare);

        /*
            set which square the piece is located on

            @param location the square
        */
        virtual void setLocation(Square* location);

        /*
            get the point value of the piece

            @return the value
        */
        virtual int value() const = 0;

        /*
            determine if the piece is white

            @return if is white
        */
        bool isWhite() const;

        /*
            get the piece's color

            @return the color
        */
        string color() const;

        /*
            display the piece

            @param outStream the output stream
        */
        virtual void display() const = 0;

        /*
            determines if the piece can legally move to a given square
            based on the geometry of the move

            @param square the square to move to
            @return of move is legal
        */
        virtual bool canMoveTo(Square& location) const = 0;

        /*
            determines if the piece is on square

            @return if on square
        */
        bool isOnSquare() const;

        /*
            gets the piece's location

            @return the square the piece is on
        */
        Square* location() const;

    protected:
        bool _isWhite;
        string _color;

    private:

        // private attributes
        Square* _square;
};

#endif