#include "game.h"
#include <iostream>

game::game(int Moves)
{
    //ctor
    this->remainingMoves = Moves;
    //Almacena los movimientos disponibles
}

game::~game()
{
    //dtor
}

int game::setRemainingMoves(int Moves)
{
    this->remainingMoves = Moves;
    return this->remainingMoves;
}

int game::getRemainingMoves()
{
    return this->remainingMoves;
}

//Funcion para reducir los movimientos
void game::reduceMoves()
{
    remainingMoves--;
}


