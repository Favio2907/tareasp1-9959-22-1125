#include "mapcell.h"
#ifndef GAMEMAP2_H
#define GAMEMAP2_H


class gamemap2
{
    public:
        gamemap2();
        mapcell* playerCell2;
        mapcell cell [15][15];
        void draw();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCel2(int playerX, int playerY);
        void drawVictoria();
        virtual ~gamemap2();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile2();
        void createMapToFile2();
};

#endif // GAMEMAP2_H
