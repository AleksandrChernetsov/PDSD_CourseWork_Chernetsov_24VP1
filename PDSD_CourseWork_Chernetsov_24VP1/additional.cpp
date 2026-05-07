#include "additional.h"

int inputInt(const char* prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt << " (целое от " << min << " до " << max << "): ";
        if (std::cin >> value) {
            char next = std::cin.peek();
            if (next != '\n' && next != ' ' && next != '\t' && next != EOF) {
                std::cout << "Неверный ввод, повторите.\n";
            }
            else if (value >= min && value <= max) {
                std::cin.ignore(LONG_MAX, '\n');
                return value;
            }
            else {
                std::cout << "Число вне допустимого диапазона. Повторите ввод.\n";
            }
        }
        else {
            std::cin.clear();
            std::cout << "Неверный ввод, повторите.\n";
        }
        std::cin.ignore(LONG_MAX, '\n');
    }
}