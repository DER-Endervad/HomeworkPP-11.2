#include <iostream>
#include "big_integer.h"
//#include <sstream>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Проверка функции сложения двух больших чисел:" << std::endl;
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    std::cout << "number 1 + number 2 = " << number1 << " + " << number2 << " = ";
    auto result = number1 + number2;
    std::cout << result << "\n" << std::endl; // 193099

    std::cout << "Проверка функции умножения на число:" << std::endl;
    std::cout << "number 1 * 15 = " << number1 << " * 15" << " = ";
    auto result2 = number1 * 15;
    std::cout << result2 << "\n" << std::endl; // 2 896 485
    system("pause");
}
