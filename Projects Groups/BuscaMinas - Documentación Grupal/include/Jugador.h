#ifndef JUGADOR_H
#define JUGADOR_H


class Jugador {
private:
    std::string nickname;
    int score;
    int juegos_jugados;
    int vidas;
public:
    Jugador(std::string nombre) {
        nickname = nombre;
        score = 0;
        juegos_jugados = 0;
        vidas = 3;
    }
    std::string getNickname() const {
        return nickname;
    }
    int getScore() const {
        return score;
    }
    int getJuegosJugados() const {
        return juegos_jugados;
    }
    int getVidas() const {
        return vidas;
    }
    void restarVida() {
        vidas--;
    }
    void sumarScore(int puntos) {
        score += puntos;
    }
    void sumarJuego() {
        juegos_jugados++;
    }
};
