
// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include "settree.h"


using namespace std;

// función que resuelve el problema
pair<bool, int>  resolver(const SetTree<int> &conjunto,const int &aux) {

    pair<bool, int> sol = conjunto.lower_bound(aux);
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElem;
    cin >> numElem;
    if (numElem == 0)
        return false;

    SetTree<int> conjunto;
    int aux;
    for (int i = 0; i < numElem; i++) {
        cin >> aux;
        conjunto.insert(aux);
    }
    int preguntas;
    cin >> preguntas;
    int aux2;
    for (int i = 0; i < preguntas; i++) {
        cin >> aux2;
        pair<bool, int> sol = resolver(conjunto, aux2);

        if (sol.first) {
            cout << sol.second << endl;
        }
        else {
            cout << "NO HAY" << endl;
        }
    }
    cout << "---" << endl;


    return true;

}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
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