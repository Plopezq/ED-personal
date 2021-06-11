// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;


tuple<int, int, int> aux(const BinTree<char> &arbol) {
    //devuelve num_nodos, num_hojas y altura
    if (arbol.empty()) {//arbol vacio
        return { 0, 0, 0 };
    }
    else if (arbol.left().empty() && arbol.right().empty()) {//es una hoja
        return { 1, 1, 1 };
    }else{
        //hijo izq
        auto [num_nodos_izq, num_hojas_izq, altura_izq] = aux( arbol.left() );
        auto [num_nodos_der, num_hojas_der, altura_der] = aux( arbol.right() );
       

        //hijo der
        int numNodos = 1 + num_nodos_izq + num_nodos_der;
        int hojas = num_hojas_izq + num_hojas_der;
        int altura = 1 + max(altura_izq, altura_der);

        return {numNodos, hojas, altura};
    }
}


// función que resuelve el problema
tuple<int, int, int> resolver(const BinTree<char> &T) {
    //devuelve num_nodos, num_hojas y altura
    return aux(T);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    
    BinTree<char> T = read_tree<char>(cin);
    auto[num_nodos, num_hojas, altura] = resolver(T);
    // escribir sol
    cout << num_nodos << " " << num_hojas << " " << altura << endl;

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