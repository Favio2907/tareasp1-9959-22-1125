#ifndef CONFIG_H
#define CONFIG_H



class Config// Definición de la clase Config
{
    public:
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        // Constructor de la clase Config con parámetros para configurar el tablero
        int getfilasTablero(); // Método para obtener el número de filas del tablero
        int setfilasTablero(int filasTablero); // Método para establecer el número de filas del tablero
        int getcolumnasTablero(); // Método para obtener el número de columnas del tablero
        int setcolumnasTablero(int columnasTablero); // Método para establecer el número de columnas del tablero
        int getminasTablero(); // Método para obtener el número de minas del tablero
        int setminasTablero(int minasTablero); // Método para establecer el número de minas del tablero
        bool getmodoDesarrolladorTablero(); // Método para obtener el estado del modo desarrollador del tablero
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero); // Método para establecer el estado del modo desarrollador del tablero
        int getvidasTablero(); // Método para obtener el número de vidas del tablero
        int setvidasTablero(int vidasTablero); // Método para establecer el número de vidas del tablero
        void menuConfiguracion(); // Método para mostrar un menú de configuración

    protected: // Sección protegida de la clase

    private: // Sección privada de la clase
        int filasTablero; // Número de filas del tablero
        int columnasTablero; // Número de columnas del tablero
        int minasTablero; // Número de minas del tablero
        bool modoDesarrolladorTablero; // Estado del modo desarrollador del tablero
        int vidasTablero; // Número de vidas del tablero


};

#endif // CONFIG_H
