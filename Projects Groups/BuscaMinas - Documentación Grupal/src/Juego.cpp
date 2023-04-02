#include "Juego.h"
#include "Config.h"
#include <iostream>

using namespace std;

// Retorna un n�mero aleatorio en el rango [minimo, maximo].
int Juego::aleatorio_en_rango(int minimo, int maximo)
{
    // La función rand() retorna un número entero aleatorio en el rango [0, RAND_MAX].
    // Por lo tanto, para obtener un número aleatorio en el rango [minimo, maximo], se utiliza la siguiente fórmula:
    // minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1)
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

// Retorna una fila aleatoria en el rango [0, filas-1] del tablero.
int Juego::filaAleatoria()
{
    // Se utiliza la función aleatorio_en_rango para generar un número entero aleatorio en el rango [0, filas-1].
    // El valor de filas se obtiene utilizando el método getAlturaTablero() del objeto Tablero.
    return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
}

// Retorna una columna aleatoria en el rango [0, columnas-1] del tablero.
int Juego::columnaAleatoria()
{
    // Se utiliza la función aleatorio_en_rango para generar un número entero aleatorio en el rango [0, columnas-1].
    // El valor de columnas se obtiene utilizando el método getAnchoTablero() del objeto Tablero.
    return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
}

// Constructor que recibe un objeto Tablero y la cantidad de minas que se colocar�n.
Juego::Juego(Tablero tablero, int cantidadMinas)
{
    // Se guarda el objeto Tablero y la cantidad de minas que se colocarán en el juego.
    this->tablero = tablero;
    this->cantidadMinas = cantidadMinas;
    // Se coloca las minas aleatoriamente en el tablero.
    this->colocarMinasAleatoriamente();

}

// Coloca las minas en el tablero de manera aleatoria.
void Juego::colocarMinasAleatoriamente()
{
    int x, y, minasColocadas = 0;

    while (minasColocadas < this->cantidadMinas)
    {
        // Obtiene una posici�n aleatoria para colocar una mina
        x = this->columnaAleatoria();
        y = this->filaAleatoria();

        // Intenta colocar una mina en la posici�n aleatoria. Si ya hab�a una mina en esa posici�n, no se coloca.
        if (this->tablero.colocarMina(x, y))
        {
            minasColocadas++;
        }
    }
}

int Juego::solicitarFilaUsuario()
{
    // Pide al usuario que ingrese la fila en la que desea jugar.
    int fila = 0;
    cout << "Ingresa la FILA en la que desea jugar: ";
    cin >> fila;

    // Retorna la fila ingresada menos 1, ya que los �ndices del tablero comienzan en 0.
    return fila - 1;
}

int Juego::solicitarColumnaUsuario()
{
    // Pide al usuario que ingrese la columna en la que desea jugar.
    int columna = 0;
    cout << "Ingresa la COLUMNA en la que desea jugar: ";
    cin >> columna;

    // Retorna la columna ingresada menos 1, ya que los �ndices del tablero comienzan en 0.
    return columna - 1;
}

bool Juego::jugadorGana()
{
    // Cuenta el n�mero de celdas que no tienen minas y que a�n no han sido descubiertas.
    int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();

    // Si todas las celdas sin minas est�n descubiertas, el jugador ha ganado.
    if (conteo == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Juego::iniciar()
{
    int fila, columna;

    // Ciclo principal del juego.
    while (true)
    {
        // Imprime el estado actual del tablero.
        this->tablero.imprimir();

        // Pide al usuario que ingrese una fila y columna para descubrir.
        fila = this->solicitarFilaUsuario();
        columna = this->solicitarColumnaUsuario();

        // Descubre la celda seleccionada por el usuario y guarda la respuesta en respuestaAUsuario.
        bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

        // Si la respuesta del usuario es falsa (es decir, la celda seleccionada tenía una mina), el juego termina y se muestra el tablero completo.
        if (!respuestaAUsuario)
			{
				cout << "Perdiste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}

			// Si el jugador ha ganado, se muestra el tablero completo y se termina el juego.
			if (this->jugadorGana())
			{
				cout << "Ganaste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				break;
			}
    }
}
