// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "ListLinkedSingle.h"


// función que resuelve el problema
void resolver(ListLinkedSingle<int> &lista, int comienzo, int longitud) {

    lista.invSeg(comienzo, longitud);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    int posIniSeg;
    int longSeg;
    ListLinkedSingle<int> lista;

    std::cin >> numElem;
    if (!std::cin)
        return false;
    std::cin >> posIniSeg;
    std::cin >> longSeg;

    //lECTURA DE LA LISTA
    int aux;
    for (int i = 0; i < numElem; i++ ) {
        std::cin >> aux;
        lista.push_back(aux);
    }
    resolver(lista, posIniSeg, longSeg);

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