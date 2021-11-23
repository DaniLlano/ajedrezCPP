/*
    this class represents a game of chess
*/

#ifndef GAME_H
#define GAME_H

#include <set>
#include <iostream>
#include "board.h"
#include "piece.h"
#include "player.h"

using namespace std;

class Game
{
    public:

    /*
        destructor
    */
   ~Game();

   /*
        set up a new game of chess
   */
    static void initialize();

    /*
        get theplayer whose turn is next

        @return the player
    */

    static Player* getNextPlayer();

    /*
        get the player who is the opponent of the given player

        @param player the player
        @return the opponent
    */
    static Player* opponentOf(Player& player);

private:
    /*
        create a game
    */
   Game();

   // private attributes
   static Player* player1;
   static Player* player2;
   static Player* nextPlayer;
   static set<Piece*> whitePieces;
   static set<Piece*> blackPieces;
};

// game

#endif