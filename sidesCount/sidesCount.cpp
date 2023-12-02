#include <iostream>

class Figure {
public:
    Figure() : sidesCount { 0 } {}

    int getSidesCount()
    {
        return this->sidesCount;
    }

protected:
    int sidesCount;
};

class Triangle : public Figure {
public:
    Triangle() {
        this->sidesCount = 3;
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() {
        this->sidesCount = 4;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Figure fig;
    Triangle trian;
    Quadrilateral quad;
    std::cout << "Количество сторон:\n";
    std::cout << "Фигура: " << fig.getSidesCount() << std::endl;
    std::cout << "Треугольник: " << trian.getSidesCount() << std::endl;
    std::cout << "Четырёхугольник: " << quad.getSidesCount() << std::endl;
}
