#include "SetOnStack.h"
#include <algorithm>
#include <ctime>
#include <cstring>
#include <cstdlib>

SetOnStack::SetOnStack() {}

SetOnStack::SetOnStack(const SetOnStack& A) {
    elements = A.elements;
}

SetOnStack::~SetOnStack() {
    while (!elements.empty()) elements.pop();
}

bool SetOnStack::empty_check() const {
    return elements.empty();
}

bool SetOnStack::check_element(int value) const {
    if (empty_check()) return false;
    std::stack<int> temp = elements;
    while (!temp.empty()) {
        if (temp.top() == value) return true;
        temp.pop();
    }
    return false;
}

void SetOnStack::add_element(int value) {
    if (check_element(value)) return;
    elements.push(value);
}

void SetOnStack::create_set(int count, int min, int max) {
    if ((max - min + 1) < count) return;
    while (!elements.empty()) elements.pop();
    while (count) {
        int random_val = (rand() << 15) | rand();
        int value = min + (random_val % static_cast<int>(max - min + 1));
        int prev_size = elements.size();
        add_element(value);
        if (elements.size() > prev_size) count--;
    }
}

int SetOnStack::set_size() const {
    return elements.size();
}

std::string SetOnStack::create_string_from_set(const char* divider) const {
    if (empty_check()) return "";
    std::string result = "";
    std::stack<int> temp = elements;
    std::stack<int> reversed;
    while (!temp.empty()) {
        reversed.push(temp.top());
        temp.pop();
    }
    while (!reversed.empty()) {
        result += std::to_string(reversed.top()) + divider;
        reversed.pop();
    }
    result.erase(result.size() - strlen(divider));
    return result;
}

bool SetOnStack::check_subset(SetOnStack& B) {
    if (empty_check()) return true;
    if (!empty_check() && B.empty_check()) return false;
    if (set_size() > B.set_size()) return false;
    std::stack<int> temp = elements;
    while (!temp.empty()) {
        int element = temp.top();
        if (!B.check_element(element)) return false;
        temp.pop();
    }
    return true;
}

bool SetOnStack::equality_set(SetOnStack& B) {
    return check_subset(B) && B.check_subset(*this);
}

SetOnStack SetOnStack::set_union(SetOnStack B) {
    SetOnStack result;
    std::stack<int> temp = elements;
    while (!temp.empty()) {
        result.add_element(temp.top());
        temp.pop();
    }
    std::stack<int> tempB = B.elements;
    while (!tempB.empty()) {
        result.add_element(tempB.top());
        tempB.pop();
    }
    return result;
}

SetOnStack SetOnStack::set_intersection(SetOnStack B) {
    SetOnStack result;
    if (empty_check() || B.empty_check()) return result;
    std::stack<int> temp = elements;
    while (!temp.empty()) {
        int element = temp.top();
        if (B.check_element(element)) {
            result.add_element(element);
        }
        temp.pop();
    }
    return result;
}

SetOnStack SetOnStack::set_difference(SetOnStack B) {
    SetOnStack result;
    if (empty_check()) return result;
    std::stack<int> temp = elements;
    while (!temp.empty()) {
        int element = temp.top();
        if (!B.check_element(element)) {
            result.add_element(element);
        }
        temp.pop();
    }
    return result;
}

SetOnStack SetOnStack::set_symmetrical_difference(SetOnStack B) {
    return set_union(B).set_difference(set_intersection(B));
}