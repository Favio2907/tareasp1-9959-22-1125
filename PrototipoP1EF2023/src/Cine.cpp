// Rama de los proesos cine
// Favio Lopez, Carnet 9959-22-1125

#include "Cine.h"
#include <iostream>
#include <fstream> // Para trabajar con archivos
#include <limits>

using namespace std;

Cine::Cine() {
    // Inicializar las funciones disponibles
    funciones[0] = {"Pelicula 1", "10:00 AM", 100};
    funciones[1] = {"Pelicula 2", "2:00 PM", 50};
    funciones[2] = {"Pelicula 3", "7:00 PM", 80};

    // Cargar los datos almacenados previamente al iniciar el cine
    cargarClientes();
    cargarFunciones();
}

void Cine::iniciarVenta() {
    int opcion;
    do {
        system("cls");

        cout << "PrototipoP1EF2023 - Favio Lopez, Carnet 9959-22-1125" << endl;
        cout << " " << endl;
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t|BIENVENIDO AL MENU DE PROCESOS CINE|" << endl;
        cout << "\t\t\t-------------------------------------" << endl;
        cout << "\t\t\t 1. Registrar cliente" << endl;
        cout << "\t\t\t 2. Mostrar clientes" << endl;
        cout << "\t\t\t 3. Mostrar funciones disponibles" << endl;
        cout << "\t\t\t 4. Vender boletos" << endl;
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
                mostrarClientes();
                system("pause");
                break;
            case 3:
                mostrarFunciones();
                system("pause");
                break;
            case 4: {
                if (cliente.nombre.empty()) {
                    cout << "Por favor, registre al cliente primero." << endl;
                } else {
                    mostrarFunciones();
                    int opcionFuncion = seleccionarFuncion();
                    venderBoletos(opcionFuncion);
                }
                break;
            }
            case 5:
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
                break;
        }

        cout << endl;
    } while (opcion != 5);
}

void Cine::registrarCliente() {
    system("cls");

    cout << "Nombre del cliente: ";
    getline(cin, cliente.nombre);

    cout << "Direccion del cliente: ";
    getline(cin, cliente.direccion);

    guardarClientes();
}

void Cine::mostrarFunciones() {
    system("cls");

        cout<<"\n------------------------ Tabla de Funciones Registradas ------------------------"<<endl;
        cout << " " << endl;
    	cout << "\t\t\t Funciones disponibles:" << endl;
    	cout << " " << endl;
    	for (int i = 0; i < 3; i++) { // Cambia el límite según el número de funciones deseadas
        cout << i + 1 << ". \t Pelicula: " << funciones[i].pelicula << " - Horario: " << funciones[i].horario;
        cout << "- \t  Boletos disponibles: " << funciones[i].boletosDisponibles << endl;

    }
}

int Cine::seleccionarFuncion() {
    int opcion;
    do {
        cout << " " << endl;
        cout << "Seleccione una funcion (1-3): ";
        cin >> opcion;
    } while (opcion < 1 || opcion > 3); // Cambia el límite según el número de funciones deseadas

    // Limpiar el buffer de entrada después de leer un número
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return opcion;
}

void Cine::venderBoletos(int opcionFuncion) {
    Funcion& funcion = funciones[opcionFuncion - 1];

    int numBoletos;

    system("cls");

    cout << "Cantidad de boletos a comprar (disponibles: " << funcion.boletosDisponibles << "): ";
    cin >> numBoletos;

    if (numBoletos > funcion.boletosDisponibles) {
        cout << "Lo sentimos, no hay suficientes boletos disponibles." << endl;
    } else {
        funcion.boletosDisponibles -= numBoletos;
        cout << "¡Compra realizada con éxito!" << endl;
    }

    guardarFunciones();
}

void Cine::guardarClientes() {
    ofstream archivo("clientes.txt"); // Abre el archivo en modo de escritura
    if (archivo.is_open()) {
        archivo << cliente.nombre << endl;
        archivo << cliente.direccion << endl;
        archivo.close(); // Cierra el archivo después de escribir
    } else {
        cout << "No se pudo abrir el archivo para guardar los clientes." << endl;
    }
}

void Cine::cargarClientes() {
    ifstream archivo("clientes.txt"); // Abre el archivo en modo de lectura
    if (archivo.is_open()) {
        getline(archivo, cliente.nombre);
        getline(archivo, cliente.direccion);
        archivo.close(); // Cierra el archivo después de leer
    } else {
        cout << "No se pudo abrir el archivo para cargar los clientes. Se usarán valores por defecto." << endl;
    }
}

void Cine::guardarFunciones() {
    ofstream archivo("funciones.txt"); // Abre el archivo en modo de escritura
    if (archivo.is_open()) {
        for (int i = 0; i < 3; i++) { // Cambia el límite según el número de funciones deseadas
            archivo << funciones[i].pelicula << endl;
            archivo << funciones[i].horario << endl;
            archivo << funciones[i].boletosDisponibles << endl;
        }
        archivo.close(); // Cierra el archivo después de escribir
    } else {
        cout << "No se pudo abrir el archivo para guardar las funciones." << endl;
    }
}

void Cine::cargarFunciones() {
    ifstream archivo("funciones.txt"); // Abre el archivo en modo de lectura
    if (archivo.is_open()) {
        for (int i = 0; i < 3; i++) { // Cambia el límite según el número de funciones deseadas
            getline(archivo, funciones[i].pelicula);
            getline(archivo, funciones[i].horario);
            archivo >> funciones[i].boletosDisponibles;
            archivo.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer de entrada
        }
        archivo.close(); // Cierra el archivo después de leer
    } else {
        cout << "No se pudo abrir el archivo para cargar las funciones. Se usarán valores por defecto." << endl;
    }
}

void Cine::mostrarClientes() {

    system("cls");
    ifstream archivo("clientes.txt"); // Abre el archivo en modo de lectura
    if (archivo.is_open()) {
        string nombre, direccion;
        getline(archivo, nombre);
        getline(archivo, direccion);

        if (!nombre.empty() && !direccion.empty()) {

        cout<<"\n------------------------ Tabla de Clientes Registrados ------------------------"<<endl;
        cout << " " << endl;
        cout << "\t\t\t Clientes registrados:" << endl;
        cout << "\t\t\t Nombre: " << nombre << endl;
        cout << "\t\t\t Direccion: " << direccion << endl;
        } else {
            cout << "No hay clientes registrados." << endl;
        }

        archivo.close(); // Cierra el archivo después de leer
    } else {
        cout << "No se pudo abrir el archivo para cargar los clientes." << endl;
    }
}
