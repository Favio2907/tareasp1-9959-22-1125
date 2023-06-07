//Esta es una actualizacion del programa

#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

//Definicion de prototipos
void menuPrincipal();
void menuOperacionesBasicas();
void menuOperacionesExtendidas();

int main()
{
    menuPrincipal();
    return 0;
}

void menuPrincipal()
{
    int opciones;
    bool repetir = true;
    do
    {
        system("cls");
        cout << "\n\n\t\t\t MENU CALCULADORA" << endl;
        cout << "\t\t\t------------------" << endl;
        cout << "\t1. Operaciones Basicas" << endl;
        cout << "\t2. Operaciones Extendidas" << endl;
        cout << "\t3. SALIR" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opciones;
        switch (opciones)
        {
        case 1:
                menuOperacionesBasicas();
                break;
        case 2:
                menuOperacionesExtendidas();
                break;
        case 3:
                repetir = false;
                break;
        }
    } while (repetir);
}
