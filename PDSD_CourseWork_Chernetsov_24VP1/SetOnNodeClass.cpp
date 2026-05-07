#include "SetOnNodeClass.h"
#include <cstdlib>
#include <string>
#include <cstring>
#include <ctime>

SetOnNodeClass::SetOnNodeClass() {
    head = nullptr;
}

SetOnNodeClass::SetOnNodeClass(const SetOnNodeClass& A) {
    head = nullptr;
    Node* current = A.head;
    while (current != nullptr) {
        head = add_element(current->value);
        current = current->next;
    }
}

SetOnNodeClass::~SetOnNodeClass() {
    delete_set();
}

bool SetOnNodeClass::empty_check() {
    return head == nullptr;
}

bool SetOnNodeClass::check_element(int value) {
    if (empty_check()) return false;
    Node* current = head;
    while (current != nullptr) {
        if (current->value == value) return true;
        current = current->next;
    }
    return false;
}

SetOnNodeClass::Node* SetOnNodeClass::add_element(int value) {
    if (check_element(value)) return head;
    Node* new_node = new Node;
    new_node->next = head;
    new_node->value = value;
    head = new_node;
    return head;
}

SetOnNodeClass::Node* SetOnNodeClass::create_set(int count, int min, int max) {
    if ((max - min + 1) < count) return nullptr;
    delete_set();
    Node* previous;
    while (count) {
        int random_val = (rand() << 15) | rand();
        int value = min + (random_val % static_cast<int>(max - min + 1));
        previous = head;
        head = add_element(value);
        if (previous != head) count--;
    }
    return head;
}

int SetOnNodeClass::set_size() {
    int length = 0;
    Node* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

std::string SetOnNodeClass::create_string_from_set(const char* divider) {
    if (empty_check()) return "";
    std::string result = "";
    Node* temp = head;
    while (temp != nullptr) {
        result += std::to_string(temp->value);
        result += divider;
        temp = temp->next;
    }
    result.erase(result.size() - strlen(divider));
    return result;
}

SetOnNodeClass::Node* SetOnNodeClass::delete_set() {
    if (empty_check()) return nullptr;
    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        delete current;
    }
    return head;
}

bool SetOnNodeClass::check_subset(SetOnNodeClass& B) {
    if (empty_check()) return true;
    if (!empty_check() && B.empty_check()) return false;
    if (set_size() > B.set_size()) return false;
    Node* temp = head;
    while (temp != nullptr) {
        if (!B.check_element(temp->value)) return false;
        temp = temp->next;
    }
    return true;
}

bool SetOnNodeClass::equality_set(SetOnNodeClass& B) {
    return check_subset(B) && B.check_subset(*this);
}

SetOnNodeClass SetOnNodeClass::set_union(SetOnNodeClass B) {
    SetOnNodeClass result;
    Node* temp = head;
    while (temp != nullptr) {
        result.head = result.add_element(temp->value);
        temp = temp->next;
    }
    temp = B.head;
    while (temp != nullptr) {
        result.head = result.add_element(temp->value);
        temp = temp->next;
    }
    return result;
}

SetOnNodeClass SetOnNodeClass::set_intersection(SetOnNodeClass B) {
    SetOnNodeClass result;
    if (empty_check() || B.empty_check()) return result;
    Node* temp = head;
    while (temp != nullptr) {
        if (B.check_element(temp->value)) {
            result.head = result.add_element(temp->value);
        }
        temp = temp->next;
    }
    return result;
}

SetOnNodeClass SetOnNodeClass::set_difference(SetOnNodeClass B) {
    SetOnNodeClass result;
    if (empty_check()) return result;
    Node* temp = head;
    while (temp != nullptr) {
        if (!B.check_element(temp->value)) {
            result.head = result.add_element(temp->value);
        }
        temp = temp->next;
    }
    return result;
}

SetOnNodeClass SetOnNodeClass::set_symmetrical_difference(SetOnNodeClass B) {
    return set_union(B).set_difference(set_intersection(B));
}