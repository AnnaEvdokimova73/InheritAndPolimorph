#include <iostream>

class Figure {
public:
    Figure() : sidesCount { 0 }, name{ "Фигура:" } {}

    std::string getName()
    {
        return this->name;
    }

    int getSidesCount()
    {
        return this->sidesCount;
    }

protected:
    std::string name;
    int sidesCount;
};

class Triangle : public Figure {
public:
    Triangle() {
        this->sidesCount = 3;
        this->name = "Треугольник:";
    }
};

class Quadrilateral : public Figure {
public:
    Quadrilateral() {
        this->sidesCount = 4;
        this->name = "Четырехугольник:";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Figure fig;
    Triangle trian;
    Quadrilateral quad;
    std::cout << "Количество сторон:\n";
    std::cout << fig.getName() << " " << fig.getSidesCount() << std::endl;
    std::cout << trian.getName() << " " << trian.getSidesCount() << std::endl;
    std::cout << quad.getName() << " "  << quad.getSidesCount() << std::endl;
}
