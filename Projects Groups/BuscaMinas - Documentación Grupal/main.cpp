#include <iostream>
#include <unistd.h> // Biblioteca para la funci�n getpid()
#include "Juego.h" // Archivo de encabezado para la clase Juego
#include "Config.h" // Archivo de encabezado para la clase Config

using namespace std;

int main() //Es el punto de entrada del programa y comienza definiendo las constantes necesarias para el juego, como el n�mero de filas y columnas en el tablero, el n�mero m�nimo de minas que se deben colocar en el tablero y el n�mero de vidas que tendr� el jugador.
{
    // Definici�n de constantes que se utilizar�n en el juego
    const int FILASTABLERO = 5; // N�mero de filas del tablero
    const int COLUMNASTABLERO = 5; // N�mero de columnas del tablero
    const int MINASENTABLERO = 3; // N�mero de minas en el tablero
    const bool MODODESARROLLADOR = true; // Modo desarrollador: muestra el tablero completo al inicio del juego
    const int VIDASTABLERO = 3; // N�mero de vidas para el jugador

    // Creaci�n de un objeto Config para almacenar la configuraci�n del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    // Creaci�n de un objeto Juego con el tablero y el n�mero de minas especificados en la configuraci�n del juego
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    // Dibuja la portada del juego
    juego.dibujarPortada("portada.txt");

    // Inicializaci�n de la semilla de generaci�n de n�meros aleatorios
    srand(getpid()); // La funci�n getpid() obtiene el ID de proceso actual del sistema operativo para utilizarlo como semilla en la generaci�n de n�meros aleatorios.

    // Variables para almacenar la selecci�n del usuario y controlar el flujo del men�
    int opciones;
    bool repetir = true;

    do
    {
        // Limpia la pantalla
        system("cls"); // Limpia la consola para que el men� se muestre de manera clara.


        // Muestra el men�
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t---------------------" << endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el juego" << endl;
        cout << "\t\t3. Salir del Menu" << endl;
        cout << "\n\t\tIngrese una opcion: ";

        // Lee la selecci�n del usuario5
        cin >> opciones;

        // Ejecuta la acci�n correspondiente seg�n la selecci�n del usuario
        switch (opciones)
        {
        case 1:
            {
                // Abre el men� de configuraci�n y actualiza la configuraci�n del juego
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 2:
            {
                // Crea un objeto Juego con el tablero y el n�mero de minas especificados en la configuraci�n del juego
                Juego juego(Tablero(configuracionJuego.getFilasTablero(), configuracionJuego.getColumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());

                // Inicia el juego
                juego.iniciar();

                // Pausa la ejecuci�n del programa para que el usuario pueda ver los resultados
                system("pause");
                break;
            }
        case 3:
            repetir = false;
            break;
        }
    }while(repetir);
    system("cls");
    juego.dibujarPortada("creditos.txt"); // Muestra una portada de cr�ditos y finaliza el programa. Primero, se llama a la funci�n "dibujarPortada" del objeto "juego" para mostrar la portada de cr�ditos en la pantalla.

    // Indica que el programa se ha ejecutado correctamente
    return 0;
}
