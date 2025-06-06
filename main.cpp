#include <iostream>
#include "LineSegmentClass.h"
#include <Windows.h>

using namespace std;

/**
 * <summary>
 * Функция для безопасного ввода числового значения с проверкой.
 * </summary>
 * <param name="prompt">Приглашение для ввода.</param>
 * <returns>Введенное пользователем число.</returns>
 * <exception cref="runtime_error">Если ввод некорректен.</exception>
 * <remarks>
 * Циклически запрашивает ввод, пока не будет получено корректное число.
 * В случае ошибки выводит сообщение через cerr.
 * </remarks>
 */
double GetInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cerr << "Ошибка: Введено некорректное значение. Пожалуйста, введите число." << endl;
        }
        else {
            cin.ignore();
            return value;
        }
    }
}

/**
 * <summary>
 * Главная функция программы.
 * </summary>
 * <returns>Код возврата (0 - успешное выполнение).</returns>
 * <remarks>
 * Демонстрирует работу с классом LineSegmentClass:
 * 1. Запрашивает координаты двух отрезков
 * 2. Выводит информацию об отрезках
 * 3. Находит и выводит пересечение отрезков
 * </remarks>
 */
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        const double start1 = GetInput("Введите координату начала первого отрезка: ");
        const double end1 = GetInput("Введите координату конца первого отрезка: ");
        const LineSegmentClass segment1(start1, end1);

        const double start2 = GetInput("Введите координату начала второго отрезка: ");
        const double end2 = GetInput("Введите координату конца второго отрезка: ");
        const LineSegmentClass segment2(start2, end2);

        cout << "Первый " << segment1 << endl;
        cout << "Второй " << segment2 << endl;

        const auto intersection = segment1.GetIntersection(segment2);
        if (intersection) {
            cout << "Пересечение: " << *intersection << endl;
        }
        else {
            cout << "Отрезки не пересекаются." << endl;
        }
    }
    catch (const exception& e) {
        cerr << "Произошла ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}
