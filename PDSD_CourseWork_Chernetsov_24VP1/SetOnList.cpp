#include "SetOnList.h"
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cstdlib>

SetOnList::SetOnList() {}

SetOnList::SetOnList(const SetOnList& A) {
    elements = A.elements;
}

SetOnList::~SetOnList() {
    elements.clear();
}

bool SetOnList::empty_check() {
    return elements.empty();
}

bool SetOnList::check_element(int value) {
    if (empty_check()) return false;
    return std::find(elements.begin(), elements.end(), value) != elements.end();
}

void SetOnList::add_element(int value) {
    if (check_element(value)) return;
    elements.push_front(value);
}

void SetOnList::create_set(int count, int min, int max) {
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

int SetOnList::set_size() {
    return elements.size();
}

std::string SetOnList::create_string_from_set(const char* divider) {
    if (empty_check()) return "";
    std::string result = "";
    for (const auto& element : elements) {
        result += std::to_string(element) + divider;
    }
    result.erase(result.size() - strlen(divider));
    return result;
}

bool SetOnList::check_subset(SetOnList& B) {
    if (empty_check()) return true;
    if (!empty_check() && B.empty_check()) return false;
    if (set_size() > B.set_size()) return false;
    for (const auto& element : elements) {
        if (!B.check_element(element)) return false;
    }
    return true;
}

bool SetOnList::equality_set(SetOnList& B) {
    return check_subset(B) && B.check_subset(*this);
}

SetOnList SetOnList::set_union(SetOnList B) {
    SetOnList result;
    for (const auto& element : elements) {
        result.add_element(element);
    }
    for (const auto& element : B.elements) {
        result.add_element(element);
    }
    return result;
}

SetOnList SetOnList::set_intersection(SetOnList B) {
    SetOnList result;
    if (empty_check() || B.empty_check()) return result;
    for (const auto& element : elements) {
        if (B.check_element(element)) {
            result.add_element(element);
        }
    }
    return result;
}

SetOnList SetOnList::set_difference(SetOnList B) {
    SetOnList result;
    if (empty_check()) return result;
    for (const auto& element : elements) {
        if (!B.check_element(element)) {
            result.add_element(element);
        }
    }
    return result;
}

SetOnList SetOnList::set_symmetrical_difference(SetOnList B) {
    return set_union(B).set_difference(set_intersection(B));
}