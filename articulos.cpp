#include <iostream>
#include "articulos.h"
using namespace std;

Articulo::Articulo(string _ID, string _nombre,float _precio,int _existencias,int _cantidad){
    ID = _ID;
    nombre = _nombre;
    precio = _precio;
    existencias = _existencias;
    cantidad = _cantidad;
}


string Articulo::name(){
    return nombre;
}

string Articulo::id(){
    return ID;
}

float Articulo::price(){
    return precio;
}

int Articulo::existance(){
    return existencias;
}

int Articulo::cant(){
    return cantidad;
}

void Articulo::mostrarArticulo(){
    cout<<"ID: "<<Articulo::id()<<"| Nombre: "<<Articulo::name()<<"| Cantidad: "<<Articulo::cant()<<"| Precio: $"<<Articulo::cant()*Articulo::price()<<endl;
}

void Articulo::agregarArticulo(){
    cantidad++;
    existencias--;
    cout<<"Articulo ["<<Articulo::price()<<" - "<<Articulo::name()<<"] agregado con exito.";
}

float Articulo::subT(){
    float individual=0;
    individual += Articulo::cant()*Articulo::price();
    return individual;
}

void Articulo::eliminarUnArticulo(){
    cantidad--;
    existencias++;
}

void Articulo::borrarArticulo(){
    while(Articulo::cant()!=0){
        Articulo::eliminarUnArticulo();
    }
}

void Articulo::comprado(){
    cantidad = 0;
}

//Articulos !!
string agua_ID="001", agua_nombre="Agua"; float agua_precio=9.99; int agua_existencias=13, agua_cantidad=0;
string chips_ID="002", chips_nombre="Chips"; float chips_precio=15.99; int chips_existencias=10, chips_cantidad=0;
string galletas_ID="003", galletas_nombre="Galletas"; float galletas_precio=11.99; int galletas_existencias=7, galletas_cantidad=0;

Articulo agua = Articulo(agua_ID, agua_nombre, agua_precio, agua_existencias, agua_cantidad);
Articulo chips = Articulo(chips_ID, chips_nombre, chips_precio, chips_existencias, chips_cantidad);
Articulo galletas = Articulo(galletas_ID, galletas_nombre, galletas_precio, galletas_existencias, galletas_cantidad);
