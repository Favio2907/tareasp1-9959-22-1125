#include "Celda.h"
#include <iostream>
using namespace std;

// Constructor por defecto de la clase Celda. No recibe parámetros y no hace nada, ya que todos los atributos de la clase se inicializan con valores por defecto.
Celda::Celda()
{
}

// Constructor con parimetros de la clase Celda. Recibe tres parámetros: la coordenada X de la celda, la coordenada Y de la celda y un valor booleano que indica si la celda contiene una mina o no. Este constructor asigna los valores recibidos a los atributos correspondientes de la clase.
Celda::Celda(int coordenadaX, int coordenadaY, bool estadoMina)
{
    this->coordenadaX = coordenadaX; // Asigna la coordenada X recibida al atributo de la clase
    this->coordenadaY = coordenadaY; // Asigna la coordenada Y recibida al atributo de la clase
    this->mina = estadoMina; // Asigna el estado de la mina recibido al atributo de la clase
    this->minaDescubierta = false; // Inicializa el estado de la mina descubierta en falso
}
// Método para establecer la coordenada X de la celda. Recibe un parámetro de tipo entero que representa la nueva coordenada X de la celda y lo asigna al atributo correspondiente de la clase.
int Celda::setCoordenadaX(int coordenadaX)
{
    this->coordenadaX = coordenadaX; // Asigna la coordenada X recibida al atributo de la clase
}
// Método para obtener la coordenada X de la celda. Devuelve el valor del atributo correspondiente de la clase.
int Celda::getCoordenadaX()
{
    return this->coordenadaX; // Devuelve el valor del atributo de la clase
}
// Método para establecer la coordenada Y de la celda, Recibe un parámetro de tipo entero que representa la nueva coordenada Y de la celda y lo asigna al atributo correspondiente de la clase.
int Celda::setCoordenadaY(int coordenadaY)
{
    this->coordenadaY = coordenadaY;  // Asigna la coordenada Y recibida al atributo de la clase
}

// Método para obtener la coordenada Y de la celda. Devuelve el valor del atributo correspondiente de la clase.
int Celda::getCoordenadaY()
{
    return this->coordenadaY;  // Devuelve el valor del atributo de la clase
}

// Método para establecer el estado de la mina de la celda. Recibe un parámetro de tipo booleano que indica si la celda contiene una mina o no. Si la celda ya tiene una mina asignada, este método devuelve false, de lo contrario asigna el valor recibido al atributo correspondiente de la clase y devuelve true.
bool Celda::setMina(bool estadoMina)
{
    if (this->getMina()) // Si la celda ya tiene una mina asignada, devuelve falso
    {
        return false;
    }
    else{ // En caso contrario, asigna el estado de la mina recibido al atributo de la clase y devuelve verdadero
        this->mina = estadoMina;
        return true;
    }
}

// Método para obtener el estado de la mina de la celda. Devuelve el valor del atributo correspondiente de la clase.
bool Celda::getMina()
{
    return this->mina; // Devuelve el valor del atributo de la clase
}

// Método para establecer el estado de la mina descubierta de la celda. método para establecer el estado de la mina descubierta de la celda. Recibe un parámetro de tipo booleano que indica si la mina de la celda ha sido descubierta o no. Asigna el valor recibido al atributo correspondiente de la clase.
bool Celda::setMinaDescubierta(bool minaDescubierta)
{
    this->minaDescubierta = minaDescubierta;  // Asigna el estado de la mina descubierta recibido al atributo de la clase
}

// Método para obtener el estado de la mina descubierta de la celda. Devuelve el valor del atributo correspondiente de la clase.
bool Celda::getMinaDescubierta()
{
    return this->minaDescubierta; // Devuelve el valor del atributo de la clase
}

// Método para imprimir en consola la informacion de la celda. Imprime la coordenada X, la coordenada Y y el estado de la mina de la celda en la consola.
void Celda::imprimirCelda()
{
    cout << "Celda en " << this->coordenadaX << ", " << this->coordenadaY << " con mina? " << this->mina << "\n";
}
