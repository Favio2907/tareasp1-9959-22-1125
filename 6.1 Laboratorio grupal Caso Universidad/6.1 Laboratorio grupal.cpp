//Este ejemplo pretende mostrar el sistema de notas de la Universidad Mariano Galvez a traves de matrices en lenguaje C++

#include <iostream>
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int NUMERO_ALUMNOS = 10;
const int NUMERO_FACULTADES = 3;
const int MAX_LONGITUD_CADENA = 100;

int busquedaAleatorios(int minimo, int maximo);

void notasAlumno();

const int PPARCIAL = 1;
const int NOTA = 1;
const int SPARCIAL = 1;
const int PARCIALF = 1;
const int RECUPERA = 1;
const int MAX_NOTA = 20;
const int MIN_NOTA = 0;
const int MAX_PPARCIAL = 20;
const int MIN_PPARCIAL = 0;
const int MAX_SPARCIAL = 25;
const int MIN_SPARCIAL = 0;
const int MAX_PARCIALF = 35;
const int MIN_PARCIALF = 0;
const int MAX_RECUPERA = 35;
const int MIN_RECUPERA = 0;

void llenarMatriz(float matriz[NUMERO_ALUMNOS][PPARCIAL+1]);
void llenarMatriz1(float matriz1[NUMERO_ALUMNOS][NOTA+1]);
void llenarMatriz2(float matriz2[NUMERO_ALUMNOS][SPARCIAL+1]);
void llenarMatriz3(float matriz3[NUMERO_ALUMNOS][PARCIALF+1]);
void llenarMatriz4(float matriz4[NUMERO_ALUMNOS][RECUPERA+1]);
void imprimirLineaMatriz();
void imprimirMatriz (float matriz [NUMERO_ALUMNOS][PPARCIAL+1] , float matriz1 [NUMERO_ALUMNOS][NOTA+1] , float matriz2 [NUMERO_ALUMNOS][SPARCIAL+1], float matriz3 [NUMERO_ALUMNOS][PARCIALF+1], float matriz4[NUMERO_ALUMNOS][RECUPERA+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA]);
void imprimirMatriz2 (float matriz [NUMERO_ALUMNOS][PPARCIAL+1] , float matriz1 [NUMERO_ALUMNOS][NOTA+1] , float matriz2 [NUMERO_ALUMNOS][SPARCIAL+1], float matriz3 [NUMERO_ALUMNOS][PARCIALF+1], float matriz4[NUMERO_ALUMNOS][RECUPERA+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA]);

void promedioFacultades();
void promedioComparacion();

//Menú principal una función nueva que te permita ingresar las notas de las 2 facultades
void menuPrincipal();
void seleccionFacultad();
void ingresoNotas();


int main()
{
    menuPrincipal();

    return 0;

}

int busquedaAleatorios(int minimo, int maximo)
 {
     return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) +1); //saca un numero random de 0 a 100
 }

//Elegir que hacer
void menuPrincipal(){
    char opcion;
    int opciones; //capturar la opcion que requira
    bool repetir = true; //para mantener el ciclo (repecion al regresar al menu)
    do{
        system("cls");
        cout << "\n\n\t\tINGRESO DE NOTAS SIMULACION UMG"<< endl;
        cout << "\t\t--------------------------------\n"<< endl;
        cout << "                ##     ##  ##     ##   ######   "<< endl;
        cout << "                ##     ##  ###   ###  ##    ##  "<< endl;
        cout << "                ##     ##  #### ####  ##        "<< endl;
        cout << "                ##     ##  ## ### ##  ##   #### "<< endl;
        cout << "                ##     ##  ##     ##  ##    ##  "<< endl;
        cout << "                ##     ##  ##     ##  ##    ##  "<< endl;
        cout << "                 #######   ##     ##   ######   "<< endl;
        cout << "\n\n\t\tMENU PRINCIPAL"<< endl;
        cout << "\t\t-----------------"<< endl;
        cout << "\t1. Ingreso a Notas"<< endl;
        cout << "\t2. --------SALIR--------"<< endl;
        cout << "\n\t Ingrese una opcion: ";
        cin >> opciones;

        switch (opciones){
        case 1:
            //do{
            seleccionFacultad();
            //cout << "\n\n\tDeseas realizar otro ingreso de notas? escribir s si Si, o n si No"<<endl;
            //cin >> opcion;
           // }while(opcion == 's');
            //cout << "\n\n\t "<< endl;
            //cout << "\n\tNo se realizara ningun ingraso de notas mas"<< endl;
            //system ("pause > nul");
            break;

        case 2:
            cout << "\n\tNo se realizara ninguna operacion"<<endl;
            cout << "\n\tSaliendo del programa"<<endl;
            repetir = false;
            break;

        }
    }while(repetir);
}

//Seleccionar Facultad
void seleccionFacultad()
{
    char opcion;
    int opciones = 0; //Inicializar opciones para volver a escribir
    bool repetir = true; //Repetir el ciclo al regresar al menu
    do{
        system("cls");
        cout << "\n\n\t\tSELECCIONE LA OPCION A LA QUE DESEA ACCEDER"<< endl;
        cout << "\t\t--------------------------------\n"<< endl;
        cout << "\n\t\tMENU FACULTAD"<< endl;
        cout << "\t\t-----------------"<< endl;
        cout << "\t1. Facultad de ingenieria"<< endl;
        cout << "\t2. Facultad de arquitectura"<< endl;
        cout << "\t3. Facultad de administracion"<< endl;
        cout << "\t4. Comparar Notas entre Facultades"<< endl;
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
            promedioFacultades();
            break;

        case 5:
            repetir = false;
            break;
        }
    }while(repetir);
}


//Solicitar notas
void ingresoNotas()
{
    string curso;
    system("cls");
    cout<<"Ingrese el nombre del curso a ingresar: ";
    cin >> curso;
    cout<<"Las notas son del curso de: "<<curso<<endl;
    srand(getpid()); //habilita la funcion de stdlib, cuando utilizo el rand (numero random)
    float matriz1 [NUMERO_ALUMNOS][NOTA+1];//definimos la matriz
    float matriz [NUMERO_ALUMNOS][PPARCIAL+1];
    float matriz2 [NUMERO_ALUMNOS][SPARCIAL+1];
    float matriz3 [NUMERO_ALUMNOS][SPARCIAL+1];
    float matriz4[NUMERO_ALUMNOS][RECUPERA+1];
    char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"Juan","Pedro","Kathy","Sandra","Diego","Melany","Oswaldo","Daniela","Francisco","Xavier"};
    llenarMatriz(matriz);
    llenarMatriz1(matriz1);
    llenarMatriz2(matriz2);
    llenarMatriz2(matriz3);
    llenarMatriz4(matriz4);
    imprimirMatriz(matriz,matriz1,matriz2,matriz3,matriz4, alumnos);
    cout<<"\nATENCION: SI LA ZONA NO ES MAYOR A 26pts, NO SE TIENE DERECHO A EXAMEN FINAL NI A EXAMEN DE RECUPERACION\n"<<endl;
    cout<<"ATENCION: SI LA ZONA CON EXAMEN FINAL NO ES MAYOR A 61pts, ENTONCES SE DEBERA DE COLOCAR EXAMEN DE RECUPERACION "<<endl;
    cout<<"Y SE DEBERA DE CANCELAR EL EXAMEN FINAL\n "<<endl;
    system ("pause > nul");

}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][PPARCIAL+1]) //llenado de matriz
 {
     for (int y=0; y <  NUMERO_ALUMNOS; y++)
     {
        float sumaNotasAlumno=0;//la suma de todos
        for (int x=0; x < PPARCIAL; x++)
        {
           int calificacionAlumno = busquedaAleatorios(MIN_PPARCIAL, MAX_PPARCIAL);
           sumaNotasAlumno += (float)calificacionAlumno; //el float convierte de entero "int" a flotante
           matriz [y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / PPARCIAL;
        matriz [y][PPARCIAL]=promedioNotasAlumno;

    }
 }
void llenarMatriz1(float matriz1[NUMERO_ALUMNOS][NOTA+1]) //llenado de matriz
 {
     for (int y=0; y <  NUMERO_ALUMNOS; y++)
     {
        float sumaNotasAlumno=0;//la suma de todos
        for (int x=0; x < NOTA; x++)
        {
           int calificacionAlumno = busquedaAleatorios(MIN_NOTA, MAX_NOTA);
           sumaNotasAlumno += (float)calificacionAlumno; //el float convierte de entero "int" a flotante
           matriz1 [y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / NOTA;
        matriz1 [y][NOTA]=promedioNotasAlumno;

 }
 }
  void llenarMatriz2(float matriz2[NUMERO_ALUMNOS][SPARCIAL+1]) //llenado de matriz
 {
     for (int y=0; y <  NUMERO_ALUMNOS; y++)
     {
        float sumaNotasAlumno=0;//la suma de todos
        for (int x=0; x < SPARCIAL; x++)
        {
           int calificacionAlumno = busquedaAleatorios(MIN_SPARCIAL, MAX_SPARCIAL);
           sumaNotasAlumno += (float)calificacionAlumno; //el float convierte de entero "int" a flotante
           matriz2 [y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / SPARCIAL;
        matriz2 [y][SPARCIAL]=promedioNotasAlumno;

 }
 }
 void llenarMatriz3(float matriz3[NUMERO_ALUMNOS][PARCIALF+1]) //llenado de matriz
 {
     for (int y=0; y <  NUMERO_ALUMNOS; y++)
     {
        float sumaNotasAlumno=0;//la suma de todos
        for (int x=0; x < PARCIALF; x++)
        {
           int calificacionAlumno = busquedaAleatorios(MIN_PARCIALF, MAX_PARCIALF);
           sumaNotasAlumno += (float)calificacionAlumno; //el float convierte de entero "int" a flotante
           matriz3 [y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / PARCIALF;
        matriz3 [y][SPARCIAL]=promedioNotasAlumno;

 }
 }
void llenarMatriz4(float matriz4[NUMERO_ALUMNOS][RECUPERA+1]) //llenado de matriz
 {
     for (int y=0; y <  NUMERO_ALUMNOS; y++)
     {
        float sumaNotasAlumno=0;//la suma de todos
        for (int x=0; x < RECUPERA; x++)
        {
           int calificacionAlumno = busquedaAleatorios(MIN_RECUPERA, MAX_RECUPERA);
           sumaNotasAlumno += (float)calificacionAlumno; //el float convierte de entero "int" a flotante
           matriz4 [y][x] = calificacionAlumno;
        }
        float promedioNotasAlumno = sumaNotasAlumno / RECUPERA;
        matriz4 [y][RECUPERA]=promedioNotasAlumno;

 }
 }

 void imprimirMatriz (float matriz [NUMERO_ALUMNOS][PPARCIAL+1] , float matriz1 [NUMERO_ALUMNOS][NOTA+1] , float matriz2 [NUMERO_ALUMNOS][SPARCIAL+1], float matriz3 [NUMERO_ALUMNOS][PARCIALF+1], float matriz4 [NUMERO_ALUMNOS][RECUPERA+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA])
{
    float promedioMayor = matriz[0][PPARCIAL]; //matriz
    float promedioMenor = matriz[0][PPARCIAL]; //matriz
    float promedioMayor1 = matriz1[0][NOTA]; //matriz
    float promedioMenor1 = matriz1[0][NOTA]; //matriz
    float promedioMayor2 = matriz2[0][SPARCIAL]; //matriz
    float promedioMenor2 = matriz2[0][SPARCIAL]; //matriz
    float promedioMayor3 = matriz3[0][PARCIALF]; //matriz
    float promedioMenor3 = matriz3[0][PARCIALF]; //matriz
    float promedioMayor4 = matriz4[0][RECUPERA]; //matriz
    float promedioMenor4 = matriz4[0][RECUPERA]; //matriz
    char alumnoPromedioMayor [MAX_LONGITUD_CADENA]; //vector
    char alumnoPromedioMenor [MAX_LONGITUD_CADENA]; //vector

    memcpy(alumnoPromedioMayor, alumnos[0], MAX_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAX_LONGITUD_CADENA);
    imprimirLineaMatriz();
    cout <<"|  Alumno  |";
    for (int x=0; x < NOTA; x++)
    {
        cout<<"NOTA   |";
    }
    for (int x=0; x < PPARCIAL; x++)
    {
        cout<<"Primer Parcial|";
    }
     for (int x=0; x < SPARCIAL; x++)
    {
        cout<<"Segundo Parcial|";
    }
    for (int x=0; x < PARCIALF; x++)
    {
        cout<<"Parcial Final|";
    }
    for (int x=0; x < RECUPERA; x++)
    {
        cout<<"Recuperacion   |";
    }
    cout <<("Total Zona     |");
    cout <<("Promedio       |\n");
    imprimirLineaMatriz();
    float notaMayor=0;
    float alumnoMayor;
    for (int y=0; y< NUMERO_ALUMNOS; y++)
    {
        cout <<"|  "<<alumnos[y]<<"   |";
        float suma = 0;
        for (int x=0; x< NOTA; x++)
        {
            int calificacion = matriz[y][x];
            cout <<"  "<<calificacion<<"  |";
        }
        for (int x=0; x< PPARCIAL; x++)
        {
            int calificacion = matriz1[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }
        for (int x=0; x< SPARCIAL; x++)
        {
            int calificacion = matriz2[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }
        float zonaPasar = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL];
        float zona = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL]+matriz3 [y][PARCIALF];
        if (zonaPasar <=25)
        {
            for (int x=0; x< PARCIALF; x++)
        {
            int calificacion = matriz3[y][x]-matriz3[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }

            for (int x=0; x< RECUPERA; x++)
                {
                    int calificacion = matriz4[y][x]-matriz4[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
                float zonaPasar = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL];
                cout<<"\t"<< fixed << setprecision(2)<< (double) zonaPasar<<"    |";
                float promedio = (zonaPasar)/4;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";

        }
        else if (zona <=60)
        {
             for (int x=0; x< PARCIALF; x++)
        {
            int calificacion = matriz3[y][x];
            cout <<"\t"<<calificacion<<"\t|";
        }
              for (int x=0; x< RECUPERA; x++)
                {
                    int calificacion = matriz4[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
                float zona1 = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL]+matriz4 [y][RECUPERA];
                cout<<"\t"<< fixed << setprecision(2)<< (double) zona1<<"    |";
                float promedio = (zona1)/3;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";
                if(zona>notaMayor)
                {
                    notaMayor=zona1;//95% de exito
                    alumnoMayor= y;
                }

        }else
        {
            for (int x=0; x< PARCIALF; x++)
            {
                int calificacion = matriz3[y][x];
                cout <<"\t"<<calificacion<<"\t|";
            }
            for (int x=0; x< RECUPERA; x++)
                {
                    int calificacion = matriz4[y][x]-matriz4[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
            cout<<"\t"<< fixed << setprecision(2)<< (double) zona<<"    |";
            float promedio = (zona)/4;
            cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";
            if(zona>notaMayor)
            {
                notaMayor=zona;//95% de exito
                alumnoMayor= y;
            }

        }
        imprimirLineaMatriz();

    }
    int y = alumnoMayor;
    cout << "El mejor alumno de la Facultad es " << alumnos[y] << " con "<< notaMayor << endl;

}


 void imprimirMatriz2 (float matriz [NUMERO_ALUMNOS][PPARCIAL+1] , float matriz1 [NUMERO_ALUMNOS][NOTA+1] , float matriz2 [NUMERO_ALUMNOS][SPARCIAL+1], float matriz3 [NUMERO_ALUMNOS][PARCIALF+1], float matriz4 [NUMERO_ALUMNOS][RECUPERA+1], char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA])
{

    float mejorFac=0;
    float mejorFacNum=0;
    float notaMayor;
    int mejorAlumFac=0;
    float mejorAlumFacNum=0;
    float promedioGenFac=0;
    char facultades[NUMERO_FACULTADES][MAX_LONGITUD_CADENA] = {"Facultad de Ingenieria","Facultad de Arquitectura","Facultad de Administracion"};


    for (int f = 0; f < NUMERO_FACULTADES; f++)
    {
        llenarMatriz(matriz);
        llenarMatriz1(matriz1);
        llenarMatriz2(matriz2);
        llenarMatriz2(matriz3);
        llenarMatriz4(matriz4);

        cout << "\n\nNotas para la " << facultades[f] << endl;

        float promedioMayor = matriz[0][PPARCIAL]; //matriz
        float promedioMenor = matriz[0][PPARCIAL]; //matriz
        float promedioMayor1 = matriz1[0][NOTA]; //matriz
        float promedioMenor1 = matriz1[0][NOTA]; //matriz
        float promedioMayor2 = matriz2[0][SPARCIAL]; //matriz
        float promedioMenor2 = matriz2[0][SPARCIAL]; //matriz
        float promedioMayor3 = matriz3[0][PARCIALF]; //matriz
        float promedioMenor3 = matriz3[0][PARCIALF]; //matriz
        float promedioMayor4 = matriz4[0][RECUPERA]; //matriz
        float promedioMenor4 = matriz4[0][RECUPERA]; //matriz
        char alumnoPromedioMayor [MAX_LONGITUD_CADENA]; //vector
        char alumnoPromedioMenor [MAX_LONGITUD_CADENA]; //vector

        memcpy(alumnoPromedioMayor, alumnos[0], MAX_LONGITUD_CADENA);
        memcpy(alumnoPromedioMenor, alumnos[0], MAX_LONGITUD_CADENA);
        imprimirLineaMatriz();
        cout <<"|  Alumno  |";
        for (int x=0; x < NOTA; x++)
        {
            cout<<"NOTA   |";
        }
        for (int x=0; x < PPARCIAL; x++)
        {
            cout<<"Primer Parcial|";
        }
        for (int x=0; x < SPARCIAL; x++)
        {
            cout<<"Segundo Parcial|";
        }
        for (int x=0; x < PARCIALF; x++)
        {
            cout<<"Parcial Final|";
        }
        for (int x=0; x < RECUPERA; x++)
        {
            cout<<"Recuperacion   |";
        }
        cout <<("Total Zona     |");
        cout <<("Promedio       |\n");
        imprimirLineaMatriz();
        float notaMayor=0;
        float alumnoMayor;
        for (int y=0; y< NUMERO_ALUMNOS; y++)
        {
            cout <<"|  "<<alumnos[y]<<"   |";
            float suma = 0;
            for (int x=0; x< NOTA; x++)
            {
                int calificacion = matriz[y][x];
                cout <<"  "<<calificacion<<"  |";
            }
            for (int x=0; x< PPARCIAL; x++)
            {
                int calificacion = matriz1[y][x];
                cout <<"\t"<<calificacion<<"\t|";
            }
            for (int x=0; x< SPARCIAL; x++)
            {
                int calificacion = matriz2[y][x];
                cout <<"\t"<<calificacion<<"\t|";
            }
            float zonaPasar = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL];
            float zona = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL]+matriz3 [y][PARCIALF];
            promedioGenFac+=zona;
            if (zonaPasar <=25)
            {
                for (int x=0; x< PARCIALF; x++)
                {
                    int calificacion = matriz3[y][x]-matriz3[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }

                for (int x=0; x< RECUPERA; x++)
                {
                    int calificacion = matriz4[y][x]-matriz4[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
                float zonaPasar = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL];
                cout<<"\t"<< fixed << setprecision(2)<< (double) zonaPasar<<"    |";
                float promedio = (zonaPasar)/4;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";

            }
            else if (zona <=60)
            {
                for (int x=0; x< PARCIALF; x++)
                {
                    int calificacion = matriz3[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
                for (int x=0; x< RECUPERA; x++)
                {
                    int calificacion = matriz4[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
                float zona1 = matriz [y][PPARCIAL]+matriz1 [y][NOTA]+matriz2 [y][SPARCIAL]+matriz4 [y][RECUPERA];
                cout<<"\t"<< fixed << setprecision(2)<< (double) zona1<<"    |";
                float promedio = (zona1)/3;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";
                if(zona1>notaMayor)
                {
                    notaMayor=zona1;//95% de exito
                    alumnoMayor= y;
                }

            }else
            {
                for (int x=0; x< PARCIALF; x++)
                {
                    int calificacion = matriz3[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
                for (int x=0; x< RECUPERA; x++)
                {
                    int calificacion = matriz4[y][x]-matriz4[y][x];
                    cout <<"\t"<<calificacion<<"\t|";
                }
                cout<<"\t"<< fixed << setprecision(2)<< (double) zona<<"    |";
                float promedio = (zona)/4;
                cout<<"\t"<< fixed << setprecision(2)<< (double) promedio<<"    |\n";
                if(zona>notaMayor)
                {
                    notaMayor=zona;//95% de exito
                    alumnoMayor= y;
                }

            }
            imprimirLineaMatriz();

        }
    int y = alumnoMayor;
    cout << "El mejor alumno de la Facultad es " << alumnos[y] << " con "<< notaMayor << endl;

    if(notaMayor>mejorFac)
    {
        mejorFac = notaMayor;//95% de exito
        mejorFacNum = f;
    }
    if(alumnoMayor>mejorAlumFac)
    {
        mejorAlumFac = alumnoMayor;
        mejorAlumFacNum = f;
    }
    }


    //Colocar promedio y competencias de las facultades...
    int f = mejorFacNum;    //Mejor facultad
    int j = mejorAlumFacNum;   //Mejor alumno 3 facultades
    promedioGenFac= promedioGenFac/30;          //Promedio general

    cout << "\nLa mejor facultad es: " << facultades[f] << endl;
    cout << "El mejor alumno por las 3 facultades: " << alumnos[j]<< endl;
    cout << "Promedio general de las 3 facultades: " << promedioGenFac << endl;

    system ("pause > nul");
}

 void imprimirLineaMatriz()
 {
     cout <<"+--------------------------------------------";
     for (int x=0; x < SPARCIAL; x++) //imprime bloques de guiones para llenar la matriz
     {
        cout<<"---------------------------------------------------------------------";
     }
     cout <<"+\n";
 }


//Creacion de matrices para cada facultad en el mismo plano, trabajar desde aqui...
void promedioFacultades()
{
    srand(getpid());
    string curso;
    system("cls");
    cout<<"Ingrese el nombre del curso a comparar: ";
    cin >> curso;
    cout<<"\nLas notas son del curso de: "<<curso << endl;
    float matriz1 [NUMERO_ALUMNOS][NOTA+1];//definimos la matriz
    float matriz [NUMERO_ALUMNOS][PPARCIAL+1];
    float matriz2 [NUMERO_ALUMNOS][SPARCIAL+1];
    float matriz3 [NUMERO_ALUMNOS][SPARCIAL+1];
    float matriz4[NUMERO_ALUMNOS][RECUPERA+1];

    char alumnos[NUMERO_ALUMNOS][MAX_LONGITUD_CADENA] = {"Juan","Pedro","Kathy","Sandra","Diego","Melany","Oswaldo","Daniela","Francisco","Xavier"};


    imprimirMatriz2(matriz,matriz1,matriz2,matriz3,matriz4, alumnos);

    system ("pause > nul");
}
