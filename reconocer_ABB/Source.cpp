using namespace std;

#include "bintree.h"

template<typename T>
tuple<bool, int, int> bynary_search_tree_rec(const BinTree<T> &tree) {
	if (tree.empty()) {
		return{ true, {} , {} };
	}
	else {
		auto [bst_iz, min_iz, max_iz] = binary_search_tree_rec(tree.left());
		auto [bst_dr, min_dr, max_dr] = binary_search_tree_rec(tree.right());

		bool bst = bst_iz && bst_dr 
			&& (tree.left.empty() || max_iz <= tree.root() )
			&& (tree.right().empty() || tree.root() < min_dr);


		int min = tree.left().empty() ? tree.root() : min_iz;
		int max = tree.right().empty() ? tree.root() : max_dr;

		return { bst, min, max };
	}
}