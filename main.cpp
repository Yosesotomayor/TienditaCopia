#include <iostream>
#include "menu.cpp"
using namespace std;

int main(){
    int opcion;
    Excel();
    Menu menu = Menu(opcion);
    menu.mostrarMenu();
    cerrarE();
    return 0;
}
