class Articulo{
    private:
        string ID;
        string nombre;
        float precio;
        int existencias;
    public:
        Articulo(string, string,float,int);
        void agregarArticulo(string,string nombre,float,int);
        void borrarArticulo(string,string nombre,float,int);
};  