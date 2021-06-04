/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

 /*
  * Introduce el nombre y apellidos de los/as componentes del grupo:
  *
  * Estudiante 1: Pablo Lopez Martin
  * Estudiante 2:
  *
  */

#include <iostream>
#include <cassert>
#include <fstream>

const int GRADO_MAX = 10000;

  /* Define la clase 'Polinomio' aquí */
class Polinomio {
public:
	Polinomio() :coeficientes() {};
	void anyadir_monomio(int coef, int exp);
	long evaluar(int valor) const;

private:
	int coeficientes[GRADO_MAX + 1];
};

bool tratar_caso() {


}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

	while (tratar_caso()) {}

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
	return 0;
}