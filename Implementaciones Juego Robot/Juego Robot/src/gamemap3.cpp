#include "gamemap3.h"
#include "player.h"
#include <iostream>
#include <fstream>
//Implementacion de toda la funcionabilidad del mapa del juego

using namespace std;

gamemap3::gamemap3()
{
    //ctor
    playerCell3 = NULL;
    loadMapFromFile3();
    isGameOver = false;
}

void gamemap3::draw(){
    //system("cls");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            // Utilizar las celulas cuando se dibuja el mapa
            cout << cell [i][j].id;
        }
        cout << endl;
    }
}
bool gamemap3::setPlayerCel3(int playerX, int playerY)
{
    string opcion;
    if (cell[playerX][playerY].isBlockedCell() == false && cell[playerX][playerY].isBlockedCel2() == false)
    {
        if (cell[playerX][playerY].id == '$')
        {
            drawVictoria();
            isGameOver = true;
            return true;
        } else
        { // evalúa espacio
            //Se verifica que maque con cero la posicion que abandona el jugador
            if (playerCell3 != NULL)
            {
                // Cambio permitira quitar los ceros en el camino del jugador, al traslador un cero a un char se convierte en espacio
                //playerCell->id='0';
                playerCell3->id=0;
            }
            cout << "Las coordenadas del jugador estan en: " << playerX << "," << playerY << endl;
            //Cambio de coordenadas para corregiro problema de los movimientos del jugador en el eje X
            //playerCell = &cell[playerY][playerX];
            playerCell3 = &cell[playerX][playerY];
            playerCell3->id='®';//ascii 169
        }

        return true;
    }
    else
    {
        return false;
    }

}
void gamemap3::loadMapFromFile3()
{
    string line;
    int row = 0;
    char userInput = ' ';
    ifstream myFile("map3.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            //cout << line << endl;
            for (int p = 0; p < line.length(); p++)
            {
                if (line[p] == '0')
                {
                    cell[row][p].id = 0;
                } else
                {
                    cell[row][p].id = line[p];
                }
                //Cambio para quitar ceros y colocar espacios en blanco en el mapa
                //cell[row][p].id = line[p];
            }

            row++;
        }
        myFile.close();
    }
    else
    {
        cout << "Error FATAL: archivo del mapa no pudo ser cargado" << endl;
        cin >> userInput;
        if (userInput='s')
        {
            createMapToFile3();
        } else
        {
            cout << "NO podemos continuar el juego" << endl;
        }
    }

}
void gamemap3::createMapToFile3()
{
    ofstream myFile("map3.txt");
    if (myFile.is_open())
    {
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (i == 0 || i == 14)
                {
                    myFile << "1";
                    myFile << "#";
                } else
                {
                    if (j == 0 || j == 14)
                    {
                        myFile << "1";
                        myFile << "#";
                    } else
                    {
                        myFile << "0";
                        myFile << "#";
                    }
                }

            }
            myFile << endl;
        }
        myFile.close();
    } else
    {
        cout << "Error FATAL: archivo no pudo ser creado" << endl;
    }
}
void gamemap3::drawVictoria()
{
    string line;
    char  userInput = ' ';
    ifstream myFile("premio.txt");
    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while( getline(myFile, line))
        {
            cout << line << endl;
        }
        myFile.close();
        cin >> userInput;
    }
    else
    {
        cout << "Error FATAL: el archivo de ganador no pudo ser cargado" << endl;
    }
}
gamemap3::~gamemap3()
{
    //dtor
}
