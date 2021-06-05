// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include "persona.h"
#include "lista.h"


using namespace std;
// función que resuelve el problema
void resolver(ListLinkedSingle<Persona> &listaPersonas, int edadMin, int edadMax) {

    //CREAR FUNCION LAMBDA
    
    //LLAMAR A REMOVE_IF DE LISTA
    listaPersonas.remove_if([edadMin, edadMax](int edad) { return ( (edad >= edadMin) && (edad <= edadMax) ); });


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numIncritos;
    int edadMin;
    int edadMax;
    cin >> numIncritos;
    cin >> edadMin;
    cin >> edadMax;

    if ((numIncritos == 0)&&(edadMin == 0)&&(edadMax == 0))
        return false;

    int edad;
    string nombre;
    ListLinkedSingle<Persona> listaPersonas;
    for (int i = 0; i < numIncritos; i++) {
        Persona p;
        cin >> edad;
        getline(cin, nombre);
        p.setEdad(edad);
        p.setNombre(nombre);

        listaPersonas.push_back(p);
    }

    resolver(listaPersonas, edadMin, edadMax);

    // escribir sol
    for (int i = 0; i < listaPersonas.size(); i++) {
        cout << listaPersonas[i].getNombre() << endl;
    }
    cout << "---" << endl;
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
