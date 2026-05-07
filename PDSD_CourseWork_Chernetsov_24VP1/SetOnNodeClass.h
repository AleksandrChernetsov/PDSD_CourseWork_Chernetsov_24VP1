#ifndef SETONNODECLASS_H
#define SETONNODECLASS_H

#include <string>

class SetOnNodeClass {
private:
    struct Node {
        Node* next;
        int value;
    };
    Node* head;

public:
    SetOnNodeClass();
    SetOnNodeClass(const SetOnNodeClass& A);
    ~SetOnNodeClass();

    bool empty_check();
    bool check_element(int value);
    Node* add_element(int value);
    Node* create_set(int count, int min, int max);
    int set_size();
    std::string create_string_from_set(const char* divider);
    Node* delete_set();
    bool check_subset(SetOnNodeClass& B);
    bool equality_set(SetOnNodeClass& B);
    SetOnNodeClass set_union(SetOnNodeClass B);
    SetOnNodeClass set_intersection(SetOnNodeClass B);
    SetOnNodeClass set_difference(SetOnNodeClass B);
    SetOnNodeClass set_symmetrical_difference(SetOnNodeClass B);
};

#endif