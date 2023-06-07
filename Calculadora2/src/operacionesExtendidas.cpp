#include "operacionesExtendidas.h"

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

void factorial();

operacionesExtendidas::operacionesExtendidas()
{

}

//Implementacion de funciones
void menuOperacionesExtendidas()
{
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Operaciones Extendidas" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t1. Factorial" << endl;
        cout << "\t2. SALIR" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
                factorial();
                break;
        case 2: repetir = false;
                break;
        }
    } while (repetir);
}

void factorial()
{
    system("cls");
    int numeroIngresado, i;
    float resultadoFactorial;
    cout << "\n\t\t\tCalculo del Factorial" << endl;
    cout << "\t\t\t---------------------" << endl;
    cout << "\n\tIngrese Numero: ";
    cin >> numeroIngresado;
    resultadoFactorial = 1;
    for (i=1; i <= numeroIngresado; i++)
    {
        resultadoFactorial = resultadoFactorial * i;
    }
    cout << "\t" << numeroIngresado << "! = " << resultadoFactorial << endl;
    system("pause>nul");
}
