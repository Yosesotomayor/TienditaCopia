#include <iostream>
#include "articulos.h"
using namespace std;

Articulo::Articulo(string _ID, string _nombre,float _precio,int _existencias){
    ID = _ID;
    nombre = _nombre;
    precio = _precio;
    existencias = _existencias;
}

void Articulo::agregarArticulo(string ID, string nombre, float precio, int existencias){
    cout<<"Articulo ["<<ID<<" - "<<nombre<<"] agregado con exito.";
}

void Articulo::borrarArticulo(string ID, string nombre, float precio, int existencias){
    cout<<"Articulo ["<<ID<<" - "<<nombre<<"] eliminado con exito.";
}

//articulos
string ID, nombre; float precio; int existenciasA = 19, existenciasC = 12, existenciasG = 8;
Articulo agua = Articulo(ID, nombre, precio, existenciasA);
Articulo chips = Articulo(ID, nombre, precio, existenciasC);
Articulo galletas = Articulo(ID, nombre, precio, existenciasG);

