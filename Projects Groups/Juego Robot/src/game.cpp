#include "game.h"
#include <iostream>

game::game(int Moves, int Moves2, int Moves3)
{
    //ctor
    this->remainingMoves = Moves;
    //Almacena los movimientos disponibles
    this->remainingMoves2 = Moves2;
    //Almacena los movimientos disponibles
    this->remainingMoves3 = Moves3;
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

int game::setRemainingMoves2(int Moves2)
{
    this->remainingMoves2 = Moves2;
    return this->remainingMoves2;
}

int game::getRemainingMoves2()
{
    return this->remainingMoves2;
}

int game::setRemainingMoves3(int Moves3)
{
    this->remainingMoves3 = Moves3;
    return this->remainingMoves3;
}

int game::getRemainingMoves3()
{
    return this->remainingMoves3;
}

//Funcion para reducir los movimientos
void game::reduceMoves()
{
    remainingMoves--;
}

void game::reduceMoves2()
{
    remainingMoves2--;
}

void game::reduceMoves3()
{
    remainingMoves3--;
}


