// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

// función que resuelve el problema
string resolver(string frase) {

    queue<char> cola;
    stack<char> pila;
    //PRIMERA FASE
    for (int i = 0; i < frase.length(); i += 2) {
        cola.push(frase[i]);
        pila.push(frase[i + 1]);
    }
    if (frase.length() % 2 != 0) {//Si es impar el tamanyo de la frase
        pila.pop();
    }
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }

    //Ya solo queda intercambiar las vocales
    string resultado = "";
    stack<char> aux;
    while (!cola.empty()) {
        //Intercambiar las consonantes
        if (cola.front() == 'a' || cola.front() == 'e' || cola.front() == 'i' || cola.front() == 'o' || cola.front() == 'u' ||
            cola.front() == 'A' || cola.front() == 'E' || cola.front() == 'I' || cola.front() == 'O' || cola.front() == 'U') {
            //SON VOCAL, se meten al string

            while (!aux.empty()) {//Anyado las consonantes en orden ya correcto
                resultado += aux.top();
                aux.pop();
            }
            resultado += cola.front();
            cola.pop();
        }
        else {
            aux.push(cola.front());
            cola.pop();
        }

    }

    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string str;
    std::getline(std::cin, str);

    if (!std::cin)
        return false;

    string sol = resolver(str);

    // escribir sol
    cout << sol << endl;

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