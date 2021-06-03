// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "ListLinkedSingle.h"

// función que resuelve el problema
void resolver(ListLinkedSingle<int> &lista) {
    //Duplicar elementos de la lista 1 a 1

    lista.duplicate();

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    ListLinkedSingle<int> lista;
    int aux;
   std:: cin >> aux;
    while (aux != 0) {
        lista.push_back(aux);
       std:: cin >> aux;
    }

    resolver(lista);
    // escribir sol
    lista.display();
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