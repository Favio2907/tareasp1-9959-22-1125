#include "UsoMatriz.h"

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int NUMERO_EQUIPOS = 5;
const int NUMERO_LIGAS = 3;
const int MAX_LONGITUD_CADENA = 100;

int busquedaAleatorios(int minimo, int maximo);

void notasEquipo();

const int PFECHA = 1;
const int NOTA = 1;
const int SFECHA = 1;
const int UFECHA = 1;

const int MAX_NOTA = 15;
const int MIN_NOTA = 10;
const int MAX_PFECHA = 15;
const int MIN_PFECHA = 10;
const int MAX_SFECHA = 15;
const int MIN_SFECHA = 10;
const int MAX_UFECHA = 15;
const int MIN_UFECHA = 10;


void llenarMatriz(float matriz[NUMERO_EQUIPOS][PFECHA+1]);
void llenarMatriz1(float matriz1[NUMERO_EQUIPOS][NOTA+1]);
void llenarMatriz2(float matriz2[NUMERO_EQUIPOS][SFECHA+1]);
void llenarMatriz3(float matriz3[NUMERO_EQUIPOS][UFECHA+1]);
void imprimirLineaMatriz();
void imprimirMatriz (float matriz [NUMERO_EQUIPOS][PFECHA+1] , float matriz1 [NUMERO_EQUIPOS][NOTA+1] , float matriz2 [NUMERO_EQUIPOS][SFECHA+1], float matriz3 [NUMERO_EQUIPOS][UFECHA+1], char equipos[NUMERO_EQUIPOS][MAX_LONGITUD_CADENA]);
void imprimirMatriz2 (float matriz [NUMERO_EQUIPOS][PFECHA+1] , float matriz1 [NUMERO_EQUIPOS][NOTA+1] , float matriz2 [NUMERO_EQUIPOS][SFECHA+1], float matriz3 [NUMERO_EQUIPOS][UFECHA+1], char equipos[NUMERO_EQUIPOS][MAX_LONGITUD_CADENA]);

void promedioLigas();
void promedioComparacion();


void menuPrincipal();
void seleccionLigas();
void ingresoNotas();

int busquedaAleatorios(int minimo, int maximo)
 {
     return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) +1);
 }

void menuPrincipal(){
    char opcion;
    int opciones;
    bool repetir = true;
    do{
        system("cls");
        cout << "\n\n\t\tINGRESO DE NOTAS LIGAS"<< endl;
        cout << "\t\t----------------------\n"<< endl;
        cout << "\n\n\t\t  MENU PRINCIPAL"<< endl;
        cout << "\t\t-----------------"<< endl;
        cout << "\t1. Ingreso a Notas"<< endl;
        cout << "\t2. --------SALIR--------"<< endl;
        cout << "\n\t Ingrese una opcion: ";
        cin >> opciones;

        switch (opciones){
        case 1:
            seleccionLigas();
            break;

        case 2:
            cout << "\n\tNo se realizara ninguna operacion"<<endl;
            cout << "\n\tSaliendo del programa"<<endl;
            repetir = false;
            break;

        }
    }while(repetir);
}

void seleccionLigas()
{
    char opcion;
    int opciones = 0;
    bool repetir = true;
    do{
        system("cls");
        cout << "\n\n\t\tSELECCIONE LA OPCION"<< endl;
        cout << "\t\t--------------------\n"<< endl;
        cout << "\n\t\t    MENU LIGAS"<< endl;
        cout << "\t\t-----------------"<< endl;
        cout << "\t1. Liga Nacional"<< endl;
        cout << "\t2. Liga de Ascenso"<< endl;
        cout << "\t3. Liga Segunda Division"<< endl;
        cout << "\t4. Comparar Notas entre Ligas"<< endl;
        cout << "\t5. --------VOLVER--------"<< endl;
        cout << "\n\tPara cambiar las notas por favor reinicie el programa" <<endl;
        cout << "\n\t Ingrese una opcion: ";
        cin >> opciones;

        switch (opciones){
        case 1:
            ingresoNotas();
            break;

        case 2:
            ingresoNotas();
            break;

        case 3:
            ingresoNotas();
            break;

        case 4:
            promedioLigas();
            break;

        case 5:
            repetir = false;
            break;
        }
    }while(repetir);
}


void ingresoNotas()
{
    string fecha;
    system("cls");
    cout<<"Ingrese la fecha de la liga: ";
    cin >> fecha;
    cout<<"Las notas son de la fecha de: "<<fecha<<endl;
    srand(getpid());
    float matriz1 [NUMERO_EQUIPOS][NOTA+1];
    float matriz [NUMERO_EQUIPOS][PFECHA+1];
    float matriz2 [NUMERO_EQUIPOS][SFECHA+1];
    float matriz3 [NUMERO_EQUIPOS][SFECHA+1];

    char equipos[NUMERO_EQUIPOS][MAX_LONGITUD_CADENA] = {"Equipo 1", "Equipo 2", "Equipo 3", "Equipo 4", "Equipo 5"};
    llenarMatriz(matriz);
    llenarMatriz1(matriz1);
    llenarMatriz2(matriz2);
    llenarMatriz2(matriz3);

    imprimirMatriz(matriz,matriz1,matriz2,matriz3,equipos);
    system ("pause > nul");

}

void llenarMatriz(float matriz[NUMERO_EQUIPOS][PFECHA+1])
 {
     for (int y=0; y <  NUMERO_EQUIPOS; y++)
     {
        float sumaNotasGrupo=0;
        for (int x=0; x < PFECHA; x++)
        {
           int calificacionGrupo = busquedaAleatorios(MIN_PFECHA, MAX_PFECHA);
           sumaNotasGrupo += (float)calificacionGrupo;
           matriz [y][x] = calificacionGrupo;
        }
        float promedioNotasEquipo = sumaNotasGrupo / PFECHA;
        matriz [y][PFECHA]=promedioNotasEquipo;

    }
 }
void llenarMatriz1(float matriz1[NUMERO_EQUIPOS][NOTA+1])
 {
     for (int y=0; y <  NUMERO_EQUIPOS; y++)
     {
        float sumaNotasGrupo=0;
        for (int x=0; x < NOTA; x++)
        {
           int calificacionGrupo = busquedaAleatorios(MIN_NOTA, MAX_NOTA);
           sumaNotasGrupo += (float)calificacionGrupo;
           matriz1 [y][x] = calificacionGrupo;
        }
        float promedioNotasEquipo = sumaNotasGrupo / NOTA;
        matriz1 [y][NOTA]=promedioNotasEquipo;

 }
 }
  void llenarMatriz2(float matriz2[NUMERO_EQUIPOS][SFECHA+1])
 {
     for (int y=0; y <  NUMERO_EQUIPOS; y++)
     {
        float sumaNotasGrupo=0;
        for (int x=0; x < SFECHA; x++)
        {
           int calificacionGrupo = busquedaAleatorios(MIN_SFECHA, MAX_SFECHA);
           sumaNotasGrupo += (float)calificacionGrupo;
           matriz2 [y][x] = calificacionGrupo;
        }
        float promedioNotasEquipo = sumaNotasGrupo / SFECHA;
        matriz2 [y][SFECHA]=promedioNotasEquipo;

 }
 }
 void llenarMatriz3(float matriz3[NUMERO_EQUIPOS][UFECHA+1])
 {
     for (int y=0; y <  NUMERO_EQUIPOS; y++)
     {
        float sumaNotasGrupo=0;
        for (int x=0; x < UFECHA; x++)
        {
           int calificacionGrupo = busquedaAleatorios(MIN_UFECHA, MAX_UFECHA);
           sumaNotasGrupo += (float)calificacionGrupo;
           matriz3 [y][x] = calificacionGrupo;
        }
        float promedioNotasEquipo = sumaNotasGrupo / UFECHA;
        matriz3 [y][SFECHA]=promedioNotasEquipo;

 }
 }



 void imprimirMatriz (float matriz [NUMERO_EQUIPOS][PFECHA+1] , float matriz1 [NUMERO_EQUIPOS][NOTA+1] , float matriz2 [NUMERO_EQUIPOS][SFECHA+1], float matriz3 [NUMERO_EQUIPOS][UFECHA+1], char equipos[NUMERO_EQUIPOS][MAX_LONGITUD_CADENA])
{
    float promedioMayor = matriz[0][PFECHA];
    float promedioMenor = matriz[0][PFECHA];
    float promedioMayor1 = matriz1[0][NOTA];
    float promedioMenor1 = matriz1[0][NOTA];
    float promedioMayor2 = matriz2[0][SFECHA];
    float promedioMenor2 = matriz2[0][SFECHA];
    float promedioMayor3 = matriz3[0][UFECHA];
    float promedioMenor3 = matriz3[0][UFECHA];

    char alumnoPromedioMayor [MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor [MAX_LONGITUD_CADENA];

    memcpy(alumnoPromedioMayor, equipos[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, equipos[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout <<"|   Equipos   |";
    for (int x=0; x < NOTA; x++)
    {
        cout<<"NOTA   |";
    }
    for (int x=0; x < PFECHA; x++)
    {
        cout<<"Primer Parcial|";
    }
     for (int x=0; x < SFECHA; x++)
    {
        cout<<"Segundo Parcial|";
    }
    for (int x=0; x < UFECHA; x++)
    {
        cout<<"Parcial Final|";
    }

    cout <<("Total Zona     |");
    cout <<("Promedio       |\n");
    imprimirLineaMatriz();
    float notaMayor=0;
    float equipoMayor;
    for (int y=0; y< NUMERO_EQUIPOS; y++)
    {
        cout <<"|  "<<equipos[y]<<"   |";
        float suma = 0;
        for (int x=0; x< NOTA; x++)
        {
            int calificacion = matriz[y][x];
            cout <<"  "<<calificacion<<"  |";
        }
        for (int x=0; x< PFECHA; x++)
        {
            int calificacion = matriz1[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }
        for (int x=0; x< SFECHA; x++)
        {
            int calificacion = matriz2[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }
        float zonaPasar = matriz [y][PFECHA]+matriz1 [y][NOTA]+matriz2 [y][SFECHA];
        float zona = matriz [y][PFECHA]+matriz1 [y][NOTA]+matriz2 [y][SFECHA]+matriz3 [y][UFECHA];
        if (zonaPasar <=25)
        {
            for (int x=0; x< UFECHA; x++)
        {
            int calificacion = matriz3[y][x]-matriz3[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }


                float zonaPasar = matriz [y][PFECHA]+matriz1 [y][NOTA]+matriz2 [y][SFECHA];
                cout<<"\t"<< fixed << setprecision(2)<< (double) zonaPasar<<"    |";
                float promedio = (zonaPasar)/4;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";

        }
        else if (zona <=60)
        {
             for (int x=0; x< UFECHA; x++)
        {
            int calificacion = matriz3[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }



                if(zona>notaMayor)
                {

                    equipoMayor= y;
                }

        }else
        {
            for (int x=0; x< UFECHA; x++)
            {
                int calificacion = matriz3[y][x];
                cout <<"\t"<<calificacion<<"\t|";
            }


            cout<<"\t"<< fixed << setprecision(2)<< (double) zona<<"    |";
            float promedio = (zona)/4;
            cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";
            if(zona>notaMayor)
            {
                notaMayor=zona;
                equipoMayor= y;
            }

        }
        imprimirLineaMatriz();

    }
    int y = equipoMayor;
    cout << "El mejor equipo de la liga es " << equipos[y] << " con "<< notaMayor << endl;

}


 void imprimirMatriz2 (float matriz [NUMERO_EQUIPOS][PFECHA+1] , float matriz1 [NUMERO_EQUIPOS][NOTA+1] , float matriz2 [NUMERO_EQUIPOS][SFECHA+1], float matriz3 [NUMERO_EQUIPOS][UFECHA+1], char equipos[NUMERO_EQUIPOS][MAX_LONGITUD_CADENA])
{

    float mejorLig=0;
    float mejorLigNum=0;
    float notaMayor;
    int mejorGruoLigas=0;
    float mejorGrupLigNum=0;
    float promedioGenLig=0;
    char ligas[NUMERO_LIGAS][MAX_LONGITUD_CADENA] = {"Liga Nacional","Liga de Ascenso","Liga Segunda Division"};


    for (int f = 0; f < NUMERO_LIGAS; f++)
    {
        llenarMatriz(matriz);
        llenarMatriz1(matriz1);
        llenarMatriz2(matriz2);
        llenarMatriz2(matriz3);


        cout << "\n\nNotas para la " << ligas[f] << endl;

        float promedioMayor = matriz[0][PFECHA];
        float promedioMenor = matriz[0][PFECHA];
        float promedioMayor1 = matriz1[0][NOTA];
        float promedioMenor1 = matriz1[0][NOTA];
        float promedioMayor2 = matriz2[0][SFECHA];
        float promedioMenor2 = matriz2[0][SFECHA];
        float promedioMayor3 = matriz3[0][UFECHA];
        float promedioMenor3 = matriz3[0][UFECHA];

        char grupoPromedioMayor [MAX_LONGITUD_CADENA];
        char grupoPromedioMenor [MAX_LONGITUD_CADENA];

        memcpy(grupoPromedioMayor, equipos[0], MAX_LONGITUD_CADENA);
        memcpy(grupoPromedioMenor, equipos[0], MAX_LONGITUD_CADENA);
        imprimirLineaMatriz();
        cout <<"|   Equipos   |";
        for (int x=0; x < NOTA; x++)
        {
            cout<<" 2010 |";
        }
        for (int x=0; x < PFECHA; x++)
        {
            cout<<" 2011 |";
        }
        for (int x=0; x < SFECHA; x++)
        {
            cout<<" 2012 |";
        }
        for (int x=0; x < UFECHA; x++)
        {
            cout<<" 2014 |";
        }

        cout <<("Total Puntaje |");
        cout <<("   Promedio    |\n");
        imprimirLineaMatriz();
        float notaMayor=0;
        float equipoMayor;
        for (int y=0; y< NUMERO_EQUIPOS; y++)
        {
            cout <<"|  "<<equipos[y]<<"   |";
            float suma = 0;
            for (int x=0; x< NOTA; x++)
            {
                int calificacion = matriz[y][x];
                cout <<"  "<<calificacion<<"  |";
            }
            for (int x=0; x< PFECHA; x++)
            {
                int calificacion = matriz1[y][x];
                cout <<"  "<<calificacion<<"  |";
            }
            for (int x=0; x< SFECHA; x++)
            {
                int calificacion = matriz2[y][x];
                cout <<"  "<<calificacion<<"  |";
            }
            float zonaPasar = matriz [y][PFECHA]+matriz1 [y][NOTA]+matriz2 [y][SFECHA];
            float zona = matriz [y][PFECHA]+matriz1 [y][NOTA]+matriz2 [y][SFECHA]+matriz3 [y][UFECHA];
            promedioGenLig+=zona;
            if (zonaPasar <=25)
            {
                for (int x=0; x< UFECHA; x++)
                {
                    int calificacion = matriz3[y][x]-matriz3[y][x];
                    cout <<"  "<<calificacion<<"  |";
                }



                float zonaPasar = matriz [y][PFECHA]+matriz1 [y][NOTA]+matriz2 [y][SFECHA];
                cout<<"\t"<< fixed << setprecision(2)<< (double) zonaPasar<<"    |";
                float promedio = (zonaPasar)/4;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";

            }
            else if (zona <=60)
            {
                for (int x=0; x< UFECHA; x++)
                {
                    int calificacion = matriz3[y][x];
                    cout <<"  "<<calificacion<<"  |";
                }

                float zona1 = matriz [y][PFECHA]+matriz1 [y][NOTA]+matriz2 [y][SFECHA];
                cout<<"\t"<< fixed << setprecision(2)<< (double) zona1<<"    |";
                float promedio = (zona1)/3;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";
                if(zona1>notaMayor)
                {
                    notaMayor=zona1;
                    equipoMayor= y;
                }

            }else
            {
                for (int x=0; x< UFECHA; x++)
                {
                    int calificacion = matriz3[y][x];
                    cout <<"  "<<calificacion<<"  |";
                }

                cout<<"\t"<< fixed << setprecision(2)<< (double) zona<<"    |";
                float promedio = (zona)/4;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";
                if(zona>notaMayor)
                {
                    notaMayor=zona;
                    equipoMayor= y;
                }

            }
            imprimirLineaMatriz();

        }
    int y = equipoMayor;
    cout << "El mejor equipo de la Liga es " << equipos[y] << " con "<< notaMayor << endl;

    if(notaMayor>mejorLig)
    {
        mejorLig = notaMayor;
        mejorLigNum = f;
    }
    if(equipoMayor>mejorGruoLigas)
    {
        mejorGruoLigas = equipoMayor;
        mejorGrupLigNum = f;
    }
    }


    int f = mejorLigNum;
    int j = mejorGrupLigNum;
    promedioGenLig= promedioGenLig/30;

    cout << "\nLa mejor liga es: " << ligas[f] << endl;
    cout << "El mejor equipo por las 3 Ligas: " << equipos[j]<< endl;
    cout << "Promedio general de las 3 Ligas: " << promedioGenLig << endl;

    system ("pause > nul");
}

 void imprimirLineaMatriz()
 {
     cout <<"+--------------------------------------------";
     for (int x=0; x < SFECHA; x++)
     {
        cout<<"----------------------------";
     }
     cout <<"+\n";
 }

void promedioLigas()
{
    srand(getpid());
    string fecha;
    system("cls");
    cout<<"Ingrese la fecha de la liga: ";
    cin >> fecha;
    cout<<"\nLas notas son de la fecha de: "<<fecha << endl;
    float matriz1 [NUMERO_EQUIPOS][NOTA+1];
    float matriz [NUMERO_EQUIPOS][PFECHA+1];
    float matriz2 [NUMERO_EQUIPOS][SFECHA+1];
    float matriz3 [NUMERO_EQUIPOS][SFECHA+1];

    char equipos[NUMERO_EQUIPOS][MAX_LONGITUD_CADENA] = {"Equipo 1", "Equipo 2", "Equipo 3", "Equipo 4", "Equipo 5"};


    imprimirMatriz2(matriz,matriz1,matriz2,matriz3, equipos);

    system ("pause > nul");
}
