#include "IngresarDatosEmpleado.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


IngresarDatosEmpleado::IngresarDatosEmpleado(int id, string nombre, string apellido, string genero, string puesto, string departamento, int dia, int mes, int dpi, int telefono, int telefono1, int numCuenta, float sueldo, float comisiones, float percepciones_extra, float horas_extra, float isr)
{
    //El valor del parámetro se asigna al miembro de la clase.
    //El operador this se usa para referirse al miembro de la clase y no al parámetro de la función que tiene el mismo nombre.
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->genero = genero;
    this->puesto = puesto;
    this->departamento = departamento;
    this->dia = dia;
    this->mes = mes;
    this->dpi = dpi;
    this->telefono = telefono;
    this->telefono1 = telefono1;
    this->numCuenta = numCuenta;
    this->sueldo = sueldo;
    this->comisiones = comisiones;
    this->percepciones_extra = percepciones_extra;
    this->horas_extra = horas_extra;
    this->isr = isr;
}

// set y get para nid
int IngresarDatosEmpleado::setId(int id) {
    this->id = id;
}
int IngresarDatosEmpleado::getId() {
    return this->id;
}

// set y get para nombre
string IngresarDatosEmpleado::setNombre(string nombre) {
    this->nombre = nombre;
}
string IngresarDatosEmpleado::getNombre() {
    return this->nombre;
}

// set y get para apellido
string IngresarDatosEmpleado::setApellido(string apellido) {
    this->apellido = apellido;
}
string IngresarDatosEmpleado::getApellido() {
    return this->apellido;
}

// set y get para genero
string IngresarDatosEmpleado::setGenero(string genero) {
    this->genero = genero;
}
string IngresarDatosEmpleado::getGenero() {
    return this->genero;
}

// set y get para dia
int IngresarDatosEmpleado::setDia(int dia) {
    this->dia = dia;
}
int IngresarDatosEmpleado::getDia() {
    return this->dia;
}

// set y get para mes
int IngresarDatosEmpleado::setMes(int mes) {
    this->mes = mes;
}
int IngresarDatosEmpleado::getMes() {
    return this->mes;
}

// set y get para dpi
int IngresarDatosEmpleado::setDpi(int dpi) {
    this->dpi = dpi;
}
int IngresarDatosEmpleado::getDpi() {
    return this->dpi;
}

// set y get para telefono
int IngresarDatosEmpleado::setTelefono(int telefono) {
    this->telefono = telefono;
}
int IngresarDatosEmpleado::getTelefono() {
    return this->telefono;
}

// set y get para telefono1
int IngresarDatosEmpleado::setTelefono1(int telefono1) {
    this->telefono1 = telefono1;
}
int IngresarDatosEmpleado::getTelefono1() {
    return this->telefono1;
}

// set y get para numCuenta
int IngresarDatosEmpleado::setNumCuenta(int numCuenta) {
    this->numCuenta = numCuenta;
}
int IngresarDatosEmpleado::getNumCuenta() {
    return this->numCuenta;
}

// set y get para sueldo
float IngresarDatosEmpleado::setSueldo(float sueldo) {
    this->sueldo = sueldo;
}
float IngresarDatosEmpleado::getSueldo() {
    return this->sueldo;
}

// set y get para comisiones
float IngresarDatosEmpleado::setComisiones(float comisiones) {
    this->comisiones = comisiones;
}
float IngresarDatosEmpleado::getComisiones() {
    return this->comisiones;
}

// set y get para percepciones_extra
float IngresarDatosEmpleado::setPercepciones_extra(float percepciones_extras){
    this->percepciones_extra = percepciones_extras;
}
float IngresarDatosEmpleado::getPercepciones_extra(){
    return this->percepciones_extra;
}

// set y get para horas_extra
float IngresarDatosEmpleado::setHoras_extra(float horas_extra) {
    this->horas_extra = horas_extra;
}
float IngresarDatosEmpleado::getHoras_extra() {
    return this->horas_extra;
}

// set y get para isr
float IngresarDatosEmpleado::setIsr(float isr) {
    this->isr = isr;
}
float IngresarDatosEmpleado::getIsr() {
    return this->isr;
}

void IngresarDatosEmpleado::menuDatosEmpleado()
{
    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout <<"\t\t\t--------------------------------------"<<endl;
    cout <<"\t\t\t|MENU DE INGRESO DE DATOS DE EMPLEADO|"<<endl;
    cout <<"\t\t\t--------------------------------------"<<endl;
	cout<<"\t\t\t 1. Datos Personales"<<endl;
	cout<<"\t\t\t 2. Puesto del Empleado"<<endl;
	cout<<"\t\t\t 3. Departamento del Empleado"<<endl;
	cout<<"\t\t\t 4. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        insertarDatos();
        break;
	case 2:
		insertarDatosPuesto();
		break;
	case 3:
		insertarDatosDepartamento();
		break;
	case 4:
		salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 4);
}

void IngresarDatosEmpleado::insertarDatos()
{
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Datos Personales ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Persona         : ";//Solicita al usuario que ingrese el ID de la persona y lo almacena en la variable id.
	cin>> id;
	cout<<"\t\t\tNombre: ";//Solicita al usuario que ingrese el nombre del empleado y lo almacena en la variable nombre.
	cin >> nombre;
    cout << "\t\t\tApellido: ";//Solicita al usuario que ingrese el apellido del empleado y lo almacena en la variable apellido.
    cin >> apellido;
    cout << "\t\t\tGenero: ";//Solicita al usuario que ingrese el género del empleado y lo almacena en la variable genero.
    cin >> genero;
    cout << "\t\t\tEscriba su DPI: ";//Solicita al usuario que ingrese su número de DPI y lo almacena en la variable dpi.
    cin >> dpi;
    cout << "\t\t\tEscriba su primer numero de telefono: ";//Solicita al usuario que ingrese su primer número de teléfono y lo almacena en la variable telefono.
    cin >> telefono;
    cout << "\t\t\tEscriba su segundo numero de telefono: ";//Solicita al usuario que ingrese su segundo número de teléfono y lo almacena en la variable telefono1.
    cin >> telefono1;
    cout << "\t\t\tEscriba su numero de cuenta bancaria: ";//Solicita al usuario que ingrese su número de cuenta bancaria y lo almacena en la variable numCuenta.
    cin >> numCuenta;

        cout << "\n\t\t\tIngrese el dia actual: ";//Solicita al usuario que ingrese el día actual y comprueba que sea válido (entre 1 y 31). Si el valor es incorrecto, muestra un mensaje y vuelve a solicitar al usuario que ingrese un valor válido.
        cin >> dia;
        while (dia < 1 || mes> 31)
        {
            cout << "\t\t\tVerifique que el dia sea correcto" << endl;
            cin >> dia;
        }
        cout << "\n\t\t\tIngrese el mes actual: ";//Solicita al usuario que ingrese el mes actual y comprueba que sea válido (entre 1 y 12). Si el valor es incorrecto, muestra un mensaje y vuelve a solicitar al usuario que ingrese un valor válido.
        cin >> mes;
        while (mes < 1 || mes > 12)
        {
            cout << "\t\t\tVerifique que el mes sea correcto" << endl;
            cin >> mes;
        }


        cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void IngresarDatosEmpleado::insertarDatosPuesto()
{
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Puesto del Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tPuesto: ";
    cin >> puesto;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void IngresarDatosEmpleado::insertarDatosDepartamento()
{
	system("cls");
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Departamento del Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tDepartamento: ";
    cin >> departamento;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void IngresarDatosEmpleado::insertarPercepciones()
{
	system("cls");
    float horaOrdinaria, horasExtras;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Persepciones Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tSueldo: ";//Solicita al usuario que ingrese el Sueldo de la persona y lo almacena en la variable sueldo.
    cin >> sueldo;
    cout << "\t\t\tBonificacion Incentiva: "<< bonificacionIncentiva << endl;//Se muestra la Bonificacion Incentiva.
    cout << "\t\t\tComisiones: ";////Solicita al usuario que ingrese las comisiones de la persona y lo almacena en la variable comisiones.
    cin >> comisiones;
    cout << "\t\t\tPercepciones Extraordinarias: ";//Solicita al usuario que ingrese las persepciones extraordinarias de la persona y lo almacena en la variable percepciones_extra.
    cin >> percepciones_extra;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void IngresarDatosEmpleado::insertarHorasExtras()
{
	system("cls");
    float horaOrdinaria, horasExtras;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Hora Extras Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tHoras Extra: ";//Solicita al usuario que ingrese las Horas Extras de la persona y lo almacena en la variable horasExtras.
    cin >> horasExtras;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void IngresarDatosEmpleado::insertarDeducciones()
{
	system("cls");
    float horaOrdinaria, horasExtras;
	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar Deducciones Empleado ---------------------------------------------"<<endl;
    cout << "\t\t\tPrestamos: ";//Solicita al usuario que ingrese las Prestamos de la persona y lo almacena en la variable prestamos.
    cin >> prestamos;
    cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE!!!";
}
void IngresarDatosEmpleado::insertar()
{
	    //Limpia la pantalla
    system("cls");

    //Declara variables necesarias
    char x;
    float horaOrdinaria, horasExtras;

    //Crea un objeto filestream para trabajar con archivos
    fstream file;

    //Imprime texto en la consola
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n-------------------------------------------------Agregar a Empleado-----------------------------------------------------"<<endl;

    //Pide al usuario si desea agregar un empleado
    cout<<"\t\t\t\n¿Quiere agregar al empleado?(Y,N): ";
    cin>>x;

    //Si el usuario elige "y" o "Y", entra al bloque de código dentro del if
    if (x=='y'||x=='Y'){
        //Calcula el valor de la hora ordinaria y de las horas extras
        horaOrdinaria = ((((sueldo/30)/8)*1.5));
        horas_extra = horaOrdinaria * horasExtras;

        //Calcula el total de percepciones, ISR, IIGS, deducciones totales y sueldo líquido
        total_percepciones = sueldo + bonificacionIncentiva + comisiones + percepciones_extra + horas_extra;
        isr = total_percepciones * 0.05;
        iggs = total_percepciones * 0.03;
        deducciones_totales = isr + iggs + irtra + prestamos;
        sueldo_liquido = total_percepciones - deducciones_totales;

        //Abre el archivo "ParticipantRecord1.txt" para guardar como archivo de acceso aleatorio
       file.open("ParticipantRecord1.txt", ios::app | ios::out);
        file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< genero <<std::left<<std::setw(15)<< puesto  <<std::left<<std::setw(15)<< departamento <<std::left<<std::setw(15)<< dia <<std::left<<std::setw(15)<< mes <<std::left<<std::setw(15)<< dpi <<std::left<<std::setw(15)<< telefono
            <<std::left<<std::setw(15)<< telefono1 <<std::left<<std::setw(15)<< numCuenta <<std::left<<std::setw(15)<< sueldo <<std::left<<std::setw(15)<< bonificacionIncentiva <<std::left<<std::setw(15)<< comisiones <<std::left<<std::setw(15)<< percepciones_extra <<std::left<<std::setw(15)<< horas_extra
            <<std::left<<std::setw(15)<< total_percepciones <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< iggs <<std::left<<std::setw(15)<< irtra <<std::left<<std::setw(15)<< prestamos <<std::left<<std::setw(15)<< deducciones_totales <<std::left<<std::setw(15)<< sueldo_liquido << "\n";

        file.close();

       /* //Abre el archivo "ParticipantRecord1.txt" en modo de agregar y escritura
       file.open("ParticipantRecord1.txt", ios::app | ios::out);

        //Escribe la información del empleado en el archivo
	   file <<"\n\n\t\t\t Id Persona: "<<id<<endl;
       file << "|" << setw(20) << "         Datos del trabajador         |" << setw(7) << "           Percepciones Empleados          |" << setw(6) << "           Deducciones Empleados           |" << endl;
	   file << "| " << "Nombre:          " << nombre << " " << apellido << setw(10);
	   file << "|" << endl;
	   file << "| " << "Puesto:          " << puesto<< setw(10);
	   file << "|" << endl;
       file << "| " << "Departamento:    " << departamento <<setw(10);
       file << "| " << "Sueldo:                        Q " << right << sueldo << setw(4);
       file << "| " << "ISR:                           Q " << right << isr << setw(4);
       file << "|" << endl;
       file << "| " << "Genero:          " << genero << setw(10);
       file << "| " << "Bonificaciones:                Q " << right << bonificacionIncentiva << setw(5);
       file << "| " << "IGGS:                          Q " << right << iggs << setw(4);
       file << "|" << endl;
       file << "| " << "DPI:             " << dpi << setw(10);
       file << "| " << "Comisiones:                    Q " << right << comisiones << setw(5);
       file << "| " << "IRTRA:                         Q " << right << irtra << setw(8);
       file << "|" << endl;
       file << "| " << "Telefono 1:      " << telefono << setw(10);
       file << "| " << "Percepciones Extraordinarias:  Q " << right << percepciones_extra << setw(5);
       file << "| " << "Prestamos:                     Q " << right << prestamos << setw(7);
       file << "|" << endl;
       file << "| " << "Telefono 2:      " << telefono1 << setw(10);
       file << "| " << "Horas Extra:                   Q " << right << horas_extra << setw(6);
       file << "|" << endl;
       file << "| " << "Cuenta Bancaria: " << numCuenta << setw(10);
       file << "| " << "Total Percepciones:            Q " << right << total_percepciones << setw(4);
       file << "| " << "Total Deducciones:             Q " << right << deducciones_totales << setw(7);
       file << "|" << endl;
       file << "| " << setw(120);
       file << "|" << endl;
       file << "| " << "TOTAL SUELDO LIQUIDO Q " << sueldo_liquido << setw(91);
       file << "|" << endl;
       file << "| " << setw(120);
       file << "|" << endl;
       file << "| " << "Fecha de emision: " << dia << "/" << mes << setw(98);
       file << "|" << endl;
	   file.close();//Cierra el archivo
	   cout<<"\t\t\t\nSE INGRESO CORRECTAMENTE AL EMPLEADO!!!";
	   }else{
	       cout<<"\t\t\t\nNo se realizara ninguna operacion";
	   }*/

}
}
