#include "articulos.cpp"

class Carrito{
    private:
        char opcion;
        float total;
    public:
        Carrito(char,float);
        float T();
        float SubT();
        void menuCarrito();
        void mostrarCarrito();
        void comprarCarrito();
};
