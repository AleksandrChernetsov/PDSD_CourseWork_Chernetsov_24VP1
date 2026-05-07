#ifndef SETONLIST_H
#define SETONLIST_H

#include <list>
#include <string>

class SetOnList {
private:
    std::list<int> elements;

public:
    SetOnList();
    SetOnList(const SetOnList& A);
    ~SetOnList();

    bool empty_check();
    bool check_element(int value);
    void add_element(int value);
    void create_set(int count, int min, int max);
    int set_size();
    std::string create_string_from_set(const char* divider);
    bool check_subset(SetOnList& B);
    bool equality_set(SetOnList& B);
    SetOnList set_union(SetOnList B);
    SetOnList set_intersection(SetOnList B);
    SetOnList set_difference(SetOnList B);
    SetOnList set_symmetrical_difference(SetOnList B);
};

#endif