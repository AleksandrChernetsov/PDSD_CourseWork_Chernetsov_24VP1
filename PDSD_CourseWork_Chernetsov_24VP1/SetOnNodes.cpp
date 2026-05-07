#include "SetOnNodes.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>

Node* create_empty_set() {
    return nullptr;
}

bool empty_check(Node* set) {
    return set == nullptr;
}

bool check_element(Node* set, int value) {
    if (empty_check(set)) return false;
    Node* current = set;
    while (current != nullptr) {
        if (current->value == value) return true;
        current = current->next;
    }
    return false;
}

Node* add_element(Node* set, int value) {
    if (check_element(set, value)) return set;
    Node* new_node = new Node;
    new_node->next = set;
    new_node->value = value;
    return new_node;
}

Node* create_set(int count, int min, int max) {
    if ((max - min + 1) < count) return nullptr;
    Node* set = create_empty_set();
    Node* previous;
    while (count) {
        int random_val = (rand() << 15) | rand();
        int value = min + (random_val % static_cast<int>(max - min + 1));
        previous = set;
        set = add_element(set, value);
        if (previous != set) count--;
    }
    return set;
}

int set_size(Node* set) {
    int length = 0;
    while (set != nullptr) {
        length++;
        set = set->next;
    }
    return length;
}

std::string create_string_from_set(Node* set, const char* divider) {
    if (empty_check(set)) return "";
    std::string result = "";
    while (set != nullptr) {
        result += std::to_string(set->value);
        result += divider;
        set = set->next;
    }
    result.erase(result.size() - strlen(divider));
    return result;
}

Node* delete_set(Node* set) {
    if (empty_check(set)) return nullptr;
    while (set != nullptr) {
        Node* current = set;
        set = set->next;
        delete current;
    }
    return nullptr;
}

bool check_subset(Node* A, Node* B) {
    if (empty_check(A)) return true;
    if (!empty_check(A) && empty_check(B)) return false;
    if (set_size(A) > set_size(B)) return false;
    Node* temp = A;
    while (temp != nullptr) {
        if (!check_element(B, temp->value)) return false;
        temp = temp->next;
    }
    return true;
}

bool equality_set(Node* A, Node* B) {
    return check_subset(A, B) && check_subset(B, A);
}

Node* set_union(Node* A, Node* B) {
    Node* result = create_empty_set();
    Node* temp = A;
    while (temp != nullptr) {
        result = add_element(result, temp->value);
        temp = temp->next;
    }
    temp = B;
    while (temp != nullptr) {
        result = add_element(result, temp->value);
        temp = temp->next;
    }
    return result;
}

Node* set_intersection(Node* A, Node* B) {
    Node* result = create_empty_set();
    if (empty_check(A) || empty_check(B)) return result;
    Node* temp = A;
    while (temp != nullptr) {
        if (check_element(B, temp->value)) {
            result = add_element(result, temp->value);
        }
        temp = temp->next;
    }
    return result;
}

Node* set_difference(Node* A, Node* B) {
    Node* result = create_empty_set();
    if (empty_check(A)) return result;
    Node* temp = A;
    while (temp != nullptr) {
        if (!check_element(B, temp->value)) {
            result = add_element(result, temp->value);
        }
        temp = temp->next;
    }
    return result;
}

Node* set_symmetrical_difference(Node* A, Node* B) {
    return set_difference(set_union(A, B), set_intersection(A, B));
}