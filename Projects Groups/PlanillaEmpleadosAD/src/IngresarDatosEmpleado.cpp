#include "IngresarDatosEmpleado.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;


IngresarDatosEmpleado::IngresarDatosEmpleado(int idE, string nombreE, string apellidoE, string generoE, string puestoE, string departamentoE, int diaE, int mesE, int dpiE, int telefonoE, int telefono1E, int numCuentaE, float sueldoE, float comisionesE, float percepciones_extraE, float horas_extraE, float isrE)
{
    //El valor del parámetro se asigna al miembro de la clase.
    //El operador this se usa para referirse al miembro de la clase y no al parámetro de la función que tiene el mismo nombre.
    this->id = idE;
    this->nombre = nombreE;
    this->apellido = apellidoE;
    this->genero = generoE;
    this->puesto = puestoE;
    this->departamento = departamentoE;
    this->dia = diaE;
    this->mes = mesE;
    this->dpi = dpiE;
    this->telefono = telefonoE;
    this->telefono1 = telefono1E;
    this->numCuenta = numCuentaE;
    this->sueldo = sueldoE;
    this->comisiones = comisionesE;
    this->percepciones_extra = percepciones_extraE;
    this->horas_extra = horas_extraE;
    this->isr = isrE;
}

// set y get para nid
int IngresarDatosEmpleado::setId(int idE) {
    this->id = idE;
}
int IngresarDatosEmpleado::getId() {
    return this->id;
}

// set y get para nombre
string IngresarDatosEmpleado::setNombre(string nombreE) {
    this->nombre = nombreE;
}
string IngresarDatosEmpleado::getNombre() {
    return this->nombre;
}

// set y get para apellido
string IngresarDatosEmpleado::setApellido(string apellidoE) {
    this->apellido = apellidoE;
}
string IngresarDatosEmpleado::getApellido() {
    return this->apellido;
}

// set y get para genero
string IngresarDatosEmpleado::setGenero(string generoE) {
    this->genero = generoE;
}
string IngresarDatosEmpleado::getGenero() {
    return this->genero;
}

// set y get para dia
int IngresarDatosEmpleado::setDia(int diaE) {
    this->dia = diaE;
}
int IngresarDatosEmpleado::getDia() {
    return this->dia;
}

// set y get para mes
int IngresarDatosEmpleado::setMes(int mesE) {
    this->mes = mesE;
}
int IngresarDatosEmpleado::getMes() {
    return this->mes;
}

// set y get para dpi
int IngresarDatosEmpleado::setDpi(int dpiE) {
    this->dpi = dpiE;
}
int IngresarDatosEmpleado::getDpi() {
    return this->dpi;
}

// set y get para telefono
int IngresarDatosEmpleado::setTelefono(int telefonoE) {
    this->telefono = telefonoE;
}
int IngresarDatosEmpleado::getTelefono() {
    return this->telefono;
}

// set y get para telefono1
int IngresarDatosEmpleado::setTelefono1(int telefono1E) {
    this->telefono1 = telefono1E;
}
int IngresarDatosEmpleado::getTelefono1() {
    return this->telefono1;
}

// set y get para numCuenta
int IngresarDatosEmpleado::setNumCuenta(int numCuentaE) {
    this->numCuenta = numCuentaE;
}
int IngresarDatosEmpleado::getNumCuenta() {
    return this->numCuenta;
}

// set y get para sueldo
float IngresarDatosEmpleado::setSueldo(float sueldoE) {
    this->sueldo = sueldoE;
}
float IngresarDatosEmpleado::getSueldo() {
    return this->sueldo;
}

// set y get para comisiones
float IngresarDatosEmpleado::setComisiones(float comisionesE) {
    this->comisiones = comisionesE;
}
float IngresarDatosEmpleado::getComisiones() {
    return this->comisiones;
}

// set y get para percepciones_extra
float IngresarDatosEmpleado::setPercepciones_extra(float percepciones_extrasE){
    this->percepciones_extra = percepciones_extrasE;
}
float IngresarDatosEmpleado::getPercepciones_extra(){
    return this->percepciones_extra;
}

// set y get para horas_extra
float IngresarDatosEmpleado::setHoras_extra(float horas_extraE) {
    this->horas_extra = horas_extraE;
}
float IngresarDatosEmpleado::getHoras_extra() {
    return this->horas_extra;
}

// set y get para isr
float IngresarDatosEmpleado::setIsr(float isrE) {
    this->isr = isrE;
}
float IngresarDatosEmpleado::getIsr() {
    return this->isr;
}

void IngresarDatosEmpleado::menuIngresarDatosEmpleado()
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
	cout<<"\t\t\t 4. Agregar los Datos del Empleado"<<endl;
	cout<<"\t\t\t 5. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
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
		insertar();
		break;
	case 5:
		salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 5);
}

void IngresarDatosEmpleado::menuIngresarProcesos()
{
    system("cls");
    fstream file,file1;
    int found=0;
    int participant_id;
    cout<<"\n-------------------------Agregar Procesos Empleado-------------------------"<<endl;
    file1.open("Record1.txt", ios::in);
    if(!file1) {
        cout<<"\n\t\t\tNo hay informacion..,";
        file1.close();
    } else {
        cout<<"\n Ingrese Id del empleado que desea actualizar: ";
        cin>>participant_id;
        file.open("ParticipantRecord1.txt", ios::app | ios::out);
        file1 >> id >>nombre >>apellido >>genero >>puesto >>departamento >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
        while(!file1.eof())
        {
			if(participant_id=id)
			{
                bool salir = false;
                int choice;

                fstream file2;
                file2.open("Bitacora.txt", ios::app | ios::out);

                int accion0 = 7001;
                int accion1 = 7002;
                int accion2 = 7003;
                int accion3 = 7004;
                int accion4 = 7005;

                found++;

                do
                {
                    system("cls");
                    cout <<"\t\t\t---------------------------------------"<<endl;
                    cout <<"\t\t\t|MENU DE INGRESO DE DATOS DE PLANILLA|"<<endl;
                    cout <<"\t\t\t---------------------------------------"<<endl;
                    cout<<"\t\t\t 1. Ingreso de Percepciones del Empledo"<<endl;
                    cout<<"\t\t\t 2. Ingreso de Horas Extras del Empleado"<<endl;
                    cout<<"\t\t\t 3. Ingreso de Deducciones del Empleado"<<endl;
                    cout<<"\t\t\t 4. Agregar los Datos del Empleado"<<endl;
                    cout<<"\t\t\t 5. Exit"<<endl;

                    cout<<"\t\t\t-------------------------------"<<endl;
                    cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
                    cout<<"\t\t\t-------------------------------"<<endl;
                    cout<<"Ingresa tu Opcion: ";
                    cin>>choice;

                    switch(choice)
                    {
                    case 1:
                        insertarPercepciones();
                        file2<<"\t\t\tAccion: Ingreso Percepciones - " <<accion1<<"\n"<<endl;
                        break;
                    case 2:
                        insertarHorasExtras();
                        file2<<"\t\t\tAccion: Ingreso Horas Extras - " <<accion2<<"\n"<<endl;
                        break;
                    case 3:
                        insertarDeducciones();
                        file2<<"\t\t\tAccion: Ingreso Deducciones - " <<accion3<<"\n"<<endl;
                        break;
                    case 4:
                        insertar2();
                        file2<<"\t\t\tAccion: Ingreso Todos los Datos - " <<accion4<<"\n"<<endl;
                        break;
                    case 5:
                        salir = true;
                    default:
                        cout<<"\t\t\t\nSaliendo del menu";
                    }
                    getch();
                }while(choice!= 5);
                file2.close();
                break;
            }
        }
        if(found==0)
		{
			cout << "No se encontró ningún registro con esa ID." << endl;
		}
		file.close();
    }
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

    //Crea un objeto filestream para trabajar con archivos
    fstream file1;

    //Imprime texto en la consola
    cout<<"\n------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n-------------------------------------------------Agregar a Empleado-----------------------------------------------------"<<endl;

    //Pide al usuario si desea agregar un empleado
    cout<<"\t\t\t\n¿Quiere agregar al empleado?(Y,N): ";
    cin>>x;

    //Si el usuario elige "y" o "Y", entra al bloque de código dentro del if
    if (x=='y'||x=='Y'){

        float sueldo = 0;
        float comisiones = 0;
        float percepciones_extra = 0;
        float horas_extra = 0;
        float isr = 0;
        float iggs = 0;
        float prestamos = 0;
        float deducciones_totales = 0;
        float sueldo_liquido = 0;
        float irtra = 0;
        float total_percepciones = 0;
        float bonificacionIncentiva = 0;

        //Abre el archivo "Record1.txt" para guardar como archivo de acceso aleatorio
        file1.open("Record1.txt", ios::app | ios::out);
        file1<<std::left<<std::setw(10)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< genero <<std::left<<std::setw(15)<< puesto  <<std::left<<std::setw(15)<< departamento <<std::left<<std::setw(15)<< dia <<std::left<<std::setw(15)<< mes <<std::left<<std::setw(15)<< dpi <<std::left<<std::setw(15)<< telefono
            <<std::left<<std::setw(15)<< telefono1 <<std::left<<std::setw(15)<< numCuenta <<std::left<<std::setw(15)<< sueldo <<std::left<<std::setw(15)<< bonificacionIncentiva <<std::left<<std::setw(15)<< comisiones <<std::left<<std::setw(15)<< percepciones_extra <<std::left<<std::setw(15)<< horas_extra
            <<std::left<<std::setw(15)<< total_percepciones <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< iggs <<std::left<<std::setw(15)<< irtra <<std::left<<std::setw(15)<< prestamos <<std::left<<std::setw(15)<< deducciones_totales <<std::left<<std::setw(15)<< sueldo_liquido << "\n";

        file1.close();

         cout << "Empleado guardado exitosamente" << endl;

    }
}

void IngresarDatosEmpleado::insertar2()
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
        file<<std::left<<std::setw(10)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< genero <<std::left<<std::setw(15)<< puesto  <<std::left<<std::setw(15)<< departamento <<std::left<<std::setw(15)<< dia <<std::left<<std::setw(15)<< mes <<std::left<<std::setw(15)<< dpi <<std::left<<std::setw(15)<< telefono
             <<std::left<<std::setw(15)<< telefono1 <<std::left<<std::setw(15)<< numCuenta <<std::left<<std::setw(15)<< sueldo <<std::left<<std::setw(15)<< bonificacionIncentiva <<std::left<<std::setw(15)<< comisiones <<std::left<<std::setw(15)<< percepciones_extra <<std::left<<std::setw(15)<< horas_extra
             <<std::left<<std::setw(15)<< total_percepciones <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< iggs <<std::left<<std::setw(15)<< irtra <<std::left<<std::setw(15)<< prestamos <<std::left<<std::setw(15)<< deducciones_totales <<std::left<<std::setw(15)<< sueldo_liquido << "\n";

        file.close();

         cout << "Empleado guardado exitosamente" << endl;

    }
}
