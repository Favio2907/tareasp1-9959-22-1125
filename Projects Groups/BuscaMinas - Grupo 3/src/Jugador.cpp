#include "Jugador.h" // Incluimos el archivo de encabezado "Jugador.h"
#include <iostream> // Incluimos la biblioteca iostream para utilizar la funci�n cout

// Implementaci�n del constructor de la clase Jugador
Jugador::Jugador(int vidas) : vida(vidas)
{
}

// Implementaci�n del m�todo para obtener la vida del jugador
void Jugador::obtenerVida() {
    std::cout << "La vida del jugador es: " << vida << std::endl;
}

// Implementaci�n del m�todo para disminuir la vida del jugador
int Jugador::disminuirVida()
{
     vida--; // Disminuimos la vida del jugador en 1
     return vida; // Devolvemos el nuevo valor de la vida del jugador
}
