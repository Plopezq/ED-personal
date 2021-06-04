// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "pila.h"


// función que resuelve el problema
bool resolver(std::string str) {
    StackArray<char> pila;

    int i = 0;
    bool equilibrado = true;


    while (i<str.length() && equilibrado) {
        switch (str[i])
        {
        case'[':
        case'{':
        case'(':
            pila.push(str[i]);
            break;
        case']':
            if (pila.empty() || pila.top() != '[') equilibrado = false;
            else pila.pop();
            break;
        case'}':
            if (pila.empty() || pila.top() != '{') equilibrado = false;
            else pila.pop();
            break;
        case')':
            if (pila.empty() || pila.top() != '(') equilibrado = false;
            else pila.pop();
            break;
        default:
            break;
        }



        i++;
    }


    if (equilibrado && !pila.empty()) equilibrado = false;


    return equilibrado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string str;

    std::getline(std::cin, str);


    if (!std::cin)
        return false;


    bool equilibrado = resolver(str);

    // escribir sol

    std::cout << (equilibrado ? "SI" : "NO") << std::endl;


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