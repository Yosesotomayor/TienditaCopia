#include <iostream>
#include "carrito.h"
using namespace std;

Carrito::Carrito(char _opcion){
    opcion = _opcion;
}

void Carrito::mostrarCarrito(){
    system("clear");
    
}

void Carrito::comprarCarrito(){
    system("clear");
    
}

void Carrito::menuCarrito(){
    system("clear");
    do{
        cout<<"\n\t  --CARRITO--\n";
        cout<<"1 Mostrar\n";
        cout<<"2 ComprarCarrito\n";
        cout<<"R Regresar\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion){
            case '1': mostrarCarrito();
                break;
            case '2': comprarCarrito();
                break;
            case 'R': system("clear");
                break;
            case 'r': system("clear");
                break;
            default:    system("clear");
                        cout<<"Opcion invalida...";
        }
    }while(opcion!='r' && opcion!='R');
}