#ifndef SETONNODES_H
#define SETONNODES_H

#include <string>

struct Node {
    int value;
    Node* next;
};

Node* create_empty_set();
bool empty_check(Node* set);
bool check_element(Node* set, int value);
Node* add_element(Node* set, int value);
Node* create_set(int count, int min, int max);
int set_size(Node* set);
std::string create_string_from_set(Node* set, const char* divider);
Node* delete_set(Node* set);
bool check_subset(Node* A, Node* B);
bool equality_set(Node* A, Node* B);
Node* set_union(Node* A, Node* B);
Node* set_intersection(Node* A, Node* B);
Node* set_difference(Node* A, Node* B);
Node* set_symmetrical_difference(Node* A, Node* B);

#endif