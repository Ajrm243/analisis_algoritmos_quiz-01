#include <iostream>
#include <string>

using namespace std;

/*
    Creacion de las clase "Madre" Noticia
*/

class Noticia {
    // atributos privados
    private:
        string titulo;
        string fecha;
        string reportero;
    public:
        // SETTER
        void setTitulo(string pTitulo) {
            titulo = pTitulo;
        }
        void setFecha(string pFecha) {
            fecha = pFecha;
        }
        void setReportero(string pReportero) {
            reportero = pReportero;
        }

        // GETTER
        string getTitulo() {
            return titulo;
        }
        string getFecha() {
            return fecha;
        }
        string getReportero() {
            return reportero;
        }
        
        // Constructor
        Noticia(string pTitulo, string pFecha, string pReportero) {
            setTitulo(pTitulo);
            setFecha(pFecha);
            setReportero(pReportero);
        }

        // Devuelve el nombre de la clase
        virtual const string classname() { return "Noticia"; }

        // Método abstracto
        virtual string getInfo() {
            return "Soy " + classname() + "\nTitulo: " + getTitulo() + "\nFecha: " + getFecha() + "\nReportero: " + getReportero();
        }
};

class NoticiaPaper: Noticia {
    // atributos privados
    private:
        string foto;
    public:
        // SETTER
        void setFoto(string pFoto) {
            foto = pFoto;
        }

        // GETTER
        string getFoto() {
            return foto;
        }

        // Constructor
        NoticiaPaper(string pTitulo, string pFecha, string pReportero, string pFoto) : Noticia(pTitulo, pFecha, pReportero) {
            setFoto(pFoto);
        }

        // Devuelve el nombre de la clase
        virtual const string classname() { return "Noticia"; }

        // Método abstracto
        virtual string getInfo() {
            return "Soy " + classname() + "\nTitulo: " + getTitulo() + "\nFecha: " + getFecha() + "\nReportero: " + getReportero();
        }
};

int main() {

    return 0;
}