
#include<string>
#include<unordered_map>
#include<list>
#include <stdexcept>

using namespace std;


class iPud {

public:
	//CONSTRUCTOR
	iPud(){ };

	//METODOS
	void addSong(const string& song, const string& artist, const int& duration) {
		if (ipud.count(song)) {//ya existe la cancion
			throw domain_error("Ya existe la cancion");
		}
		//else, la anyadimos al ipud
		ipud[song].artista = artist;
		ipud[song].duracion = duration;
		//ipud[song].itListaRecientes = cancionesRecientes.end(); 
		//ipud[song].itListaReproduccion = listaReproduccion.end();
	}

	bool addToPlaylist(const string& song) {
		//busco a ver si ya esta en la lista de reproduccion
		auto it = ipud[song].itListaReproduccion;
		if (it == listaReproduccion.end()) { //NO existe la cancion
			infoCancion can = ipud[song];
			listaReproduccion.push_back(can);
			ipud[song].itListaReproduccion = --listaReproduccion.end();
			return false;
		}

		return true;
	}

	string current() const {
		return "aux";
	}

	void play() {

	}

	int totalTime() const{
		return 1;
	}

	//list<string> recent(const int N) {

	//}

	void deleteSong(const string& song) {


	}


private:
	struct infoCancion {
		string titulo;//se identifican por su nombre
		string artista;
		int duracion;
		//puntero a la lista de reproduccion
		list<infoCancion>::iterator itListaReproduccion;
		//puntero a la lista de recientes
		list<infoCancion>::iterator itListaRecientes;
		infoCancion() : duracion(0){};
	};
	unordered_map<string, infoCancion> ipud;
	list<infoCancion> cancionesRecientes; //lista de canciones recientes
	list<infoCancion> listaReproduccion;
	//int totalTime;
};



int main() {
	iPud canciones;

	canciones.addSong("pepe", "luis", 3);
	canciones.addToPlaylist("pepe");
	canciones.addToPlaylist("pepe");

	canciones.addSong("juan", "y medio", 3);
	return 0;
}