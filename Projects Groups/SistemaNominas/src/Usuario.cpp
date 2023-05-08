#include "usuario.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

Usuario::Usuario(string usuario, string contrasena) // Se define el constructor de la clase Usuario, que recibe como par�metros un usuario y una contrase�a
{
    this->usuario=usuario; // Se asigna el valor del par�metro usuario al atributo usuario de la clase
    this->contrasena=contrasena; // Se asigna el valor del par�metro contrasena al atributo contrasena de la clase
}

string Usuario::setUusuario(string usuario) { // Se define el m�todo setUsuario, que recibe como par�metro un usuario
    this->usuario = usuario; // Se asigna el valor del par�metro usuario al atributo usuario de la clase
}

string Usuario::getUusuario() { // Se define el m�todo getUsuario
    return this->usuario; // Se devuelve el valor del atributo usuario de la clase
}

string Usuario::setContrasena(string contrasena) { // Se define el m�todo setContrasena, que recibe como par�metro una contrase�a
    this->contrasena = contrasena; // Se asigna el valor del par�metro contrasena al atributo contrasena de la clase
}

string Usuario::getSontrasena(){ // Se define el m�todo getContrasena
    return this->contrasena; // Se devuelve el valor del atributo contrasena de la clase
}

void Usuario::menuUsuarios(){
    int choice; // Se declara la variable choice para almacenar la opci�n elegida por el usuario
	char x; // Se declara la variable x para almacenar la respuesta del usuario al preguntar si quiere agregar otra persona
	bool repetir = true; // Se inicializa la variable repetir en true

	do
    {
	system("cls"); // Se limpia la pantalla

    cout <<"\t\t\t----------------------------------"<<endl; // Se imprime un mensaje de bienvenida al men� de usuarios
    cout <<"\t\t\t| BIENVENIDO AL MENU DE USUARIOS |"<<endl;
    cout <<"\t\t\t----------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Nuevos Usuarios"<<endl; // Se imprime la opci�n para ingresar nuevos usuarios
	cout<<"\t\t\t 2. Despliegue De Usuarios"<<endl; // Se imprime la opci�n para desplegar los usuarios
	cout<<"\t\t\t 3. Modificar Usuarios"<<endl; // Se imprime la opci�n para modificar usuarios
	cout<<"\t\t\t 4. Borrar Usuarios"<<endl; // Se imprime la opci�n para borrar usuarios
	cout<<"\t\t\t 5. Exit"<<endl; // Se imprime la opci�n para salir

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl; // Se imprime una l�nea indicando que se debe elegir una opci�n
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice; // Se lee la opci�n elegida por el usuario

    switch(choice) // Se utiliza un switch para ejecutar el c�digo correspondiente a la opci�n elegida por el usuario
    {
    case 1:
    	do // Se utiliza un do-while para permitir al usuario agregar m�s de una persona
    	{
    		ingresarUsuarios(); // Se llama al m�todo para ingresar nuevos usuarios
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x; // Se pregunta al usuario si desea agregar otra persona
		}while(x=='y'||x=='Y'); // Se repite el ciclo mientras la respuesta del usuario sea afirmativa
		break;
	case 2:
	    verificarUsuario();
		desplegarUsurios(); // Se llama al m�todo para desplegar los usuarios
		break;
	case 3:
	    verificarUsuario();
		modificarUsuarios(); // Se llama al m�todo para modificar usuarios
		break;
	case 4:
	    verificarUsuario();
		borrarUsurios(); // Se llama al m�todo para borrar usuarios
		break;
	case 5:
	    repetir=false; // Se cambia el valor de repetir a false para salir del men�
        cout<<"\t\t\t\nSaliendo del menu";
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez.."; // Se imprime un mensaje de error si la opci�n elegida es inv�lida
	}
	getch(); // Se espera a que el usuario presione una tecla para continuar
    }while(choice!= 5); // Se repite el ciclo mientras la opci�n elegida por el usuario sea diferente a 6 (salida del men�)
}

void Usuario::menuBitacora(){
    int choice; // Se declara la variable choice para almacenar la opci�n elegida por el usuario
	char x; // Se declara la variable x para almacenar la respuesta del usuario al preguntar si quiere agregar otra persona
	bool repetir = true; // Se inicializa la variable repetir en true

	do
    {
	system("cls"); // Se limpia la pantalla

    cout <<"\t\t\t------------------------------------"<<endl;
    cout <<"\t\t\t|  BIENVENIDO AL MENU DE BITACORA  |"<<endl;
    cout <<"\t\t\t------------------------------------"<<endl;
	cout<<"\t\t\t 1. Buscar entradas"<<endl;
	cout<<"\t\t\t 2. Leer entradas"<<endl;
	cout<<"\t\t\t 3. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3]"<<endl; // Se imprime una linea indicando que se debe elegir una opci�n
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice; // Se lee la opcion elegida por el usuario

    switch(choice) // Se utiliza un switch para ejecutar el c�digo correspondiente a la opci�n elegida por el usuario
    {
	case 1:
	    verificarUsuario();
	    //buscarEntrada();

		break;
	case 2:
	    verificarUsuario();
	    //LeerEntrada();

		break;
	case 3:
	    repetir=false; // Se cambia el valor de repetir a false para salir del men�
        cout<<"\t\t\t\nSaliendo del menu";
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez.."; // Se imprime un mensaje de error si la opci�n elegida es inv�lida
	}
	getch(); // Se espera a que el usuario presione una tecla para continuar
    }while(choice!= 3); // Se repite el ciclo mientras la opci�n elegida por el usuario sea diferente a 6 (salida del men�)
}

//void Usuario::agregarEntrada(){


//}

//void Usuario::buscarEntrada(){


//}

//void Usuario::editarEntrada(){


//}

//void Usuario::eliminarEntrada(){


//}

void Usuario::ingresarUsuarios(){
    system("cls");
    fstream file;//objeto "fstream" para manejar archivos

    // Declaraci�n de variables
    string usuario, contrasena;

    // Imprime mensaje y solicita al usuario que ingrese el nombre de usuario y la contrase�a
    cout<<"\n------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-------------------------------------------------Agregar Usuarios al Sistema--------------------------------------------"<<endl;
    cout << "\t\t\t\nIngrese el nombre de usuario:         ";
    cin >> usuario;
    cout << "\t\t\t\nIngrese la contrasena:         ";

// Inicia la entrada de caracteres uno por uno, ocultando la contrase�a con asteriscos
char caracter;
caracter = getch();
contrasena = "";
while (caracter != 13){ // El bucle se ejecuta hasta que el usuario presiona la tecla "Enter" (c�digo ASCII 13)
    if(caracter != 8) // Si el caracter ingresado no es "Backspace" (c�digo ASCII 8)
    {
        contrasena.push_back(caracter); // Agrega el caracter ingresado al final de la cadena "contrasena"
        cout<< "*"; // Imprime un asterisco en la consola
    }else{ // Si el caracter ingresado es "Backspace"
        if(contrasena.length()>0) // Si la cadena "contrasena" tiene al menos un caracter
        {
            cout<<"\b \b"; // Borra el �ltimo caracter ingresado de la consola (mueve el cursor una posici�n a la izquierda, imprime un espacio en blanco y mueve el cursor de nuevo a la izquierda)
            contrasena = contrasena.substr(0, contrasena.length() - 1); // Elimina el �ltimo caracter ingresado de la cadena "contrasena"
        }
    }
    caracter = getch(); // Lee el siguiente caracter ingresado por el usuario
}

// Abre el archivo "Usuarios1.txt" en modo de apendizaje y escritura
file.open("Usuarios1.txt", ios::app | ios::out);

// Escribe en el archivo los datos del usuario ingresados por el usuario, con un ancho de 15 caracteres para cada campo
file<<std::left<<std::setw(15)<< usuario <<std::left<<std::setw(15)<< contrasena << "\n";

// Cierra el archivo
file.close();

// Imprime mensaje de �xito
cout << "\t\t\t\nUsuario registrado exitosamente.";
}
void Usuario::desplegarUsurios()
{
    system("cls"); // limpia la pantalla de la consola
	fstream file; // crea un objeto de archivo de la biblioteca fstream
	int total=0; // inicializa una variable para contar el n�mero de usuarios

	// Imprime el encabezado para la tabla de usuarios registrados
	cout<<"\n-------------------------Tabla de Usuarios Registrados-------------------------"<<endl;

	file.open("Usuarios1.txt",ios::in); // abre el archivo "Usuarios1.txt" en modo lectura
	if(!file) // si no se pudo abrir el archivo
	{
		cout<<"\n\t\t\tNo hay informaci�n..."; // muestra un mensaje de error
		file.close(); // cierra el archivo
	}
	else // si se pudo abrir el archivo
	{
		file >> usuario >> contrasena; // lee el primer usuario del archivo

		// mientras no se llegue al final del archivo
		while(!file.eof())
		{
			total++; // incrementa el contador de usuarios
			cout<<"\t\t\t Nombre de usuario: "<<usuario<<endl; // muestra el nombre del usuario
			cout<<"\t\t\t Contrase�a del usuario: "<<contrasena<<endl; // muestra la contrase�a del usuario
			file >> usuario >> contrasena; // lee el siguiente usuario del archivo
		}

		if(total==0) // si no se encontr� ning�n usuario en el archivo
		{
			cout<<"\n\t\t\tNo hay informacion..."; // muestra un mensaje de error
		}
	}

	file.close(); // cierra el archivo
}
void Usuario::modificarUsuarios()
{
	system("cls");
    fstream file, file1;  // Se crean dos objetos de archivo para leer y escribir en archivos de texto
    string participant;  // Se define una cadena para almacenar el nombre del usuario a modificar
    int found=0;  // Se define una variable para contar si se encuentra el usuario en el archivo
    cout<<"\n-------------------------Modificacion de Usuarios-------------------------"<<endl;  // Muestra un mensaje en pantalla
    file.open("Usuarios1.txt",ios::in);  // Abre el archivo de texto en modo lectura
    if(!file)  // Si el archivo no se pudo abrir
    {
        cout<<"\n\t\t\tNo hay informacion..,";  // Muestra un mensaje en pantalla
        file.close();  // Cierra el archivo
    }
    else  // Si el archivo se pudo abrir
    {
        cout<<"\n Ingrese el nombre del Usuario que quiere modificar: ";  // Muestra un mensaje en pantalla para ingresar el usuario a modificar
        cin>>participant;  // Lee el nombre del usuario a modificar
        file1.open("Record.txt",ios::app | ios::out);  // Abre otro archivo de texto en modo escritura y agrega el contenido al final del archivo
        file >> usuario >> contrasena;  // Lee el primer usuario y contrase�a del archivo
        while(!file.eof())  // Mientras no se llegue al final del archivo
        {
            if(participant!=usuario)  // Si el usuario no es el que se quiere modificar
            {
                file1<<std::left<<std::setw(15)<< usuario <<std::left<<std::setw(15)<< contrasena << "\n";  // Escribe en el archivo temporal el usuario y contrase�a sin modificar
            }
            else  // Si se encuentra el usuario a modificar
            {
                cout << "\t\t\t\nIngrese el nombre de usuario:         ";
                cin >> usuario;
                cout << "\t\t\t\nIngrese la contrasena:         ";
                cin >> contrasena;
                file1<<std::left<<std::setw(15)<< usuario <<std::left<<std::setw(15)<< contrasena << "\n";  // Escribe en el archivo temporal el usuario y contrase�a modificados
                found++;  // Incrementa el contador de usuarios modificados
            }
            file >> usuario >> contrasena;  // Lee el siguiente usuario y contrase�a del archivo
        }
        file1.close();  // Cierra el archivo temporal
        file.close();  // Cierra el archivo original
        remove("Usuarios1.txt");  // Elimina el archivo original
        rename("Record.txt","Usuarios1.txt");  // Renombra el archivo temporal con el nombre del archivo original
        cout << "\t\t\t\nUsuario Modificado exitosamente.";  // Muestra un mensaje en pantalla
    }
}
void Usuario::borrarUsurios()
{
	system("cls");

	// Declarar dos objetos de la clase fstream para manejar los archivos
	fstream file, file1;

	// Declarar una variable para almacenar el nombre del usuario a borrar
	string participant;

	// Declarar una variable para indicar si se encontr� al usuario a borrar
	int found = 0;

	// Mostrar un mensaje para indicar que se va a borrar un usuario
	cout << "\n-------------------------Usuarios a Borrar-------------------------" << endl;

	// Abrir el archivo "Usuarios1.txt" en modo lectura
	file.open("Usuarios1.txt", ios::in);

	// Verificar si el archivo se pudo abrir
	if (!file)
	{
		cout << "\n\t\t\tNo hay informacion...";

		// Cerrar el archivo
		file.close();
	}
	else
	{
		// Pedir al usuario que ingrese el nombre del usuario a borrar
		cout << "\n Ingrese el nombre del Usuario que quiere Borrar: ";
		cin >> participant;

		// Abrir el archivo "Record.txt" en modo append y escritura
		file1.open("Record.txt", ios::app | ios::out);

		// Leer el nombre de usuario y contrase�a del archivo "Usuarios1.txt"
		file >> usuario >> contrasena;

		// Mientras no se llegue al final del archivo "Usuarios1.txt"
		while (!file.eof())
		{
			// Verificar si el nombre de usuario le�do es diferente al nombre del usuario a borrar
			if (participant != usuario)
			{
				// Escribir el nombre de usuario y contrase�a en el archivo "Record.txt"
				file1 << std::left << std::setw(15) << usuario << std::left << std::setw(15) << contrasena << "\n";
			}
			else
			{
				// Incrementar el contador de usuarios encontrados
				found++;

				// Mostrar un mensaje indicando que se borr� al usuario exitosamente
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}

			// Leer el siguiente nombre de usuario y contrase�a del archivo "Usuarios1.txt"
			file >> usuario >> contrasena;
		}

		// Verificar si no se encontr� al usuario a borrar
		if (found == 0)
		{
			cout << "\n\t\t\t Nombre del Usuario no encontrado...";
		}

		// Cerrar los archivos
		file1.close();
		file.close();

		// Borrar el archivo "Usuarios1.txt"
		remove("Usuarios1.txt");

		// Renombrar el archivo "Record.txt" como "Usuarios1.txt"
		rename("Record.txt", "Usuarios1.txt");
	}
}
bool Usuario::verificarUsuario() {
// Declaraci�n de variables locales
string usuario, contrasena;  // Almacenan el usuario y la contrase�a ingresados
int contador = 0;  // Contador de intentos
bool encontrado = false;  // Indica si se encontr� el usuario y la contrase�a correctos

// El ciclo se repite mientras el n�mero de intentos sea menor a 3 y no se haya encontrado un usuario v�lido
while (contador < 3 && !encontrado) {

    // Limpiar la pantalla y mostrar el t�tulo del login
    system("cls");
    cout <<"\t\t\t-------------------------"<<endl;
    cout <<"\t\t\t|   LONGIN DE USUARIO   |"<<endl;
    cout <<"\t\t\t-------------------------"<<endl;

    // Mostrar mensaje de advertencia
    cout <<"\n\tAdvertencia: Solo tienes permitido 3 intentos!!!"<<endl;
    cout <<"\t-------------------------------------------------"<<endl;

    // Solicitar al usuario el nombre de usuario y la contrase�a
    cout << "\t\t\t\nIngrese el nombre de usuario:         ";
    cin >> usuario;
    cout << "\t\t\t\nIngrese la contrasena:         ";
    char caracter;
    caracter = getch();

    // Ocultar la contrase�a ingresada por el usuario
    contrasena = "";
    while (caracter != 13){
        if(caracter != 8)
        {
            contrasena.push_back(caracter);
            cout<< "*";
        }else{
            if(contrasena.length()>0)
            {
                cout<<"\b \b";
                contrasena = contrasena.substr(0, contrasena.length() - 1);
            }
        }
        caracter = getch();
    }

    // Abrir el archivo de usuarios y contrase�as
    ifstream file;
    file.open("Usuarios1.txt", ios::in);

    // Verificar si el archivo se abri� correctamente
    if (!file) {
        cout << "No se pudo abrir el archivo." << endl;
        file.close();
        return false;
    }

    // Buscar el usuario en el archivo
    string user, pass;
    while (file >> user >> pass) {
        if (user == usuario && pass == contrasena) {
            encontrado = true;
            break;
        }
    }
    file.close();

    // Si no se encontr� el usuario, se incrementa el contador
    if (!encontrado) {
        cout << "\n\tUSUARIO Y/O PASSWORD INCORRECTOS" << endl;
        cout << "\n\tPerdio un intento, Intente de nuevo" << endl;
        contador++;
        system("pause");
    }
}

// Si se encontr� el usuario, se retorna true
if (encontrado) {
    cout << "\n\tBienvenido " << usuario << "!" << endl;
    return true;
} else {
    cout << "\n\tPERDIO LOS 3 INTENTOS" << endl;
    cout << "\n\tNO PODRA INGRESAR MAS INTENTOS" << endl;
    return false;
}
}

