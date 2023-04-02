#ifndef TABLERO_H
#define TABLERO_H
//Estas dos líneas inician una construcción de preprocesador de C++ que evita que se incluya múltiples veces el mismo archivo de cabecera (header) en el código fuente.
#include <iostream>
#include <vector>
#include "Celda.h"
//Incluye las bibliotecas necesarias para que la clase Tablero funcione correctamente: iostream, vector y "Celda.h" (archivo que define otra clase llamada Celda).
using namespace std;
class Tablero//Clase Tablero
    {
        public:
            Tablero();//Constructor sin argumentos que inicializa un tablero por defecto.
            Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador);//Constructor con argumentos que inicializa un tablero con las dimensiones dadas y modoDesarrollador activado o desactivado.

            int getAlturaTablero();//Devuelve la altura del tablero.
            int setAlturaTablero(int alturaTablero);//Establece la altura del tablero y devuelve el valor anterior.

            int getAnchoTablero();//Devuelve el ancho del tablero.
            int setAnchoTablero(int anchoTablero);//Establece el ancho del tablero y devuelve el valor anterior.

            bool getModoDesarrollador();//Devuelve el valor del modo desarrollador (activado o desactivado).
            bool setModoDesarrollador(bool modoDesarrollador);//Establece el valor del modo desarrollador y devuelve el valor anterior.

            void imprimirSeparadorEncabezado();//Imprime un separador para el encabezado del tablero.
            void imprimirSeparadorFilas();// Imprime un separador entre filas del tablero.
            void imprimirEncabezado();//Imprime el encabezado del tablero.
            void imprimir();//Imprime el tablero completo.

            bool colocarMina(int x, int y);//Coloca una mina en la posición (x, y)
            bool descubrirMina(int x, int y);//Intenta descubrir la celda en la posición (x, y) del tablero, devuelve verdadero si la celda contiene una mina o falso si no la contiene. Si la celda ya ha sido descubierta, no hace nada.

            int contarCeldasSinMinasYSinDescubrir();//Cuenta el número de celdas en el tablero que no contienen minas y aún no han sido descubiertas. Devuelve el número de celdas contadas.

        protected:
        private:

            int alturaTablero, anchoTablero;//Atributos que representan la altura y el ancho del tablero.
            bool modoDesarrollador;//Atributo que indica si el juego está en modo desarrollador o no.
            vector<vector<Celda> > contenidoTablero;//Matriz que representa el contenido del tablero, es decir, las celdas y sus estados (mina, descubierta, etc.).
            string getRepresentacionMina(int x, int y);//Método que devuelve la representación de una mina en la posición (x, y) del tablero.
            int minasCercanas(int fila, int columna);//Método que cuenta el número de minas cercanas a la celda en la posición (fila, columna) del tablero.
};
#endif // TABLERO_H //Esta línea indica el final del bloque de definición de la clase Tablero y el final del archivo de encabezado "Tablero.h".
