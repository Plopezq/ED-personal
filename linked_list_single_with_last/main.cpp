
#include <cassert>
#include <iostream>
#include <string>

class ListLinkedSingle {
private:
    struct Node {
        std::string value;
        Node* next;
    };

public:
    ListLinkedSingle() : head(nullptr), last(nullptr){ }

    ~ListLinkedSingle() {
        delete_list(head);
        last = nullptr;
    }

    ListLinkedSingle(const ListLinkedSingle& other)
        : head(copy_nodes(other.head)) { 
        last = last_node();
        if (head != nullptr) { //La lista no es unitaria o esta vacia
            last = last_node();
        }
        else { //La lista es unitaria o esta vacia
            last = nullptr;
        }
    }

    void push_front(const std::string& elem) {
        Node* new_node = new Node{ elem, head };
        head = new_node;
        if (last == nullptr) { //Si la lista estaba vacia, ahora ya tiene 1 elemento
            last = new_node;
        }
    }

    void push_back(const std::string& elem);

    void pop_front() {
        assert(head != nullptr);
        Node* old_head = head;
        head = head->next;
        delete old_head;
    }

    void pop_back();

    int size() const;

    bool empty() const {
        return head == nullptr;
    };

    const std::string& front() const {
        assert(head != nullptr);
        return head->value;
    }

    std::string& front() {
        assert(head != nullptr);
        return head->value;
    }

    const std::string& back() const {
        assert(last != nullptr);
        return last->value;
    }

    std::string& back() {
        assert(last != nullptr);
        return last->value;
    }

    const std::string& at(int index) const {
        Node* result_node = nth_node(index);
        assert(result_node != nullptr);
        return result_node->value;
    }

    std::string& at(int index) {
        Node* result_node = nth_node(index);
        assert(result_node != nullptr);
        return result_node->value;
    }

    void display(std::ostream& out) const;
    void display() const {
        display(std::cout);
    }

private:
    Node* head;
    Node* last;

    void delete_list(Node* start_node);
    Node* last_node() const;
    Node* nth_node(int n) const;
    Node* copy_nodes(Node* start_node) const;

};

ListLinkedSingle::Node* ListLinkedSingle::copy_nodes(Node* start_node) const {
    if (start_node != nullptr) {
        Node* result = new Node{ start_node->value, copy_nodes(start_node->next) };
        return result;
    }
    else {
        return nullptr;
    }
}

void ListLinkedSingle::delete_list(Node* start_node) {
    if (start_node != nullptr) {
        delete_list(start_node->next);
        delete start_node;
    }
}

void ListLinkedSingle::push_back(const std::string& elem) {
    Node* new_node = new Node{ elem, nullptr };
    if (head == nullptr) {
        head = new_node;
    }
    else {
        last->next = new_node;
        last = new_node;
    }
}

void ListLinkedSingle::pop_back() {
    assert(head != nullptr);
    if (head->next == nullptr) { //Lista unitaria
        delete head;
        head = nullptr;
        last = nullptr;
    }
    else { //
        Node* previous = head;
        Node* current = head->next;

        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }

        delete current;
        previous->next = nullptr;
        last = previous;
    }
}

int ListLinkedSingle::size() const {
    int num_nodes = 0;

    Node* current = head;
    while (current != nullptr) {
        num_nodes++;
        current = current->next;
    }

    return num_nodes;
}


ListLinkedSingle::Node* ListLinkedSingle::last_node() const {
    //assert(head != nullptr);
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

ListLinkedSingle::Node* ListLinkedSingle::nth_node(int n) const {
    assert(0 <= n);
    int current_index = 0;
    Node* current = head;

    while (current_index < n && current != nullptr) {
        current_index++;
        current = current->next;
    }

    return current;
}

void ListLinkedSingle::display(std::ostream& out) const {
    out << "[";
    if (head != nullptr) {
        out << head->value;
        Node* current = head->next;
        while (current != nullptr) {
            out << ", " << current->value;
            current = current->next;
        }
    }
    out << "]";
}



int main() {
    return 0;
}