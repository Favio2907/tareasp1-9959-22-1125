#include "Juego.h"
#include "Config.h"
#include "Tablero.h"
#include "persona.h"
#include <fstream>
#include <unistd.h>

// Retorna un numero aleatorio en el rango [minimo, maximo].
int Juego::aleatorio_en_rango(int minimo, int maximo)
	{
    // La función rand() retorna un número entero aleatorio en el rango [0, RAND_MAX].
    // Por lo tanto, para obtener un número aleatorio en el rango [minimo, maximo], se utiliza la siguiente fórmula:
    // minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1)
		return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
	}

	// Retorna una fila aleatoria en el rango [0, filas-1] del tablero.
	int Juego::filaAleatoria()
	{
    // Se utiliza la función aleatorio_en_rango para generar un número entero aleatorio en el rango [0, filas-1].
    // El valor de filas se obtiene utilizando el método getAlturaTablero() del objeto Tablero.
		return this->aleatorio_en_rango(0, this->tablero.getAlturaTablero() - 1);
	}

	// Retorna una columna aleatoria en el rango [0, columnas-1] del tablero.
	int Juego::columnaAleatoria()
	{
    // Se utiliza la función aleatorio_en_rango para generar un número entero aleatorio en el rango [0, columnas-1].
    // El valor de columnas se obtiene utilizando el método getAnchoTablero() del objeto Tablero.
		return this->aleatorio_en_rango(0, this->tablero.getAnchoTablero() - 1);
	}
    // Constructor que recibe un objeto Tablero y la cantidad de minas que se colocaron.
	Juego::Juego(Tablero tablero, int cantidadMinas, int vidasTablero)
	{
	    // Se guarda el objeto Tablero y la cantidad de minas y vidas que se colocarán en el juego.
		this->tablero = tablero;
		this->cantidadMinas = cantidadMinas;
		this->vidasTablero = vidasTablero;
		// Se coloca las minas aleatoriamente en el tablero.
		this->colocarMinasAleatoriamente();
	}

	// Coloca las minas en el tablero de manera aleatoria.
	void Juego::colocarMinasAleatoriamente()
	{
		int x, y, minasColocadas = 0;

		while (minasColocadas < this->cantidadMinas)
		{
		    // Obtiene una posición aleatoria para colocar una mina
			x = this->columnaAleatoria();
			y = this->filaAleatoria();

			// Intenta colocar una mina en la posicion aleatoria. Si ya habia una mina en esa posicion, no se coloca.
			if (this->tablero.colocarMina(x, y))
			{
				minasColocadas++;
			}
		}
	}

	int Juego::solicitarFilaUsuario()
	{
	    // Pide al usuario que ingrese la fila en la que desea jugar.
		int fila = 0;
		cout << "Ingresa la FILA en la que desea jugar: ";
		cin >> fila;

		// Retorna la fila ingresada menos 1, ya que los indices del tablero comienzan en 0.
		return fila - 1;
	}

	int Juego::solicitarColumnaUsuario()
	{
	    // Pide al usuario que ingrese la columna en la que desea jugar.
		int columna = 0;
		cout << "Ingresa la COLUMNA en la que desea jugar: ";
		cin >> columna;

		// Retorna la columna ingresada menos 1, ya que los indices del tablero comienzan en 0.
		return columna - 1;
	}

	bool Juego::jugadorGana()
	{
	    // Cuenta el numero de celdas que no tienen minas y que aun no han sido descubiertas.
		int conteo = this->tablero.contarCeldasSinMinasYSinDescubrir();

		// Si todas las celdas sin minas estan descubiertas, el jugador ha ganado.
		if (conteo == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Juego::iniciar()
	{
        system("cls");// Limpia la pantalla

        // Declaración de variables:
		int fila, columna; // Variables para manejar la posición del usuario en una matriz o tabla.
		string id,name,fecha; // Variables para almacenar los datos personales del usuario.
		int tiempo; // Variable para almacenar el tiempo que el usuario tardó en completar el juego.
		int score = 0; // Variable para almacenar la puntuación del usuario en el juego.
		char r; // Variable para almacenar una respuesta o opción de selección del usuario.

		// Creación de un objeto persona con los datos proporcionados:
        persona estudiante(id,name,fecha, tiempo, score);

        // Llamada al método buscar1() del objeto persona:
        estudiante.buscar1();

        // Obtención del tiempo actual como tiempo de inicio para una actividad:
        time_t tiempoInicio = time(NULL);

        // Ciclo principal del juego.
		while (true)
		{
			cout << "\nSCORE: " << score << "     VIDAS: " << vidasTablero << endl;//Imprime el score y las vidas restantes del jugador en pantalla

			// Imprime el estado actual del tablero.
			this->tablero.imprimir();

			// Pide al usuario que ingrese una fila y columna para descubrir.
			fila = this->solicitarFilaUsuario();
			columna = this->solicitarColumnaUsuario();

			// Descubre la celda seleccionada por el usuario y guarda la respuesta en respuestaAUsuario.
			bool respuestaAUsuario = this->tablero.descubrirMina(columna, fila);

			// Si la respuesta del usuario es verdadera (es decir, la celda seleccionada no tenía una mina), el juego le suma 5 puntos.
			if (respuestaAUsuario)
			{
			    score += 5;//Suma 5 puntos al score con un acierto
			}
			// Si la respuesta del usuario es falsa (es decir, la celda seleccionada tenía una mina), el juego le reduce 5 puntos y 1 vida.
			if (!respuestaAUsuario)
			{
			    score -= 5;//Resta 5 puntos al score al detectar una mina
			    vidasTablero--;//Reduce en 1 las vidas ddel jugador
			}
			if (vidasTablero == 0)//Si las vidas llegan a 0, el jugador pierde el juego
			{
			    system("cls");// Limpia la pantalla
                cout << "\nPERDISTE EL JUEGO!!!!!!!!!\n";
                cout << "\nESFUERZATE MAS PARA LA PROXIMA!!!!!!!!\n";
                cout << "\nTe mostramos donde estaban las minas\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				time_t tiempoFin = time(NULL);
                int tiempoTranscurrido = difftime(tiempoFin, tiempoInicio);
                cout << "\nTIEMPO OBTENIDO: " << tiempoTranscurrido << " segundos\n" << endl;
                cout << "\nPUNTUACION FINAL: " << score << " puntos\n" << endl;
                cout<<"\n\n �Desea guardar su record?(Y,N): ";
                cin>>r;
                if (r=='y'||r=='Y')
                {
                    string id,name,fecha;
                    persona estudiante(id,name,fecha, tiempoTranscurrido, score);
                    estudiante.nuevaPartida();
                }
				break;
			}

			// Si el jugador ha ganado, se muestra el tablero completo y se termina el juego.
			if (this->jugadorGana())
			{
			    system("cls");// Limpia la pantalla
				cout << "Ganaste el Juego\n";
				this->tablero.setModoDesarrollador(true);
				this->tablero.imprimir();
				cout << "\nPUNTUACION FINAL: " << score << " puntos\n" << endl;
                cout<<"\n\n �Desea guardar su record?(Y,N): ";
                cin>>r;
                if (r=='y'||r=='Y')
                {
                    estudiante.nuevaPartida();
                }
				break;
			}
		}
	}
void Juego::dibujarPortada(string nombreArchivo)
	{
        string line;
        //char userInput = ' ';
        ifstream myFile(nombreArchivo);
        if(myFile.is_open())
        {
            //Se obtiene la portada del juego
            while( getline(myFile, line))
            {
                cout << line << endl;
            }
            myFile.close();
            system("pause");
        }
        else
        {
            cout << "Error FATAL: el archivo de portada no pudo ser cargado" << endl;
            system("pause");
        }
	}
