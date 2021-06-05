// Nombre del alumno:Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;
// función que resuelve el problema
vector<int> resolver(vector<int> dineroSobres, int numPersonas) {
    vector<int> sol;
    stack<int> pila;

    for (int i = 0; i < dineroSobres.size() - (numPersonas - 1); i ++) { //recorro el vector
        int z = 1;
        pila.push(dineroSobres[i]);
        while (z < numPersonas ) {
            if (pila.top() < dineroSobres[z + i]) {
                pila.pop();
                pila.push(dineroSobres[z + i]);
            }
            z++;
        }
        sol.push_back(pila.top());
        pila.pop();
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numSobres;
    int numPersonas; //sobres que coge
    cin >> numSobres;
    cin >> numPersonas;


    if ((numSobres == 0) && (numPersonas == 0))
        return false;
    //Lectura fila sobres
    vector<int> dineroSobres;
    int aux;
    for (int i = 0; i < numSobres; i++) {
        cin >> aux;
        dineroSobres.push_back(aux);
    }

    vector<int> sol = resolver(dineroSobres, numPersonas);

    // escribir sol
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
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
