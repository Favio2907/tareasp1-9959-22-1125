#ifndef JUGADOR_H
#define JUGADOR_H

#include "Config.h"

class Jugador {
public:
    Jugador(int vidas);
    void obtenerVida();
    int disminuirVida();

private:
    int vida;
};

#endif // JUGADOR_H

