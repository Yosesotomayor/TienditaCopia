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
    if(cV!=true){
        cout<<"Articulos: \n";
    }
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
    char opcion;
    system("clear");
    if(cV == false){
        cout<<"Esta seguro de comprar los articulos por " <<carrito.T()<<"? (y/n): "; cin>>opcion;
        switch(opcion){
            case 'y': system("clear");
                    agua.comprado();
                    chips.comprado();
                    galletas.comprado();
                    cV = true;
                    cout<<"Gracias!";
                break;
            case 'N': system("clear");
                break;
            case 'n': system("clear");
                break;
            default : system("clear");
        }
    }
    else{
        cout<<"El carrito esta vacio!";
    }
}

void Carrito::vaciarCarrito(){
    agua.borrarArticulo();
    chips.borrarArticulo();
    galletas.borrarArticulo();
    cout<<"El carrito se ha vaciado con exito!";
}

void Carrito::menuCarrito(){
    system("clear");
    char op;
    string id_; bool band = false, band1 = false;
    string arr[3] = {"001","002","003"};
    if(agua.cant() != 0 || chips.cant() != 0 || galletas.cant() != 0){
        cV=false;
    }
    do{
        cout<<"\n\t  --CARRITO--\n";
        cout<<"1 Mostrar\n";
        cout<<"2 Comprar carrito\n";
        cout<<"3 Eliminar articulo\n";
        cout<<"4 Vaciar carrito\n";
        cout<<"R Regresar\n";
        cout<<"Opcion: "; cin>>opcion;
        switch(opcion){
            case '1': mostrarCarrito();
                break;
            case '2': comprarCarrito();
                break;
            case '3':
                system("clear");
                if(cV == false){
                    do{
                        cout<<"|"<<agua.id()<<"->"<<agua.name()<<"|  |"<<chips.id()<<"->"<<chips.name()<<"|  |"<<galletas.id()<<"->"<<galletas.name()<<"|"<<endl;
                        cout<<"Digite ID: "; cin>>id_;
                        system("clear");
                        for (int i=0;i<3;i++) {
                            if(id_ == arr[i]){
                                band = true;
                                break;
                            }
                        }
                        if(id_=="001"){
                            if(agua.cant()!=0){
                                agua.eliminarUnArticulo();
                                cout<<"Articulo ["<<agua.price()<<" - "<<agua.name()<<"] eliminado con exito.";
                            }
                            else{
                                cout<<"Articulo no esta en el carrito!\n";
                            }
                        }
                        else if(id_=="002"){
                            if(chips.cant()!=0){
                                chips.eliminarUnArticulo();
                                cout<<"Articulo ["<<chips.price()<<" - "<<chips.name()<<"] eliminado con exito.";
                            }
                            else{
                                cout<<"Articulo no esta en el carrito!\n";
                            }
                        }
                        else if(id_=="003"){
                            if(galletas.cant()!=0){
                                galletas.eliminarUnArticulo();
                                cout<<"Articulo ["<<galletas.price()<<" - "<<galletas.name()<<"] eliminado con exito.";
                            }
                            else{
                                cout<<"Articulo no esta en el carrito!\n";
                            }
                        }
                        else{
                            cout<<"ID de articulo inexistente...\n";
                        }
                    }while(band != true);
                }
                else{
                    cout<<"El carrito esta vacio!";
                }
                if(agua.cant()==0 && chips.cant()==0 && galletas.cant()==0){
                    cV = true;
                }
                break;
            case '4': system("clear");
                    if(cV == false){
                        do{
                            cout<<"Esta seguro que quiere vaciar su carrito? (y/n): "; cin>>op;
                            switch (op){
                            case 'y': system("clear");
                                    carrito.vaciarCarrito();
                                    cV = true;
                                    band1=true;
                                break;
                            case 'n': system("clear");
                                    band1=true;
                                break;
                            case 'N': system("clear");
                                    band1=true;
                                break;
                            default: system("clear");
                                    cout<<"Opcion invalida...";
                            }
                        }while(band1!=true);
                    }
                    else{
                        cout<<"El carrito esta vacio!";
                    }
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
