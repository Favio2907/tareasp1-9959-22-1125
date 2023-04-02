#ifndef CONFIG_H
#define CONFIG_H


class Config // Definici�n de la clase Config
{
    public:
        Config(int filasTablero, int columnasTablero, int minasTablero, bool modoDesarrolladorTablero, int vidasTablero);
        // Constructor de la clase Config con par�metros para configurar el tablero
        int getFilasTablero(); // M�todo para obtener el n�mero de filas del tablero
        int setFilasTablero(int filasTablero); // M�todo para establecer el n�mero de filas del tablero
        int getColumnasTablero(); // M�todo para obtener el n�mero de columnas del tablero
        int setColumnasTablero(int columnasTablero); // M�todo para establecer el n�mero de columnas del tablero
        int getminasTablero(); // M�todo para obtener el n�mero de minas del tablero
        int setminasTablero(int minasTablero); // M�todo para establecer el n�mero de minas del tablero
        bool getmodoDesarrolladorTablero(); // M�todo para obtener el estado del modo desarrollador del tablero
        bool setmodoDesarrolladorTablero(bool mododesarrolladorTablero); // M�todo para establecer el estado del modo desarrollador del tablero
        int getvidaTablero(); // M�todo para obtener el n�mero de vidas del tablero
        int setvidaTablero(int vidaTablero); // M�todo para establecer el n�mero de vidas del tablero
        void menuConfiguracion(); // M�todo para mostrar un men� de configuraci�n

    protected: // Secci�n protegida de la clase

    private: // Secci�n privada de la clase
        int filasTablero; // N�mero de filas del tablero
        int columnasTablero; // N�mero de columnas del tablero
        int minasTablero; // N�mero de minas del tablero
        bool mododesarrolladorTablero; // Estado del modo desarrollador del tablero
        int vidaTablero; // N�mero de vidas del tablero
};

#endif // CONFIG_H //
