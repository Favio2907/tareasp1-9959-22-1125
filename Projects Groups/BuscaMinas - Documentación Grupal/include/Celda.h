#ifndef CELDA_H
#define CELDA_H

// Libreria que guarda los atributos y los prototipos de los metodos utilizados para crear y administrar las celdas de juego
// Fecha: 17 marzo 2023

class Celda // Esta clase representa una celda en un juego de buscaminas y tiene varios atributos como la coordenadaX, coordenadaY, mina y minaDescubierta.
{
public:
    // Constructor por defecto que inicializa la coordenadaX y la coordenadaY a cero, la mina y la minaDescubierta a falso
    Celda();

    // Constructor que toma la coordenadaX, la coordenadaY y el estado de la mina como par�metros para inicializar la celda
    Celda(int coordenadaX, int coordenadaY, bool estadoMina);

    // M�todos para establecer y obtener la coordenadaX y la coordenadaY de la celda
    int setCoordenadaX(int coordenadaX); // Establece la coordenada X de la celda
    int getCoordenadaX(); // Obtiene la coordenada X de la celda
    int setCoordenadaY(int coordenadaY); // Establece la coordenada Y de la celda
    int getCoordenadaY(); // Obtiene la coordenada Y de la celda

    // M�todos para establecer y obtener el estado de la mina en la celda
    bool setMina(bool estadoMina); // Establece si la celda contiene una mina o no
    bool getMina(); // Obtiene el estado de la mina en la celda

    // M�todos para establecer y obtener el estado de la mina descubierta en la celda
    bool setMinaDescubierta(bool minaDescubierta); // Establece si la mina en la celda ha sido descubierta o no
    bool getMinaDescubierta(); // Obtiene el estado de la mina descubierta en la celda

    // M�todo que imprime el estado actual de la celda (mina descubierta, mina sin descubrir, etc.)
    void imprimirCelda();

protected:
    // Atributos protegidos, accesibles s�lo por la clase Celda y sus subclases (si las hubiera)

private:
    // Atributos privados, accesibles s�lo por la clase Celda
    int coordenadaX, coordenadaY; // Coordenadas de la celda en el tablero
    bool mina; // Indica si la celda contiene una mina
    bool minaDescubierta; // Indica si la mina de la celda ha sido descubierta
};

#endif // CELDA_H
