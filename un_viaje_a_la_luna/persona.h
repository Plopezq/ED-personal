#include <string>


class Persona {

public:
	Persona(){
		edad = 0;
		nombre = "";
	}; //constructor 

	std::string getNombre() {
		return this->nombre;
	}
	void setNombre(std::string nom) {
		this->nombre = nom;
	}
	int getEdad() {
		return this->edad;
	}
	void setEdad(int edad) {
		this->edad = edad;
	}

private:

	int edad;
	std::string nombre;
};