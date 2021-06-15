// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"

using namespace std;

// función que resuelve el problema
template <typename T>
T resolver(const BinTree<T> &arbol) {
    //ARBOL NO VACIO
    if (arbol.empty()) return {};
    if (arbol.left().empty() && arbol.right().empty()) {//es una hoja
        return arbol.root();
    }
    else {
        T min_izq= resolver(arbol.left());
        T min_der = resolver(arbol.right());


        return min(min_izq, min_der);
    }
}

bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    cin >> tipo;
    if (!std::cin)
        return false;

    if (tipo == 'N') {
        BinTree<int> arbol = read_tree<int>(cin);
        if (arbol.empty()) { cout << endl; }
        else {
            int sol = resolver(arbol);
            cout << sol << endl;
        }
    }
    else {//Tipo = P
        BinTree<string> arbol = read_tree<string>(cin);
        if (arbol.empty()) {
            cout << endl;
        }
        else {
            string sol = resolver(arbol);
            cout << sol << endl;
        }
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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