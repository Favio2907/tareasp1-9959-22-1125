#include "operacionesBasicas.h"

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

void sumar();
void restar();
void multiplicar();
void dividir();

operacionesBasicas::operacionesBasicas()
{

}

//Implementacion de funciones
void menuOperacionesBasicas()
{
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\t\tMenu Operaciones Basicas" << endl;
        cout << "\t\t\t------------------------" << endl;
        cout << "\t1. Sumar dos numeros" << endl;
        cout << "\t2. Restar dos numeros" << endl;
        cout << "\t3. Multiplicar dos numeros" << endl;
        cout << "\t4. Dividir dos numeros" << endl;
        cout << "\t5. SALIR" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
                sumar();
                break;
        case 2:
                restar();
                break;
        case 3:
                multiplicar();
                break;
        case 4:
                dividir();
                break;
        case 5: repetir = false;
                break;
        }
    } while (repetir);
}

void sumar()
{
    int primerNumero, segundoNumero;
    float resultadoSumar;

    system("cls");
    cout << "\n\tIngrese primer Numero: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Numero: ";
    cin >> segundoNumero;
    cout << "\n\t-----------------------------------" << endl;
    resultadoSumar = primerNumero + segundoNumero;
    cout << "\tResultado de la suma: " << resultadoSumar << endl;
    system("pause>nul");
}

void restar()
{
    int primerNumero, segundoNumero;
    float resultadoRestar;

    system("cls");
    cout << "\n\tIngrese primer Numero: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Numero: ";
    cin >> segundoNumero;
    cout << "\n\t-----------------------------------" << endl;
    resultadoRestar = primerNumero - segundoNumero;
    cout << "\tResultado de la resta: " << resultadoRestar << endl;
    system("pause>nul");
}

void multiplicar()
{
    int primerNumero, segundoNumero;
    float resultadoMultiplicar;

    system("cls");
    cout << "\n\tIngrese primer Numero: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Numero: ";
    cin >> segundoNumero;
    cout << "\n\t-----------------------------------" << endl;
    resultadoMultiplicar = primerNumero * segundoNumero;
    cout << "\tResultado de la multiplicacion: " << resultadoMultiplicar << endl;
    system("pause>nul");
}

void dividir()
{
    int primerNumero, segundoNumero;
    float resultadoDividir;

    system("cls");
    cout << "\n\tIngrese primer Numero: ";
    cin >> primerNumero;
    cout << "\n\tIngrese segundo Numero: ";
    cin >> segundoNumero;
    cout << "\n\t-----------------------------------" << endl;
    if (segundoNumero == 0)
    {
        cout << "\tSegundo numero no puede ser cero (0) ERROR" << endl;
    } else
    {
        resultadoDividir = primerNumero / segundoNumero;
        cout << "\tResultado de la division: " << resultadoDividir << endl;
    }
    system("pause>nul");
}
