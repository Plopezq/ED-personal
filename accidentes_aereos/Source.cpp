// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <utility>
#include <vector>
#include <stack>


// función que resuelve el problema
void resolver(std::vector<std::pair<std::string, int>> vector) {
    std::stack<std::pair<std::string, int>> pila; //pila de los accidentes
    //pila.push(vector[0]);
    for (int i = 0; i < vector.size(); i++) //recorremos el vector
    {
        pila.push(vector[i]); //accidente a tratar
        while (!pila.empty() && (pila.top().second <= vector[i].second) ) //bucle while para la pila
        {
            //elimino de la pila
            pila.pop();
        }
        // escribir sol
        if (pila.empty()) {
            std::cout << "NO HAY" << std::endl;
        }
        else {
            std::cout << pila.top().first << std::endl; //fecha que tiene que ser
        }
        pila.push(vector[i]); //accidente a tratar
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numCasos;
    std::cin >> numCasos;
    if (!std::cin)
        return false;
    std::vector<std::pair<std::string, int>> vector;

    for (int i = 0; i < numCasos; i++) {
        std::pair<std::string, int> datos;
        std::cin >> datos.first;
        std::cin >> datos.second;
        vector.push_back(datos);
    }

    resolver(vector);

    std::cout << "---" << std::endl;

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