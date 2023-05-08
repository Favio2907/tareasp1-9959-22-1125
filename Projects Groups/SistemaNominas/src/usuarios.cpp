#include<cstdlib>
#include<conio.h>
#include<iostream>

#define USER "grupo3"
#define PASS "12345"

using namespace std;
#include "usuarios.h"

usuarios::usuarios()
{
    //ctor
}

usuarios::~usuarios()
{
    //dtor
}
bool usuarios::loginUsuarios(){
    string usuario, contra;
    int contador=0;
    bool ingresa=false;
    do{
        system("cls");
        cout<<"---------------------------"<<endl;
        cout<<" AUTENTICACION DE USUARIOS "<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"Codigo Usuario: ";
        getline(cin,usuario);
        cout<<"\nContrasena: ";

        char caracter;
        caracter = getch();
        contra="";
        while (caracter != 13)
        {
            if (caracter != 0)
            {
                contra.push_back(caracter);
                cout<<"*";
            } else
            {
                if (contra.length() > 0)
                {
                    cout<<"\b \b";
                    contra = contra.substr(0,contra.length()-1);
                }
            }
            caracter = getch();
        }

        if(usuario==USER && contra==PASS){
            ingresa=true;

        } else {
            cout<<"\nEl usuario y/o contrasena son incorrectos"<<endl;
            cin.get();
            contador++;

        }
    } while (ingresa==false && contador<3);
    if (ingresa==false){
        cout<<"\nLo siento, no puede ingresar al sistema, su contrasena es invalida "<<endl;
        cin.get();
    } else {
        cout<<"\n=== Bienvenido al Sistema ==="<<endl;
        cin.get();
    }
    return ingresa;
}
void usuarios::menuUsuarios(){
int choice;

    do {
    system("cls");
    cout<<"\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\t |   SISTEMA GESTION DE NOMINAS - Catalogos Usuarios |"<<endl;
    cout<<"\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\t 1. Ingreso Usuarios"<<endl;
    cout<<"\t\t\t 2. Consulta Usuarios"<<endl;
    cout<<"\t\t\t 3. Modificacion Usuarios"<<endl;
    cout<<"\t\t\t 4. Eliminacion Usuarios"<<endl;
    cout<<"\t\t\t 5. Retorna menu anterior"<<endl;
    cout<<"\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
    cout<<"\t\t\t-----------------------------------------------------"<<endl;
    cout<<"\t\t\tIngresa una Opcion: "<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
        //do
        {
            //catalogos();
            //cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
            //cint>>x;
        }//while(x=='y'||x=='Y');
        break;
    case 2:
        //display();
        break;
    case 3:
        //modify();
        break;
    case 4:
        //search();
        break;
    case 5:
        //break;
    default:
        cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
    }
    cin.get();
    getch();
    }while(choice!= 5);
}
