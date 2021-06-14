/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */

/*
 * MUY IMPORTANTE: Para realizar este ejercicio solo podéis
 * modificar el código contenido entre las etiquetas <answer>
 * y </answer>. Toda modificación fuera de esas etiquetas no será
 * corregida.
 *
 * Tampoco esta permitido modificar las líneas que contienen
 * las etiquetas <answer> y </answer>, obviamente :-)
 */

//@ <answer>
/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1: Pablo Lopez Martin
 *
 */
//@ </answer>

#include <iostream>
#include <cassert>
#include <fstream>
#include<stack>
using namespace std;

// Puedes copiar aquí algunas de las implementaciones de los TADs vistos esta semana:

// Pilas: https://github.com/manuelmontenegro/ED-2021/blob/master/lineales/stack_array/stack_array.h
// Colas: https://github.com/manuelmontenegro/ED-2021/blob/master/lineales/queue_array/queue_array.h
// Colas dobles: https://github.com/manuelmontenegro/ED-2021/blob/master/lineales/deque/dequeue.h

// En caso de utilizar alguno de los TADs anteriores, ha de copiarse TAL CUAL, sin realizar ningún cambio
// en sus implementaciones. Para facilitar la corrección, coloca la implementación de estos TADs fuera
// de las etiquetas <answer> y </answer>. El profesor asumirá que tienen la misma implementación que la
// vista en teoría.

// Alternativamente, puedes utilizar las clases de la librería estándar de C++ (stack<T>, queue<T> y deque<T>).


// ----------------------------------------------------------------
//@ <answer>

bool tratar_caso() {
  // Completar
	int num;
	cin >> num;
	if (num == -1) return false;
	stack<int> pila;

	while (num != -1) {
		pila.push(num);
		//Para cada caso
		while (!pila.empty() && pila.top() <= num ) {
			pila.pop();
		}
		if (pila.empty()) {
			cout << "NO HAY" << endl;
		}
		else {
			cout << pila.top() << endl;
		}
		pila.push(num);

		cin >> num;
	}
	cout << "---" << endl;

	return true;
}

//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso()) { }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
#endif
  return 0;
}
