#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

fstream excel;

class Articulo {
    public:

        string ID;
        string Nombre;
        float Precio;
        int Existencias;
        int Cantidad;

    void displayItem() {
        cout<<"ID: "<<ID<< '\n';
        cout<<"Name: "<<Nombre<< '\n';
        cout<<"Price: "<<Precio<< '\n';
        cout<<"Existances: "<<Existencias<< '\n';
        cout<<endl;
    
    }
    void displayExistencias(){
        cout<<Existencias;
    }

    void agregarArticulo(){
            Cantidad++;
            Existencias--;
            cout<<"Articulo ["<<ID<<" - "<<Nombre<<"] agregado con exito.";
        }
    void mostrarArticulo(){
            cout<<"ID: "<<ID<<"| Nombre: "<<Nombre<<"| Cantidad: "<<Cantidad<<"| Precio: $"<<Cantidad*Precio<<endl;
        }
    void eliminarUnArticulo(){
            Cantidad--;
            Existencias++;
        }
        void borrarArticulo(){
            while(Cantidad!=0){
                eliminarUnArticulo();
            }
        }
        float subT(){
            float individual=0;
            individual += Cantidad*Precio;
            return individual;
        }
        void comprado(){
            Cantidad = 0;
        }
};



void cerrarE(){
        excel.close();
}

void addTitulo(){

    excel.open("Existencias.csv", ios::out);
    string TITULOS = "ID,Nombre,Precio,Existencias\n";
    excel << TITULOS;

    cerrarE();
}
/*
void addLinea(string ID, string Nombre, string Precio, string Existencias){

    excel.open("Existencias.csv", ios::app);
    string endline = "\n";
    excel << ID <<','<< Nombre<<',' << Precio<<',' << Existencias << endline ;

    cerrarE();
}*/
// FUNCION PARA CONVERTIR LOS DATOS DEL CSV A VECTORES
vector<Articulo> Data;

void convertExcel(){
    vector<Articulo> Data;
    ifstream convert;
    convert.open("Existencias.csv", ios::in);
    string tempString;
    string line;
       
        while(!convert.eof()){
            Articulo item;
            stringstream inputString(line);
            getline(convert,item.ID,',');
            getline(convert,item.Nombre,',');
            getline(convert,tempString,',');
            item.Precio = atof(tempString.c_str());
            tempString = "";
            getline(convert,tempString);
            item.Existencias= atoi(tempString.c_str());
            
            Data.push_back(item);
            line = "";
        }
        //MOSTRAR
        /*for(int i=0;i<Data.size();i++){
            Data[i].displayItem();
        }*/

        //Data[0].displayItem();
        Data[0].displayExistencias();
        convert.close();
}

void abrirE(){

    excel.open("Existencias.csv",ios::in);

    if(excel.fail()){

        addTitulo();
/*
        addLinea("001","Agua","9.99","10");
        addLinea("002","Chips","15.99","10");
        addLinea("003","Galletas","11.99","10"); */
    }
    else{
        excel.open("Existencias.csv", ios::app);
    }
}    

void Excel(){
    convertExcel();
}

//Articulos !!

/*
Articulo agua("001","Agua",9.99,10,0);
Articulo chips("002","Chips",15.99,10,0);
Articulo galletas("003","Galletas",11.99,10,0);
*/