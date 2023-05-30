#include "Planilla.h"
#include "Usuarios.h"
#include "bitacora.h"
#include "DatosEmpleado.h"
//#include "Puesto.h"
//#include "Departamento.h"

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
    string nombre, apellido, genero, puesto, departamento;
    int numero;
    int id;
    int dia, mes, dpi, telefono, telefono1 , numCuenta;
    float sueldo;
    float bonificacionIncentiva = 250;
    float comisiones;
    float percepciones_extra;
    float horas_extra;
    float total_percepciones;
    float isr;
    float iggs;
    float irtra = 75;
    float prestamos;
    float deducciones_totales;
    float sueldo_liquido;
    DatosEmpleado empleado(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);


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
        empleado.menuDatos();
		break;
	case 2:
		do // Se utiliza un do-while para permitir al usuario agregar más de una persona
    	{
    		ingreso.ingresarUsuarios(); // Se llama al método para ingresar nuevos usuarios
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
    string nombre, apellido, genero, puesto, departamento;
    int id;
    int dia, mes, dpi, telefono, telefono1 , numCuenta;
    float sueldo;
    float bonificacionIncentiva = 250;
    float comisiones;
    float percepciones_extra;
    float horas_extra;
    float total_percepciones;
    float isr;
    float iggs;
    float irtra = 75;
    float prestamos;
    float deducciones_totales;
    float sueldo_liquido;
    DatosEmpleado empleado(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);

    Usuario ingreso;

    bitacora consulta;


    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|BIENVENIDO AL MENU DE PROCESOS|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Proceso Datos Planilla"<<endl;
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
        empleado.menuProcesosEmpleado();
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
    string nombre, apellido, genero, puesto, departamento;
    int id;
    int dia, mes, dpi, telefono, telefono1 , numCuenta;
    float sueldo;
    float bonificacionIncentiva = 250;
    float comisiones;
    float percepciones_extra;
    float horas_extra;
    float total_percepciones;
    float isr;
    float iggs;
    float irtra = 75;
    float prestamos;
    float deducciones_totales;
    float sueldo_liquido;
    DatosEmpleado empleado(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);

    Usuario ingreso;

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion12 = 7022;
    int accion13 = 7023;

    bool salir = false;
    int choice;
    char x;
	do
    {
	system("cls");

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
        empleado.desplegar();
        file2<<"\t\t\tAccion: Informes Datos para Planilla - " <<accion12<<"\n"<<endl;
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
