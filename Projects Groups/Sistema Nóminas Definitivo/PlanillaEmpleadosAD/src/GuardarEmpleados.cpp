#include "GuardarEmpleados.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

GuardarEmpleados::GuardarEmpleados(int idE, string nombre, string apellido, string genero, string puesto, string departamento, int dia, int mes, int dpi, int telefono, int telefono1, int numCuenta, float sueldo, float comisiones, float percepciones_extra, float horas_extra, float isr)
{
    //ctor
    id = idE;
}

void GuardarEmpleados::guardarEmpleado() {
    ofstream archivo("datos_empleados.txt", ios::out | ios::binary | ios::app);
    if (!archivo) {
      cout << "Error al abrir el archivo." << endl;
      return;
    }
    archivo.write(reinterpret_cast<const char*>(this), sizeof(GuardarEmpleados));
    archivo.close();
  }

void GuardarEmpleados::mostrarEmpleados(int idE) {
    ifstream archivo("datos_empleados.txt", ios::in | ios::binary);
    if (!archivo) {
      cout << "No se encontraron datos de empleados" << endl;
      return;
    }
    GuardarEmpleados empleado;
    bool encontrado = false;
    while (archivo.read(reinterpret_cast<char*>(&empleado), sizeof(GuardarEmpleados))) {
      if (empleado.id == idE) {
      empleado.mostrarEmpleado();
      encontrado = true;
        }
    }
    if (!encontrado) {
    std::cout << "No se encontró un empleado con el ID especificado" << std::endl;
    }
    archivo.close();
  }


void GuardarEmpleados::mostrarEmpleado() const {

    cout << "Id Persona: "<< id << endl;
    cout << "|" << setw(20) << "      Datos del trabajador      |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
    cout << "| " << "Nombre:          " << nombre << " " << apellido << setw(5) << "| " << endl;
    cout << "| " << "Puesto:          " << puesto<< setw(5) << "| " << endl;
    cout << "| " << "Departamento:    " << departamento <<setw(5) << "| " << "Sueldo:                           Q " << sueldo << setw(4) << "| " << "ISR:                           Q " <<isr << setw(4) << "|" << endl;
    cout << "| " << "Genero:          " << genero << setw(7) << "| " << "Bonificaciones:                   Q " << bonificacionIncentiva << setw(5) << "| " << "IGGS:                          Q " << iggs << setw(4) << "|" << endl;
    cout << "| " << "DPI:             " << dpi << setw(10) << "| " << "Comisiones:                       Q " << comisiones << setw(5) << "| " << "IRTRA:                         Q " << irtra << setw(8) << "|" << endl;
    cout << "| " << "Telefono 1:      " << telefono << setw(10) << "| " << "Percepciones Extraordinarias:     Q " << percepciones_extra << setw(5) << "| " << "Prestamos:                     Q " << prestamos << setw(7) << "|" << endl;
    cout << "| " << "Telefono 2:      " << telefono1 << setw(10) << "| " << "Horas Extra:                      Q " << horas_extra << setw(6) << "| " << setw(43) << "|" << endl;
    cout << "| " << "Cuenta Bancaria: " << numCuenta << setw(10) << "| " << "Total Percepciones:               Q " << total_percepciones << setw(4) << "| " << "Total Deducciones:             Q " << deducciones_totales << setw(7) << "|" << endl;
    cout << "| " << setw(120) << "|" << endl;
    cout << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(93) << "|" << endl;
    cout << "| " << setw(120) << "|" << endl;
    cout << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98) << "|" << endl;
  }
