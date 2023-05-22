#ifndef GUARDAREMPLEADOS_H
#define GUARDAREMPLEADOS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class GuardarEmpleados
{
    public:
        GuardarEmpleados(int id = 0, string nombre = "", string apellido = "", string genero = "", string puesto = "", string departamento = "", int dia = 0, int mes = 0, int dpi = 0, int telefono = 0, int telefono1 = 0, int numCuenta = 0, float sueldo = 0, float comisiones = 0, float percepciones_extra = 0, float horas_extra = 0, float isr = 0);

        void guardarEmpleado();
        static void mostrarEmpleados(int id);
        void mostrarEmpleado() const;

    protected:

    private:

        string nombre, apellido, genero, puesto, departamento; // 'nombre', 'apellido' y 'genero' son variables tipo 'string' que almacenan los datos personales del empleado.
        int id; // 'id' es una variable tipo 'int' que almacena el ID del empleado.
        int dia, mes, dpi, telefono, telefono1 , numCuenta; // 'dia', 'mes', 'dpi', 'telefono', 'telefono1' y 'numCuenta' son variables tipo 'int' que almacenan informaci�n de contacto y DPI del empleado.
        float sueldo; // 'sueldo' es el salario base del empleado.
        float comisiones; // 'comisiones' son las comisiones que se le otorgan al empleado por ventas o desempe�o.
        float percepciones_extra; // 'percepciones_extra' son otras percepciones adicionales que se le otorgan al empleado.
        float horas_extra; // 'horas_extra' son las horas extra que el empleado trabaja y por las cuales recibe un pago adicional.
        float isr; // 'isr' es el Impuesto Sobre la Renta que se deduce del salario del empleado.
        float iggs; // 'iggs' es la cotizaci�n del empleado al Instituto Guatemalteco de Seguridad Social.
        float prestamos; // 'prestamos' son los pr�stamos que el empleado ha recibido y que se deducen de su salario.
        float deducciones_totales; // 'deducciones_totales' es el total de todas las deducciones del salario, incluyendo ISR, IGGS, prestamos y otras deducciones.
        float sueldo_liquido; // 'sueldo_liquido' es el salario restante despu�s de las deducciones.
        float irtra = 75; // Monto fijo de contribuci�n al IRTRA
        float total_percepciones; // Total de percepciones, incluyendo sueldo, comisiones, horas extra, etc.
        float bonificacionIncentiva = 250;  // Monto fijo de bonificaci�n incentivada, que se suma a las percepciones totales
};

#endif // GUARDAREMPLEADOS_H
