#include<iostream>
#include<algorithm>
#include <cassert>
#include <iomanip>
#include <fstream>



using namespace std;

const int MAX_CHARS = 1000;

class ConjuntoChar {
public:
	ConjuntoChar();
	bool pertenece(char letra) const {
		return binary_search(elems, elems + num_elems, letra);
	}
	void anyadir(char letra) { //Anyadimos de forma ordenada creciente
		int i = 0;
		while (i < num_elems && elems[i] < letra) { //Para saber donde añadir
			i++;
		}

		if (letra != elems[i]) { //No anyadimos letras repetidas
			for (int j = num_elems; j > i; j--) { //Por si toca insertar en un hueco ocupado
				elems[j] = elems[j - 1];
			}
			//Anyadimos
			elems[i] = letra;
			num_elems++;
		}
	}
private:
	int num_elems;
	char elems[MAX_CHARS];
};

//El invariante nos dice que estan ordenados de menor a mayor
//Ademas no hay elementos repetidos




int main(){
	//TODO en el futuro, el codigo de arriba es correcto

}
