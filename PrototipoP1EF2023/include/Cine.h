#ifndef CINE_H
#define CINE_H

#include <string>

using namespace std;

struct Funcion {
    string pelicula;
    string horario;
    int boletosDisponibles;
};

class Cine {
public:
    Cine();
    void iniciarVenta();
    void registrarCliente();
    void mostrarFunciones();
    int seleccionarFuncion();
    void venderBoletos(int opcionFuncion);

private:
    struct Cliente {
        string nombre;
        string direccion;
    };

    Cliente cliente;
    Funcion funciones[3]; // Cambia el tamaño según el número de funciones deseadas

    void guardarClientes();
    void cargarClientes();
    void guardarFunciones();
    void cargarFunciones();
    void mostrarClientes();
};

#endif // CINE_H
