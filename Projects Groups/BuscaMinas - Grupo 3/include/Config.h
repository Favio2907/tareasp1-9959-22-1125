#ifndef CONFIG_H
#define CONFIG_H



class Config// Definici�n de la clase Config
{
    public:
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        // Constructor de la clase Config con par�metros para configurar el tablero
        int getfilasTablero(); // M�todo para obtener el n�mero de filas del tablero
        int setfilasTablero(int filasTablero); // M�todo para establecer el n�mero de filas del tablero
        int getcolumnasTablero(); // M�todo para obtener el n�mero de columnas del tablero
        int setcolumnasTablero(int columnasTablero); // M�todo para establecer el n�mero de columnas del tablero
        int getminasTablero(); // M�todo para obtener el n�mero de minas del tablero
        int setminasTablero(int minasTablero); // M�todo para establecer el n�mero de minas del tablero
        bool getmodoDesarrolladorTablero(); // M�todo para obtener el estado del modo desarrollador del tablero
        bool setmodoDesarrolladorTablero(bool modoDesarrolladorTablero); // M�todo para establecer el estado del modo desarrollador del tablero
        int getvidasTablero(); // M�todo para obtener el n�mero de vidas del tablero
        int setvidasTablero(int vidasTablero); // M�todo para establecer el n�mero de vidas del tablero
        void menuConfiguracion(); // M�todo para mostrar un men� de configuraci�n

    protected: // Secci�n protegida de la clase

    private: // Secci�n privada de la clase
        int filasTablero; // N�mero de filas del tablero
        int columnasTablero; // N�mero de columnas del tablero
        int minasTablero; // N�mero de minas del tablero
        bool modoDesarrolladorTablero; // Estado del modo desarrollador del tablero
        int vidasTablero; // N�mero de vidas del tablero


};

#endif // CONFIG_H
