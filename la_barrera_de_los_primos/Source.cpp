// Nombre del alumno: Pablo Lopez Martin
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
    //numero y profundidad
    if (arbol.empty()) {//arbol vacio
        return{ -1, 0 };
    }
    else if (arbol.left().empty() && arbol.right().empty()) {
        return { arbol.root(), 1 };
    }
    else {
        auto [num_izq, prof_izq] = resolver(arbol.left());
        auto [num_der, prof_der] = resolver(arbol.right());


        int num;
        int prof;
        if (prof_izq <= prof_der) {
            num = num_izq;
            prof = prof_izq + 1;
            return { num, prof };
        }
        else {
            num = num_der;
            prof = prof_der + 1;
            return { num, prof };
        }

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    BinTree<char> arbol = BinTree<char>();
    arbol = read_tree<char>(cin);

    auto [num, prof] = resolver(arbol);
    // escribir sol
    cout << num << " " << prof << endl;

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