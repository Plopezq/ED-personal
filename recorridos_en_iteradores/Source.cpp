#include <iostream>
#include <list>

using namespace std;


void eliminar_pares(list<int> &lista) {
	auto it = lista.begin();

	while (it != lista.end()) {
		if (*it % 2 == 0) {//si es par, lo elimino
			it = lista.erase(it);
		}
		else {
			it++;
		}

	}
}
template <typename T>
bool ordenada_ascendente(const list<T>& list) {
	//INDICAR SI ESTA LISTA ESTA ORDENADA ASCENDENTEMENTE
	auto it1 = list.begin();
	if (it1 == list.end()) return true;// lista de 1 solo elemento
	auto it2 = list.begin();
	it2++;
	bool ok = true;
	while (it2 != list.end() && ok) {
		if (*it1 > *it2) {
			ok = false;
		}
		it1++;
		it2++;
	}
	return ok;
}

bool es_palindromo(const string& cadena) {
	bool palindromo = true;

	auto it1 = cadena.begin();
	auto it2 = cadena.end();

	while (it1 != it2 && it1 +1 != it2 && palindromo) {
		it2--; // CUIDADO que end apunta justo DESPUES del ultimo elemento
		if (*it1 != *it2) {
			palindromo = false;
		}
		it1++;
	}
	return palindromo;
}


int main() {
	list<int> l;

	for (int i = 0; i < 10; i++) l.push_back(i);

	eliminar_pares(l);

	for (int x: l) {
		cout << x << " ";
	}
	cout << endl;

	cout << ordenada_ascendente(l);
}

