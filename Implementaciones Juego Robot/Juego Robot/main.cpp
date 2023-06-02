#include <iostream>
#include <windows.h>
#include "player.h"
#include "mapcell.h"
#include "gamemap.h"
#include "gamemap2.h"
#include "gamemap3.h"
#include "game.h"

using namespace std;

int main()
{
    // Aplicativo elaborado en el curso de Programacion I - Universidad Mariano Galvez
    // desarrollador: daguilae - Marzo 2022

    int minutos = 1;
    int segundos = 0;

    int minutos2 = 2;
    int segundos2 = 0;

    int minutos3 = 2;
    int segundos3 = 30;

    const int Moves = 30;// Número de movimientos restantes


    gamemap map;
    gamemap2 map2;
    gamemap3 map3;

    player hero;
    game newGame(Moves);
    map.drawPortada();
    //map.draw();
    cout << "---------------------------------------------------------------------------------------\n";
    cout << " __  __  __ _  _ ___ __     _   _ ___      ___ _      \n";
    cout << "|  _ \\|  _ \\|_   |  \\/  |  __|  _ \\   | \\ | |_   \\ \\    / /  ___| |     \n";
    cout << "| |_) | |) | | | | \\  / | |_  | |_) |  |  \\| | | |  \\ \\  / /| |_  | |     \n";
    cout << "|  _/|  _  /  | | | |\\/| |  _| |  _  /   | . ` | | |   \\ \\/ / |  _| | |     \n";
    cout << "| |    | | \\ \\ | || |  | | |_| | \\ \\   | |\\  || |_   \\  /  | |_| |_ \n";
    cout << "||    ||  \\_\\__||  ||__||  \\_\\  || \\|__|   \\/   |__|___|\n";
    cout << "---------------------------------------------------------------------------------------\n";
    while(map.isGameOver==false)
    {
      cout << endl;
      cout << "Tiempo restante: " << minutos << ":" << segundos << endl;
      cout << "MOVIMIENTOS RESTANTES: " << newGame.getRemainingMoves() << endl;
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();
      newGame.reduceMoves();

            segundos--;//Resta 1 a los segundos

      //Cuando los segundos son 0, resta 1 minuto
      if (segundos<=0)
      {
          minutos--;
          segundos = 59;
      }

      if (minutos < 0 )
      {
          cout << "" << endl;
          cout << " -- Limite de tiempo alcanzado -- " << endl;

          hero.drawCreditos();
          map.isGameOver = true;//Termina el ciclo while
      }


      //Actualizar información del jugador en el mapa
      if(map.setPlayerCell(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
        //Dibujamos el mapa
        map.draw();
      }
      //map.draw();

      Sleep(1000);
    }
      //Si los movimientos restantes llegan a 0 termina el juego
      if (newGame.getRemainingMoves() == 0)
      {
          cout << endl;
          cout << " -- Limite de movimientos alcanzado -- " << endl;
          cout << " ---------- Juego Terminado ---------- " << endl;
          cout << endl << endl;
          hero.drawCreditos();
          map.isGameOver = true;//Termina el ciclo while
      }

if (map.isGameOver==true)
    {
     cout << "---------------------------------------------------------------------------------------\n";
    cout << "  __ ___ __ _    _ _   _ __   __     _   _ ___      ____ _      \n";
    cout << " / _|  __/ __| |  | | \\ | |  _ \\ / _ \\   | \\ | |   \\ \\    / /  ___| |     \n";
    cout << "| (_ | |_ | |  _| |  | |  \\| | |  | | |  | |  |  \\| | | |  \\ \\  / /| |__  | |     \n";
    cout << " \\__ \\|  _|| | |_ | |  | | . ` | |  | | |  | |  | . ` | | |   \\ \\/ / |  __| | |     \n";
    cout << " _) | |_| || | || | |\\  | || | || |  | |\\  || |_   \\  /  | |_| |_ \n";
    cout << "|__/|__\\_|_/|| \\|__/ \\_/   || \\|__|   \\/   |__|___|\n";
    cout << "---------------------------------------------------------------------------------------\n";
    hero.resetToSafePosition();
    while(map2.isGameOver==false)
    {
      cout << "Tiempo restante: " << minutos2 << ":" << segundos2 << endl;
      cout << "MOVIMIENTOS RESTANTES: " << newGame.getRemainingMoves() << endl;
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();
      newGame.reduceMoves();

            segundos2--;//Resta 1 a los segundos

      //Cuando los segundos son 0, resta 1 minuto
      if (segundos2<=0)
      {
          minutos2--;
          segundos2 = 59;
      }

      if (minutos2 < 0 )
      {
          cout << "" << endl;
          cout << " -- Limite de tiempo alcanzado -- " << endl;

          hero.drawCreditos();
          map.isGameOver = true;//Termina el ciclo while
      }

      //Actualizar información del jugador en el mapa
      if(map2.setPlayerCel2(hero.getValueX(), hero.getValueY()))
      {
        map2.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
      }
      //map.draw();

    Sleep(1000);

    }
          //Si los movimientos restantes llegan a 0 termina el juego
      if (newGame.getRemainingMoves() == 0)
      {
          cout << endl;
          cout << " -- Limite de movimientos alcanzado -- " << endl;
          cout << " ---------- Juego Terminado ---------- " << endl;
          cout << endl << endl;
          hero.drawCreditos();
          map.isGameOver = true;//Termina el ciclo while
      }
    }

    if (map2.isGameOver==true){
    cout << "---------------------------------------------------------------------------------------\n";
    cout << " ___ __ __   __ __ __     _   _ ___      ___ _      \n";
    cout << "|_   _|  _|  _ \\ / _|  __|  _ \\   | \\ | |_   \\ \\    / /  ___| |     \n";
    cout << "   | |  | |_  | |) | |    | |_  | |_) |  |  \\| | | |  \\ \\  / /| |_  | |     \n";
    cout << "   | |  |  _| |  _  /| |    |  _| |  _  /   | . ` | | |   \\ \\/ / |  __| | |     \n";
    cout << "   | |  | |_| | \\ \\| |_| |_| | \\ \\   | |\\  || |_   \\  /  | |_| |_ \n";
    cout << "   ||  |__||  \\_\\\\__|__||  \\_\\  || \\|__|   \\/   |__|___|\n";
    cout << "---------------------------------------------------------------------------------------\n";

    hero.resetToSafePosition();
      while(map3.isGameOver==false)
    {
      cout << "Tiempo restante: " << minutos3 << ":" << segundos3 << endl;
      cout << "MOVIMIENTOS RESTANTES: " << newGame.getRemainingMoves() << endl;
      cout << "Introduce comando de movimiento <w>, <a>, <s>, <d> : <x> --> Salir " << endl;
      hero.callInput();
      newGame.reduceMoves();

            segundos3--;//Resta 1 a los segundos

      //Cuando los segundos son 0, resta 1 minuto
      if (segundos3<=0)
      {
          minutos3--;
          segundos3 = 59;
      }

      if (minutos3 < 0 )
      {
          cout << "" << endl;
          cout << " -- Limite de tiempo alcanzado -- " << endl;

          hero.drawCreditos();
          map.isGameOver = true;//Termina el ciclo while
      }

      //Actualizar información del jugador en el mapa
      if(map3.setPlayerCel3(hero.getValueX(), hero.getValueY()))
      {
     //   system("cls");
        map3.draw();
      } else
      {
       // system("cls");
        hero.resetToSafePosition();
      }
      //map.draw();

    Sleep(1000);

    }
          //Si los movimientos restantes llegan a 0 termina el juego
      if (newGame.getRemainingMoves() == 0)
      {
          cout << endl;
          cout << " -- Limite de movimientos alcanzado -- " << endl;
          cout << " ---------- Juego Terminado ---------- " << endl;
          cout << endl << endl;
          hero.drawCreditos();
          map.isGameOver = true;//Termina el ciclo while
      }
    }

    return 0;

    }





