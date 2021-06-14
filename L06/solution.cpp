/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */
 
 
/*
 * MUY IMPORTANTE: Para realizar este ejercicio solo podéis
 * modificar el código contenido entre las etiquetas <answer>
 * y </answer>. Toda modificación fuera de esas etiquetas no será
 * corregida.
 *
 * Tampoco esta permitido modificar las líneas que contienen
 * las etiquetas <answer> y </answer>, obviamente :-)
 */

//@ <answer>
/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1: Pablo Lopez Martin
 *
 */
//@ </answer>


#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <utility>


// Clase para representar árboles binarios.
// No es posible modificar esta clase para la práctica.

template <class T> class BinTree {
public:
  BinTree() : root_node(nullptr) {}

  BinTree(const T &elem)
      : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

  BinTree(const BinTree &left, const T &elem, const BinTree &right)
      : root_node(std::make_shared<TreeNode>(left.root_node, elem,
                                             right.root_node)) {}

  bool empty() const { return root_node == nullptr; }

  const T &root() const {
    assert(root_node != nullptr);
    return root_node->elem;
  }

  BinTree left() const {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->left;
    return result;
  }

  BinTree right() const {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->right;
    return result;
  }

  void display(std::ostream &out) const { display_node(root_node, out); }

private:
  struct TreeNode;
  using NodePointer = std::shared_ptr<TreeNode>;

  struct TreeNode {
    TreeNode(const NodePointer &left, const T &elem, const NodePointer &right)
        : elem(elem), left(left), right(right) {}

    T elem;
    NodePointer left, right;
  };

  NodePointer root_node;

  static void display_node(const NodePointer &root, std::ostream &out) {
    if (root == nullptr) {
      out << ".";
    } else {
      out << "(";
      display_node(root->left, out);
      out << " " << root->elem << " ";
      display_node(root->right, out);
      out << ")";
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const BinTree<T> &tree) {
  tree.display(out);
  return out;
}

template <typename T> BinTree<T> read_tree(std::istream &in) {
  char c;
  in >> c;
  if (c == '.') {
    return BinTree<T>();
  } else {
    assert(c == '(');
    BinTree<T> left = read_tree<T>(in);
    T elem;
    in >> elem;
    BinTree<T> right = read_tree<T>(in);
    in >> c;
    assert(c == ')');
    BinTree<T> result(left, elem, right);
    return result;
  }
}


using namespace std;


// ----------------------------------------------------------------
// Define aquí la función pedida en el enunciado.
// Puedes definir las funciones auxiliares que necesites, pero siempre
// entre las marcas <answer> y </answer>

//@ <answer>

//devuelve DIAMETRO-ALTURA-MAX-HITOS
pair<int, int>diam_altura(const BinTree<int>& montanya) {
    if (montanya.empty()) return { 0,0 };

    else {
        auto [diam_izq, alt_izq] = diam_altura(montanya.left());
        auto [diam_der, alt_der] = diam_altura(montanya.right());

        int diam = alt_izq + alt_der + 1;
        int alt = max(alt_izq, alt_der) + 1;

        return { max(diam_izq, max(diam_der, diam)), alt };
    }
}

int max_hitos_visitados(const BinTree<int>& montanya) {

    auto [dia_izq, alt_izq]  = diam_altura(montanya.left());
    auto [dia_der, alt_der]  = diam_altura(montanya.right());

    int dia = alt_izq + alt_der + 1;

    return max(dia_izq, max(dia_der, dia));

}

// Indica aquí el coste del algoritmo y las recurrencias planteadas en
// el caso del árbol equilibrado, y en el caso del árbol degenerado.


//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------


bool tratar_caso() {
  BinTree<int> arbol = read_tree<int>(cin);
  if (arbol.empty()) return false;
  cout << max_hitos_visitados(arbol) << endl;
  return true;
}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso()) { }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif

  return 0;
}