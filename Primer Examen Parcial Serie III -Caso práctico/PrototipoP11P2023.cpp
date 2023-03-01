#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iomanip>

using namespace std;

const int NUMERO_LIGAS = 4;
const int NUMERO_FECHAS = 5;
const int MAX_CALIFICACION = 50;
const int MIN_CALIFICACION = 10;
const int MAX_LONGITUD_CADENA = 50;

int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_LIGAS][NUMERO_FECHAS+1]);
void imprimirLineaMatriz();
void imprimirMatriz(float matriz[NUMERO_LIGAS][NUMERO_FECHAS+1], char ligas[NUMERO_LIGAS][MAX_LONGITUD_CADENA]);

int main()
{
    srand(getpid());
    float matriz[NUMERO_LIGAS][NUMERO_FECHAS+1];
    char ligas[NUMERO_LIGAS][MAX_LONGITUD_CADENA] = {"Liga Nacional         ", "Liga de Ascenso       ", "Liga Segunda Division ", "Liga Metrapolitana    "};
    llenarMatriz(matriz);
    imprimirMatriz(matriz, ligas);
    return 0;
}
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
void llenarMatriz(float matriz[NUMERO_LIGAS][NUMERO_FECHAS+1])
{
    for (int y=0; y < NUMERO_LIGAS; y++)
    {
        float sumaNotasLiga = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
        {
            int calificacionLiga = busquedaAleatorios(MIN_CALIFICACION, MAX_CALIFICACION);
            sumaNotasLiga += (float)calificacionLiga;
            matriz[y][x] = calificacionLiga;
        }
        float promedioNotasLiga = sumaNotasLiga / NUMERO_FECHAS;
        matriz[y][NUMERO_FECHAS]=promedioNotasLiga;
    }
}
void imprimirLineaMatriz()
{
    cout<<"+------";
    for (int x=0; x < NUMERO_FECHAS + 1; x++)
    {
        cout<<"------------";
    }
    cout<<"+\n";
}
void imprimirMatriz(float matriz[NUMERO_LIGAS][NUMERO_FECHAS+1], char ligas[NUMERO_LIGAS][MAX_LONGITUD_CADENA])
{
    int y, x;
    float promedioMayor = matriz[0][NUMERO_FECHAS];
    float promedioMenor = matriz[0][NUMERO_FECHAS];
    char ligaPromedioMayor[MAX_LONGITUD_CADENA];
    char ligaPromedioMenor[MAX_LONGITUD_CADENA];
    memcpy(ligaPromedioMayor, ligas[0], MAX_LONGITUD_CADENA);
    memcpy(ligaPromedioMenor, ligas[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout<<"|            LIGAS            |";
    for (int x=0; x < NUMERO_FECHAS; x++)
    {
        cout<<" 201"<< (int) x + 1<<"  |";
    }
    cout<<"Promedio|\n";
    imprimirLineaMatriz();
    for (int y=0; y <NUMERO_LIGAS; y++)
    {
        cout<<"|    "<<ligas[y]<<"   |";
        float suma = 0;
        for (int x=0; x < NUMERO_FECHAS; x++)
            {
                int calificacion = matriz[y][x];
                cout<<"\t"<<calificacion<<"    |";
            }
        float promedio = matriz[y][NUMERO_FECHAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(ligaPromedioMayor, ligas[y], MAX_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(ligaPromedioMenor, ligas[y], MAX_LONGITUD_CADENA);
        }
        cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"  |\n";
        imprimirLineaMatriz();
    }
    cout<<"Promedio mayor: "<<ligaPromedioMayor<<" con " <<promedioMayor<<"\n";
    cout<<"Promedio menor: "<<ligaPromedioMenor<<" con " <<promedioMenor<<"\n";
}
