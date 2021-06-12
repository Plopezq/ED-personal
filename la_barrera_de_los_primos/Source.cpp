﻿// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

using namespace std;


bool es_primo(int numero) {
    if (numero % 2 == 0) return false;
    if (numero % 3 == 0) return false;
    if (numero % 5 == 0) return false;
    if (numero % 7 == 0) return false;
    if (numero % 11 == 0) return false;
}
bool es_multiplo_7(int numero) {
    if (numero % 7 == 0) return true;

    return false;
}

// función que resuelve el problema
pair<int, int> resolver(BinTree<char> const& arbol) {

    return { -1, -1 };

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    BinTree<char> arbol = BinTree<char>();
    arbol = read_tree<char>(cin);

    cout << es_multiplo_7(21);
    //pair<int, int> sol = resolver(arbol);
    // escribir sol


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}