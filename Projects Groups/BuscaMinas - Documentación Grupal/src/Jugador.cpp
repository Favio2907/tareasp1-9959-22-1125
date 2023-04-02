#include "Jugador.h"

Jugador::Jugador()
{
// Crear un nuevo jugador con el nombre "Diego"
Jugador jugador_actual("Diego");

// Encontrar una mina y restar una vida al jugador
jugador_actual.restarVida();

// Sumar puntos al jugador por encontrar una mina
jugador_actual.sumarScore(10);

// Incrementar el contador de juegos jugados del jugador
jugador_actual.sumarJuego();

// Obtener el nombre del jugador actual
std::cout << "Nombre del jugador actual: " << jugador_actual.getNickname() << std::endl;

// Obtener el score del jugador actual
std::cout << "Score del jugador actual: " << jugador_actual.getScore() << std::endl;

// Obtener el número de juegos jugados del jugador actual
std::cout << "Juegos jugados por el jugador actual: " << jugador_actual.getJuegosJugados() << std::endl;

// Obtener el número de vidas restantes del jugador actual
std::cout << "Vidas restantes del jugador actual: " << jugador_actual.getVidas() << std::endl;
}
