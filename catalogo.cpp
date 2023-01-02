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
        cout<<"Existencias: "; //cout<<"\t   Existencias: "<<Data[1].Existencias<<"     Existencias: "<<Data[2].Existencias<<endl;
        cout<<"R Regresar\n";
        cout<<"Opcion: "; cin>>opcion;
        switch (opcion){
        case '1': system("clear");
            if(Data[0].Existencias!=0){
                //Data[0].agregarArticulo();
            }
            else{ 
                cout<<"Articulo ["<<Data[0].ID<<" - "<<Data[0].Nombre<<"] esta agotado.";
            }
            break;
        case '2': system("clear");
                if(Data[1].Existencias!=0){
                Data[1].agregarArticulo();
            }
            else{
                cout<<"Articulo ["<<Data[1].ID<<" - "<<Data[1].Nombre<<"] esta agotado.";             
            }
            break;
        case '3': system("clear");
                if(Data[2].Existencias!=0){
                Data[2].agregarArticulo();
            }
            else{
                cout<<"Articulo ["<<Data[2].ID<<" - "<<Data[2].Nombre<<"] esta agotado.";
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
