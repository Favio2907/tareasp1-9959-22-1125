// Rama de los proesos cine
// Favio Lopez, Carnet 9959-22-1125

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <fstream>
#include <sstream>


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
    void mostrarComprasPorFuncion();

private:
    struct Cliente {
        string nombre;
        string direccion;
        int numBoletos;
    };

    vector<Cliente> clientes;
    Funcion funciones[3];

    void guardarClientes();
    void cargarClientes();
    void guardarFunciones();
    void cargarFunciones();
};

Cine::Cine() {
    // Inicializar las funciones disponibles
    funciones[0] = { "Pelicula 1", "10:00 AM", 100 };
    funciones[1] = { "Pelicula 2", "2:00 PM", 50 };
    funciones[2] = { "Pelicula 3", "7:00 PM", 80 };

    // Cargar los datos almacenados previamente al iniciar el cine
    cargarClientes();
    cargarFunciones();
}

void Cine::iniciarVenta() {
    int opcion;
    do {
        system("cls");
        cout << "PrototipoP1EF2023 - Favio Lopez, Carnet 9959-22-1125" << endl;
        cout << endl;
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t|BIENVENIDO AL MENU DE PROCESOS CINE|" << endl;
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t 1. Registrar cliente" << endl;
        cout << "\t\t\t 2. Mostrar funciones disponibles" << endl;
        cout << "\t\t\t 3. Vender boletos" << endl;
        cout << "\t\t\t 4. Mostrar compras por funcion" << endl;
        cout << "\t\t\t 5. Salir" << endl;

        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpcion a escoger:[1/2/3/4/5]" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "Ingresa tu Opcion: ";
        cin >> opcion;

        // Limpiar el buffer de entrada después de leer un número
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                registrarCliente();
                cout << "Cliente registrado con éxito." << endl;
                break;
            case 2:
                mostrarFunciones();
                system("pause");
                break;
            case 3: {
                if (clientes.empty()) {
                    cout << "Por favor, registre al menos un cliente primero." << endl;
                } else {
                    mostrarFunciones();
                    int opcionFuncion = seleccionarFuncion();
                    venderBoletos(opcionFuncion);
                }
                break;
            }
            case 4:
                mostrarComprasPorFuncion();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
                break;
        }

    } while (opcion != 5);
}

void Cine::registrarCliente() {
    system("cls");

    Cliente nuevoCliente;

    cout << "Registro de Cliente" << endl;
    cout << "-------------------" << endl;

    cout << "Nombre: ";
    getline(cin, nuevoCliente.nombre);

    cout << "Direccion: ";
    getline(cin, nuevoCliente.direccion);

    nuevoCliente.numBoletos = 0;

    clientes.push_back(nuevoCliente);

    // Guardar los clientes en el archivo de texto
    guardarClientes();
}

void Cine::mostrarFunciones() {
    system("cls");

    cout << "Funciones Disponibles" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Funcion " << i + 1 << ": " << funciones[i].pelicula << " - " << funciones[i].horario << endl;
        cout << "Boletos disponibles: " << funciones[i].boletosDisponibles << endl;
        cout << endl;
    }
}

int Cine::seleccionarFuncion() {
    int opcionFuncion;
    cout << "Seleccione una funcion (1-3): ";
    cin >> opcionFuncion;

    // Validar la opción ingresada
    while (opcionFuncion < 1 || opcionFuncion > 3) {
        cout << "Opción invalida. Ingrese un numero de funcion valido (1-3): ";
        cin >> opcionFuncion;
    }

    // Limpiar el buffer de entrada después de leer un número
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return opcionFuncion;
}

void Cine::venderBoletos(int opcionFuncion) {
    system("cls");

    int numBoletos;
    cout << "Venta de Boletos" << endl;
    cout << "----------------" << endl;

    // Obtener la función seleccionada
    Funcion& funcionSeleccionada = funciones[opcionFuncion - 1];

    // Mostrar los detalles de la función seleccionada
    cout << "Función: " << funcionSeleccionada.pelicula << " - " << funcionSeleccionada.horario << endl;
    cout << "Boletos disponibles: " << funcionSeleccionada.boletosDisponibles << endl;

    // Solicitar la cantidad de boletos a vender
    cout << "Ingrese la cantidad de boletos a vender: ";
    cin >> numBoletos;

    // Validar la cantidad de boletos ingresada
    while (numBoletos < 1 || numBoletos > funcionSeleccionada.boletosDisponibles) {
        cout << "Cantidad invalida. Ingrese una cantidad de boletos valida (1-" << funcionSeleccionada.boletosDisponibles << "): ";
        cin >> numBoletos;
    }

    // Limpiar el buffer de entrada después de leer un número
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Actualizar la disponibilidad de boletos de la función seleccionada
    funcionSeleccionada.boletosDisponibles -= numBoletos;

    // Actualizar el número de boletos vendidos para el cliente actual
    clientes.back().numBoletos += numBoletos;

    cout << "Venta realizada con exito." << endl;

    // Guardar los cambios en el archivo de texto
    guardarFunciones();
    guardarClientes();
}

void Cine::mostrarComprasPorFuncion() {
    system("cls");

    cout << "Compras por Funcion" << endl;
    cout << "-------------------" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Funcion " << i + 1 << ": " << funciones[i].pelicula << " - " << funciones[i].horario << endl;
        cout << "-------------------" << endl;

        bool encontrada = false;

        for (const auto& cliente : clientes) {
            if (cliente.numBoletos > 0) {
                encontrada = true;
                cout << "Cliente: " << cliente.nombre << endl;
                cout << "Cantidad de boletos comprados: " << cliente.numBoletos << endl;
                cout << endl;
            }
        }

        if (!encontrada) {
            cout << "No se han realizado compras para esta función." << endl;
            cout << endl;
        }
    }

    system("pause");
}

void Cine::guardarClientes() {
    ofstream archivoClientes("clientes.txt");

    if (archivoClientes.is_open()) {
        for (const auto& cliente : clientes) {
            archivoClientes << cliente.nombre << ',' << cliente.direccion << ',' << cliente.numBoletos << '\n';
        }

        archivoClientes.close();
    } else {
        cout << "No se pudo abrir el archivo de clientes." << endl;
    }
}

void Cine::cargarClientes() {
    ifstream archivoClientes("clientes.txt");

    if (archivoClientes.is_open()) {
        clientes.clear();

        string linea;

        while (getline(archivoClientes, linea)) {
            stringstream ss(linea);
            string nombre, direccion, numBoletosStr;
            int numBoletos;

            if (getline(ss, nombre, ',') && getline(ss, direccion, ',') && getline(ss, numBoletosStr, ',')) {
                numBoletos = stoi(numBoletosStr);

                Cliente cliente;
                cliente.nombre = nombre;
                cliente.direccion = direccion;
                cliente.numBoletos = numBoletos;

                clientes.push_back(cliente);
            }
        }

        archivoClientes.close();
    } else {
        cout << "No se pudo abrir el archivo de clientes." << endl;
    }
}

void Cine::guardarFunciones() {
    ofstream archivoFunciones("funciones.txt");

    if (archivoFunciones.is_open()) {
        for (const auto& funcion : funciones) {
            archivoFunciones << funcion.pelicula << ',' << funcion.horario << ',' << funcion.boletosDisponibles << '\n';
        }

        archivoFunciones.close();
    } else {
        cout << "No se pudo abrir el archivo de funciones." << endl;
    }
}

void Cine::cargarFunciones() {
    ifstream archivoFunciones("funciones.txt");

    if (archivoFunciones.is_open()) {
        string linea;
        int indice = 0;

        while (getline(archivoFunciones, linea)) {
            stringstream ss(linea);
            string pelicula, horario, boletosDisponiblesStr;
            int boletosDisponibles;

            if (getline(ss, pelicula, ',') && getline(ss, horario, ',') && getline(ss, boletosDisponiblesStr, ',')) {
                boletosDisponibles = stoi(boletosDisponiblesStr);

                Funcion funcion;
                funcion.pelicula = pelicula;
                funcion.horario = horario;
                funcion.boletosDisponibles = boletosDisponibles;

                funciones[indice++] = funcion;
            }
        }

        archivoFunciones.close();
    } else {
        cout << "No se pudo abrir el archivo de funciones." << endl;
    }

}
