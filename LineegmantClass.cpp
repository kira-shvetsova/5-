#include "LineSegmentClass.h"



/**
 * <summary>
 * Реализация конструктора по умолчанию.
 * Инициализирует отрезок [0, 0].
 * </summary>
 */
LineSegmentClass::LineSegmentClass() : start_(0), end_(0) {}

/**
 * <summary>
 * Реализация параметризованного конструктора.
 * </summary>
 * <param name="start">Начальная точка отрезка.</param>
 * <param name="end">Конечная точка отрезка.</param>
 * <remarks>
 * Если start > end, точки автоматически меняются местами.
 * </remarks>
 */
LineSegmentClass::LineSegmentClass(double start, double end) {
    if (start > end) {
        start_ = end;
        end_ = start;
    }
    else {
        start_ = start;
        end_ = end;
    }
}

/**
 * <summary>
 * Реализация конструктора копирования.
 * </summary>
 * <param name="other">Исходный отрезок для копирования.</param>
 */
LineSegmentClass::LineSegmentClass(const LineSegmentClass& other)
    : start_(other.start_), end_(other.end_) {}

/**
 * <summary>
 * Находит пересечение с другим отрезком.
 * </summary>
 * <param name="other">Отрезок для проверки пересечения.</param>
 * <returns>
 * Указатель на новый отрезок, представляющий пересечение,
 * или nullptr, если пересечения нет.
 * </returns>
 */
unique_ptr<LineSegmentClass> LineSegmentClass::GetIntersection(const LineSegmentClass& other) const {
    const double new_start = max(start_, other.start_);
    const double new_end = min(end_, other.end_);

    if (new_start < new_end) {
        return make_unique<LineSegmentClass>(new_start, new_end);
    }
    return nullptr;
}

/**
 * <summary>
 * Оператор вывода отрезка в поток.
 * </summary>
 * <param name="os">Поток вывода.</param>
 * <param name="segment">Отрезок для вывода.</param>
 * <returns>Ссылка на поток вывода.</returns>
 */
ostream& operator<<(ostream& os, const LineSegmentClass& segment) {
    os << "Отрезок: [" << segment.start_ << ", " << segment.end_ << "]";
    return os;
}

/**
 * <summary>
 * Сдвигает отрезок так, чтобы его начало было в точке 0.
 * </summary>
 * <returns>Новый отрезок с началом в нуле.</returns>
 */
LineSegmentClass LineSegmentClass::MoveToOrigin() const {
    return LineSegmentClass(0, end_ - start_);
}

/**
 * <summary>
 * Оператор преобразования в int.
 * </summary>
 * <returns>Длина отрезка, приведенная к целому числу.</returns>
 */
LineSegmentClass::operator int() const {
    return static_cast<int>(end_ - start_);
}

/**
 * <summary>
 * Оператор преобразования в double.
 * </summary>
 * <returns>Длина отрезка.</returns>
 */
LineSegmentClass::operator double() const {
    return end_ - start_;
}

/**
 * <summary>
 * Оператор сложения отрезка с числом (сдвиг отрезка).
 * </summary>
 * <param name="offset">Величина сдвига.</param>
 * <returns>Новый сдвинутый отрезок.</returns>
 */
LineSegmentClass LineSegmentClass::operator+(int offset) const {
    return LineSegmentClass(start_ + offset, end_ + offset);
}
