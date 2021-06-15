// Nombre del alumno: Pablo Lopez Martin
// Usuario del Juez: F36


#include <iostream>
#include <iomanip>
#include <fstream>
#include<unordered_map>
#include<set>

using namespace std;


class Autoscuela {

public:
    Autoscuela() {}; //constructora vacia


    //METODOS
    void alta(const string &alumno, const string &profesor) {
        //da de alta un alumno, o cambia uno existente de profesor
        if (alumnos.count(alumno) > 0) {//ya existe el alumno
            //lo cambio de profesor
            string antiguoProfesor = alumnos[alumno].profesor;
            profesores[antiguoProfesor].erase(alumno);
            alumnos[alumno].profesor = profesor;
            profesores[profesor].insert(alumno);
        }
        else {// es nuevo el alumno
            alumnos[alumno].profesor = profesor;
            profesores[profesor].insert(alumno);
        }

    }

    bool es_alumno(const string& alumno, const string& profesor) {
        if (alumnos.count(alumno) && alumnos.at(alumno).profesor == profesor) {
            return true;
        }
        else {
            return false;
        }
    }

    int puntuacion(const string& alumno) {
        if (!alumnos.count(alumno)){//no esta dado de alta con ningun profesor
            throw std::domain_error("El alumno" + alumno + "no esta matriculado");
        }
        return alumnos.at(alumno).puntuacion;
    }

    void actualizar(const string& alumno, int puntuacion) {
        if (!alumnos.count(alumno)) { //alumno no dado de alta
            throw std::domain_error("El alumno " + alumno + " no esta matriculado");
        }
        //AQUI el alumno si esta dado de alta
        alumnos[alumno].puntuacion = alumnos[alumno].puntuacion + puntuacion;
        /*
        //OTRA OPCION
        auto itera = alumnos.find(alumno);
        if (itera == alumnos.end()) { //alumno no dado de alta
            throw std::domain_error("El alumno " + alumno + " no esta matriculado");
        }
        itera->second.puntuacion += puntuacion;
        */
    }

    vector<string> examen(const string& profesor, int minimo_puntos) {
        //sacar los alumnos del profesor que tengan una puntuacion mayor o igual a minimo_puntos
        vector<string> resul;
        auto iter_prof = profesores.find(profesor);
        if (iter_prof == profesores.end()) { //El profesor no existe
            return resul;
        }
        else {//le saco los alumnos
            for (const string &alumno : iter_prof->second) {
                if (alumnos.at(alumno).puntuacion >= minimo_puntos) {
                    resul.push_back(alumno);
                }
            }
        }
        return resul;
    }

    void aprobar(const string& alumno) {
        if (alumnos.count(alumno)) {//el alumno no esta dado de alta
            throw std::domain_error("El alumno " + alumno + "no esta matriculado");
        }
        else {//lo borramos
            string profAlumno = alumnos.at(alumno).profesor;
            alumnos.erase(alumno);
            profesores.at(profAlumno).erase(alumno);
        }

    }

private: 
    struct infoAlumno {
        int puntuacion;
        string profesor;
        infoAlumno() : puntuacion(0), profesor("") { }
    };
    unordered_map<string, infoAlumno> alumnos;
    unordered_map<string, set<string>> profesores;
};





// función que resuelve el problema
TipoSolucion resolver(TipoDatos datos) {



}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    if (caso especial)
        return false;

    TipoSolucion sol = resolver(datos);

    // escribir sol

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
