
#include<list>
#include <string>
#include<vector>
#include<unordered_map>



using namespace std;


class Supermercado {
	//CONSTRUCTORES
	Supermercado(int numCajas): colas(numCajas){ }//inicializamos el vector

public:
	void nuevo_cliente(const string& cod_cliente, const int& num_cola) {
		//comprobaciones


		colas[num_cola].push_front(cod_cliente);
		clientes[cod_cliente] = num_cola;
	}

	void cambiar_cola(const string& cod_cliente, const int& num_cola) {
		//comprobaciones
		auto cli = clientes.find(cod_cliente);
		int colaActual = cli->second;
		if (colaActual != num_cola) {
			list<string>& cola = colas[colaActual];
			auto it = find(cola.begin(), cola.end(), cod_cliente);
			cola.erase(it);
			colas[num_cola].push_front(cod_cliente);
		}

	}

	int consultar_cliente(const string& cod_cliente) {
		//comprobaciones
		return clientes[cod_cliente];
	}

	int cuantos_en_cola(const int& num_cola) {

	}

	vector<string> clientes_en_cola(const int& num_cola) {


	}

private:
	struct infoCliente {
		int numCola;
		list<string>::iterator it_cola;

		infoCliente(int num_cola) : numCola(num_cola) {}
	};
	vector<list<string>> colas;//un array de tamanyo el numero de colas/cajas
	unordered_map<string, int> clientes;
};