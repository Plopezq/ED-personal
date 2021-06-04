// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <queue>


using namespace std;
// función que resuelve el problema
queue<int> resolver(stack<int> negativos, queue<int> positivos) {
    //cola y pila
    queue<int> resul;

    while (!negativos.empty()) {
        resul.push(negativos.top());
        negativos.pop();
    }

    while (!positivos.empty()) {
        resul.push(positivos.front());
        positivos.pop();
    }


    return resul;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementos;
    cin >> numElementos;

    if (numElementos == 0)
        return false;
    stack<int> negativos;
    queue<int> positivos;
    int aux;
    for (int i = 0; i < numElementos; i++) {
        cin >> aux;
        if (aux > 0) {
            positivos.push(aux);
        }
        else {
            negativos.push(aux);
        }

    }

    queue<int> sol = resolver(negativos, positivos);

    // escribir sol
    for (int i = 0; i < numElementos; i++) {
        cout << sol.front() << " ";
        sol.pop();
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
