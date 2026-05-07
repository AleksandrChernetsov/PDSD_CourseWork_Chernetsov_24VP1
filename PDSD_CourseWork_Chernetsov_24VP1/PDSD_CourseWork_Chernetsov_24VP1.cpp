#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <chrono> 
#include "additional.h"
#include "SetOnNodes.h"
#include "SetOnNodeClass.h"
#include "SetOnList.h"
#include "SetOnSet.h"
#include "SetOnStack.h"
#include "SetOnUnorderedMultimap.h"

// Определение длины UTF-8 строки в символах
size_t utf8_length(const std::string& s) {
    size_t len = 0;
    const char* ptr = s.c_str();
    while (*ptr) {
        unsigned char c = *ptr;
        if (c < 0x80) ptr += 1;
        else if ((c & 0xE0) == 0xC0) ptr += 2;
        else if ((c & 0xF0) == 0xE0) ptr += 3;
        else if ((c & 0xF8) == 0xF0) ptr += 4;
        else ptr += 1;
        ++len;
    }
    return len;
}

// Центрирование строки
std::string center_utf8(const std::string& s, int width) {
    size_t len = utf8_length(s);
    if (len >= static_cast<size_t>(width)) return s;
    int left = (width - static_cast<int>(len)) / 2;
    int right = width - static_cast<int>(len) - left;
    return std::string(left, ' ') + s + std::string(right, ' ');
}

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    system("color F0");

    std::cout << "Чернецов А.М. 24ВП1. Курсовая работа." << std::endl << std::endl;

    auto times = time(NULL);

    srand(static_cast<unsigned>(times));

    int SET1_SIZE = inputInt("Введите размер первого множества", 0, 10000);
    int SET2_SIZE = inputInt("Введите размер второго множества", 0, 10000);

    const int col_width = 25;
    const int total_width = 1 + 7 * (col_width + 1);

    std::string headers[] = { "", "Односвязный список", "Класс 'Список'", "List", "Set", "Stack", "unordered_multimap" };
    std::string rows[] = {
        "Создание множества", "Мощность", "Подмножество A-A", "Подмножество B-A",
        "Равенство A-A", "Равенство B-A", "Объединение", "Пересечение",
        "Разность A-B", "Разность B-A", "Симметричная разность"
    };

    std::cout << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');
    std::cout << '|';
    for (int i = 0; i < 7; ++i) std::cout << center_utf8(headers[i], col_width) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    Node* Set_1 = nullptr;
    SetOnNodeClass Set_2;
    SetOnList Set_3;
    SetOnSet Set_4;
    SetOnStack Set_5;
    SetOnUnorderedMultimap Set_6;

    // Функция форматирования числа (миллисекунды с 6 знаками)
    auto format_num = [&](double val) -> std::string {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(6) << val;
        return center_utf8(oss.str(), col_width);
        };

    // Лямбда для замера времени
    auto measure_time = [](auto&& func) -> double {
        auto start = std::chrono::high_resolution_clock::now();
        func();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> diff = end - start;
        return diff.count();
        };

    // 1. Создание множества (первые множества A)
    std::cout << '|' << center_utf8(rows[0], col_width) << '|';
    std::cout << format_num(measure_time([&]() { Set_1 = create_set(SET1_SIZE, 0, 10 * SET1_SIZE); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.create_set(SET1_SIZE, 0, 10 * SET1_SIZE); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.create_set(SET1_SIZE, 0, 10 * SET1_SIZE); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.create_set(SET1_SIZE, 0, 10 * SET1_SIZE); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.create_set(SET1_SIZE, 0, 10 * SET1_SIZE); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.create_set(SET1_SIZE, 0, 10 * SET1_SIZE); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 2. Мощность
    std::cout << '|' << center_utf8(rows[1], col_width) << '|';
    std::cout << format_num(measure_time([&]() { set_size(Set_1); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.set_size(); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.set_size(); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.set_size(); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.set_size(); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.set_size(); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 3. Подмножество A-A
    std::cout << '|' << center_utf8(rows[2], col_width) << '|';
    std::cout << format_num(measure_time([&]() { check_subset(Set_1, Set_1); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.check_subset(Set_2); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.check_subset(Set_3); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.check_subset(Set_4); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.check_subset(Set_5); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.check_subset(Set_6); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // Подготовка вторых множеств B
    Node* Set_11 = nullptr; SetOnNodeClass Set_22; SetOnList Set_33;
    SetOnSet Set_44; SetOnStack Set_55; SetOnUnorderedMultimap Set_66;

    Set_11 = create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
    Set_22.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
    Set_33.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
    Set_44.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
    Set_55.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);
    Set_66.create_set(SET2_SIZE, 0, 10 * SET2_SIZE);

    // 4. Подмножество B-A
    std::cout << '|' << center_utf8(rows[3], col_width) << '|';
    std::cout << format_num(measure_time([&]() { check_subset(Set_1, Set_11); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.check_subset(Set_22); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.check_subset(Set_33); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.check_subset(Set_44); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.check_subset(Set_55); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.check_subset(Set_66); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 5. Равенство A-A
    std::cout << '|' << center_utf8(rows[4], col_width) << '|';
    std::cout << format_num(measure_time([&]() { equality_set(Set_1, Set_1); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.equality_set(Set_2); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.equality_set(Set_3); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.equality_set(Set_4); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.equality_set(Set_5); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.equality_set(Set_6); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 6. Равенство B-A
    std::cout << '|' << center_utf8(rows[5], col_width) << '|';
    std::cout << format_num(measure_time([&]() { equality_set(Set_1, Set_11); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.equality_set(Set_22); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.equality_set(Set_33); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.equality_set(Set_44); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.equality_set(Set_55); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.equality_set(Set_66); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 7. Объединение
    std::cout << '|' << center_utf8(rows[6], col_width) << '|';
    std::cout << format_num(measure_time([&]() { delete_set(set_union(Set_1, Set_11)); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.set_union(Set_22); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.set_union(Set_33); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.set_union(Set_44); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.set_union(Set_55); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.set_union(Set_66); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 8. Пересечение
    std::cout << '|' << center_utf8(rows[7], col_width) << '|';
    std::cout << format_num(measure_time([&]() { delete_set(set_intersection(Set_1, Set_11)); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.set_intersection(Set_22); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.set_intersection(Set_33); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.set_intersection(Set_44); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.set_intersection(Set_55); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.set_intersection(Set_66); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 9. Разность A-B
    std::cout << '|' << center_utf8(rows[8], col_width) << '|';
    std::cout << format_num(measure_time([&]() { delete_set(set_difference(Set_1, Set_11)); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.set_difference(Set_22); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.set_difference(Set_33); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.set_difference(Set_44); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.set_difference(Set_55); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.set_difference(Set_66); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 10. Разность B-A
    std::cout << '|' << center_utf8(rows[9], col_width) << '|';
    std::cout << format_num(measure_time([&]() { delete_set(set_difference(Set_11, Set_1)); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_22.set_difference(Set_2); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_33.set_difference(Set_3); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_44.set_difference(Set_4); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_55.set_difference(Set_5); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_66.set_difference(Set_6); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl << std::setfill(' ');

    // 11. Симметричная разность
    std::cout << '|' << center_utf8(rows[10], col_width) << '|';
    std::cout << format_num(measure_time([&]() { delete_set(set_symmetrical_difference(Set_1, Set_11)); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_2.set_symmetrical_difference(Set_22); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_3.set_symmetrical_difference(Set_33); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_4.set_symmetrical_difference(Set_44); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_5.set_symmetrical_difference(Set_55); })) << '|';
    std::cout << format_num(measure_time([&]() { Set_6.set_symmetrical_difference(Set_66); })) << '|';
    std::cout << std::endl << std::setfill('-') << std::setw(total_width) << "" << std::endl;

    delete_set(Set_1);
    delete_set(Set_11);

    return 0;
}