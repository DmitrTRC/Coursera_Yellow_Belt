//
// Created by Dmitry Morozov on 20/9/22.
//

#include <iostream>
#include <sstream>

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

    string name_;

    double perimeter_;

    double area_;

};

int main() {

    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto &current_figure: figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}