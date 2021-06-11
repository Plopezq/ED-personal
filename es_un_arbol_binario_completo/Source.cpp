#include<utility>
#include<iostream>
#include <fstream>
#include "bintree.h"

using namespace std;




template<typename T>
pair<bool, int> es_completo_auxiliar(const BinTree<T>& a) {
//devuelve si es completo y la altura
    if (a.empty()) {
        return { true, 0 };
    }
    else {
        auto [es_completo_izq, altura_izq] = es_completo_auxiliar(a.left());
        auto [es_completo_der, altura_der] = es_completo_auxiliar(a.right());


        bool es_completo = es_completo_izq && es_completo_der
            && altura_izq == altura_der;
        int altura = 1 + max(altura_izq, altura_der);

        return {es_completo, altura};
    }
}

template<typename T>
bool es_completo(const BinTree<T> &a) {
    return es_completo_auxiliar(a).first;
}
void tratar_caso() {
	BinTree<char> t = read_tree<char>(cin);
	cout << (es_completo(t) ? "SI" : "NO") << endl;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        tratar_caso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}










