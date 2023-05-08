#include <iostream>
#include <fstream>
#include <string>
#include "datos.h"
#include "Usuario.h"

using namespace std;

int main() {
    string nombre, apellido, genero;
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
    datos estudiante(id, nombre, apellido,genero, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);


    string usuario, contrasena;
    Usuario ingreso(usuario, contrasena);
    bool usuarioCorrecto = ingreso.verificarUsuario();

    //if (usuarioCorrecto) {
    int choice;
	char x;
	do{
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|  BIENVENIDO AL MENU PRINCIPAL  |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Al Menu de Usurios"<<endl;
	cout<<"\t\t\t 2. Ingreso Al Menu de Plantillas"<<endl;
    cout<<"\t\t\t 3. Ingreso Al Menu de Bitacora"<<endl;
	cout<<"\t\t\t 4. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;
    switch(choice){
    case 1:
        ingreso.menuUsuarios();
        break;
    case 2:
        estudiante.menu();
        break;
    case 3:
        ingreso.menuBitacora();
        break;
    case 4:
        exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;
    }

	getch();
    }while(choice!= 4);

return 0;
}



