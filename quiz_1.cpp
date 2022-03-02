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

class NoticiaPaper: public Noticia {
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

class NoticiaRadio: public Noticia {
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

// Struct para la noticia digital
typedef struct mediaDitital {
    string tipo;    // audio, video...
    string autor;   // quien tomo la foto...
    string url;     // ./source.zzz
} mediaDigitalPointer;

class NoticiaDigital: public Noticia {
    // atributos privados
    private:
        vector<mediaDitital> listaMedia;
    public:
        // SETTER
        void setListaMedia(vector<mediaDitital> pListaMedia) {
            listaMedia = pListaMedia;
        }

        // GETTER
        string getListaMedia() {
            //string res = "\nMedia Ditital:";
            string res = "\n";
            for (mediaDitital i : listaMedia) {
                res += ("\tTipo: "+ i.tipo + "\n\tAutor: " + i.autor + "\n\tUrl: " + i.url + "\n");
            }
            return res;
        }

        // Constructor
        NoticiaDigital(string pTitulo, string pFecha, string pReportero, vector<mediaDitital> pListaMedia) : Noticia(pTitulo, pFecha, pReportero) {
            setListaMedia(pListaMedia);
        }

        // Devuelve el nombre de la clase
        virtual const string classname() { return "NoticiaDigital"; }

        // Método abstracto implementado
        virtual string getInfo()  {
            return Noticia::getInfo() + "\nMedia Digital: " + getListaMedia();
        }
};


int main() {

    // medias digitales para la NoticiaDigital
    mediaDitital media1 = {"Audio", "Mandy Osborn", "./au001.flac"};
    mediaDitital media2 = {"Foto", "Ramiro Daniles", "./ft001.jpeg"};
    mediaDitital media3 = {"Video", "Denzel Crocker", "./mv001.mkv"};
    // se añaden a un vector
    vector<mediaDitital> vectorMedia = {media1, media2, media3};

    // la lista de noticias, utiliza punteros a Noticia porque sino no es accesible el método propio de las clases hijas
    vector<Noticia*> listaNoticias;
    // se agregan al vector
    listaNoticias.push_back(new NoticiaPaper("Titulo2", "02-06-2099", "Greyvin Moya", "./image02.jpeg"));
    listaNoticias.push_back(new NoticiaRadio("Titulo3", "24-03-2050", "Andres Vargas", "./audio03.flac"));
    listaNoticias.push_back(new NoticiaDigital("Titulo4", "15-09-1998", "Anddy Alvarado", vectorMedia));
    
    // recorre las noticias del vector
    for (Noticia* n : listaNoticias) {
        cout << n->getInfo() << "\n----------------" << endl;
    }
    return 0;
}