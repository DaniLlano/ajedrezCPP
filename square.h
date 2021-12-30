/*
    square.h

    this class represents a square on a game board
*/

#ifndef SQUARE_H
#define SQUARE_H

class Piece;

using namespace std;

class Square
{
    public:

        /*
            creates a square

            @param x, y the location of the square on the board
        */
        Square(int x, int y);
        Square()

        /*
            default destructor
        */
        ~Square();

        /*
            set the piece that occupies the square

            @param piece the piece on the square
        */
        void setOccupier(Piece* piece);

        /*
            get the X position of the square

            @return the position
        */
        int getX() const;

        /*
            get the Y position of the square

            @return the position
        */
        int getY() const;
        
        /*
            determine if the square is occupied by a piece

            @return if occupied
        */
        bool occupied() const;

        /*
            get the piece that is on the square

            @return the piece
        */
        Piece* occupiedBy() const;


    private:

        // private attributes
        int _x;
        int _y;
        Piece* _piece;
};

#endif