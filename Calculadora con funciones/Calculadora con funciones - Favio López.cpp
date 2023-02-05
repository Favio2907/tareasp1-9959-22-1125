#include<iostream>
#include<cstdlib>
using namespace std;

float Sumar(float num1, float num2){
    return num1+num2;
}
float Restar(float num1, float num2){
    return num1-num2;
}
float Multiplicar(float num1, float num2){
    return num1*num2;
}
float Dividir(float num1, float num2){
    return num1/num2;
}

int main()
{
    int opcion=-1;
    float num1, num2, resultado;
    while(opcion!=5)
        {
        cout<< "1 - Sumar"<<endl;
        cout<< "2 - Restar"<<endl;
        cout<< "3 - Multiplicar"<<endl;
        cout<< "4 - Dividir"<<endl;
        cout<< "5 - Salir"<<endl;
        cout<< "Opcion: ";
        cin>>opcion;
        system("cls");
        switch(opcion)
        {
        case 1:
            cout<< "--Ingrese los valores --"<<endl;
            cout<<"Numero 1: ";
            cin>>num1;
            cout<<"Numero 2: ";
            cin>>num2;
            resultado = Sumar (num1,num2);
            cout<<"El resultado de la suma es: "<<resultado<<endl;
            break;
        case 2:
            cout<< "--Ingrese los valores --"<<endl;
            cout<<"Numero 1: ";
            cin>>num1;
            cout<<"Numero 2: ";
            cin>>num2;
            resultado = Restar (num1,num2);
            cout<<"El resultado de la resta es: "<<resultado<<endl;
            break;
        case 3:
            cout<< "--Ingrese los valores --"<<endl;
            cout<<"Numero 1: ";
            cin>>num1;
            cout<<"Numero 2: ";
            cin>>num2;
            resultado = Multiplicar (num1,num2);
            cout<<"El resultado de la multiplicacion es: "<<resultado<<endl;
            break;
        case 4:
            cout<< "--Ingrese los valores --"<<endl;
            cout<<"Numero 1: ";
            cin>>num1;
            cout<<"Numero 2: ";
            cin>>num2;
            resultado = Dividir (num1,num2);
            cout<<"El resultado de la división es: "<<resultado<<endl;
            break;
        case 5:
            break;
        default:
            cout<<"Ingreso un numero incorrecto.=\n Intente de nuevo."<<endl;
            break;
        }
        system("pause");
        system("cls");
    }
return 0;
}
