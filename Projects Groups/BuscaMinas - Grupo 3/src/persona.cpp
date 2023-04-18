#include "persona.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <unistd.h>

using namespace std;

persona::persona(string id, string name, string fecha, int tiempo, int score)
{
    this->id = id;
    this->name = name;
    this->fecha = fecha;
    this->tiempo = tiempo;
    this->score = score;

}
// Setter y Getter de id
string persona::setId(string id)
{
    this->id = id;
}
string persona::getId()
{
    return this->id;
}

// Setter y Getter de name
string persona::setName(string name)
{
    this->name = name;
}
string persona::getName()
{
    return this->name;
}

// Setter y Getter de Fecha
string persona::setFecha(string fecha)
{
    this->fecha = fecha;
}
string persona::getFecha()
{
    return this->fecha;
}

// Setter y Getter de Tiempo
int persona::setTiempo(int tiempo)
{
    this->tiempo = tiempo;
}
int persona::getTiempo()
{
    return this->tiempo;
}

// Setter y Getter de Score
int persona::setScore(int score)
{
    this->score = score;
}
int persona::getScore()
{
    return this->score;
}


void persona::menu()
{
    int opcion;
	char x;
	bool repetir = true;

	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA REGISTRO PERSONA  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de Usuario"<<endl;
	cout<<"\t\t\t 2. Despliegue de Usuarios"<<endl;
	cout<<"\t\t\t 3. Modificar los Usuarios"<<endl;
	cout<<"\t\t\t 4. Buscar los Usuarios"<<endl;
	cout<<"\t\t\t 5. Borrar Usuarios"<<endl;
	cout<<"\t\t\t 6. Salir"<<endl;

	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		desplegar();
		break;
	case 3:
		modificar();
		break;
	case 4:
		buscar();
		break;
	case 5:
		borrar();
		break;
	case 6:
		repetir = false;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	system("pause");
    }while(repetir);
}
void persona::menu1()
{
    int opcion;
	char x;
	bool repetir = true;

	do
    {
	system("cls");

	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA SCORES USUARIOS   |"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t 1. Despliegue de Scores"<<endl;
	cout<<"\t\t\t 2. Salir"<<endl;

	cout<<"Ingresa tu Opcion: ";
    cin>>opcion;

    switch(opcion)
    {
	case 1:
		desplegar1();
		break;
	case 2:
		repetir = false;
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	system("pause");
    }while(repetir);
}
void persona::ingresoTiempo()
{
	fstream file;
	int found=0;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Usuario------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Usuario------------------------"<<endl;
		cout<<"\nPorfavor ingrese su Id del Usuario: ";
		cin>>participant_id;
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id==id)
			{
            file.open("RegistroDeJuego.txt", ios::app | ios::out);
            file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< "TIEMPO OBTENIDO: " << tiempo << " segundos" <<std::left<<std::setw(15)<< "\tPUNTUACION FINAL: " << score << " puntos"<< "\n";
            file.close();
            found++;
			}
			file >> id >> name >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
			cout<<"\n\t\t\t Se usara el ultimo usuario activo...";

		}else{
            cout << "\n\t\t\t Registro guardado exitosamente..." << endl;
            sleep(2);
		}

		file.close();
	}
}
void persona::insertar()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Usuario ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Usuario         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre de Usuario     : ";
	cin>>name;
	cout<<"\t\t\tFecha del Registro: ";
	cin>>fecha;
    file.open("ParticipantRecord1.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
	file.close();
}
void persona::insertar1()
{
	system("cls");
	fstream file;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Usuario ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Usuario         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre de Usuario     : ";
	cin>>name;
	cout<<"\t\t\tFecha del Registro: ";
	cin>>fecha;
    file.open("RegistroDeJuego.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< "TIEMPO OBTENIDO: " << tiempo << " segundos" <<std::left<<std::setw(15)<< "\tPUNTUACION FINAL: " << score << " puntos"<< "\n";
	file.close();
	file.open("ParticipantRecord1.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
	file.close();
	cout << "\n\t\t\tRegistro guardado exitosamente..." << endl;
    sleep(2);
}

void persona::desplegar1()
{
    system("cls");
    fstream file;
    string line;
    cout<<"\n--------------------------------------------- Tabla de Scores ---------------------------------------------"<<endl;
    file.open("RegistroDeJuego.txt", ios::in);
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}
void persona::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n--------------------------------------------- Tabla de Scores ---------------------------------------------"<<endl;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Id Usuario: "<<id<<endl;
			cout<<"\t\t\t Nombre de Usuario: "<<name<<endl;
			cout<<"\t\t\t Fecha del Registro: "<<fecha<<endl;
			file >> id >> name >> fecha;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void persona::modificar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Modificacion Detalles Usuario-------------------------"<<endl;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		cin>>participant_id;
		file1.open("Record1.txt",ios::app | ios::out);
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id Usuario: ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre Usuario ";
				cin>>name;
				cout<<"\t\t\tFecha del Registro: ";
				cin>>fecha;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
				found++;
			}
			file >> id >> name >> fecha;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord1.txt");
		rename("Record1.txt","ParticipantRecord1.txt");
	}
}
void persona::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Usuario buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Usuario buscado------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id del Usuario: "<<id<<endl;
				cout<<"\t\t\t Nombre Del Usuario: "<<name<<endl;
				cout<<"\t\t\t Fecha del Registro: "<<fecha<<endl;
				found++;
			}
			file >> id >> name >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void persona::buscar1()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Usuario------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Usuario------------------------"<<endl;
		cout<<"\nIngrese Id del Usuario: ";
		cin>>participant_id;
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id del Usuario: "<<id<<endl;
				cout<<"\t\t\t Nombre Del Usuario: "<<name<<endl;
				cout<<"\t\t\t Fecha del Registro: "<<fecha<<endl;
				found++;
			}
			file >> id >> name >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}
void persona::borrar()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
	cout<<"\n-------------------------Detalles del Usuario a Borrar-------------------------"<<endl;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		cin>>participant_id;
		file1.open("Record1.txt",ios::app | ios::out);
		file >> id >> name >> fecha;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< fecha << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> fecha;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("ParticipantRecord1.txt");
		rename("Record1.txt","ParticipantRecord1.txt");
	}
}

void persona::nuevaPartida()
{
    int opcion;
	bool repetir = true;

    do
    {
        system("cls");

        cout<<"\t\t\t---------------------------------------"<<endl;
        cout<<"\t\t\t | SISTEMA REGISTRO DE NUEVA PARTIDA  |"<<endl;
        cout<<"\t\t\t---------------------------------------"<<endl;
        cout<<"\t\t\t 1. Registrar como nuevo usuario"<<endl;
        cout<<"\t\t\t 2. Guardar con el usuario actual"<<endl;
        cout<<"\t\t\t 3. Salir"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                insertar1();//Registrar nuevo usuario
                break;
            case 2:
                ingresoTiempo();//Usar un usuario existente
                break;
            case 3:
                repetir = false;
                break;
        }
    }while(repetir);
}
