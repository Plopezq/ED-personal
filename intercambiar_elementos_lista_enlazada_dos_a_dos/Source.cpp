﻿// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_linked_double.h"

// función que resuelve el problema
void resolver(ListLinkedDouble<int> &lista) {

    lista.interchange2();

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == 0)
        return false;

    int aux;
    ListLinkedDouble<int> lista;
    for (int i = 0; i < numElem; i++) {
        std::cin >> aux;
        lista.push_back(aux);
    }
    resolver(lista);

    // escribir sol
    lista.display();
    std::cout << std::endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
