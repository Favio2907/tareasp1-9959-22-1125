#ifndef PLAYER_H
#define PLAYER_H

// Encabezado que define toda la funcionabilidad del Jugador
class player
{
    public:
        player();
        int lastX, lastY;
        virtual ~player();
        void callInput();
        int getValueX();
        void setValueX(int valueX);
        int getValueY();
        void setValueY(int valueY);
        void resetToSafePosition();
        void drawCreditos();
        void setM(int M);
        int getM();

    protected:

    private:
        int x, y;
        int M;
        int m = 0;

};

#endif // PLAYER_H
