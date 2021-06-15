// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "header.h"


using namespace std;

// función que resuelve el problema
pair<int, int> resolver(const BinTree<char> &arbol) {
    //altura sin raiz, altura con raiz
    if (arbol.empty()) {
        return {0,0};
    }
    else {
        auto [alt_izq, alt_min_izq] = resolver(arbol.left());
        auto [alt_der, alt_min_der] = resolver(arbol.right());
        
        int altura = max(alt_izq, alt_der);
        int altura_con = 1 + min(alt_min_izq, alt_min_der);

        int altura2 = max(altura, altura_con);

        return{ altura2 , altura_con };
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    BinTree<char> arbol;
    arbol = read_tree<char>(cin);

    int sol = resolver(arbol).first;
    // escribir sol
    cout << sol << endl;

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