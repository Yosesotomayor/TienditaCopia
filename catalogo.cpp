#include <iostream>
#include "catalogo.h"
#include "carrito.cpp"
using namespace std;

Catalogo::Catalogo(char _opcion, string _nombre, string _ID){
    opcion = _opcion;
    nombre = _nombre;
    ID = _ID;
}

void Catalogo::mostrarCatalogo(){
    string ID; string nombre; float precio;
    system("clear");
    do{
        cout<<"\n\t\t\t--Catalogo--\n";
        cout<<"1 Agua : $9.99  -  2 Chips : $15.99  - 3 Galletas : $11.99\n";
        cout<<"Existencias: "<<agua.existance()<<"\t   Existencias: "<<chips.existance()<<"     Existencias: "<<galletas.existance()<<endl;
        cout<<"R Regresar\n";
        cout<<"Opcion: "; cin>>opcion;
        switch (opcion){
        case '1': system("clear");
            if(agua.existance()!=0){
                agua.agregarArticulo();
                agua.addcant();
            }
            else{
                cout<<"Articulo ["<<agua.id()<<" - "<<agua.name()<<"] esta agotado.";
            }
            break;
        case '2': system("clear");
                if(chips.existance()!=0){
                chips.agregarArticulo();
                chips.addcant();
            }
            else{
                cout<<"Articulo ["<<chips.id()<<" - "<<chips.name()<<"] esta agotado.";             
            }
            break;
        case '3': system("clear");
                if(galletas.existance()!=0){
                galletas.agregarArticulo();
                galletas.addcant();
            }
            else{
                cout<<"Articulo ["<<galletas.id()<<" - "<<galletas.name()<<"] esta agotado.";
            }
            break;
        case 'R': system("clear");
            break;
        case 'r': system("clear");
            break;
        default: system("clear");
                 cout<<"Articulo Inexistente...";
        }
    }while(opcion!='r' && opcion!='R');
}
