#pragma once
/// <summary>
/// Базовый класс, представляющий точку в 2D пространстве.
/// </summary>
class Point2D {
protected:
    double x, y;
public:
    /// <summary>Конструктор 2D точки.</summary>
    Point2D(double _x = 0, double _y = 0);
    /// <summary>Виртуальный метод вывода координат.</summary>
    virtual void Print() const;
    virtual ~Point2D();
};

/// <summary>
/// Производный класс для точки в 3D пространстве.
/// </summary>
class Point3D : public Point2D {
private:
    double z;
public:
    /// <summary>Конструктор 3D точки.</summary>
    Point3D(double _x, double _y, double _z);
    /// <summary>Расчет расстояния до другой 3D точки.</summary>
    double DistanceTo(const Point3D& other) const;
    /// <summary>Переопределенный метод вывода для 3D.</summary>
    void Print() const override;
};