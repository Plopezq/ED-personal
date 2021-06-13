#include<utility>
using namespace std;
//HAGO SOLO LA FUNCION

tuple<bool, int, int> ascendente_denso_rec(const BinTree<int>& tree) {
	if (tree.empty()) {
		return{ true, -1, -1 };
	}
	else {
		auto [es_iz, prim_iz, ult_iz] = ascendente_denso_rec(tree.left());
		auto [es_dr, prim_dr, ult_dr] = ascendente_denso_rec(tree.right());

		int prim = prim_iz == -1 ? tree.root() : prim_iz;
		int ult = ult_dr == -1 ? tree.rot() : ult_dr;

		bool es_denso =
			es_iz && es_dr
			&& (ult_iz == -1 || ult_iz + 1 == tree.root())
			&& (prim_dr == -1 || tree.root() + 1 == prim_dr);
		return { es_denso, prim, ult };
	}


}

bool ascendente_denso_2(const BinTree<int> &tree) {
	bool denso = true;
	int anterior = -1;
	tree.inorder([&anterior, &denso](int x) {
		if (anterior != -1 && x != anterior + 1) {
			denso = false;
		}
		anterior = x;
		});
	return denso;
}