

template <class T> class BinTree {
public:
	// ...
	bool empty() const;
	const T& root() const;
	BinTree left() const;
	BinTree right() const;
	pair<bool, int> num_nodos(BinTree arbol) const;
private:
	// ...
};

template<typename T>
bool num_nodos(const BinTree<T>& t) {
	if (t.empty()) {
		return 0;
	}
	else {
		return 1 + num_nodos(t.left()) + num_nodos(t.right());
	}
}




template<typename T>
pair<bool, int> es_zurdo(const BinTree<T>& t) {
	if (t.empty()) { //es un arbol vacio
		return {true, 0};
	}
	else if(t.left().empty() && t.right().empty()){// es una hoja
		return {true, 1};
	}
	auto [es_zurdo_izq, num_nodos_izq] = es_zurdo(t.left());
	auto [es_zurdo_der, num_nodos_der] = es_zurdo(t.right());
	return  es_zurdo_izq  && es_zurdo_der
		&& num_nodos_izq > num_nodos_der;
}
