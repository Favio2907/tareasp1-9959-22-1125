#ifndef MAPCELL_H
#define MAPCELL_H
// Encabezado que define toda la funcionabilidad de las celdas del mapa de juego


class mapcell
{
    public:
        //int id;
        char id;
        mapcell();
        bool isBlockedCell();
        bool isBlockedCel2();
        virtual ~mapcell();

    protected:

    private:
};

#endif // MAPCELL_H
