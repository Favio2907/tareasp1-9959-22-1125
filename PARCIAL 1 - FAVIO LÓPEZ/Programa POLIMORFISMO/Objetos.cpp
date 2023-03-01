#include <iostream>
using namespace std;
class Animal
{
public:
    void hacerSonido()
    {
        cout << "Los animales dicen: " << endl;
    }
};
class Perro: public Animal
{
public:
    void hacerSonido()
    {
        cout << "El perro dice: bow bow" << endl;
    }
};
class Gato : public Animal
{
public:
    void hacerSonido()
    {
        cout << "El gato dice: miau" << endl;
    }
};
int main()
{
    Animal miAnimal;
    Perro miPerro;
    Gato miGato;

    miAnimal.hacerSonido();  //A esto se le llama polimorfismo
    miPerro.hacerSonido();
    miGato.hacerSonido();
    return 0;
}

