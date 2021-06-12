// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"


using namespace std;
tuple<bool, int, int> es_ABB(const BinTree<char>& arbol) {
    if (arbol.empty()) {//arbol vacio
        return { true, {}, {} };
    }
    else {
        auto [bin_izq, min_izq, max_izq] = es_ABB(arbol.left());
        auto [bin_der, min_der, max_der] = es_ABB(arbol.right());

        bool bin = bin_izq && bin_der &&
            (arbol.left().empty() || max_izq < arbol.root() ) &&
            (arbol.right().empty() || min_der > arbol.root());

        int min = arbol.left().empty() ? arbol.root() : min_izq;
        int max = arbol.right().empty() ? arbol.root() : max_der;

        return { bin, min, max };
    }
}

// función que resuelve el problema
bool resolver(const BinTree<char> &arbol) {

    return get<0>(es_ABB(arbol));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    BinTree<char> arbol = BinTree<char>();
    arbol = read_tree<char>(cin);

    bool sol = resolver(arbol);
    // escribir sol
    sol == 1 ? cout << "SI" : cout << "NO";
    cout << endl;

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