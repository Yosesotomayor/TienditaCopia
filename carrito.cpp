#include <iostream>
#include "carrito.h"
using namespace std;

bool cV=true;
Carrito::Carrito(char _opcion, float _total){
    opcion = _opcion;
    total = _total;
}

char op; float iva = 1.16; float t=0;

Carrito carrito = Carrito(op,t);



float Carrito::SubT(){
    float subtotal=0; 
    subtotal += galletas.subT();
    subtotal += agua.subT();
    subtotal += chips.subT();
    return subtotal;
}

float Carrito::T(){
    total = Carrito::SubT() * iva;
    return total;
}

void Carrito::mostrarCarrito(){
    system("clear");

    cout<<"Articulos: \n";
    
    if(agua.cant()!=0){
        agua.mostrarArticulo();
            cV = false;
    }
    if(chips.cant()!=0){
        chips.mostrarArticulo();
            cV = false;
    }
    if(galletas.cant()!=0){
        galletas.mostrarArticulo();
            cV = false;
    }
    if(cV==true){
        cout<<"El carrito esta vacio!";
    }
    else{
        cout<<"\nSubtotal: $"<<carrito.SubT();
        cout<<"\nTotal: $"<<carrito.T();
    }
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
