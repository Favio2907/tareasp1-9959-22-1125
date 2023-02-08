//fecha de creación: 08/02/2022
//autor: Favio Alejandro López Gómez (Equipo 3)
//Este programa es el Laboratorio No. 1, el cual consiste en un programa que gestione las
//calificaciones de alumnos de un colegio
//Laboratorio No. 1

#include <iostream>
#include <cstdlib>

using namespace std;

void menuPrincipal();
void datosAlumnos();

int main (){
    menuPrincipal();

    return 0;

}

void menuPrincipal(){
    int opciones;
    bool repetir = true;
    do{
        system("cls");
        cout << "\n\n\t\tIngreso de calificaciones y promedios de los alumnos"<< endl;
        cout << "\t\t---------------------------------------------------------"<< endl;
        cout << "\n\n\t\tMENU PRINCIPAL"<< endl;
        cout << "\t\t-----------------"<< endl;
        cout << "\t1. Ingresar Datos de los alumnos"<< endl;
        cout << "\t2. --------SALIR--------"<< endl;
        cout << "\n\t ingrese una opcion: ";
        cin >> opciones;


        switch (opciones){
        case 1:
            datosAlumnos();
            break;

        case 2:
            cout << "\n\tNo se realizara ninguna operacion"<<endl;
            cout << "\n\tSaliendo del programa"<<endl;
            repetir = false;
            break;
        }

      }while(repetir);
}


void datosAlumnos(){
    system("cls");
    string Nombre = "";
    string Apellido="";
    float notaMate, notaFisica, notaNaturales, notaSociales,  notaComu;
    float total, promedio;
    cout << "\n\n\tIngrese las nombres y apellidos del alumno: "<<endl;
    cout << "\n\tCuales son los nombres del alumno a ingresar: ";
    cin >>Nombre;
    cout << "\n\tCuales son los apellidos del alumno a ingresar: ";
    cin >>Apellido;
      cout << "\n\tIngrese las notas del alumno: "<<endl;
    cout << "\n\tNota para el curso de Matematicas: ";
    cin >>notaMate;
    cout << "\n\tNota para el curso de FISICA: ";
    cin >>notaFisica;
    cout << "\n\tNota para el curso de Ciencias Naturales: ";
    cin >>notaNaturales;
    cout << "\n\tNota para el curso de Ciencias Sociales: ";
    cin >>notaSociales;
    cout << "\n\tNota para el curso de Comunicacion y Lenguaje: ";
    cin >>notaComu;
    system("cls");
    cout << "\n\n\tEstos son los totales y promedios del alumno: "<<endl;
    cout << "\n\tNombres: "<<Nombre<<endl;
    cout << "\n\tApellidos: "<<Apellido<<endl;
    cout << "\n\n\tNotas con sus respectivos cursos: "<<endl;
    cout << "\n\tCurso de Matematicas: "<<notaMate<<endl;
    cout << "\n\tCurso de FISICA: "<<notaFisica<<endl;
    cout << "\n\tCurso de Ciencias Naturales: "<<notaNaturales<<endl;
    cout << "\n\tCurso de Ciencias Sociales: "<<notaSociales<<endl;
    cout << "\n\tCurso de Comunicacion y Lenguaje: "<<notaComu<<endl;
    cout << "\n\n\tTotal de zona acumulada: "<<endl;
    total = notaMate+notaFisica+notaNaturales+notaSociales+notaComu;
    cout << "\n\tTotal es de: "<<total<<endl;
    cout << "\n\n\tPromedio Total: "<<endl;
    promedio = (notaMate+notaFisica+notaNaturales+notaSociales+notaComu)/5;
    cout << "\n\tTotal es de: "<<promedio<<endl;
    system ("pause > nul");

}
