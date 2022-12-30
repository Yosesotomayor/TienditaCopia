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

void Articulo::addcant(){
    cantidad++;
}

void Articulo::agregarArticulo(){
    cantidad++;
    existencias--;
    cout<<"Articulo ["<<Articulo::price()<<" - "<<Articulo::name()<<"] agregado con exito.";
}

void Articulo::borrarArticulo(){
    cantidad--;
    cout<<"Articulo ["<<Articulo::price()<<" - "<<Articulo::name()<<"] eliminado con exito.";
}

//articulos
string agua_ID="001", agua_nombre="Agua"; float agua_precio=9.99; int agua_existencias=13, agua_cantidad=0;
string chips_ID="002", chips_nombre="Chips"; float chips_precio=9.99; int chips_existencias, chips_cantidad;
string galletas_ID="003", galletas_nombre="Galletas"; float galletas_precio=9.99; int galletas_existencias, galletas_cantidad;

Articulo agua = Articulo(agua_ID, agua_nombre, agua_precio, agua_existencias, agua_cantidad);
Articulo chips = Articulo(chips_ID, chips_nombre, chips_precio, chips_existencias, chips_cantidad);
Articulo galletas = Articulo(galletas_ID, galletas_nombre, galletas_precio, galletas_existencias, galletas_cantidad);
