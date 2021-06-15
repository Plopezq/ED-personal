#include<fstream>


class Fecha {
public:
	//CONSTRUCTORES
	Fecha() : dia(0), hora(0), minuto(0) { }
	Fecha(int dia, int hora, int minuto): dia(dia), hora(hora), minuto(minuto) { }

	int get_dia()const { return dia;  }
	int get_hora()const { return hora; }
	int get_minuto()const { return minuto;  }


	bool operator<(const Fecha& other) const {
		return (dia < other.dia) 
			|| (dia == other.dia && hora < other.hora)
			|| (dia == other.dia && hora == other.hora && minuto < other.minuto);
	}

private:
	int dia, hora, minuto;

	//friend istream& operator>>(istream& is, Fecha& d);


};