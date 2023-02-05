#include<iostream>
using namespace std;

int main()
{
    int a,b;
    char operacion; //+,-,/,*

    cout<<"Introduzca los valores de a y de b, y la operacion a realizar: "<<endl;
    cout<<"a operacion b: "<<endl;
    cin>>a>>operacion>>b;

    switch(operacion)
{
        case '+': cout<<a<<operacion<<b<<"="<<a+b<<endl;
    break;
        case '-': cout<<a<<operacion<<b<<"="<<a-b<<endl;
    break;
        case '/': cout<<a<<operacion<<b<<"="<<a/b<<endl;
    break;
        case '*': cout<<a<<operacion<<b<<"="<<a*b<<endl;
    break;
}

return 0;
}
