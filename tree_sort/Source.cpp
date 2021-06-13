
using namespace std;

void tree_sort(list<T>& l) {
	SetTree<T> s;

	//relleno el tree set
	for (const T &x: s) {
		s.insert(x);
	}

	//lo paso a una lista
	auto it_lista = l.begin();
	for (const T &x : s) {
		*it_lista = x;
		++it_lista;
	}
}