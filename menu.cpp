#include <iostream>
#include "catalogo.cpp"
#include "menu.h"
using namespace std;

Menu::Menu(char _opcion){
    opcion = _opcion;
}  

void Menu::mostrarMenu(){
    char opcion1; string ID;
    char nombre[31];
    Catalogo catalogo = Catalogo(opcion1, nombre, ID);
    Carrito carrito = Carrito(opcion1,0);
    system("clear");
   Excel();
    do{
        cout<<"\n\t---Tiendita---\n";
        cout<<"1. Catalogo\n";
        cout<<"2. Carrito\n";
        cout<<"S. Salir\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion){
            case '1': system("clear");
                    catalogo.mostrarCatalogo();
                break;
            case '2': system("clear");
                      carrito.menuCarrito();
                break;
            case 's': system("clear");
                    cout<<"Vuelva pronto..."<<endl;
                break;
            case 'S': system("clear");
                    cout<<"Vuelva pronto..."<<endl;
                break;
            default:system("clear"); 
                    cout<<"Opcion inválida.";
        }
    }while(opcion!='S' && opcion!='s');
}
