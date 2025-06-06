
#ifndef LINESEGMENTCLASS_H
#define LINESEGMENTCLASS_H

#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

/**
 * @class LineSegmentClass
 * @brief Класс, представляющий отрезок на числовой прямой.
 */
class LineSegmentClass {
public:
    /**
     * <summary>
     * Конструктор по умолчанию. Создает отрезок [0, 0].
     * </summary>
     */
    LineSegmentClass();

    /**
     * <summary>
     * Параметризованный конструктор.
     * </summary>
     * <param name="start">Начальная точка отрезка.</param>
     * <param name="end">Конечная точка отрезка.</param>
     * <exception cref="std::invalid_argument">Выбрасывается, если start > end.</exception>
     */
    LineSegmentClass(double start, double end);

    /**
     * <summary>
     * Конструктор копирования.
     * </summary>
     * <param name="other">Другой объект LineSegmentClass для копирования.</param>
     */
    LineSegmentClass(const LineSegmentClass& other);

    /**
     * <summary>
     * Находит пересечение с другим отрезком.
     * </summary>
     * <param name="other">Отрезок, с которым ищется пересечение.</param>
     * <returns>unique_ptr на новый отрезок (nullptr, если пересечения нет).</returns>
     */
    unique_ptr<LineSegmentClass> GetIntersection(const LineSegmentClass& other) const;

    /**
     * <summary>
     * Оператор вывода отрезка в поток.
     * </summary>
     * <param name="os">Поток вывода.</param>
     * <param name="segment">Отрезок для вывода.</param>
     * <returns>Ссылка на поток вывода.</returns>
     */
    friend ostream& operator<<(ostream& os, const LineSegmentClass& segment);

    /**
     * <summary>
     * Сдвигает отрезок так, чтобы его начало было в 0.
     * </summary>
     * <returns>Новый отрезок со началом в нуле.</returns>
     */
    LineSegmentClass MoveToOrigin() const;

    /**
     * <summary>
     * Оператор преобразования в int (возвращает длину отрезка с округлением вниз).
     * </summary>
     * <returns>Длина отрезка как целое число.</returns>
     */
    operator int() const;

    /**
     * <summary>
     * Явный оператор преобразования в double (возвращает длину отрезка).
     * </summary>
     * <returns>Длина отрезка как число с плавающей точкой.</returns>
     */
    explicit operator double() const;

    /**
     * <summary>
     * Оператор сложения (сдвигает отрезок на заданное смещение).
     * </summary>
     * <param name="offset">Величина смещения.</param>
     * <returns>Новый сдвинутый отрезок.</returns>
     */
    LineSegmentClass operator+(int offset) const;

private:
    double start_;  ///< Начальная точка отрезка.
    double end_;    ///< Конечная точка отрезка.
};

#endif 
