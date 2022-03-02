#include <iostream>
#include <string>
#include <vector>

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
        virtual const string classname() { return "NoticiaPaper"; }

        // Método abstracto implementado
        virtual string getInfo()  {
            return Noticia::getInfo() + "\nFoto: " + getFoto();
        }
};

/*
typedef struct mediaDitital {
    string video;
    string audio;
    string foto;
} mediaDigitalPointer;
*/

/*
    TODO: hacer bien la noticia digital
*/
class NoticiaDigital: Noticia {
    // atributos privados
    private:
        vector<string> listaMedia;
    public:
        // SETTER
        void setListaMedia(vector<string> pListaMedia) {
            listaMedia = pListaMedia;
        }

        // GETTER
        string getListaMedia() {
            string res = "\n";
            for (string i : listaMedia) {
                res += (i + "\n");
            }
            return res;
        }

        // Constructor
        NoticiaDigital(string pTitulo, string pFecha, string pReportero, vector<string> pListaMedia) : Noticia(pTitulo, pFecha, pReportero) {
            setListaMedia(pListaMedia);
        }

        // Devuelve el nombre de la clase
        virtual const string classname() { return "NoticiaPaper"; }

        // Método abstracto implementado
        virtual string getInfo()  {
            return Noticia::getInfo() + "\nMedia: " + getListaMedia();
        }
};

class NoticiaRadio: Noticia {
    // atributos privados
    private:
        string audio;
    public:
        // SETTER
        void setAudio(string pAudio) {
            audio = pAudio;
        }

        // GETTER
        string getAudio() {
            return audio;
        }

        // Constructor
        NoticiaRadio(string pTitulo, string pFecha, string pReportero, string pAudio) : Noticia(pTitulo, pFecha, pReportero) {
            setAudio(pAudio);
        }

        // Devuelve el nombre de la clase
        virtual const string classname() { return "NoticiaRadio"; }

        // Método abstracto implementado
        virtual string getInfo()  {
            return Noticia::getInfo() + "\nAudio: " + getAudio();
        }
};

int main() {

    Noticia miNoticia = Noticia("Titulo1", "02-03-2022", "Ignacio Santos");
    NoticiaPaper miPaper = NoticiaPaper("Titulo2", "02-06-2099", "Greyvin Moya", "./image02.jpeg");
    NoticiaRadio miRadio = NoticiaRadio("Titulo3", "24-03-2050", "Andres Vargas", "./audio03.flac");
    //cout << miNoticia.getInfo() << endl;
    //cout << miPaper.getInfo() << endl;
    cout << miRadio.getInfo() << endl;
    return 0;
}