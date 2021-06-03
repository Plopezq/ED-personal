// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "ListLinkedSingle.h"

// función que resuelve el problema
void resolver(ListLinkedSingle<int> &lista, ListLinkedSingle<int> &other) {
    //Duplicar elementos de la lista 1 a 1
    lista.merge(other);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    ListLinkedSingle<int> lista1;
    int aux;
    std:: cin >> aux;
    while (aux != 0) {
        lista1.push_back(aux);
        std:: cin >> aux;
    }
    ListLinkedSingle<int> lista2;
    aux;
    std::cin >> aux;
    while (aux != 0) {
        lista2.push_back(aux);
        std::cin >> aux;
    }

    resolver(lista1, lista2);
    // escribir sol
    lista1.display();
    //lista2.display();
    std::cout << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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