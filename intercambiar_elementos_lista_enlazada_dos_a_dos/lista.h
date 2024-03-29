/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Inform�tica
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

 /*
  * Implementaci�n del TAD Lista mediante listas enlazadas dobles.
  *
  * Esta versi�n a�ade los atributos last y num_elems para obtener
  * implementaciones m�s eficientes.
  */

#ifndef __LIST_LINKED_DOUBLE_H
#define __LIST_LINKED_DOUBLE_H

#include <cassert>
#include <iostream>
#include <string>

class ListLinkedDouble {
private:
    struct Node {
        std::string value;
        Node* next;
        Node* prev;
    };

public:
    ListLinkedDouble() : num_elems(0) {
        head = new Node;
        head->next = nullptr;
        head->prev = nullptr;
        last = head;
    }

    ~ListLinkedDouble() { delete_list(head); }

    ListLinkedDouble(const ListLinkedDouble& other);

    void interchange2();

    void push_front(const std::string& elem) {
        Node* new_node = new Node{ elem, head->next, head };
        if (head->next != nullptr) {
            head->next->prev = new_node;
        }
        head->next = new_node;
        if (last == head) {
            last = new_node;
        }
        num_elems++;
    }

    void push_back(const std::string& elem) {
        Node* new_node = new Node{ elem, nullptr, last };
        last->next = new_node;
        last = new_node;
        num_elems++;
    }

    void pop_front() {
        assert(num_elems > 0);
        Node* target = head->next;
        head->next = target->next;
        if (target->next != nullptr) {
            target->next->prev = head;
        }
        if (last == target) {
            last = head;
        }
        delete target;
        num_elems--;
    }

    void pop_back() {
        assert(num_elems > 0);
        Node* target = last;
        target->prev->next = nullptr;
        last = target->prev;
        delete target;
        num_elems--;
    }

    int size() const { return num_elems; }

    bool empty() const { return (num_elems == 0); };

    const std::string& front() const {
        assert(num_elems > 0);
        return head->next->value;
    }

    std::string& front() {
        assert(num_elems > 0);
        return head->next->value;
    }

    const std::string& back() const {
        assert(num_elems > 0);
        return last->value;
    }

    std::string& back() {
        assert(num_elems > 0);
        return last->value;
    }

    const std::string& at(int index) const {
        assert(0 <= index && index < num_elems);
        Node* result_node = nth_node(index);
        return result_node->value;
    }

    std::string& at(int index) {
        assert(0 <= index && index < num_elems);
        Node* result_node = nth_node(index);
        return result_node->value;
    }

    void display(std::ostream& out) const;

    void display() const { display(std::cout); }

private:
    Node* head;
    Node* last;
    int num_elems;

    void delete_list(Node* start_node);
    Node* nth_node(int n) const;
};

ListLinkedDouble::ListLinkedDouble(const ListLinkedDouble& other)
    : ListLinkedDouble() {
    Node* current_other = other.head->next;

    while (current_other != nullptr) {
        Node* new_node = new Node{ current_other->value, nullptr, last };
        last->next = new_node;

        last = new_node;
        current_other = current_other->next;
    }
    num_elems = other.num_elems;
}

void ListLinkedDouble::delete_list(Node* start_node) {
    if (start_node != nullptr) {
        delete_list(start_node->next);
        delete start_node;
    }
}

ListLinkedDouble::Node* ListLinkedDouble::nth_node(int n) const {
    int current_index = 0;
    Node* current = head->next;

    while (current_index < n && current != nullptr) {
        current_index++;
        current = current->next;
    }

    return current;
}

void ListLinkedDouble::display(std::ostream& out) const {
    out << "[";
    if (head->next != nullptr) {
        out << head->next->value;
        Node* current = head->next->next;
        while (current != nullptr) {
            out << ", " << current->value;
            current = current->next;
        }
    }
    out << "]";
}

void ListLinkedDouble::interchange2() {
    //CUIDADO QUE ESTA ES UNA LISTA CIRCULAR


    //Tratar casos especiales
    //0 elementos -> por definicion simepre hay almenos 1


    //2 o mas 
    Node* first = this->head->next; //por el nodo fantasma
    Node* second = first->next;
    while (first->next != nullptr)
    {
        Node* old_prev = first->prev; //En la primera iteracion, old_prev sera el nodo fantasma

        if (second->next != nullptr) { //No es el final
            first->next = second->next;
            first->next->prev = first;
            //first->prev = second;

            second->next = first;
            second->next->prev = second;

            second->prev = old_prev;
            old_prev->next = second;


            //second->prev = old_prev;

            first = first->next;
            second = first->next;
        }
        else {// es el final
            first->next = nullptr;
            first->prev = second;


            second->prev = old_prev;
            old_prev->next = second;
            second->next = first;
            //first->next->prev = first;
        }

    }
}
#endif