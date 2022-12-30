using namespace std;

class Catalogo{
    private:
        char opcion;
        string nombre;
        string ID;
    public:
        Catalogo(char opcion, string _nombre, string _ID);
        void mostrarCatalogo();
};