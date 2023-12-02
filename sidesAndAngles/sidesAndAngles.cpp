#include <iostream>

class Figure {
public:
    Figure() : sidesCount{ 0 } {}

    int getSidesCount()
    {
        return this->sidesCount;
    }

    virtual void printInfo()
    {
        std::cout << "Количество сторон: " << this->getSidesCount() << std::endl;
    }

protected:
    int sidesCount;
};

class Triangle : public Figure {
public:
    Triangle(int _a, int _b, int _c, int _A, int _B, int _C) :
             a{_a}, b{_b}, c{_c}, A{_A}, B{_B}, C{_C}
    {
        this->sidesCount = 3;
    }

    virtual void printInfo() override
    {
        std::cout << "Стороны:\t";
        std::cout << "a = " << this->geta() << " ";
        std::cout << "b = " << this->getb() << " ";
        std::cout << "c = " << this->getc() << " ";
        std::cout << std::endl;
        std::cout << "Углы:\t";
        std::cout << "A = " << this->getA() << " ";
        std::cout << "B = " << this->getB() << " ";
        std::cout << "C = " << this->getC() << " ";
        std::cout << std::endl << std::endl;
    }

    int geta()
    {
        return this->a;
    }

    int getb()
    {
        return this->b;
    }

    int getc()
    {
        return this->c;
    }

    int getA()
    {
        return this->A;
    }

    int getB()
    {
        return this->B;
    }

    int getC()
    {
        return this->C;
    }

protected:
    int a, b, c;
    int A, B, C;
};

class Quadrilateral : public Figure {
public:
    Quadrilateral(int _a, int _b, int _c, int _d, int _A, int _B, int _C, int _D) :
                  a{ _a }, b{ _b }, c{ _c }, d{ _d }, A{ _A }, B{ _B }, C{ _C }, D{ _D } 
    {
        this->sidesCount = 4;
    }

    virtual void printInfo() override
    {
        std::cout << "Стороны:\t";
        std::cout << "a = " << this->geta() << " ";
        std::cout << "b = " << this->getb() << " ";
        std::cout << "c = " << this->getc() << " ";
        std::cout << "d = " << this->getd() << " ";
        std::cout << std::endl;
        std::cout << "Углы:\t";
        std::cout << "A = " << this->getA() << " ";
        std::cout << "B = " << this->getB() << " ";
        std::cout << "C = " << this->getC() << " ";
        std::cout << "D = " << this->getD() << " ";
        std::cout << std::endl << std::endl;
    }

    int geta()
    {
        return this->a;
    }

    int getb()
    {
        return this->b;
    }

    int getc()
    {
        return this->c;
    }

    int getd()
    {
        return this->d;
    }

    int getA()
    {
        return this->A;
    }

    int getB()
    {
        return this->B;
    }

    int getC()
    {
        return this->C;
    }
    int getD()
    {
        return this->D;
    }

protected:
    int a, b, c, d;
    int A, B, C, D;
};

// Прямоугольный треугольник
class RectTrian : public Triangle {
public:
    RectTrian(int _a, int _b, int _c, int _A, int _B) : 
        Triangle(_a, _b, _c, _A, _B, 90) {}
};

// Равнобедренный треугольник
class IsoTrian : public Triangle {
public:
    IsoTrian(int _a, int _b, int _A, int _B) :
        Triangle(_a, _b, _a, _A, _B, _A) {}
};

// Равносторонний треугольник
class EqualTrian : public IsoTrian {
public:
    EqualTrian(int _a, int _A) :
        IsoTrian(_a, _a, _A, _A) {}
};

// Параллелограмм
class Parall : public Quadrilateral {
public:
    Parall(int _a, int _b, int _A, int _B) :
        Quadrilateral(_a, _b, _a, _b, _A, _B, _A, _B) {}
};

// Прямоугольник
class Rectangle : public Parall {
public:
    Rectangle(int _a, int _b) :
        Parall (_a, _b, 90, 90) {}
};

// Квадрат
class Square : public Rectangle {
public:
    Square(int _a) :
        Rectangle (_a, _a) {}
};

// Ромб
class Rhombus : public Parall {
public:
    Rhombus(int _a, int _A, int _B) :
        Parall(_a, _a, _A, _B) {}
};

void printFigInfo(Figure* fig, int numb)
{
    switch (numb)
    {
    case 0:
        std::cout << "Треугольник:\n";
        break;
    case 1:
        std::cout << "Прямоугольный треугольник:\n";
        break;
    case 2:
        std::cout << "Равнобедренный треугольник:\n";
        break;
    case 3:
        std::cout << "Равносторонний треугольник:\n";
        break;
    case 4:
        std::cout << "Четырёхугольник:\n";
        break;
    case 5:
        std::cout << "Прямоугольник:\n";
        break;
    case 6:
        std::cout << "Квадрат:\n";
        break;
    case 7:
        std::cout << "Параллелограмм:\n";
        break;
    case 8:
        std::cout << "Ромб:\n";
        break;
    }
    fig->printInfo();
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int a = 10, b = 20, c = 30, d = 40;
    int A = 50, B = 60, C = 70, D = 80;

    Triangle trian(a, b, c, A, B, C);
    RectTrian recTrian(a, b, c, A, B);
    IsoTrian isoTrian(a, b, A, B);
    EqualTrian eqTrian(a, A);

    Quadrilateral quad(a, b, c, d, A, B, C, D);
    Rectangle rect(a, b);
    Square squar(a);
    Parall par(a, b, A, B);
    Rhombus rhom(a, A, B);

    Figure* figs[9];
    figs[0] = &trian;
    figs[1] = &recTrian;
    figs[2] = &isoTrian;
    figs[3] = &eqTrian;
    figs[4] = &quad;
    figs[5] = &rect;
    figs[6] = &squar;
    figs[7] = &par;
    figs[8] = &rhom;

    int size = sizeof(figs) / sizeof(Figure*);

    for (int i = 0; i < size; ++i)
    {
        printFigInfo(figs[i], i);
    }

    /* Different option
    
    std::cout << "Треугольник:\n";
    trian.printInfo();

    std::cout << "Прямоугольный треугольник:\n";
    recTrian.printInfo();

    std::cout << "Равнобедренный треугольник:\n";
    isoTrian.printInfo();

    std::cout << "Равносторонний треугольник:\n";
    eqTrian.printInfo();

    std::cout << "Четырёхугольник:\n";
    quad.printInfo();

    std::cout << "Прямоугольник:\n";
    rect.printInfo();

    std::cout << "Квадрат:\n";
    squar.printInfo();

    std::cout << "Параллелограмм:\n";
    par.printInfo();

    std::cout << "Ромб:\n";
    rhom.printInfo();
    */
}
