// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>


using namespace std;


// función que resuelve el problema
int resolver(int numAlumnos, int salto) {
    queue<int> cola;
    int numAl = numAlumnos;

    for (int i = 1; i <= numAlumnos; i++) {//lleno la pila
        cola.push(i);
    }

    while (numAl > 1) {
        for (int i = 0; i < salto; i++) {
            cola.push(cola.front());
            cola.pop();
        }
        cola.pop();
        numAl--;
    }


    return cola.front();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numAlumnos;
    int salto;
    cin >> numAlumnos;
    cin >> salto;

    if (numAlumnos == 0 && salto == 0)
        return false;

    int sol = resolver(numAlumnos, salto);

    // escribir sol
    cout << sol << endl;
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
