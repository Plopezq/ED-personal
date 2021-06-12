// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

using namespace std;

// función que resuelve el problema
//Devuelve altura y diametro
pair<int, int> resolver(const BinTree<char> &arbol) {
    if (arbol.empty()) {
        return { 0,0 };
    }
    auto [camino_max_iz, altura_iz] = resolver(arbol.left());
    auto [camino_max_der, altura_der] = resolver(arbol.right());

    int camino_max = max(max(camino_max_iz, camino_max_der),
                        1 + altura_iz + altura_der);
    int altura = 1 + max(altura_iz, altura_der);


    return{camino_max, altura};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    BinTree<char> arbol = BinTree<char>();
    arbol = read_tree<char>(cin);


    pair<int, int> sol = resolver(arbol);
    // escribir sol
    cout << sol.first << endl;

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