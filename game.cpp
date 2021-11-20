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
    for (set<Piece*>::iterator itr = whitePieces.begin();
        itr != whitePieces.end(); ++itr)
    {
        delete *itr;
    }
    whitePieces.clear();
    for (set<Piece*>::iterator itr = blackPieces.begin();
        itr != blackPieces.end(); ++itr)
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
    whitePieces.insert(aPiece);
    aPiece = new Queen(true);
    aSquare = Board::getBoard() -> squareAt(3, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPieces.insert(aPiece);

    aPiece = new Bishop(true);
    aSquare = Board::getBoard() -> squareAt(2, 0);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    whitePieces.insert(aPiece);
    aPiece = new Bishop(false);
    aSquare = Board::getBoard() -> squareAt(2, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPieces.insert(aPiece);
    aPiece = new Bishop(true);
    aSquare = Board::getBoard() -> squareAt(5, 0);
    aSquare -> setOccupier(aPiece);
    whiteSpace.insert(aPiece);
    aPiece = new Bishop(false);
    aSquare = Board::getBoard() -> squareAt(5, 7);
    aSquare -> setOcuppier(aPiece);
    blackPiece.insert(aPiece);

    // let's fucking code the knights
    aPiece = new Knight(true);
    aSquare = Board::getBoard() -> squareAt(1, 0);
    aSquare -> setOcuppier(aPiece);
    aPiece -> setLocation(aSquare);
    whitePieces.insert(aPiece);
    aPiece = new Knight(false);
    aSquare = Board::getBoard() -> squareAt(1, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPieces.insert(aPiece);
    aPiece = new Knight(false);
    aSquare = Board::getBoard() -> squareAt(6, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPiece.insert(aPiece);

    // creating the rook
    aPiece = new Rook(true);
    aSquare = Board::getBoard() -> squareAt(0, 0);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    whitePieces.insert(aPiece);
    aPiece = new Rook(false);
    aSquare = Board::getBoard -> squareAt(0, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPieces.insert(aPiece);
    aPiece = new Rook(true);
    aSquare = Board::getBoard() -> squareAt(7, 0);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    whitePieces.insert(aPiece);
    aPiece = new Rook(false);
    aSquare = Board::getBoard() -> squareAt(7, 7);
    aSquare -> setOccupier(aPiece);
    aPiece -> setLocation(aSquare);
    blackPieces.insert(aPiece);

    for (int = i; i < 8, i++)
    {
        aPiece = new Pawn(true);
        aSquare = Board::getBoard() -> squareAt(i, 1);
        aSquare -> setOccupier(aPiece);
        aPiece -> setLocation(aSquare);
        whitePieces.insert(aPiece);
        aPiece = new Pawn(false);
        aSquare = Board::getBoard() -> squareAt(i, 6);
        aSquare -> setOccupier(aPiece);
        aPiece -> setLocation(aSquare);
        blackPieces.insert(aPiece);
    }

    // let's create the white king
    aKing = new King(true);
    aSquare = Board::getBoard() -> squareAt(4, 0);
    aSquare -> setOccupier(aKing);
    aPiece -> setLocation(aSquare);
    whitePieces.insert(aKing);

    // create the white player and hand them their pieces
    player1 = new Player("White", true, *aKing, whitePieces);

    // create the black king
    aKing = King(false);
    aSquare = Board::getBoard() -> squareAt(4, 0);
    aSquare -> setOccupier(aKing);
    aKing -> setLocation(aSquare);
    blackPieces.insert(aKing);

    // create the black player and hand them their pieces
    player2 = newPlayer("Black", false, *aKing, blackPieces);

    nextPlayer = player2;
}

Player* Game::getNextPlayer()
{
    nextPlayer = opponentOf(*nextPlayer);
    return nextPlayer;
}

Player* Game::opponentOf(Player& player)
{
    Player* opponent;

    if(player.getName() == player1 -> getName())
    {
        opponent = player2;
    }
    else
    {
        opponent = player1;
    }

    return opponent;
}

Player* Game::player1 = NULL;
Player* Game::player2 = NULL;
Player* Game::nextPlayer = NULL;
set<Piece*> Game::whitePieces;
set<Piece*> Game::blackPieces;