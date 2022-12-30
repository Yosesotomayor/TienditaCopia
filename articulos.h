class Articulo{
    private:
        string ID;
        string nombre;
        float precio;
        int existencias;
        int cantidad;
    public:
        Articulo(string, string,float,int,int);
        //int existencias(int);
        void agregarArticulo();
        void borrarArticulo();
        string name();
        string id();
        float price();
        int existance();
        int cant();
        void addcant();
};  