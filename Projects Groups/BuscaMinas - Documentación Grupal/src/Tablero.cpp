//Esta secci�n incluye las librer�as necesarias para el archivo, que son "Tablero.h", "sstream" e "iostream".
#include "Tablero.h"
#include <sstream>
#include <iostream>
using namespace std;
Tablero::Tablero()// Constructor por defecto
{
}
Tablero::Tablero(int alturaTablero, int anchoTablero, bool modoDesarrollador) // Constructor de la clase Tablero que recibe como argumentos la altura, ancho y el modo desarrollador del tablero a crear.
{
 this->alturaTablero = alturaTablero;// Asigna el valor de alturaTablero al atributo alturaTablero de la instancia actual (this).
this->anchoTablero = anchoTablero;//Asigna el valor de anchoTablero al atributo anchoTablero de la instancia actual.
 this->modoDesarrollador = modoDesarrollador;//Asigna el valor de modoDesarrollador al atributo modoDesarrollador de la instancia actual.
 int x, y;//Declara dos variables enteras x e y para ser usadas en el bucle for.
 for (y=0; y < this->alturaTablero; y++)//Inicia un bucle for que itera desde 0 hasta el valor de alturaTablero de la instancia actual.
 {
 vector<Celda> fila;//Crea un vector fila de objetos de tipo Celda.
 for (x=0; x < this->anchoTablero; x++)//Inicia un bucle for que itera desde 0 hasta el valor de anchoTablero de la instancia actual.
 {
 fila.push_back((Celda(x, y, false)));// Agrega un objeto Celda vac�o al final del vector fila con coordenadas (x, y) y con el atributo tieneMina establecido en false.
 }
 this->contenidoTablero.push_back(fila);//Agrega el vector fila al final del vector contenidoTablero de la instancia actual.
 }
}
int Tablero::getAlturaTablero()// M�todo que retorna la altura del tablero
{
 return this->alturaTablero;
}
int Tablero::setAlturaTablero(int alturaTablero)// M�todo que establece la altura del tablero
{
 this->alturaTablero = alturaTablero;
}
int Tablero::getAnchoTablero()// M�todo que retorna el ancho del tablero
{
 return this->anchoTablero;
}
int Tablero::setAnchoTablero(int anchoTablero)// M�todo que establece el ancho del tablero
{
 this->anchoTablero = anchoTablero;
}
bool Tablero::getModoDesarrollador()// M�todo que retorna el estado del modo desarrollador
{
 return this->modoDesarrollador;
}
bool Tablero::setModoDesarrollador(bool modoDesarrollador)// M�todo que establece el estado del modo desarrollador
{
 this->modoDesarrollador = modoDesarrollador;
}
string Tablero::getRepresentacionMina(int coordenadaX, int coordenadaY)//Este m�todo toma dos argumentos: coordenadaX y coordenadaY, que representan la posici�n de una celda en el tablero.
{
Celda celdaTemporal = this->contenidoTablero.at(coordenadaY).at(coordenadaX); // Se obtiene la celda correspondiente a las coordenadas dadas
 if (celdaTemporal.getMinaDescubierta() || this->modoDesarrollador)// Si la celda ya ha sido descubierta o se est� en modo desarrollador
 {
 if (celdaTemporal.getMina())// Si la celda tiene una mina, se retorna el caracter "*"
 {
 return "*";
 }
 else// Si no tiene mina, se obtiene la cantidad de minas cercanas
 {
 int cantidadCelda=this->minasCercanas(coordenadaY,coordenadaX);// Se cuenta la cantidad de minas cercanas a la celda
 // Se convierte la cantidad a un string
 string cantidadCeldaString = " ";
 stringstream ss;
 ss << cantidadCelda;
 ss >> cantidadCeldaString;
 return cantidadCeldaString;// Se retorna la cantidad de minas cercanas como string
 }
 }
 else
 {
 return "?";//Si no es asi retorna un ?
//return ".";
 }
}
int Tablero::minasCercanas(int filaTablero, int columnaTablero)//M�todo que cuenta el n�mero de minas cercanas a la celda en la posici�n (fila, columna) del tablero.
{
 int contadorTablero = 0;// Inicializa el contador en 0
 int filaInicioTablero, filaFinTablero, columnaInicioTablero, columnaFinTablero;// Declara las variables de las filas y columnas de inicio y fin
 if (filaTablero <= 0)// Si la fila actual es menor o igual a 0
{
filaInicioTablero = 0;// Asigna 0 como inicio de fila
}
else
{
filaInicioTablero = filaTablero - 1;// Asigna el valor anterior a la fila actual como inicio de fila
}
if (filaTablero + 1 >= this->alturaTablero)// Si la fila actual + 1 es mayor o igual a la altura del tablero
{
filaFinTablero = this->alturaTablero - 1;// Asigna la altura del tablero - 1 como fin de fila
}
else
{
filaFinTablero = filaTablero + 1;// Asigna el valor siguiente a la fila actual como fin de fila
}
if (columnaTablero <= 0)// Si la columna actual es menor o igual a 0
{
columnaInicioTablero = 0;// Asigna 0 como inicio de columna
}
else
{
columnaInicioTablero = columnaTablero - 1;// Asigna el valor anterior a la columna actual como inicio de columna
}
if (columnaTablero + 1 >= this->anchoTablero)// Si la columna actual + 1 es mayor o igual al ancho del tablero
{
columnaFinTablero = this->anchoTablero - 1;// Asigna el ancho del tablero - 1 como fin de columna
}
else
{
columnaFinTablero = columnaTablero + 1;// Asigna el valor siguiente a la columna actual como fin de columna
}
int m;
for (m = filaInicioTablero; m <= filaFinTablero; m++)// Recorre las filas desde el inicio hasta el fin
{
int l;
for (l = columnaInicioTablero; l <= columnaFinTablero; l++)// Recorre las columnas desde el inicio hasta el fin
{
if (this->contenidoTablero.at(m).at(l).getMina())// Si la celda en la fila y columna actual tiene una mina
{
contadorTablero++;// Aumenta el contador en 1
}
}
}
return contadorTablero;// Devuelve el contador de minas cercanas
}
void Tablero::imprimirSeparadorEncabezado()//Imprime un separador para el encabezado del tablero.
{
int m;//Declara una variable entera m para ser usada en un bucle for.
for (m = 0; m <= this->anchoTablero; m++)//Inicia un bucle for que va desde m = 0 hasta m <= this->anchoTablero (inclusive). El valor de m se incrementa en 1 en cada iteraci�n.
{
cout << "----";// Muestra en la salida est�ndar "----".
if (m + 2 == this->anchoTablero)//Si el valor actual de m sumado a 2 es igual al ancho del tablero (this->anchoTablero), se ejecuta el siguiente bloque de c�digo.
{
cout << "-"; //Muestra en la salida est�ndar "-".
}
}
cout << "\n";//Imprime una nueva l�nea en la salida est�ndar para separar el separador del encabezado del resto del tablero.
}
void Tablero::imprimirSeparadorFilas()//La funci�n imprimirSeparadorFilas imprime una l�nea separadora entre las filas del tablero.
{
int m;//Declara la variable m para ser usada en el ciclo for que sigue.
for (m = 0; m <= this->anchoTablero; m++)//Inicia un ciclo for que va desde 0 hasta la longitud de this->anchoTablero, lo cual es el ancho del tablero m�s 1.
{
if (m <= 1)//Si m es menor o igual a 1, se imprimir� un |---, lo cual es la separaci�n de la primera columna del tablero.
{
cout << "|---";
}
else//De lo contrario, se imprimir� un +---, lo cual es la separaci�n entre las dem�s columnas.
{
cout << "+---";
}
if (m == this->anchoTablero)//Si m es igual a la longitud de this->anchoTablero, se imprime un +, lo cual indica el final de la l�nea separadora
{
cout << "+";
}
}
cout << "\n";//Imprime un salto de l�nea para separar la l�nea actual de la siguiente.
}
void Tablero::imprimirEncabezado()//Imprime el encabezado del tablero.
{
this->imprimirSeparadorEncabezado();// Imprime la l�nea de separaci�n del encabezado del tablero
cout << "| ";// Imprime el margen izquierdo del tablero
int l;
for (l = 0; l < this->anchoTablero; l++)// Itera sobre cada columna del tablero
{
cout << "| " << l + 1 << " ";// Imprime el n�mero de la columna, m�s un margen y un separador
if (l + 1 == this->anchoTablero)// Si es la �ltima columna, agrega un separador final
{
cout << "|";// Imprime el margen izquierdo del tablero
}
}
cout << "\n";// Agrega un salto de l�nea despu�s de imprimir el encabezado completo
}
void Tablero::imprimir()//Esta l�nea define la funci�n imprimir que pertenece a la clase Tablero.
{
this->imprimirEncabezado();// Imprime el encabezado del tablero
this->imprimirSeparadorEncabezado();// Imprime un separador horizontal
int x, y;
for (y = 0; y < this->alturaTablero; y++)// Ciclo para recorrer todas las filas del tablero
{
cout << "| " << y + 1 << " ";// Imprime el n�mero de fila
for (x = 0; x < this->anchoTablero; x++)// Ciclo para recorrer todas las columnas del tablero
 {
{
cout << "| " << this->getRepresentacionMina(x, y) << " ";// Imprime la representaci�n de la casilla en la posici�n (x, y)
if (x + 1 == this->anchoTablero)// Si es la �ltima columna, imprime una barra vertical de cierre
{
cout << "|";
}
}
cout << "\n";// Salto de l�nea para pasar a la siguiente fila
this->imprimirSeparadorFilas();// Imprime un separador horizontal
}
}
 bool Tablero::colocarMina(int x, int y)//funci�n colocarMina() que recibe dos par�metros enteros x e y.
{
return this->contenidoTablero.at(y).at(x).setMina(true);//Retorna el valor devuelto por la funci�n setMina(true) que es invocada en la celda ubicada en la fila y y columna x del
tablero.
}
 bool Tablero::descubrirMina(int x, int y)//funci�n descubrirMina() que recibe dos par�metros enteros x e y.
{
this->contenidoTablero.at(y).at(x).setMinaDescubierta(true);//Llama a la funci�n setMinaDescubierta(true) para la celda ubicada en la fila y y columna x del tablero, lo que indica
que la mina ha sido descubierta.
Celda celda = this->contenidoTablero.at(y).at(x);// Obtiene la celda ubicada en la fila y y columna x del tablero y la almacena en la variable celda.
if (celda.getMina())//Si la celda contiene una mina, entra al siguiente bloque de c�digo.
{
return false;// Retorna false para indicar que se ha descubierto una mina.
}
return true;//Retorna true para indicar que no se ha descubierto una mina.
}
int Tablero::contarCeldasSinMinasYSinDescubrir()//Cuenta el n�mero de celdas en el tablero que no contienen minas y a�n no han sido descubiertas. Devuelve el n�mero de celdas
contadas.
{
int x, y, contador = 0;//// Declara tres variables enteras e inicializa el contador en 0.
for (y = 0; y < this->alturaTablero; y++)// Bucle for anidado que recorre las filas del tablero.
{
for (x = 0; x < this->anchoTablero; x++)// Bucle for anidado que recorre las columnas del tablero.
{
Celda celdaTemporal = this->contenidoTablero.at(y).at(x);// Obtiene la celda temporal en la posici�n (x,y).
if (!celdaTemporal.getMinaDescubierta() && !celdaTemporal.getMina())// Verifica si la celda no est� descubierta y no tiene una mina.
{
contador++;// Si la celda no tiene una mina y no est� descubierta, incrementa el contador.
}
}
}
return contador;// Retorna la cantidad de celdas sin minas y sin descubrir.
}
