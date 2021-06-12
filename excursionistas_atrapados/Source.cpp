// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F-36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree.h"
using namespace std;


template <typename T>
pair<int, int> aux(const BinTree<T>& arbol) {
    //devuelve num_equipos necesarios para el rescate y maximo de rescatados por un solo equipo
    if (arbol.empty()) { //es vacio
        return {0, 0};
    }
    else{
        auto [n_equipos_izq, max_rescatados_izq] = aux(arbol.left());
        auto [n_equipos_der, max_rescatados_der] = aux(arbol.right());

        if (arbol.root() == 0) {
            return { n_equipos_izq + n_equipos_der, max(max_rescatados_izq, max_rescatados_der) };
        }
        else {
            if (n_equipos_izq == 0 && n_equipos_der == 0) {
                return { 1, arbol.root() }; //Sale un equipo ya que no hay
            }
            else {
                return { n_equipos_izq + n_equipos_der, max(max_rescatados_izq, max_rescatados_der) };
            }
        }
    }
    

}

// función que resuelve el problema
template <typename T>
pair<int, int> resolver(const BinTree<T> &arbol) {
    //devuelve num_equipos necesarios para el rescate y maximo de rescatados por un solo equipo

    return aux(arbol);

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    BinTree<char> arbol = read_tree<char>(cin);

    auto[num_equipos, max_excursionistas] = resolver(arbol);
    // escribir sol
    cout << num_equipos << " " << max_excursionistas << "\n";

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