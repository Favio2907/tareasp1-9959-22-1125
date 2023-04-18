#ifndef JUEGO_H
#define JUEGO_H
#include "Tablero.h"


/*
 * Clase que representa el juego del buscaminas.
 * Esta clase es responsable de administrar la lógica del juego,
 * incluyendo la colocación de minas, la interacción con el usuario,
 * y la determinación de si el jugador ha ganado o perdido.
 */
class Juego
{
private:
    //Config config;
	Tablero tablero;
	int cantidadMinas;// Inicializa la variable cantidadMinas como entero
	int vidasTablero;// Inicializa la variable vidasTablero como entero

    int aleatorio_en_rango(int minimo, int maximo);   // Retorna un número aleatorio en el rango [minimo, maximo].
    int filaAleatoria();                             // Retorna una fila aleatoria en el rango [0, filas-1] del tablero.
    int columnaAleatoria();                         // Retorna una columna aleatoria en el rango [0, columnas-1] del tablero.
public:

    // Constructor que recibe un objeto Tablero y la cantidad de minas que se colocarón.
    Juego(Tablero tablero, int cantidadMinas, int vidasTablero);

	// Coloca las minas en el tablero de manera aleatoria.
	void colocarMinasAleatoriamente();

	// Pide al usuario que ingrese una fila para descubrir.
	int solicitarFilaUsuario();

    // Pide al usuario que ingrese una columna para descubrir.
	int solicitarColumnaUsuario();

	// Retorna true si el jugador gana el juego (todas las celdas sin minas están descubiertas).
	bool jugadorGana();

	// Inicia el juego.
	void iniciar();

	// Dibuja una portada para un archivo con el nombre especificado en el parámetro "nombreArchivo".
	void dibujarPortada(string nombreArchivo);
};

#endif // JUEGO_H
