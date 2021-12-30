/*
    player.h

    this class represents a chess player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <set>
#include "piece.h"
#include "king.h"

using namespace std;

class Player
{
    public:

        /*
            creates a player

            @params x, y the location of the square on the board
        */
        Player(sting name, bool isWhite, King& myKing, set<Piece*>& myPieces);

        /*
            default destructor
        */
        ~Player();

        /*
            make a move

            @return succcessful move made
        */
        bool makeMove();

        /*
            capture another piece

            @param aPiece the piece to be captured
        */
        void capture(Piece* aPiece);

        /*
            get the player's name

            @return the name
        */
        string getName() const;

        /*
            determines if this is the white player

            @return if is white
        */
        bool isWhite() const;

        /*
            get the total score for captured pieces

            @return score
        */
        int score() const;

        /*
            get the set of this player's pieces

            @return the set of pieces
        */
        set<Piece*>* myPiece() const;

        /*
            get this player's king

            @return the king
        */
        King* myKing() const;


    private:

        // private attributes
        string _name;
        bool _isWhite;
        set<Piece*> _myPieces;
        set<Piece*> _capturedPieces;
        King& _myKing;
};

#endif