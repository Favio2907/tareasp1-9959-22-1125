#include "DatosEmpleado.h"
#include "GuardarEmpleados.h"
#include "IngresarDatosEmpleado.h"
#include "Usuarios.h"
#include "bitacora.h"

#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

DatosEmpleado::DatosEmpleado(int id, string nombre, string apellido, string genero, string puesto, string departamento, int dia, int mes, int dpi, int telefono, int telefono1, int numCuenta, float sueldo, float comisiones, float percepciones_extra, float horas_extra, float isr)
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
int DatosEmpleado::setId(int id) {
    this->id = id;
}
int DatosEmpleado::getId() {
    return this->id;
}

// set y get para nombre
string DatosEmpleado::setNombre(string nombre) {
    this->nombre = nombre;
}
string DatosEmpleado::getNombre() {
    return this->nombre;
}

// set y get para apellido
string DatosEmpleado::setApellido(string apellido) {
    this->apellido = apellido;
}
string DatosEmpleado::getApellido() {
    return this->apellido;
}

// set y get para genero
string DatosEmpleado::setGenero(string genero) {
    this->genero = genero;
}
string DatosEmpleado::getGenero() {
    return this->genero;
}

// set y get para dia
int DatosEmpleado::setDia(int dia) {
    this->dia = dia;
}
int DatosEmpleado::getDia() {
    return this->dia;
}

// set y get para mes
int DatosEmpleado::setMes(int mes) {
    this->mes = mes;
}
int DatosEmpleado::getMes() {
    return this->mes;
}

// set y get para dpi
int DatosEmpleado::setDpi(int dpi) {
    this->dpi = dpi;
}
int DatosEmpleado::getDpi() {
    return this->dpi;
}

// set y get para telefono
int DatosEmpleado::setTelefono(int telefono) {
    this->telefono = telefono;
}
int DatosEmpleado::getTelefono() {
    return this->telefono;
}

// set y get para telefono1
int DatosEmpleado::setTelefono1(int telefono1) {
    this->telefono1 = telefono1;
}
int DatosEmpleado::getTelefono1() {
    return this->telefono1;
}

// set y get para numCuenta
int DatosEmpleado::setNumCuenta(int numCuenta) {
    this->numCuenta = numCuenta;
}
int DatosEmpleado::getNumCuenta() {
    return this->numCuenta;
}

// set y get para sueldo
float DatosEmpleado::setSueldo(float sueldo) {
    this->sueldo = sueldo;
}
float DatosEmpleado::getSueldo() {
    return this->sueldo;
}

// set y get para comisiones
float DatosEmpleado::setComisiones(float comisiones) {
    this->comisiones = comisiones;
}
float DatosEmpleado::getComisiones() {
    return this->comisiones;
}

// set y get para percepciones_extra
float DatosEmpleado::setPercepciones_extra(float percepciones_extras){
    this->percepciones_extra = percepciones_extras;
}
float DatosEmpleado::getPercepciones_extra(){
    return this->percepciones_extra;
}

// set y get para horas_extra
float DatosEmpleado::setHoras_extra(float horas_extra) {
    this->horas_extra = horas_extra;
}
float DatosEmpleado::getHoras_extra() {
    return this->horas_extra;
}

// set y get para isr
float DatosEmpleado::setIsr(float isr) {
    this->isr = isr;
}
float DatosEmpleado::getIsr() {
    return this->isr;
}

void DatosEmpleado::menuDatos()
{
    string nombre, apellido, genero, puesto, departamento;
    int id;
    int dia, mes, dpi, telefono, telefono1 , numCuenta;
    IngresarDatosEmpleado empleado2(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);

    bool salir = false;
    int choice;

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion0 = 7001;

	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------------"<<endl;
    cout <<"\t\t\t| MENU DE INGRESO DE DATOS DE PLANILLA |"<<endl;
    cout <<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso de Datos del Empleado"<<endl;
	cout<<"\t\t\t 2. Exit"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
		empleado2.menuDatosEmpleado();
		file2<<"\t\t\tAccion: Ingreso Datos del Empleado - " <<accion0<<"\n"<<endl;
		break;
	case 2:
		salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 2);
    file2.close();
}




void DatosEmpleado::menuProcesosEmpleado()
{
    float sueldo;
    float bonificacionIncentiva = 250;
    float comisiones;
    float percepciones_extra;
    float horas_extra;
    float total_percepciones;
    float isr;
    float iggs;
    float irtra = 75;
    float prestamos;
    float deducciones_totales;
    float sueldo_liquido;
    IngresarDatosEmpleado empleado2(id, nombre, apellido,genero, puesto, departamento, dia, mes, dpi, telefono, telefono1, numCuenta, sueldo, comisiones, percepciones_extra, horas_extra, isr);

    fstream file2;
    file2.open("Bitacora.txt", ios::app | ios::out);

    int accion1 = 7002;
    int accion2 = 7003;
    int accion3 = 7004;
    int accion4 = 7005;

    int accion6 = 7007;
    int accion7 = 7008;
    int accion8 = 7009;

    bool salir = false;
    int choice;
	do
    {
	system("cls");

    cout <<"\t\t\t----------------------------------"<<endl;
    cout <<"\t\t\t|MENU DE PROCESOS DE PLANILLA|"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
    cout<<"\t\t\t 1. Ingreso de Percepciones del Empledo"<<endl;
	cout<<"\t\t\t 2. Ingreso de Horas Extras del Empleado"<<endl;
	cout<<"\t\t\t 3. Ingreso de Deducciones del Empleado"<<endl;
	cout<<"\t\t\t 4. Agregar los Datos del Empleado"<<endl;
	cout<<"\t\t\t 5. Buscar Datos Empledo"<<endl;
	cout<<"\t\t\t 6. Borrar Datos Empledo"<<endl;
	cout<<"\t\t\t 7. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
		empleado2.insertarPercepciones();
		file2<<"\t\t\tAccion: Ingreso Percepciones - " <<accion1<<"\n"<<endl;
		break;
	case 2:
		empleado2.insertarHorasExtras();
		file2<<"\t\t\tAccion: Ingreso Horas Extras - " <<accion2<<"\n"<<endl;
		break;
	case 3:
		empleado2.insertarDeducciones();
		file2<<"\t\t\tAccion: Ingreso Deducciones - " <<accion3<<"\n"<<endl;
		break;
    case 4:
		empleado2.insertar();
		file2<<"\t\t\tAccion: Ingreso Todos los Datos - " <<accion4<<"\n"<<endl;
		break;
	case 5:
		buscar();
		file2<<"\t\t\tAccion: Busco a un Empleado - " <<accion7<<"\n"<<endl;
		break;
	case 6:
		borrar();
		file2<<"\t\t\tAccion: Borro a un Empleado -  "<<accion8<<endl;
		file2<<"\t\t\tId Empleado Borrado: " <<id<<"\n"<<endl;
		break;
    case 7:
		salir = true;
    default:
        cout<<"\t\t\t\nSaliendo del menu";
	}
	getch();
    }while(choice!= 7);
    file2.close();
}

void DatosEmpleado::desplegar()
{
    system("cls");
    fstream file;//Se declara una variable "file" de tipo fstream para abrir el archivo.
    string line;//Se declara una variable "line" de tipo string para almacenar las líneas leídas del archivo.
    cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
    file.open("ParticipantRecord1.txt", ios::in);//Se abre el archivo en modo lectura "ios::in" y se verifica si se pudo abrir correctamente.
    if (file.is_open()) {
        while (getline(file, line)) {//Se usa un ciclo while para leer todas las líneas del archivo "ParticipantRecord1.txt" y mostrarlas en la consola con "cout << line << endl;".
            cout << line << endl;
        }
        file.close();//Se cierra el archivo "file.close();".
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}
void DatosEmpleado::modificar()
{
    system("cls");
    fstream file,file1;
    int participant_id;
    int found=0;
    cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<endl;
    file.open("ParticipantRecord1.txt", ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion..,";
        file.close();
    } else {
        cout<<"\n Ingrese Id de la personas que quiere modificar: ";
        cin>>participant_id;
        file1.open("Record1.txt", ios::app | ios::out);
        while(file >> id >> nombre >> apellido >> genero >> dia >> mes >> dpi >> telefono >> telefono1 >> numCuenta >> sueldo >> bonificacionIncentiva >> comisiones >> percepciones_extra >> horas_extra >> total_percepciones >> isr >> iggs >> irtra >> prestamos >> deducciones_totales >> sueldo_liquido) {
			if(participant_id!=id)
			{
                    file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< genero <<std::left<<std::setw(15)<< puesto  <<std::left<<std::setw(15)<< departamento <<std::left<<std::setw(15)<< dia <<std::left<<std::setw(15)<< mes <<std::left<<std::setw(15)<< dpi <<std::left<<std::setw(15)<< telefono
                        <<std::left<<std::setw(15)<< telefono1 <<std::left<<std::setw(15)<< numCuenta <<std::left<<std::setw(15)<< sueldo <<std::left<<std::setw(15)<< bonificacionIncentiva <<std::left<<std::setw(15)<< comisiones <<std::left<<std::setw(15)<< percepciones_extra <<std::left<<std::setw(15)<< horas_extra
                        <<std::left<<std::setw(15)<< total_percepciones <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< iggs <<std::left<<std::setw(15)<< irtra <<std::left<<std::setw(15)<< prestamos <<std::left<<std::setw(15)<< deducciones_totales <<std::left<<std::setw(15)<< sueldo_liquido << "\n";

                file.close();

                /*file <<"\n\n\t\t\t Id Persona: "<<id<<endl;
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
                file << "|" << endl;*/
			}
			else{
                int num_empleados;
                float horaOrdinaria, horasExtras;
			    cout<<"\t\t\tIngresa Id Persona         : ";
	            cin>>id;
	            cout<<"\t\t\tNombre: ";
	            cin >> nombre;
                cout << "\t\t\tApellido: ";
                cin >> apellido;
                cout << "\t\t\tGenero: ";
                cin >> genero;
                cout << "\t\t\tEscriba su DPI: ";
                cin >> dpi;
                cout << "\t\t\tEscriba su primer numero de telefono: ";
                cin >> telefono;
                cout << "\t\t\tEscriba su segundo numero de telefono: ";
                cin >> telefono1;
                cout << "\t\t\tEscriba su numero de cuenta bancaria: ";
                cin >> numCuenta;

                cout << "\n\t\t\tIngrese el dia actual:" << endl;
                cin >> dia;
                while (dia < 1 || mes> 31)
                {
               cout << "\t\t\tVerifique que el dia sea correcto" << endl;
               cin >> dia;
               }
               cout << "\n\t\t\tIngrese el mes actual:" << endl;
               cin >> mes;
               while (mes < 1 || mes > 12)
               {
               cout << "\t\t\tVerifique que el mes sea correcto" << endl;
               cin >> mes;
               }

              cout << "\t\t\tSueldo: ";
              cin >> sueldo;
              cout << "\t\t\tBonificacion Incentiva: "<< bonificacionIncentiva << endl;
              cout << "\t\t\tComisiones: ";
              cin >> comisiones;
              cout << "\t\t\tPercepciones Extraordinarias: ";
              cin >> percepciones_extra;
              cout << "\t\t\tHoras Extra: ";
              cin >> horasExtras;
              cout << "\t\t\tPrestamos: ";
              cin >> prestamos;
              horaOrdinaria = ((((sueldo/30)/8)*1.5));
              horas_extra = horaOrdinaria * horasExtras;
              cout << "" << endl;

              total_percepciones = sueldo + bonificacionIncentiva + comisiones + percepciones_extra + horas_extra;

              isr = total_percepciones * 0.05;
              iggs = total_percepciones * 0.03;

              deducciones_totales = isr + iggs + irtra + prestamos;

              sueldo_liquido = total_percepciones - deducciones_totales;


                file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< apellido <<std::left<<std::setw(15)<< genero <<std::left<<std::setw(15)<< puesto  <<std::left<<std::setw(15)<< departamento <<std::left<<std::setw(15)<< dia <<std::left<<std::setw(15)<< mes <<std::left<<std::setw(15)<< dpi <<std::left<<std::setw(15)<< telefono
                    <<std::left<<std::setw(15)<< telefono1 <<std::left<<std::setw(15)<< numCuenta <<std::left<<std::setw(15)<< sueldo <<std::left<<std::setw(15)<< bonificacionIncentiva <<std::left<<std::setw(15)<< comisiones <<std::left<<std::setw(15)<< percepciones_extra <<std::left<<std::setw(15)<< horas_extra
                    <<std::left<<std::setw(15)<< total_percepciones <<std::left<<std::setw(15)<< isr <<std::left<<std::setw(15)<< iggs <<std::left<<std::setw(15)<< irtra <<std::left<<std::setw(15)<< prestamos <<std::left<<std::setw(15)<< deducciones_totales <<std::left<<std::setw(15)<< sueldo_liquido << "\n";

            file.close();

                /*file <<"\n\n\t\t\t Id Persona: "<<id<<endl;
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
                file << "|" << endl;*/
            }
		    file1 >> id>>nombre >>apellido >>genero >>puesto >>departamento >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		    }
		    file1.close();
		    file.close();
		    remove("ParticipantRecord1.txt");
		    rename("Record1.txt","ParticipantRecord.txt");
	        }
}


void DatosEmpleado::buscar()
{
    system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord1.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		int participant_id;
		cout<<"\n-------------------------Datos de Persona buscada------------------------"<<endl;
		cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		cin>>participant_id;
		file >> id >>nombre >>apellido >>genero >>puesto >>departamento >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		while(!file.eof())
		{
			if(participant_id==id)
			{
                cout <<"\n\n\t\t\t Id Persona: "<<id<<endl;
                cout << "|" << setw(20) << "         Datos del trabajador         |" << setw(7) << "         Percepciones Empleados          |" << setw(6) << "       Deducciones Empleados       |" << endl;
                cout << "| " << "Nombre:          " << setw(12) << left << nombre << " " << apellido
                     << setw(1) << right << "|" << endl;
                cout << "| " << "Puesto:          " << setw(20) << left << puesto
                     << setw(1) << right << "|" << endl;
                cout << "| " << "Departamento:    " << setw(20) << left << departamento
                     << "| " << "Sueldo:                        Q " << setw(7) << right << sueldo
                     << "| " << "ISR:                     Q " << setw(7) << right << isr
                     << setw(1) << right << "|" << endl;
                cout << "| " << "Genero:          " << setw(12) << left << genero << setw(10) << right
                     << "| " << "Bonificaciones:                Q " << setw(7) << right << bonificacionIncentiva
                     << "| " << "IGGS:                    Q " << setw(7) << right << iggs
                     << setw(1) << right << "|" << endl;
                cout << "| " << "DPI:             " << setw(12) << left << dpi << setw(10) << right
                     << "| " << "Comisiones:                    Q " << setw(7) << right << comisiones
                     << "| " << "IRTRA:                   Q " << setw(7) << right << irtra
                     << setw(1) << right << "|" << endl;
                cout << "| " << "Telefono 1:      " << setw(12) << left << telefono << setw(10) << right
                     << "| " << "Percepciones Extraordinarias:  Q " << setw(7) << right << percepciones_extra
                     << "| " << "Prestamos:               Q " << setw(7) << right << prestamos
                     << setw(1) << right << "|" << endl;
                cout << "| " << "Telefono 2:      " << setw(12) << left << telefono1 << setw(10) << right
                     << "| " << "Horas Extra:                   Q " << setw(7) << right << horas_extra
                     << setw(1) << right << "|" << endl;
                cout << "| " << "Cuenta Bancaria: " << setw(12) << left << numCuenta << setw(10) << right
                     << "| " << "Total Percepciones:            Q " << setw(7) << right << total_percepciones
                     << "| " << "Total Deducciones:       Q " << setw(7) << right << deducciones_totales
                     << setw(1) << right << "|" << endl;
                cout << "| " << setw(116) << right
                     << "|" << endl;
                cout << "| " << "TOTAL SUELDO LIQUIDO Q " << setw(92) << left << sueldo_liquido
                     << "|" << endl;
                cout << "| " << setw(116) << right
                     << "|" << endl;
                cout << "| " << "Fecha de emision: " << dia << "/" << setw(94) << left << mes
                     << "|" << endl;
				found++;
			}
			file >> id>>nombre >>apellido >>genero >>dia >>mes >>dpi >>telefono >>telefono1 >>numCuenta >>sueldo >>bonificacionIncentiva >>comisiones >>percepciones_extra >>horas_extra >>total_percepciones >>isr >>iggs >>irtra >>prestamos >>deducciones_totales >>sueldo_liquido;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}

    /*system("cls");
    cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<endl;
       // Abre el archivo en modo de lectura
    ifstream file("ParticipantRecord1.txt");

    // Lee la ID que deseas buscar
    string id_buscada;
    cout << "Ingresa la ID que deseas buscar: ";
    cin >> id_buscada;

    //GuardarEmpleados ingresando(id_buscada);
    //ingresando.mostrarEmpleados(id_buscada);

    // Busca la ID en el archivo
    bool encontrado = false;
    string linea;
    while (getline(file, linea)) {
        if (linea.find(id_buscada) != string::npos) {
            encontrado = true;
            cout << linea << endl; // Muestra la línea que contiene la ID buscada
            while (getline(file, linea)) {
                if (linea.find("Id Persona:") != string::npos) {
                    // Se encontró una nueva ID, se detiene la búsqueda
                    break;
                }
                cout << linea << endl; // Muestra la línea siguiente
            }
        }
    }

    // Cierra el archivo
    file.close();

    // Si la ID no se encontró, se muestra un mensaje
    if (!encontrado) {
        cout << "No se encontró la ID buscada." << endl;
    }*/
}

void DatosEmpleado::borrar()
{
	system("cls");
    string id;
    cout << "Ingrese la ID del registro que desea eliminar: ";
    cin >> id;

    ifstream fileIn("ParticipantRecord1.txt"); //Abrir el archivo de lectura
    ofstream fileOut("temp.txt"); //Crear un archivo temporal para escribir los datos actualizados

    string line;
    bool encontrado = false; //Bandera para indicar si se encontró la ID

    while (getline(fileIn, line)) {
        if (line.find(id) != string::npos) { //Si se encuentra la ID
            encontrado = true; //Cambiar la bandera a verdadero para indicar que se encontró
            for (int i = 0; i < 1; i++) { //Saltar 10 líneas (que corresponden a la información del registro)
                getline(fileIn, line);
            }
        }
        else {
            fileOut << line << endl; //Escribir la línea en el archivo temporal
        }
    }

    fileIn.close(); //Cerrar el archivo de lectura
    fileOut.close(); //Cerrar el archivo temporal
    remove("ParticipantRecord1.txt"); //Eliminar el archivo original
    rename("temp.txt", "ParticipantRecord1.txt"); //Cambiar el nombre del archivo temporal al nombre original

    if (encontrado) {
        cout << "Registro eliminado exitosamente." << endl;
    }
    else {
        cout << "No se encontró ningún registro con esa ID." << endl;
    }
}
