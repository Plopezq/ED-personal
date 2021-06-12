

// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

using namespace std;


pair<bool, int> es_zurdo(const BinTree<char>& tree) {
    //devuelve si es zurdo, y numNodos de ese arbol
    if (tree.empty()) {//es un arbol vacio -> es zurdo
        return { true, 0 };
    }
    else if(tree.left().empty() && tree.right().empty()){//es una hoja --> es zurdo
        return { true, 1 };
    }
    else {
        auto [esz_izq, num_nodos_izq] = es_zurdo(tree.left());
        auto [esz_der, num_nodos_der] = es_zurdo(tree.right());

        bool zurdo = esz_izq && esz_der &&
            num_nodos_izq > num_nodos_der;
        int numNodos = 1 + num_nodos_izq + num_nodos_der;

        return {zurdo, numNodos};
    }
}



// función que resuelve el problema
bool resolver(const BinTree<char> arbol) {
    pair<bool, int> sol = es_zurdo(arbol);
    return sol.first;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    BinTree<char> arbol = BinTree<char>();
    arbol = read_tree<char>(cin);


    bool sol = resolver(arbol);
    // escribir sol
    if (sol) {
        cout << "SI" << endl;
    }
    else {
        cout << "NO" << endl;
    }

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