//
// Created by Dmitry Morozov on 12/11/22.
//

#ifndef COURSERA_YELLOW_BELT_MAIN_RECTANGLE_HPP
#define COURSERA_YELLOW_BELT_MAIN_RECTANGLE_HPP


class Rectangle {
public:
    Rectangle(int width, int height);

    int GetArea() const;

    int GetPerimeter() const;

    int GetWidth() const;

    int GetHeight() const;

private:
    int width_, height_;
};


#endif //COURSERA_YELLOW_BELT_MAIN_RECTANGLE_HPP
