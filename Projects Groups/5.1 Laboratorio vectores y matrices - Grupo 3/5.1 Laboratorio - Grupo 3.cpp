//5.1 Laboratorio vectores y matrices - Grupo 3

//Este ejemplo pretende mostrar el nivel de adaptación de C a C++, utilizando matrices o arreglos bidimensionales
//Fecha de Creación: 15 de febrero 2023

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>

using namespace std;

const int NUMERO_ALUMNOS = 10;
const int NUMERO_MATERIAS = 5;
const int MAX_CALIFICACION = 100;
const int MIN_CALIFICACION = 0;
const int MAX_LONGITUD_CADENA = 100;

int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1]);
void imprimirLineaMatriz();
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA]);

int main()
{
    srand(getpid());
    float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1];
    char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"Mario", "Elisa", "Maria", "Sofia", "Pablo", "Marco", "Amber", "Jorge", "Cesar", "David"};
    llenarMatriz(matriz);
    imprimirMatriz(matriz, alumnos);
    return 0;
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1])
{
    for (int y=0; y < NUMERO_ALUMNOS; y++)
    {
        float sumaNotasAlumno = 0;
        for (int x=0; x < NUMERO_MATERIAS; x++)
        {
            int calificacionAlumno = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
            sumaNotasAlumno += (float)calificacionAlumno;
            matriz[y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / NUMERO_MATERIAS;
        matriz[y][NUMERO_MATERIAS]=promedioNotasAlumno;
    }
}
void imprimirLineaMatriz()
{
    cout<<"+---------";
    for (int x=0; x < NUMERO_MATERIAS + 1; x++)
    {
        cout<<"---------";
    }
    cout<<"+\n";
}
void imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_MATERIAS+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA])
{
    int y, x;
    float promedioMayor = matriz[0][NUMERO_MATERIAS];
    float promedioMenor = matriz[0][NUMERO_MATERIAS];
    char alumnoPromedioMayor[MAX_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout<<"|   Alumno   |";
    for (int x=0; x < NUMERO_MATERIAS; x++)
    {
        cout<<"Cal "<< (int) x + 1<<"  |";
    }
    cout<<"Promedio|\n";
    imprimirLineaMatriz();
    for (int y=0; y <NUMERO_ALUMNOS; y++)
    {
        cout<<"|    "<<alumnos[y]<<"   |";
        float suma = 0;
        for (int x=0; x < NUMERO_MATERIAS; x++)
            {
                int calificacion = matriz[y][x];
                cout<<"\t"<<calificacion<<"    |";
            }
        float promedio = matriz[y][NUMERO_MATERIAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAX_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAX_LONGITUD_CADENA);
        }
        cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"  |\n";
        imprimirLineaMatriz();
    }
    cout<<"Promedio mayor: "<<alumnoPromedioMayor<<" con " <<promedioMayor<<"\n";
    cout<<"Promedio menor: "<<alumnoPromedioMenor<<" con " <<promedioMenor<<"\n";
}
