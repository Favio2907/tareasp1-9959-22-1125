#ifndef DATOS_H
#define DATOS_H


#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>


using namespace std;


class datos
{
    public:
        datos();
        datos(int id, string nombre, string apellido, string genero, int dia, int mes, int dpi, int telefono, int telefono1, int numCuenta, float sueldo, float comisiones, float percepciones_extra, float horas_extra, float isr);

        string setNombre(string nombre); //Recibe como par�metro una cadena de texto nombre y se utiliza para establecer el valor del atributo privado nombre de la clase. La funci�n devuelve el nuevo valor asignado al atributo.
        string getNombre(); //No recibe par�metros y se utiliza para obtener el valor actual del atributo privado nombre de la clase. La funci�n devuelve una cadena de texto que representa el valor actual del atributo.
        string setApellido(string apellido); //Recibe como par�metro una cadena de texto apellido y se utiliza para establecer el valor del atributo privado apellido de la clase. La funci�n devuelve el nuevo valor asignado al atributo.
        string getApellido(); //No recibe par�metros y se utiliza para obtener el valor actual del atributo privado apellido de la clase. La funci�n devuelve una cadena de texto que representa el valor actual del atributo.
        string setGenero(string genero); //Recibe como par�metro una cadena de texto genero y se utiliza para establecer el valor del atributo privado genero de la clase. La funci�n devuelve el nuevo valor asignado al atributo.
        string getGenero(); //No recibe par�metros y se utiliza para obtener el valor actual del atributo privado genero de la clase. La funci�n devuelve una cadena de texto que representa el valor actual del atributo.

        // Funciones de la clase para establecer y obtener los valores de los atributos privados:

        int setId(int id); // Establece el valor del atributo privado 'id' de la clase
        int getId(); // Obtiene el valor del atributo privado 'id' de la clase

        int setDia (int dia); // Establece el valor del atributo privado 'dia' de la clase
        int getDia(); // Obtiene el valor del atributo privado 'dia' de la clase

        int setMes (int mes); // Establece el valor del atributo privado 'mes' de la clase
        int getMes(); // Obtiene el valor del atributo privado 'mes' de la clase

        int setDpi (int dpi); // Establece el valor del atributo privado 'dpi' de la clase
        int getDpi(); // Obtiene el valor del atributo privado 'dpi' de la clase

        int setTelefono (int telefono); // Establece el valor del atributo privado 'telefono' de la clase
        int getTelefono(); // Obtiene el valor del atributo privado 'telefono' de la clase

        int setTelefono1(int telefono1); // Establece el valor del atributo privado 'telefono1' de la clase
        int getTelefono1(); // Obtiene el valor del atributo privado 'telefono1' de la clase

        int setNumCuenta (int numCuenta); // Establece el valor del atributo privado 'numCuenta' de la clase
        int getNumCuenta(); // Obtiene el valor del atributo privado 'numCuenta' de la clase

        float setSueldo(float sueldo); // Establece el valor del atributo privado 'sueldo' de la clase
        float getSueldo(); // Obtiene el valor del atributo privado 'sueldo' de la clase

        float setComisiones(float comisiones); // Establece el valor del atributo privado 'comisiones' de la clase
        float getComisiones(); // Obtiene el valor del atributo privado 'comisiones' de la clase

        float setPercepciones_extra(float percepciones_extra); // Establece el valor del atributo privado 'percepciones_extra' de la clase
        float getPercepciones_extra(); // Obtiene el valor del atributo privado 'percepciones_extra' de la clase

        float setHoras_extra(float horas_extra); // Establece el valor del atributo privado 'horas_extra' de la clase
        float getHoras_extra(); // Obtiene el valor del atributo privado 'horas_extra' de la clase

        float setIsr(float isr); // Establece el valor del atributo privado 'isr' de la clase
        float getIsr(); // Obtiene el valor del atributo privado 'isr' de la clase

        float setIggs(float iggs); // Establece el valor del atributo privado 'iggs' de la clase
        float getIggs(); // Obtiene el valor del atributo privado 'iggs' de la clase

        float setPrestamosfloatm(float prestamosfloatm); // Establece el valor del atributo privado 'prestamosfloatm' de la clase
        float getPrestamosfloatm(); // Obtiene el valor del atributo privado 'prestamosfloatm' de la clase

        void menu(); // La funcion menu() muestra un menu en consola para que el usuario pueda elegir entre diferentes opciones.
		void insertar(); // La funci�n insertar() permite al usuario ingresar informaci�n para crear un nuevo registro y lo guarda en un archivo.
		void desplegar(); // La funci�n desplegar() lee y muestra todos los registros almacenados en el archivo.
		void modificar(); // La funci�n modificar() permite al usuario seleccionar un registro por ID y modificar su informaci�n.
		void buscar(); // La funci�n buscar() permite al usuario buscar un registro por ID y mostrar su informaci�n.
		void borrar(); // La funci�n borrar() permite al usuario eliminar un registro por ID.
		void imprimirLinea(); // La funci�n imprimirLinea() imprime una l�nea de caracteres en consola para mejorar la legibilidad del men� y los resultados.

		void menuDatos(); //Funcion menu el cual nos permitira ingresar los datos del empleado
		void insertarDatos(); // Ingresara los datos del empleado
		void insertarPercepciones(); // Ingresara las percepciones del empleado
		void insertarHorasExtras(); //Ingresara las horas extras del empleado
		void insertarDeducciones(); //Ingresara las deducciones extras del empleado

		void menuBusquedaDatos();




    protected:

    private:
        string nombre, apellido, genero; // 'nombre', 'apellido' y 'genero' son variables tipo 'string' que almacenan los datos personales del empleado.
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

#endif // PERSONA_H"
