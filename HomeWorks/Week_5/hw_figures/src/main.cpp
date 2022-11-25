//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <sstream>
#include <memory>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

// базовый класс Figure с чисто виртуальными методами Name, Perimeter и Area;
//
// классы Triangle, Rect и Circle, которые являются наследниками класса Figure и переопределяют его виртуальные методы;
//
// функцию CreateFigure, которая в зависимости от содержимого входного потока создаёт shared_ptr<Rect>, shared_ptr<Triangle> или shared_ptr<Circle>.

class Figure {
public:
    virtual string Name() const = 0;

    virtual double Perimeter() const = 0;

    virtual double Area() const = 0;

private:




};

class Triangle : public Figure {

public:
    Triangle(double a, double b, double c) : a_(a), b_(b), c_(c) {}

    string Name() const override {

        return "TRIANGLE";
    }

    double Perimeter() const override {

        return a_ + b_ + c_;
    }

    double Area() const override {

        double p = Perimeter() / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

private:
    double a_, b_, c_;
};

class Rect : public Figure {

public:
    Rect(double width, double height) : width_(width), height_(height) {}

    string Name() const override {

        return "RECT";
    }

    double Perimeter() const override {

        return 2 * (width_ + height_);
    }

    double Area() const override {

        return width_ * height_;
    }

private:
    double width_, height_;

};

class Circle : public Figure {

public:
    Circle(double r) : r_(r) {}

    string Name() const override {

        return "CIRCLE";
    }

    double Perimeter() const override {

        return 2 * pi_ * r_;
    }

    double Area() const override {

        return pi_ * r_ * r_;
    }

private:
    double r_;
    double pi_ = 3.14;
};


shared_ptr<Figure> CreateFigure(istream &is) {

    string figure_type;
    is >> figure_type;

    if (figure_type == "TRIANGLE") {

        double a, b, c;
        is >> a >> b >> c;

        return make_shared<Triangle>(a, b, c);

    } else if (figure_type == "RECT") {

        double width, height;
        is >> width >> height;

        return make_shared<Rect>(width, height);

    } else if (figure_type == "CIRCLE") {

        double r;
        is >> r;

        return make_shared<Circle>(r);
    }

    return nullptr;
}

//int main() {
//
//    vector<shared_ptr<Figure>> figures;
//    for (string line; getline(cin, line);) {
//        istringstream is(line);
//
//        string command;
//        is >> command;
//        if (command == "ADD") {
//            // Пропускаем "лишние" ведущие пробелы.
//            // Подробнее об std::ws можно узнать здесь:
//            // https://en.cppreference.com/w/cpp/io/manip/ws
//            is >> ws;
//            figures.push_back(CreateFigure(is));
//        } else if (command == "PRINT") {
//            for (const auto &current_figure: figures) {
//                cout << fixed << setprecision(3)
//                     << current_figure->Name() << " "
//                     << current_figure->Perimeter() << " "
//                     << current_figure->Area() << endl;
//            }
//        }
//    }
//    return 0;
//}