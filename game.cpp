#include "game.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
#include "square.h"

Game::Game()
{
}

Game::~Game()
{
    // delete pieces
    for (set<Piece*>::iterator itr = whitePieces.begin(); itr != whitePieces.end(); ++itr)
    {
        delete *itr;
    }
    whitePieces.clear();
    for (set<Piece*>::iterator itr = blackPieces.begin(); itr != blackPieces.end(); ++itr)
    {
        delete *itr;
    }
    blackPieces.clear();

    // delete players
    delete &player1;
    delete &player2;
}

void Game::initialize()
{
    Piece* aPiece;
    King* aKing;
    Square* aSquare;

    // create piece sets
    whitePieces = *(new set<Piece*>);
    blackPieces = *(new set<Piece*>);

    // create each piece
    // set their locations
    // put them in their respective collections
    aPiece = new Queen(true);
    aSquare = Board::getBoard() -> squareAt(3, 0);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    whitePiece.insert(aPiece);
    aPiece = new Queen(true);
    aSquare = Board::getBoard() -> squareAt(3, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPiece.insert(aPiece);

    aPiece = new Bishop(true);
    aSquare = Board::getBoard() -> squareAt(2, 0);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    whitePiece.insert(aPiece);
    aPiece = new Bishop(false);
    aSquare = Board::getBoard() -> squareAt(2, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPiece.insert(aPiece)
}