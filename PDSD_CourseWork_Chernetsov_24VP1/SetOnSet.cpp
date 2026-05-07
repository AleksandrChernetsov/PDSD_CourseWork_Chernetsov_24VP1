#include "SetOnSet.h"
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cstdlib>

SetOnSet::SetOnSet() {}

SetOnSet::SetOnSet(const SetOnSet& A) {
    elements = A.elements;
}

SetOnSet::~SetOnSet() {
    elements.clear();
}

bool SetOnSet::empty_check() {
    return elements.empty();
}

bool SetOnSet::check_element(int value) {
    if (empty_check()) return false;
    return elements.find(value) != elements.end();
}

void SetOnSet::add_element(int value) {
    elements.insert(value);
}

void SetOnSet::create_set(int count, int min, int max) {
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

int SetOnSet::set_size() {
    return elements.size();
}

std::string SetOnSet::create_string_from_set(const char* divider) {
    if (empty_check()) return "";
    std::string result = "";
    for (const auto& element : elements) {
        result += std::to_string(element) + divider;
    }
    result.erase(result.size() - strlen(divider));
    return result;
}

bool SetOnSet::check_subset(SetOnSet& B) {
    if (empty_check()) return true;
    if (!empty_check() && B.empty_check()) return false;
    if (set_size() > B.set_size()) return false;
    for (const auto& element : elements) {
        if (!B.check_element(element)) return false;
    }
    return true;
}

bool SetOnSet::equality_set(SetOnSet& B) {
    return check_subset(B) && B.check_subset(*this);
}

SetOnSet SetOnSet::set_union(SetOnSet B) {
    SetOnSet result;
    for (const auto& element : elements) {
        result.add_element(element);
    }
    for (const auto& element : B.elements) {
        result.add_element(element);
    }
    return result;
}

SetOnSet SetOnSet::set_intersection(SetOnSet B) {
    SetOnSet result;
    if (empty_check() || B.empty_check()) return result;
    for (const auto& element : elements) {
        if (B.check_element(element)) {
            result.add_element(element);
        }
    }
    return result;
}

SetOnSet SetOnSet::set_difference(SetOnSet B) {
    SetOnSet result;
    if (empty_check()) return result;
    for (const auto& element : elements) {
        if (!B.check_element(element)) {
            result.add_element(element);
        }
    }
    return result;
}

SetOnSet SetOnSet::set_symmetrical_difference(SetOnSet B) {
    return set_union(B).set_difference(set_intersection(B));
}