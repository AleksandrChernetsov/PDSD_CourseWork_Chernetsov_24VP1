#ifndef SETONUNORDEREDMULTIMAP_H
#define SETONUNORDEREDMULTIMAP_H

#include <unordered_map>
#include <string>

class SetOnUnorderedMultimap {
private:
    std::unordered_multimap<int, bool> elements;

public:
    SetOnUnorderedMultimap();
    SetOnUnorderedMultimap(const SetOnUnorderedMultimap& A);
    ~SetOnUnorderedMultimap();

    bool empty_check() const;
    bool check_element(int value) const;
    void add_element(int value);
    void create_set(int count, int min, int max);
    int set_size() const;
    std::string create_string_from_set(const char* divider) const;
    bool check_subset(SetOnUnorderedMultimap& B);
    bool equality_set(SetOnUnorderedMultimap& B);
    SetOnUnorderedMultimap set_union(SetOnUnorderedMultimap B);
    SetOnUnorderedMultimap set_intersection(SetOnUnorderedMultimap B);
    SetOnUnorderedMultimap set_difference(SetOnUnorderedMultimap B);
    SetOnUnorderedMultimap set_symmetrical_difference(SetOnUnorderedMultimap B);
};

#endif