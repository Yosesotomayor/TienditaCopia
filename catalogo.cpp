#include <iostream>
#include "catalogo.h"
#include "articulos.cpp"
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
        cout<<"R Regresar\n";
        cout<<"Opcion: "; cin>>opcion;
        switch (opcion){
        case '1': system("clear");
            if(existenciasA!=0){
                agua.agregarArticulo("001","Agua",9.99,existenciasA);
                existenciasA--;
                cout<<endl<<existenciasA;
            }
            else{
                cout<<"Articulo ["<<"001"<<" - "<<"Agua"<<"] esta agotado.";
            }
            break;
        case '2': system("clear");
                if(existenciasC!=0){
                agua.agregarArticulo("002","Chips",15.99,existenciasC);
                existenciasC--;
                cout<<endl<<existenciasC;
            }
            else{
                cout<<"Articulo ["<<"002"<<" - "<<"Chips"<<"] esta agotado.";             
            }
            break;
        case '3': system("clear");
                if(existenciasG!=0){
                agua.agregarArticulo("003","Galletas",11.99,existenciasG);
                existenciasG--;
                cout<<endl<<existenciasG;
            }
            else{
                cout<<"Articulo ["<<"003"<<" - "<<"Galletas"<<"] esta agotado.";
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
