// Definici�n de guardas para evitar inclusiones m�ltiples del archivo persona.h
#ifndef PERSONA_H
#define PERSONA_H


#include<iostream> // Para entradas y salidas de consola
#include<fstream> // Para lectura y escritura de archivos
#include<stdlib.h> // Para funciones de uso general
#include<cstdlib> // Para funciones matem�ticas
#include<conio.h> // Para funciones de entrada de teclado
#include<iomanip> // Para formateo de salidas


using namespace std;

// Definici�n de la clase persona
class persona
{
    public:
        // Constructores
        persona();
        persona(string id, string name, string fecha, int tiempo, int score);

        // M�todos para establecer y obtener valores de los atributos privados
        string setId(string id);
        string getId();
        string setName(string name);
        string getName();
        string setFecha(string fecha);
        string getFecha();
        int setTiempo(int tiempo);
        int getTiempo();
        int setScore(int score);
        int getScore();

        // M�todos para el men� de opciones del programa
        void menu();
		void insertar();
		void insertar1();
		void desplegar();
		void modificar();
		void buscar();
		void buscar1();
		void borrar();
		void ingresoTiempo();
		void nuevaPartida();

		// M�todos para el men� de opciones secundario del programa
		void menu1();
		void desplegar1();

    protected:

    private:
        // Atributos privados de la clase
        string id,name,fecha;
        int tiempo, score;
};

#endif // PERSONA_H"
