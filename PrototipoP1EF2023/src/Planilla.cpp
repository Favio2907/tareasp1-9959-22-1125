// Rama de la planilla
// Favio Lopez, Carnet 9959-22-1125

#include "Planilla.h"
#include "Usuarios.h"
#include "bitacora.h"
#include "Cine.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

Planilla::Planilla()
{

}

void menuCatalogos()
{

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion5 = 7006;

    Usuario ingreso;

    bool salir = false;
    int choice;
    char x;
	do
    {
	system("cls");

    cout << "PrototipoP1EF2023 - Favio Lopez, Carnet 9959-22-1125" << endl;
    cout <<" "<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t| BIENVENIDO AL MENU DE CATALOGO |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Datos Para Planilla"<<endl;
	cout<<"\t\t\t 2. Ingreso Datos Para Usuarios Nuevos"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        //();
		break;
	case 2:
		do // Se utiliza un do-while para permitir al usuario agregar mas de una persona
    	{
    		ingreso.ingresarUsuarios(); // Se llama al m�todo para ingresar nuevos usuarios
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x; // Se pregunta al usuario si desea agregar otra persona
    		file2<<"\t\t\tAccion: Ingreso Un Usuario - " <<accion5<<"\n"<<endl;
		}while(x=='y'||x=='Y'); // Se repite el ciclo mientras la respuesta del usuario sea afirmativa
		break;

    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
    file2.close();
}

void menuProcesos()
{

    Cine cine;

    Usuario ingreso;

    bitacora consulta;


    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout << "PrototipoP1EF2023 - Favio Lopez, Carnet 9959-22-1125" << endl;
    cout <<" "<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE PROCESOS|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Proceso Datos Cine"<<endl;
	cout<<"\t\t\t 2. Proceso Datos Usuarios"<<endl;
	cout<<"\t\t\t 3. Consulta de Bitacora"<<endl;
	cout<<"\t\t\t 4. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cine.iniciarVenta();
		break;
	case 2:
		ingreso.menuUsuarios();
		break;
    case 3:
		consulta.desplegarBitacora();
		system("pause");
		menuProcesos();
		break;

    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 4);
}
void menuInformes()
{

    Usuario ingreso;

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion13 = 7023;

    bool salir = false;
    int choice;
    char x;
	do
    {
	system("cls");

    cout << "PrototipoP1EF2023 - Favio Lopez, Carnet 9959-22-1125" << endl;
    cout <<" "<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE INFORMES  |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Informes Datos Para Planilla"<<endl;
	cout<<"\t\t\t 2. Informes Datos Para Usuarios Nuevos"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        //();
		break;
	case 2:
	    ingreso.desplegarUsurios();
	    file2<<"\t\t\tAccion: Informes Datos para Usuarios - " <<accion13<<"\n"<<endl;
		break;

    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 3);
    file2.close();
}
