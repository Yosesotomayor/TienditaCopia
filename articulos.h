class Articulo{
    private:
        string ID;
        string nombre;
        float precio;
        int existencias;
        int cantidad;
    public:
        Articulo(string, string,float,int,int);
        void mostrarArticulo();
        void agregarArticulo();
        void eliminarUnArticulo();
        void borrarArticulo();
        float subT();
        string name();
        string id();
        float price();
        int existance();
        int cant();
        void comprado();
};  
