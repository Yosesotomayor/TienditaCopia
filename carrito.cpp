#include <iostream>
#include "excel.cpp"
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
    subtotal += Data[0].subT();
    subtotal += Data[1].subT();
    subtotal += Data[2].subT();
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
   if(Data[0].Cantidad!=0){
        Data[0].mostrarArticulo();
            cV = false;
    }
    if(Data[1].Cantidad!=0){
        Data[1].mostrarArticulo();
            cV = false;
    }
    if(Data[2].Cantidad!=0){
        Data[2].mostrarArticulo();
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
                    Data[0].comprado();
                    Data[1].comprado();
                    Data[2].comprado();
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
    Data[0].borrarArticulo();
    Data[1].borrarArticulo();
    Data[2].borrarArticulo();
    cout<<"El carrito se ha vaciado con exito!";
}

void Carrito::menuCarrito(){
    system("clear");
    char op;
    string id_; bool band = false, band1 = false;
    string arr[3] = {"001","002","003"};
    if(Data[0].Cantidad != 0 || Data[1].Cantidad != 0 || Data[2].Cantidad != 0){
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
                        cout<<"|"<<Data[0].ID<<"->"<<Data[0].Nombre<<"|  |"<<Data[1].ID<<"->"<<Data[1].Nombre<<"|  |"<<Data[2].ID<<"->"<<Data[2].Nombre<<"|"<<endl;
                        cout<<"Digite ID: "; cin>>id_;
                        system("clear");
                        for (int i=0;i<3;i++) {
                            if(id_ == arr[i]){
                                band = true;
                                break;
                            }
                        }
                        if(id_=="001"){
                            if(Data[0].Cantidad!=0){
                                Data[0].eliminarUnArticulo();
                                cout<<"Articulo ["<<Data[0].Precio<<" - "<<Data[0].Nombre<<"] eliminado con exito.";
                            }
                            else{
                                cout<<"Articulo no esta en el carrito!\n";
                            }
                        }
                        else if(id_=="002"){
                            if(Data[1].Cantidad!=0){
                                Data[1].eliminarUnArticulo();
                                cout<<"Articulo ["<<Data[1].Precio<<" - "<<Data[1].Nombre<<"] eliminado con exito.";
                            }
                            else{
                                cout<<"Articulo no esta en el carrito!\n";
                            }
                        }
                        else if(id_=="003"){
                            if(Data[2].Cantidad!=0){
                                Data[2].eliminarUnArticulo();
                                cout<<"Articulo ["<<Data[2].Precio<<" - "<<Data[2].Nombre<<"] eliminado con exito.";
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
                if(Data[0].Cantidad==0 && Data[1].Cantidad==0 && Data[2].Cantidad==0){
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
