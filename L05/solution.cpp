/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */
 
 
/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1: Pablo Lopez Martin
 *
 */

#include <iostream>
#include <fstream>
#include <list>


using namespace std;


bool es_toeplitz(const list<list<int>> &matriz) {
  // Implementar
	auto padre1 = matriz.begin();
	auto padre2 = ++matriz.begin();
	bool toeplitz = true;

	while (padre2 != matriz.end() && toeplitz) {//recorro filas
		auto hijo1 = padre1->begin();
		auto hijo2 = ++padre2->begin();
		while (hijo2 != padre2->end() && toeplitz) {
			if (*hijo1 != *hijo2) {
				toeplitz = false;
			}
			++hijo1;
			++hijo2;
		}
		++padre1;
		++padre2;
	}

	return toeplitz;
}

bool tratar_caso() {
  // Implementar
	list<list<int>> matriz;

	int num;
	cin >> num;
	if (num == 0) return false;
	while (num != 0) {//filas
		list<int> fila;
		while (num != 0) { //elementos de las filas
			fila.push_back(num);
			cin >> num;
		}
		matriz.push_back(fila);
		cin >> num;
	}

	bool sol = es_toeplitz(matriz);

	if (sol) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return true;
}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso()) { }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif

  return 0;
}