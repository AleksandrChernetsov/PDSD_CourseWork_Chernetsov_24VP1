#ifndef SETONSTACK_H
#define SETONSTACK_H

#include <stack>
#include <string>

class SetOnStack {
private:
    std::stack<int> elements;

public:
    SetOnStack();
    SetOnStack(const SetOnStack& A);
    ~SetOnStack();

    bool empty_check() const;
    bool check_element(int value) const;
    void add_element(int value);
    void create_set(int count, int min, int max);
    int set_size() const;
    std::string create_string_from_set(const char* divider) const;
    bool check_subset(SetOnStack& B);
    bool equality_set(SetOnStack& B);
    SetOnStack set_union(SetOnStack B);
    SetOnStack set_intersection(SetOnStack B);
    SetOnStack set_difference(SetOnStack B);
    SetOnStack set_symmetrical_difference(SetOnStack B);
};

#endif