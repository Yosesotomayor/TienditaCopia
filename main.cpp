#include <iostream>
#include "menu.cpp"
using namespace std;

int main(){
    int opcion;
    Menu menu = Menu(opcion);
    menu.mostrarMenu();
    return 0;
}