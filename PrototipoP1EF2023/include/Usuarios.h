#ifndef USUARIOS_H
#define USUARIOS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Usuario { // Se define la clase Usuario
public:
    Usuario(); // Se define el constructor de la clase, el cual recibe como par�metros un usuario y una contrase�a

    string setUusuario(string usuario); // Se define el m�todo setUsuario, que permite establecer el valor del atributo usuario
    string getUusuario(); // Se define el m�todo getUsuario, que permite obtener el valor del atributo usuario
    string setContrasena(string pass); // Se define el m�todo setContrasena, que permite establecer el valor del atributo contrasena
    string getContrasena(); // Se define el m�todo getContrasena, que permite obtener el valor del atributo contrasena

    void menuUsuarios(); // Se define el m�todo menuUsuarios, que muestra el men� de opciones para el usuario
    void ingresarUsuarios(); // Se define el m�todo ingresarUsuarios, que permite ingresar un nuevo usuario
    void desplegarUsurios(); // Se define el m�todo desplegarUsuarios, que permite mostrar todos los usuarios registrados
    void modificarUsuarios(); // Se define el m�todo modificarUsuarios, que permite modificar los datos de un usuario
    void borrarUsurios(); // Se define el m�todo borrarUsuarios, que permite eliminar un usuario
    bool verificarUsuario(); // Se define el m�todo verificarUsuario, que verifica si el usuario y la contrase�a son correctos

    string getUsuarioAutenticado();

private:
    string usuario, contrasena; // Se definen los atributos usuario y contrasena como privados, para que s�lo puedan ser accedidos desde dentro de la clase
    string usuarioAutenticado;

    int id;
};

#endif // USUARIOS_H
