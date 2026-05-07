#ifndef SETONSET_H
#define SETONSET_H

#include <set>
#include <string>

class SetOnSet {
private:
    std::set<int> elements;

public:
    SetOnSet();
    SetOnSet(const SetOnSet& A);
    ~SetOnSet();

    bool empty_check();
    bool check_element(int value);
    void add_element(int value);
    void create_set(int count, int min, int max);
    int set_size();
    std::string create_string_from_set(const char* divider);
    bool check_subset(SetOnSet& B);
    bool equality_set(SetOnSet& B);
    SetOnSet set_union(SetOnSet B);
    SetOnSet set_intersection(SetOnSet B);
    SetOnSet set_difference(SetOnSet B);
    SetOnSet set_symmetrical_difference(SetOnSet B);
};

#endif