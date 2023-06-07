#ifndef CINE_H
#define CINE_H

#include <string>
#include <vector>  // Agrega esta l�nea para incluir la biblioteca vector

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
    Funcion funciones[3];
    vector<Cliente> clientes;  // Agrega esta l�nea

    void guardarClientes();
    void cargarClientes();
    void guardarFunciones();
    void cargarFunciones();
    void mostrarClientes();
    void mostrarComprasPorFuncion();  // Agrega esta funci�n
};

#endif // CINE_H
