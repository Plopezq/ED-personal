
#include<unordered_map>
#include<map>
#include<list>
#include<string>
#include <stdexcept>

using namespace std;

class Outlet {
public:

	Outlet() : ventas({ { },0 }) { };

	void an_oferta(const string &producto, const int &unidades) {
		if (ofertas.count(producto)) {//existe ya el producto o numUnidades es negativo
			throw domain_error("Ya existe el producto");
		}
		else if (unidades <= 0) {
			throw domain_error("Ya existe el producto");
		}
		//calculos
		ofertas[producto].numUnidadesOfertadas = unidades;
	}

	void pon_en_espera(const string& cliente, const string& producto) {
		infoProducto& info = buscarProducto(producto);//busco producto en ofertas
			// si existe el producto en las ofertas
		if (clientes.count(cliente)) { // si existe el cliente
			auto it_cliente = clientes.find(cliente);
			auto it_producto_cliente = it_cliente->second.find(producto); //busco si el cliente quiere el producto
			if (it_producto_cliente == it_cliente->second.end()) { //No esta esperando a ese producto
				ofertas[producto].esperaClientes.push_back(cliente);
				clientes[cliente][producto] = --ofertas[producto].esperaClientes.end();
			}
		}
		else {
			//no existe el 
			ofertas[producto].esperaClientes.push_back(cliente);
			clientes[cliente][producto] = --ofertas[producto].esperaClientes.end();
		}


	}
	void cancela_espera(const string& cliente, const string& producto) {

		auto it_cliente = clientes.find(cliente);
		if (it_cliente == clientes.end()) {
			throw domain_error("No existe el cliente");
		}
		auto it_cliente_producto = it_cliente->second.find(producto);
		if (it_cliente_producto == it_cliente->second.end()) {
			throw domain_error("No esta en la espera");
		}
		else {//si existe, y esta esperando
			ofertas[producto].esperaClientes.erase(it_cliente_producto->second);
		}

	}
	int num_en_espera(const string& producto){
		return ofertas[producto].esperaClientes.size();
	}

	void venta(const string& producto, const int& unidades) {
		infoProducto& info = buscarProducto(producto);		
		if (info.numUnidadesOfertadas < unidades) {
			throw domain_error("No quedan existencias");
		}
		string cliente = primero_en_espera(producto);
		ventas[producto] += unidades;
		info.numUnidadesOfertadas -= unidades;
		if (info.numUnidadesOfertadas == 0) {
			//eliminamos el producto ofertado
			ofertas.erase(producto);
		}
		//eliminar el clinete de la lista de espera
		info.esperaClientes.pop_front();
		clientes[cliente].erase(producto);
	}

	string primero_en_espera(const string& producto) {
		return ofertas[producto].esperaClientes.front();
	}

	list<pair<string, int>> lista_ventas() {
		list<pair<string, int>> resul;

		for (auto[k, v] : ventas) {
			resul.push_back({k,v});
		}
		return resul;
	}




private:
	struct infoProducto {
		int numUnidadesOfertadas;
		list<string> esperaClientes;
	};

	//producto
	unordered_map<string, infoProducto> ofertas;
	//cliente	producto-iterador a la cola de espera
	unordered_map<string, unordered_map<string, list<string>::iterator>> clientes;

	//producto, ventas
	map<string, int> ventas;

	infoProducto& buscarProducto(const string& producto) {
		auto it_producto = ofertas.find(producto);
		if (it_producto == ofertas.end()) {
			throw domain_error("producto no existente");
		}
		return it_producto->second;
	}
};