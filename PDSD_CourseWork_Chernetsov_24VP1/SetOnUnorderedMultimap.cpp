#include "SetOnUnorderedMultimap.h"
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cstdlib>

SetOnUnorderedMultimap::SetOnUnorderedMultimap() {}

SetOnUnorderedMultimap::SetOnUnorderedMultimap(const SetOnUnorderedMultimap& A) {
    elements = A.elements;
}

SetOnUnorderedMultimap::~SetOnUnorderedMultimap() {
    elements.clear();
}

bool SetOnUnorderedMultimap::empty_check() const {
    return elements.empty();
}

bool SetOnUnorderedMultimap::check_element(int value) const {
    if (empty_check()) return false;
    return elements.find(value) != elements.end();
}

void SetOnUnorderedMultimap::add_element(int value) {
    if (check_element(value)) return;
    elements.insert({ value, true });
}

void SetOnUnorderedMultimap::create_set(int count, int min, int max) {
    if ((max - min + 1) < count) return;
    elements.clear();
    while (count) {
        int random_val = (rand() << 15) | rand();
        int value = min + (random_val % static_cast<int>(max - min + 1));
        int prev_size = elements.size();
        add_element(value);
        if (elements.size() > prev_size) count--;
    }
}

int SetOnUnorderedMultimap::set_size() const {
    return elements.size();
}

std::string SetOnUnorderedMultimap::create_string_from_set(const char* divider) const {
    if (empty_check()) return "";
    std::string result = "";
    for (const auto& pair : elements) {
        result += std::to_string(pair.first) + divider;
    }
    result.erase(result.size() - strlen(divider));
    return result;
}

bool SetOnUnorderedMultimap::check_subset(SetOnUnorderedMultimap& B) {
    if (empty_check()) return true;
    if (!empty_check() && B.empty_check()) return false;
    if (set_size() > B.set_size()) return false;
    for (const auto& pair : elements) {
        if (!B.check_element(pair.first)) return false;
    }
    return true;
}

bool SetOnUnorderedMultimap::equality_set(SetOnUnorderedMultimap& B) {
    return check_subset(B) && B.check_subset(*this);
}

SetOnUnorderedMultimap SetOnUnorderedMultimap::set_union(SetOnUnorderedMultimap B) {
    SetOnUnorderedMultimap result;
    for (const auto& pair : elements) {
        result.add_element(pair.first);
    }
    for (const auto& pair : B.elements) {
        result.add_element(pair.first);
    }
    return result;
}

SetOnUnorderedMultimap SetOnUnorderedMultimap::set_intersection(SetOnUnorderedMultimap B) {
    SetOnUnorderedMultimap result;
    if (empty_check() || B.empty_check()) return result;
    for (const auto& pair : elements) {
        if (B.check_element(pair.first)) {
            result.add_element(pair.first);
        }
    }
    return result;
}

SetOnUnorderedMultimap SetOnUnorderedMultimap::set_difference(SetOnUnorderedMultimap B) {
    SetOnUnorderedMultimap result;
    if (empty_check()) return result;
    for (const auto& pair : elements) {
        if (!B.check_element(pair.first)) {
            result.add_element(pair.first);
        }
    }
    return result;
}

SetOnUnorderedMultimap SetOnUnorderedMultimap::set_symmetrical_difference(SetOnUnorderedMultimap B) {
    return set_union(B).set_difference(set_intersection(B));
}