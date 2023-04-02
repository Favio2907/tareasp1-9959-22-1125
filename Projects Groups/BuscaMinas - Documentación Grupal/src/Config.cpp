#include <iostream>
#include <unistd.h>
#include "Config.h"//Incluye el encabezado Config.h que contiene la declaración de funciones

using namespace std;

// Definición del constructor de la clase Config
Config::Config(int filasTablero, int columnasTablero, int minasTablero, bool mododesarrolladorTablero, int vidaTablero)
{
    // Asignación de los valores y parametros iniciales para las variables miembro
    this->filasTablero = filasTablero;//Puntero this para indicar que filasTablero es equivalente a filasTablero y almacenando su contenido
    this->columnasTablero = columnasTablero;//Puntero this para indicar que columnasTablero es equivalente a columnasTablero y almacenando su contenido
    this->minasTablero = minasTablero;//Puntero this para indicar que minasTablero es equivalente a minasTablero y almacenando su contenido
    this->mododesarrolladorTablero = mododesarrolladorTablero;//Puntero this para indicar que mododesarrolladorTablero es equivalente a mododesarrolladorTablero y almacenando su contenido
    this->vidaTablero = vidaTablero;//Puntero this para indicar que vidaTablero es equivalente a vidaTablero y almacenando su contenido
}

// Definición de la función menuConfiguracion de la clase Config, sirve para ejecutar la ventana de configuración
void Config::menuConfiguracion()
{
    srand(getpid());//Permite que la función genere nuevamente valores aleatorios y diferentes en cada reinicio del programa
    int opciones;//Inicializa la variable opciones
    int valorIngresado;//Inicializa la variable valorIngresado
    bool repetir = true;//Establece la variable repetir como booleano con el valor true

    do      //Ciclo while para ejecutar el programa las veces que se desee
    {
        system("cls");//Borra la información en pantalla antes de imprimir el menu configuración
        cout << "\n\n\t\tCONFIGURACION ACTUAL -Menu-" << endl;
        cout << "\t\t---------------------" << endl;
        cout << "\t\t1. Filas del Tablero = " << this-> getFilasTablero() << endl;//Puntero this para acceder al valor de getFilasTablero almacenado en el constructor que es el numero de filas
        cout << "\t\t2. Columnas del Tablero = " << this-> getColumnasTablero() << endl;//Puntero this para acceder al valor de getColumnasTablero almacenado en el constructor que es el numero de columnas
        cout << "\t\t3. Minas del Tablero = " << this-> getminasTablero() << endl;//Puntero this para acceder al valor de getminasTablero almacenado en el constructor que es el numero de minas
        cout << "\t\t4. Modo del Juego = " << this-> getmodoDesarrolladorTablero() << endl;//Puntero this para acceder al valor de getmodoDesarrolladorTablero almacenado en el constructor que indica si el modo desarrollador esta activado o no
        cout << "\t\t5. Vidas del Jugador = " << this-> getvidaTablero() << endl;//Puntero this para acceder al valor de getvidaTablero almacenado en el constructor que es el numero de vidas
        cout << "\t\t6. Retornar al menu general" << endl;//Opcion para regresar al menu general
        cout << "\n\t\tIngrese una opcion: ";//Pide al usuario ingresar un valor
        cin >> opciones;//Toma el valor ingresado por el usuario y lo asigna a la variable opciones
        if (opciones != 6)//Si el valor de opciones es diferente de 6, vuelve a solicitar al usuario que ingrese un valor
        {
            cout << "\n\tIngrese el valor que desea cambiar: ";//Solicita un valor para cambiar la configuración predeterminada del programa
            cin >> valorIngresado;//Toma el valor ingresado por el usuario y lo asigna a la variable valorIngresado
        }
        switch (opciones)//Crea una estructura de control que determina la acción a realizar segun el valor de opciones
        {
        case 1:
            {
                // Si la opción elegida es 1, se llama a la función setFilasTablero
                this -> setFilasTablero(valorIngresado);
                cout << "Filas del Tablero Actualizadas" << endl;
                break;//Finaliza la ejecución del bucle
            }
        case 2:
            {
                // Si la opción elegida es 2, se llama a la función setColumnasTablero
                this -> setColumnasTablero(valorIngresado);
                cout << "Columnas del Tablero Actualizadas" << endl;
                break;//Finaliza la ejecución del bucle
            }
        case 3:
            {
                // Si la opción elegida es 3, se llama a la función setminasTablero
                this -> setminasTablero(valorIngresado);
                cout << "Minas del Tablero Actualizadas" << endl;
                break;//Finaliza la ejecución del bucle
            }
        case 4:
            {
                // Si la opción elegida es 4, se llama a la función setmodoDesarrolladorTablero
                this -> setmodoDesarrolladorTablero(valorIngresado);
                cout << "Modo del Jeugo Actualizado" << endl;
                break;//Finaliza la ejecución del bucle
            }
        case 5:
            {
                // Si la opción elegida es 5, se llama a la función setvidaTablero
                this -> setvidaTablero(valorIngresado);
                cout << "Vidas del Jugador Actualizado" << endl;
                break;//Finaliza la ejecución del bucle
            }
        case 6:
            repetir = false;//Establece la variable booleana repetir como false
            break;//Finaliza la ejecución del bucle
        }
        system("pause");//Detiene la ejecución del programa
    }while(repetir);//Repite el ciclo mientras la variable repetir sea true
}

// Métodos del constructor de tipo entero para obtener y establecer valores de cada variable
int Config::getFilasTablero()//Invoca la funcion publica getFilasTablero para obtener el numero de filas del tablero
{
    return this ->filasTablero;//Retorna el valor de filasTablero
}
int Config::setFilasTablero(int filasTablero)//Establece el valor, con la función setFilasTablero, segun los parametros de configuración de la funcion privada filasTablero
{
    return this->filasTablero = filasTablero;//Retorna el valor de filasTablero y lo almacena en memoria
}

int Config::getColumnasTablero()//Invoca la funcion publica getColumnasTablero para obtener el numero de columnas del tablero
{
    return this ->columnasTablero;//Retorna el valor de columnasTablero
}
int Config::setColumnasTablero(int columnasTablero)//Establece el valor, con la función setColumnasTablero, segun los parametros de configuración de la funcion privada columnasTablero
{
    return this->columnasTablero = columnasTablero;//Retorna el valor de columnasTablero y lo almacena en memoria
}

int Config::getminasTablero()//Invoca la funcion publica getminasTablero para obtener el numero de minas del tablero
{
    return this ->minasTablero;//Retorna el valor de minasTablero
}
int Config::setminasTablero(int minasTablero)//Establece el valor, con la función setminasTablero, segun los parametros de configuración de la funcion privada minasTablero
{
    return this->minasTablero = minasTablero;//Retorna el valor de minasTablero y lo almacena en memoria
}

bool Config::getmodoDesarrolladorTablero()//Invoca la funcion publica getmodoDesarrolladorTablero para obtener el valor true o false del modo desarrollador
{
    return this ->mododesarrolladorTablero;//Retorna el valor de mododesarrolladorTablero
}
bool Config:: setmodoDesarrolladorTablero(bool mododesarrolladorTablero)//Establece el valor true o false, con la función setmodoDesarrolladorTablero, segun los parametros de configuración de la funcion privada mododesarrolladorTablero
{
    return this->mododesarrolladorTablero = mododesarrolladorTablero;//Retorna el valor true o false del mododesarrolladorTablero y lo almacena en memoria
}

int Config::getvidaTablero()//Invoca la funcion publica getvidaTablero para obtener el numero de vidas que proporciona el tablero
{
    return this ->vidaTablero;//Retorna el valor de vidaTablero
}
int Config::setvidaTablero(int vidaTablero)//Establece el valor, con la función setvidaTablero, segun los parametros de configuración de la funcion privada vidaTablero
{
    return this->vidaTablero = vidaTablero;//Retorna el valor de vidaTablero y lo almacena en memoria
}
