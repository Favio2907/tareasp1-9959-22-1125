#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<stdio.h>
#include <unistd.h>
#include <string.h>
using namespace std;

const string ADMIN_USERNAME = "Administrador";
const string ADMIN_PASSWORD = "2003";

// Definición de estructuras
struct Producto {
    int codigo;
    string nombre;
    double precio;
};

struct Cliente {
    int id;
    string nombre;
    string direccion;
};

class persona
{
	private:
		string nombre,direccion,id,NombreProducto;
	public:

		void menu();
		void menuCatalogos();
		void insertar();
		void insertar1();
		void desplegar();
};

void authenticate() {
    string username, password;
    int attempts = 3;
    while (attempts > 0) {
        system("cls");
        cout <<"\t\t\t-------------------------"<<endl;
        cout <<"\t\t\t|   LONGIN DE USUARIO   |"<<endl;
        cout <<"\t\t\t-------------------------"<<endl;
        cout <<" "<<endl;
        // Mostrar mensaje de advertencia
        cout <<"\n\tAdvertencia: Solo tienes permitido 3 intentos!!!"<<endl;
        cout <<"\t------------------------------------------------"<<endl;
        cout <<" "<<endl;
        cout << "Ingrese el nombre de usuario: ";
        cin >> username;
        cout << "Ingrese la contrasena: ";


        char c;
        password = "";
        while ((c = getch()) != '\r') { // Leer caracteres hasta que se presione Enter
            if (c == '\b' && password.length() > 0) { // Si se presiona Backspace, borrar último caracter ingresado
                password.pop_back();
                cout << "\b \b";
            } else if (isprint(c)) { // Si es un caracter imprimible, agregar a la contraseña
                password += c;
                cout << "*";
            }
        }

        if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
            return;
        } else {
            cout << endl << "Credenciales incorrectas. Intenta de nuevo." << endl;
            attempts--;
        }
    }
    cout << "Demasiados intentos fallidos. Saliendo del programa." << endl;
    exit(0);
}

int main() {
    authenticate();

    persona estudiante;
	estudiante.menu();
	estudiante.menuCatalogos();

    return 0;
}


void persona::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");
    // Mostrar título con carnet y nombre completo
    cout << "Prototipo2PP12023  - Favio Lopez, Carnet 9959-22-1125" << endl;
    cout <<" "<<endl;

	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"\t\t\t|       MENU GENERAL       |"<<endl;
	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"\t\t\t 1. Catalogos"<<endl;
	cout<<"\t\t\t 2. Informes - Reportes"<<endl;
	cout<<"\t\t\t 3. Salir del sistema"<<endl;

	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	menuCatalogos();
		break;
	case 2:
		desplegar();
		break;
	case 3:
		exit(0);
		break;
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 3);
}

void persona::menuCatalogos()
{

    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t--- SubMenu de Catalogos ---"<<endl;
	cout <<" "<<endl;
	cout<<"\t\t\t 1. Clientes"<<endl;
	cout<<"\t\t\t 2. Producto"<<endl;
	cout<<"\t\t\t 3. Regresar al Menu General"<<endl;

	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl;
	cout<<"\t\t\t----------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
		insertar1();
		break;

	case 2:
		insertar();
		break;
	case 3:
		menu();
		break;
	}
	getch();
    }while(choice!= 3);
}

void persona::insertar1()
{
	system("cls");

	fstream file;
    cout<<"\t\t\tIngrese el nombre del cliente     :  ";
	cin>>nombre;
	cout<<"\t\t\tIngrese la direccion del cleinte  :  ";
	cin>>direccion;
	file.open("ParticipantRecord.txt", ios::app | ios::out);
	file
	<<std::setw(15)<<std::left<<std::setw(15)<< nombre
	<<std::setw(15)<<std::left<<std::setw(15)<< direccion << "\n";
	file.close();
}

void persona::insertar()
{
	system("cls");

	fstream file;
    cout<<"\t\t\tIngrese el ID del producto     :  ";
	cin>>id;
	cout<<"\t\t\tIngrese el nombre del producto :  ";
	cin>>NombreProducto;
	file.open("ParticipantRecord.txt", ios::app | ios::out);
	file
	<<std::setw(15)<<std::left<<std::setw(15)<< id
	<<std::setw(15)<<std::left<<std::setw(15)<< NombreProducto << "\n";
	file.close();
}
void persona::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		file >> nombre >> direccion >> id >> NombreProducto;
		while(!file.eof())
		{
			total++;
			cout<<""<<endl;
			cout<<"\t\t\t Nombre Persona     : "<<nombre<<endl;
			cout<<"\t\t\t Direccion Persona  : "<<direccion<<endl;
			cout<<"\t\t\t ID de Producto     : "<<id<<endl;
			cout<<"\t\t\t Nombre de Producto : "<<NombreProducto<<endl;
			file >> id >> NombreProducto >> nombre >> direccion;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
