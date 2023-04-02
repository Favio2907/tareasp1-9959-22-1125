#include <iostream>
#include <unistd.h> // Biblioteca para la función getpid()
#include "Juego.h" // Archivo de encabezado para la clase Juego
#include "Config.h" // Archivo de encabezado para la clase Config

using namespace std;

int main() //Es el punto de entrada del programa y comienza definiendo las constantes necesarias para el juego, como el número de filas y columnas en el tablero, el número mínimo de minas que se deben colocar en el tablero y el número de vidas que tendrá el jugador.
{
    // Definición de constantes que se utilizarán en el juego
    const int FILASTABLERO = 5; // Número de filas del tablero
    const int COLUMNASTABLERO = 5; // Número de columnas del tablero
    const int MINASENTABLERO = 3; // Número de minas en el tablero
    const bool MODODESARROLLADOR = true; // Modo desarrollador: muestra el tablero completo al inicio del juego
    const int VIDASTABLERO = 3; // Número de vidas para el jugador

    // Creación de un objeto Config para almacenar la configuración del juego
    Config configuracionJuego(FILASTABLERO, COLUMNASTABLERO, MINASENTABLERO, MODODESARROLLADOR, VIDASTABLERO);
    // Creación de un objeto Juego con el tablero y el número de minas especificados en la configuración del juego
    Juego juego(Tablero(configuracionJuego.getfilasTablero(), configuracionJuego.getcolumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());
    // Dibuja la portada del juego
    juego.dibujarPortada("portada.txt");

    // Inicialización de la semilla de generación de números aleatorios
    srand(getpid()); // La función getpid() obtiene el ID de proceso actual del sistema operativo para utilizarlo como semilla en la generación de números aleatorios.

    // Variables para almacenar la selección del usuario y controlar el flujo del menú
    int opciones;
    bool repetir = true;

    do
    {
        // Limpia la pantalla
        system("cls"); // Limpia la consola para que el menú se muestre de manera clara.


        // Muestra el menú
        cout << "\n\n\t\tBUSCA MINAS -Menu-" << endl;
        cout << "\t\t---------------------" << endl;
        cout << "\t\t1. Configuracion del Juego" << endl;
        cout << "\t\t2. Iniciar el juego" << endl;
        cout << "\t\t3. Salir del Menu" << endl;
        cout << "\n\t\tIngrese una opcion: ";

        // Lee la selección del usuario5
        cin >> opciones;

        // Ejecuta la acción correspondiente según la selección del usuario
        switch (opciones)
        {
        case 1:
            {
                // Abre el menú de configuración y actualiza la configuración del juego
                configuracionJuego.menuConfiguracion();
                break;
            }
        case 2:
            {
                // Crea un objeto Juego con el tablero y el número de minas especificados en la configuración del juego
                Juego juego(Tablero(configuracionJuego.getFilasTablero(), configuracionJuego.getColumnasTablero(), configuracionJuego.getmodoDesarrolladorTablero()), configuracionJuego.getminasTablero());

                // Inicia el juego
                juego.iniciar();

                // Pausa la ejecución del programa para que el usuario pueda ver los resultados
                system("pause");
                break;
            }
        case 3:
            repetir = false;
            break;
        }
    }while(repetir);
    system("cls");
    juego.dibujarPortada("creditos.txt"); // Muestra una portada de créditos y finaliza el programa. Primero, se llama a la función "dibujarPortada" del objeto "juego" para mostrar la portada de créditos en la pantalla.

    // Indica que el programa se ha ejecutado correctamente
    return 0;
}
